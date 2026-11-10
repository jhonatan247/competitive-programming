#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd)"
CODE_SCRIPT="$ROOT_DIR/scripts/code.sh"

usage() {
    cat <<EOF
Usage:
  $(basename "$0") <contest> <problem>
  $(basename "$0") <name>

Find exact or partial contest/problem names below the cp directory.
EOF
}

relative_path() {
    printf '%s\n' "${1#"$ROOT_DIR"/}"
}

find_exact_directories() {
    local name="$1"
    find "$ROOT_DIR" \
        \( -path "$ROOT_DIR/.git" \) -prune \
        -o -type d -print0 |
        while IFS= read -r -d '' path; do
            if [ "$(basename -- "$path")" = "$name" ]; then
                printf '%s\0' "$path"
            fi
        done
}

find_exact_files() {
    local name="$1"
    find "$ROOT_DIR" \
        \( -path "$ROOT_DIR/.git" \) -prune \
        -o -type f -print0 |
        while IFS= read -r -d '' path; do
            if [ "$(basename -- "$path")" = "$name" ]; then
                printf '%s\0' "$path"
            fi
        done
}

find_partial_files() {
    local fragment="$1"
    find "$ROOT_DIR" \
        \( -path "$ROOT_DIR/.git" \) -prune \
        -o -type f -print0 |
        while IFS= read -r -d '' path; do
            if [[ "$(basename -- "$path")" == *"$fragment"* ]]; then
                printf '%s\0' "$path"
            fi
        done
}

print_directories() {
    local path
    if [ "$#" -eq 1 ]; then
        printf '%s\n' "$1"
        return
    fi

    for path in "$@"; do
        relative_path "$path"
    done
}

unique_directories() {
    local path directory existing seen
    local -a directories=()

    for path in "$@"; do
        directory="$(dirname -- "$path")"
        seen=0
        for existing in "${directories[@]}"; do
            if [ "$existing" = "$directory" ]; then
                seen=1
                break
            fi
        done
        if [ "$seen" -eq 0 ]; then
            directories+=("$directory")
        fi
    done

    printf '%s\0' "${directories[@]}"
}

unique_paths() {
    local path existing seen
    local -a paths=()

    for path in "$@"; do
        seen=0
        for existing in "${paths[@]}"; do
            if [ "$existing" = "$path" ]; then
                seen=1
                break
            fi
        done
        if [ "$seen" -eq 0 ]; then
            paths+=("$path")
        fi
    done

    printf '%s\0' "${paths[@]}"
}

if [ "$#" -lt 1 ] || [ "$#" -gt 2 ]; then
    usage >&2
    exit 1
fi

if [ "$#" -eq 2 ]; then
    contest="$1"
    problem="$2"
    matches=()

    while IFS= read -r -d '' contest_dir; do
        problem_file="$contest_dir/$problem.cpp"
        if [ -f "$problem_file" ]; then
            matches+=("$problem_file")
        fi
    done < <(find_exact_directories "$contest")

    while IFS= read -r -d '' problem_file; do
        matches+=("$problem_file")
    done < <(find_exact_files "${contest}${problem}.cpp")

    if [ "${#matches[@]}" -eq 0 ]; then
        printf "No matches found for contest '%s' and problem '%s'.\n" \
            "$contest" "$problem"
        exit 0
    fi

    directories=()
    while IFS= read -r -d '' directory; do
        directories+=("$directory")
    done < <(unique_directories "${matches[@]}")
    print_directories "${directories[@]}"
    if [ "${#matches[@]}" -eq 1 ]; then
        match_dir="$(dirname -- "${matches[0]}")"
        match_name="$(basename -- "${matches[0]}" .cpp)"
        "$CODE_SCRIPT" -f "$match_dir" "$match_name" >&2
    fi
    exit 0
fi

name="$1"
directories=()
files=()

while IFS= read -r -d '' path; do
    directories+=("$path")
done < <(find_exact_directories "$name")

while IFS= read -r -d '' path; do
    files+=("$path")
done < <(find_exact_files "$name")

if [ "${#directories[@]}" -gt 0 ] || [ "${#files[@]}" -gt 0 ]; then
    exact_matches=("${directories[@]}")
    for path in "${files[@]}"; do
        exact_matches+=("$(dirname -- "$path")")
    done
    matching_directories=()
    while IFS= read -r -d '' directory; do
        matching_directories+=("$directory")
    done < <(unique_paths "${exact_matches[@]}")
    print_directories "${matching_directories[@]}"
    if [ "${#files[@]}" -eq 1 ]; then
        match_dir="$(dirname -- "${files[0]}")"
        match_name="$(basename -- "${files[0]}" .cpp)"
        "$CODE_SCRIPT" -f "$match_dir" "$match_name" >&2
    fi
    exit 0
fi

partial_matches=()
while IFS= read -r -d '' path; do
    partial_matches+=("$path")
done < <(find_partial_files "$name")

if [ "${#partial_matches[@]}" -eq 0 ]; then
    printf "No matches found for '%s'.\n" "$name"
    exit 0
fi

matching_directories=()
while IFS= read -r -d '' directory; do
    matching_directories+=("$directory")
done < <(unique_directories "${partial_matches[@]}")
print_directories "${matching_directories[@]}"