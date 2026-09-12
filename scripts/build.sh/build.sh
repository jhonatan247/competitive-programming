#!/usr/bin/env bash
set -euo pipefail

# ---------- Argument check ----------
if [ -z "${1:-}" ]; then
    echo "Usage: $0 <problem_name_without_extension>"
    exit 1
fi

PROBLEM="$1"
SRC="${PROBLEM}.cpp"

if [ ! -f "$SRC" ]; then
    echo "Error: Source file '$SRC' not found"
    exit 1
fi

# ---------- Detect OS ----------
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
    echo "Error: No suitable GNU C++ compiler found."
    echo "  OS:   $OS"
    echo "  Arch: $ARCH"
    if [ "$OS" = "Darwin" ]; then
        echo "  Fix:  brew install gcc"
    else
        echo "  Fix:  sudo apt update && sudo apt install build-essential"
    fi
    exit 1
fi

# ---------- Show what we're using ----------
echo "Platform:       $OS ($ARCH)"
echo "Using compiler: $GPP"
"$GPP" --version | head -n 1
echo

# ---------- Compile ----------
#   -DLOCAL              enable local-only debug code
#   -O2                  optimization level
#   -std=c++17           language standard
#   -Wall -Wextra        useful warnings
#   -Wno-unknown-pragmas silence pragma warnings on ARM (no SSE4)
"$GPP" -DLOCAL -O2 -std=c++17 -Wall -Wextra -Wno-unknown-pragmas \
    -o "$PROBLEM" "$SRC"

echo
echo "Built: ./$PROBLEM"