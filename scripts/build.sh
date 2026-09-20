#!/usr/bin/env bash
set -euo pipefail

# ---------- Parse arguments ----------
DEBUG=0
VERBOSE=0
PROBLEM=""

usage() {
    cat <<EOF
Usage: $0 [--debug] [--verbose] <problem_name_without_extension>

Modes:
  (no flags)         Quick build: -O2, no warnings, no LOCAL
  --debug            Adds -DLOCAL (enables #ifdef LOCAL code)
  --verbose          Adds all useful warnings (OS-dependent)
  --debug --verbose  Both: -DLOCAL + full warnings

Examples:
  $0 sol
  $0 --debug sol
  $0 --verbose sol
  $0 --debug --verbose sol
EOF
}

while [ $# -gt 0 ]; do
    case "$1" in
        --debug)   DEBUG=1; shift ;;
        --verbose) VERBOSE=1; shift ;;
        -h|--help) usage; exit 0 ;;
        -*)
            echo "Error: unknown option '$1'" >&2
            usage >&2
            exit 1
            ;;
        *)
            if [ -n "$PROBLEM" ]; then
                echo "Error: multiple problem names given ('$PROBLEM', '$1')" >&2
                exit 1
            fi
            PROBLEM="$1"
            shift
            ;;
    esac
done

if [ -z "$PROBLEM" ]; then
    usage >&2
    exit 1
fi

SRC="${PROBLEM}.cpp"
if [ ! -f "$SRC" ]; then
    echo "Error: source file '$SRC' not found" >&2
    exit 1
fi

# ---------- Detect OS / arch ----------
OS="$(uname -s)"
ARCH="$(uname -m)"

# ---------- Find a suitable GNU g++ ----------
find_compiler() {
    if [ "$OS" = "Darwin" ]; then
        # macOS: /usr/bin/g++ is Apple Clang, not GNU.
        # Search Homebrew prefixes (ARM first, then Intel) for versioned GNU g++.
        local prefixes=("/opt/homebrew/bin" "/usr/local/bin")
        local versions=(18 17 16 15 14 13)
        for prefix in "${prefixes[@]}"; do
            for v in "${versions[@]}"; do
                if [ -x "$prefix/g++-$v" ]; then
                    echo "$prefix/g++-$v"
                    return 0
                fi
            done
        done
    else
        # Linux / WSL: system g++ is already GNU GCC.
        if command -v g++ >/dev/null 2>&1; then
            command -v g++
            return 0
        fi
    fi
    return 1
}

if ! GPP="$(find_compiler)"; then
    echo "Error: no suitable GNU C++ compiler found." >&2
    echo "  OS:   $OS" >&2
    echo "  Arch: $ARCH" >&2
    if [ "$OS" = "Darwin" ]; then
        echo "  Fix:  brew install gcc" >&2
    else
        echo "  Fix:  sudo apt update && sudo apt install build-essential" >&2
    fi
    exit 1
fi

# ---------- Assemble flags ----------
# Base flags: always applied.
FLAGS=(-O2 -std=c++17 -Wno-unknown-pragmas)

# --debug: define LOCAL for #ifdef LOCAL blocks (freopen, dbg macros, etc.)
if [ "$DEBUG" -eq 1 ]; then
    FLAGS+=(-DLOCAL -g -fsanitize=address,undefined)
fi

# --verbose: enable comprehensive warnings, tuned per OS.
if [ "$VERBOSE" -eq 1 ]; then
    FLAGS+=(-Wall -Wextra -Wshadow -Wconversion)

    if [ "$OS" = "Darwin" ] && [ "$ARCH" = "arm64" ]; then
        # Apple Silicon: GCC/clang here has no SSE4, so <x86intrin.h> pragmas
        # and -msse4 style targets warn. -Wno-unknown-pragmas already covers
        # the pragma side; nothing extra needed for the common case.
        : # placeholder for future ARM-specific flags
    fi
fi

# ---------- Show what we're doing ----------
echo "Platform:        $OS ($ARCH)"
echo "Compiler:        $GPP"
"$GPP" --version | head -n 1
echo "Debug (LOCAL):   $([ "$DEBUG" -eq 1 ] && echo yes || echo no)"
echo "Verbose (warns): $([ "$VERBOSE" -eq 1 ] && echo yes || echo no)"
echo "Flags:           ${FLAGS[*]}"
echo

# ---------- Compile ----------
"$GPP" "${FLAGS[@]}" -o "$PROBLEM" "$SRC"

echo
echo "Built: ./$PROBLEM"
