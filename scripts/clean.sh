#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd)"

python3 - "$ROOT_DIR" <<'PY'
from pathlib import Path
import sys

root = Path(sys.argv[1])
folders = [root / name for name in ("scripts", "library", "config")]
changed_files = []

for folder in folders:
    if not folder.is_dir():
        raise SystemExit(f"error: directory not found: {folder}")

    for path in folder.rglob("*"):
        if not path.is_file() or path.is_symlink():
            continue

        data = path.read_bytes()
        cleaned = data.replace(b"\r", b"")
        if cleaned == data:
            continue

        path.write_bytes(cleaned)
        changed_files.append(path.relative_to(root))

for path in changed_files:
    print(f"cleaned {path}")

print(f"Removed carriage returns from {len(changed_files)} file(s).")
PY