#!/usr/bin/env bash
set -euo pipefail

usage() {
    cat <<EOF
Usage: $(basename "$0") [-t] [-f folder] <name>

Open <name> in Vim, defaulting to the .cpp extension, optionally creating
and entering <folder>.

Options:
  -t            Treat the problem as a multi-test problem.
  -f folder     Create and enter folder before opening the file.
  -h, --help    Show this help message.
EOF
}

MULTI_TEST=0
FOLDER=""
NAME=""

while [ $# -gt 0 ]; do
    case "$1" in
        -t)
            MULTI_TEST=1
            shift
            ;;
        -f)
            if [ $# -lt 2 ]; then
                echo "Error: -f requires a folder" >&2
                usage >&2
                exit 1
            fi
            FOLDER="$2"
            shift 2
            ;;
        -h|--help)
            usage
            exit 0
            ;;
        -*)
            echo "Error: unknown option '$1'" >&2
            usage >&2
            exit 1
            ;;
        *)
            if [ -n "$NAME" ]; then
                echo "Error: multiple problem names given ('$NAME', '$1')" >&2
                usage >&2
                exit 1
            fi
            NAME="$1"
            shift
            ;;
    esac
done

if [ -z "$NAME" ]; then
    echo "Error: a problem name is required" >&2
    usage >&2
    exit 1
fi

SKIP_MULTI_TEST_PROMPT=0
NAME_BASE="${NAME##*/}"
case "$NAME_BASE" in
    *.cpp)
        ;;
    *.*)
        SKIP_MULTI_TEST_PROMPT=1
        ;;
    *_gen|*_int)
        NAME="${NAME}.cpp"
        SKIP_MULTI_TEST_PROMPT=1
        ;;
    *)
        NAME="${NAME}.cpp"
        ;;
esac

if [ -n "$FOLDER" ]; then
    mkdir -p -- "$FOLDER"
    cd -- "$FOLDER"
fi

if [ "$MULTI_TEST" -eq 0 ] &&
    [ "$SKIP_MULTI_TEST_PROMPT" -eq 0 ] &&
    [ ! -e "$NAME" ]; then
    printf 'Is this a multi-test problem? [y/N] '
    if ! IFS= read -r answer; then
        echo >&2
        echo "Error: could not read the multi-test choice" >&2
        exit 1
    fi

    case "$answer" in
        y|Y|yes|YES|Yes)
            MULTI_TEST=1
            ;;
    esac
fi

if [ "$MULTI_TEST" -eq 1 ]; then
    exec vim --cmd 'let g:test_cases=1' -- "$NAME"
fi

exec vim -- "$NAME"
