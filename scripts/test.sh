#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd)"
LIBRARY_DIR="$ROOT_DIR/library"
BUILD_DIR="$(mktemp -d "${TMPDIR:-/tmp}/cp-library-tests.XXXXXX")"
trap 'rm -rf -- "$BUILD_DIR"' EXIT

find_compiler() {
    if [ "$(uname -s)" = "Darwin" ]; then
        local compiler
        for compiler in g++-18 g++-17 g++-16 g++-15 g++-14 g++; do
            if command -v "$compiler" >/dev/null 2>&1; then
                command -v "$compiler"
                return 0
            fi
        done
    elif command -v g++ >/dev/null 2>&1; then
        command -v g++
        return 0
    fi
    return 1
}

if ! CXX="$(find_compiler)"; then
    echo "Error: no suitable GNU C++ compiler found." >&2
    exit 1
fi

TESTS=()
while IFS= read -r test_file; do
    TESTS+=("$test_file")
done < <(find "$LIBRARY_DIR" -type f -name '*.test.cpp' -print | sort)
if [ "${#TESTS[@]}" -eq 0 ]; then
    echo "No library tests found."
    exit 0
fi

for test_file in "${TESTS[@]}"; do
    test_name="${test_file#"$ROOT_DIR"/}"
    executable="$BUILD_DIR/$(basename "${test_file%.cpp}")"
    echo "==> $test_name"
    "$CXX" -std=c++23 -O2 -Wall -Wextra -Wpedantic \
        -Wconversion -Wshadow -I"$LIBRARY_DIR" \
        -o "$executable" "$test_file"
    "$executable"
done

echo "All library tests passed (${#TESTS[@]})."