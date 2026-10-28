import json
from pathlib import Path
from typing import Any


REPOSITORY_DIRECTORY = Path(__file__).resolve().parents[1]
PROJECT_DIRECTORY = REPOSITORY_DIRECTORY.parent
DATA_DIRECTORY = REPOSITORY_DIRECTORY / "data"
OUTPUT_PATH = DATA_DIRECTORY / "problem-library.json"


def build_template(directory: Path) -> dict[str, Any]:
    template: dict[str, Any] = {}
    contents: dict[str, Any] = {}
    problems: dict[str, Any] = {}

    for entry in sorted(directory.iterdir(), key=lambda path: path.name):
        if entry.is_dir():
            contents[entry.name] = build_template(entry)
        elif (
            entry.is_file()
            and entry.suffix == ".cpp"
            and "_" not in entry.name
        ):
            problems[entry.stem] = {"title": entry.stem}

    if contents:
        template["contents"] = contents
    if problems:
        template["problems"] = problems

    return template


def merge_missing(existing: dict[str, Any], generated: dict[str, Any], title: str) -> None:
    existing.setdefault("title", title)

    for section in ("contents", "problems"):
        generated_items = generated.get(section, {})
        if not generated_items:
            continue

        existing_items = existing.setdefault(section, {})
        if not isinstance(existing_items, dict):
            raise ValueError(f"{section!r} in the {title!r} entry must be a JSON object")

        for name, generated_item in generated_items.items():
            existing_item = existing_items.get(name)
            if existing_item is None:
                existing_items[name] = generated_item
            elif isinstance(existing_item, dict):
                merge_missing(existing_item, generated_item, name)
            else:
                raise ValueError(f"{name!r} in the {title!r} entry must be a JSON object")


def load_existing(path: Path) -> dict[str, Any]:
    if not path.exists():
        return {}

    with path.open(encoding="utf-8") as file:
        data = json.load(file)

    if not isinstance(data, dict):
        raise ValueError(f"{path} must contain a JSON object")
    return data


def build_source(source_name: str) -> dict[str, Any]:
    source_directory = PROJECT_DIRECTORY / source_name
    generated = {}
    for directory in sorted(source_directory.iterdir(), key=lambda path: path.name):
        if directory.is_dir():
            generated[directory.name] = {
                "title": directory.name,
                **build_template(directory),
            }
    return generated


def merge_source(
    existing: dict[str, Any],
    generated: dict[str, Any],
    source_name: str,
) -> None:
    source_data = existing.setdefault(source_name, {})
    if not isinstance(source_data, dict):
        raise ValueError(f"{source_name!r} in {OUTPUT_PATH} must be a JSON object")

    for name, generated_item in generated.items():
        existing_item = source_data.get(name)
        if existing_item is None:
            source_data[name] = generated_item
        elif isinstance(existing_item, dict):
            merge_missing(existing_item, generated_item, name)
        else:
            raise ValueError(
                f"{name!r} in {source_name!r} in {OUTPUT_PATH} must be a JSON object"
            )


def main() -> None:
    existing = load_existing(OUTPUT_PATH)
    for source_name in ("learning", "training"):
        legacy_path = DATA_DIRECTORY / f"{source_name}.json"
        if source_name not in existing and not OUTPUT_PATH.exists():
            existing[source_name] = load_existing(legacy_path)
        merge_source(existing, build_source(source_name), source_name)

    DATA_DIRECTORY.mkdir(parents=True, exist_ok=True)
    with OUTPUT_PATH.open("w", encoding="utf-8", newline="\n") as file:
        json.dump(existing, file, indent=4, ensure_ascii=False)
        file.write("\n")


if __name__ == "__main__":
    main()
