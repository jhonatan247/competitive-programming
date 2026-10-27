#!/usr/bin/env bash
# compile.sh — expand local #include "..." into a single self-contained .cpp
# Usage:    inline-cp.sh path/to/A.cpp

set -euo pipefail

# ---------------------------------------------------------------------------
# helpers & config
# ---------------------------------------------------------------------------

readlinkf() {
  if command -v realpath >/dev/null 2>&1; then
    realpath -- "$1"
  elif readlink -f / >/dev/null 2>&1; then
    readlink -f -- "$1"
  else
    python3 -c 'import os,sys; print(os.path.realpath(sys.argv[1]))' -- "$1"
  fi
}

die() { printf 'inline-cp: %s\n' "$*" >&2; exit 1; }

[[ $# -eq 1 ]] || die "usage: $(basename "$0") path/to/source.cpp"
[[ -f $1 ]] || die "no such file: $1"

SRC=$(readlinkf "$1")
[[ $SRC == *_compiled.cpp ]] && die "refusing to inline an already-generated file: $SRC"

SRC_DIR=$(dirname -- "$SRC")
LIB_DIR="${CP_LIB_DIR:-$HOME/cp/library}"
OUT="${SRC%.*}_compiled.cpp"

# ---------------------------------------------------------------------------
# expansion state
# ---------------------------------------------------------------------------

declare -A SEEN=()
declare -A STACK=()

resolve() {
  local raw=$1 from_dir=$2 cand
  for cand in "$from_dir/$raw" "$raw" "$LIB_DIR/$raw"; do
    if [[ -f $cand ]]; then
      readlinkf "$cand"
      return
    fi
  done
  die "cannot resolve #include \"$raw\""
}

expand() {
  local path=$1
  local dir
  dir=$(dirname -- "$path")

  [[ -n ${STACK[$path]:-} ]] && die "cyclic include detected at: $path"
  [[ -n ${SEEN[$path]:-}  ]] && return

  SEEN[$path]=1
  STACK[$path]=1

  # --- PATH REDACTION ---
  local display_path="$path"
  if [[ "$display_path" == "$LIB_DIR"/* ]]; then
    display_path="~/cp/library/${display_path#"$LIB_DIR/"}"
  elif [[ "$display_path" == "$HOME"/* ]]; then
    display_path="~/${display_path#"$HOME/"}"
  fi

  printf '// >>> %s\n' "$display_path"

  local line raw
  while IFS= read -r line || [[ -n $line ]]; do
    if [[ $line =~ ^[[:space:]]*#[[:space:]]*include[[:space:]]*\"([^\"]+)\" ]]; then
      raw=${BASH_REMATCH[1]}
      expand "$(resolve "$raw" "$dir")"
    else
      printf '%s\n' "$line"
    fi
  done < "$path"

  printf '// <<< %s\n' "$display_path"
  unset 'STACK[$path]'
}

# ---------------------------------------------------------------------------
# main: walk the source, expanding quoted includes
# ---------------------------------------------------------------------------

: > "$OUT"

{
  while IFS= read -r line || [[ -n $line ]]; do
    if [[ $line =~ ^[[:space:]]*#[[:space:]]*include[[:space:]]*\"([^\"]+)\" ]]; then
      expand "$(resolve "${BASH_REMATCH[1]}" "$SRC_DIR")"
    else
      printf '%s\n' "$line"
    fi
  done < "$SRC"
} >> "$OUT"

# ---------------------------------------------------------------------------
# syntax check (Using your global build.sh)
# ---------------------------------------------------------------------------

if command -v build.sh >/dev/null 2>&1; then
  # We pass OUT without the .cpp extension because your build.sh appends it
  if ! build.sh "${OUT%.cpp}" > /dev/null; then
    die "build check failed: $OUT"
  fi
else
  # Fallback just in case PATH is modified
  if ! g++ -std=c++23 -O2 -fsyntax-only "$OUT"; then
    die "syntax check failed: $OUT"
  fi
fi

printf 'wrote %s\n' "$OUT"
