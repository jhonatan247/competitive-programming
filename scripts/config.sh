#!/bin/bash

ln -s ~/cp/config/.vimrc ~/.vimrc
ln -s ~/cp/config/cpp.snippets ~/.vim/UltiSnips/cpp.snippets

curl -fLo ~/.vim/autoload/plug.vim --create-dirs \
    https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim

LINE='export PATH=$PATH:~/cp/scripts/'
grep -qxF "$LINE" ~/.zshrc || echo "$LINE" >> ~/.zshrc

LINE='export CPLUS_INCLUDE_PATH=~/cp/library:$CPLUS_INCLUDE_PATH'
grep -qxF "$LINE" ~/.zshrc || echo "$LINE" >> ~/.zshrc

LINE='export CPLUS_INCLUDE_PATH=~/ac-library:$CPLUS_INCLUDE_PATH'
grep -qxF "$LINE" ~/.zshrc || echo "$LINE" >> ~/.zshrc

LINE="alias count='count.sh'"
grep -qxF "$LINE" ~/.zshrc || echo "$LINE" >> ~/.zshrc

LINE="alias in='in.sh'"
grep -qxF "$LINE" ~/.zshrc || echo "$LINE" >> ~/.zshrc

LINE="alias config='config.sh'"
grep -qxF "$LINE" ~/.zshrc || echo "$LINE" >> ~/.zshrc

LINE="alias src='source ~/.zshrc'"
grep -qxF "$LINE" ~/.zshrc || echo "$LINE" >> ~/.zshrc

LINE="alias vimrc='vim ~/.vimrc'"
grep -qxF "$LINE" ~/.zshrc || echo "$LINE" >> ~/.zshrc

LINE="alias vsrc='vim ~/.zshrc'"
grep -qxF "$LINE" ~/.zshrc || echo "$LINE" >> ~/.zshrc

LINE="alias vtemplate='vim ~/cp/library/template.cpp'"
grep -qxF "$LINE" ~/.zshrc || echo "$LINE" >> ~/.zshrc

LINE="alias vsnippets='vim ~/cp/config/cpp.snippets'"
grep -qxF "$LINE" ~/.zshrc || echo "$LINE" >> ~/.zshrc

LINE="alias vconfig='vim ~/cp/scripts/config.sh'"
grep -qxF "$LINE" ~/.zshrc || echo "$LINE" >> ~/.zshrc

LINE="alias vdebug='vim ~/cp/library/local/debug.h'"
grep -qxF "$LINE" ~/.zshrc || echo "$LINE" >> ~/.zshrc

LINE="alias vimt=\"vim --cmd 'let g:test_cases=1'\""
grep -qxF "$LINE" ~/.zshrc || echo "$LINE" >> ~/.zshrc

chmod +x ~/cp/scripts/*


#
# Sync the AtCoder Library (ac-library) repo.
#   - Clone it if the target directory does not exist.
#   - Otherwise, run `git pull` to update it.
#
set -euo pipefail

REPO_SSH="git@github.com:atcoder/ac-library.git"
TARGET_DIR="${1:-ac-library}"   # allow overriding via $1, default: ./ac-library

# Make sure git is available
if ! command -v git >/dev/null 2>&1; then
    echo "error: git is not installed or not in PATH" >&2
    exit 1
fi

if [ ! -e "$TARGET_DIR" ]; then
    echo "==> '$TARGET_DIR' not found — cloning $REPO_SSH"
    git clone "$REPO_SSH" "$TARGET_DIR"
    echo "==> Clone complete."
elif [ ! -d "$TARGET_DIR" ]; then
    echo "error: '$TARGET_DIR' exists but is not a directory" >&2
    exit 1
elif [ ! -d "$TARGET_DIR/.git" ]; then
    # Directory exists, but it's not a git repository — refuse to touch it.
    echo "error: '$TARGET_DIR' exists but is not a git repository" >&2
    echo "       refusing to pull. Remove it manually if you want a fresh clone." >&2
    exit 1
else
    echo "==> '$TARGET_DIR' already exists — pulling latest changes"
    git -C "$TARGET_DIR" pull --ff-only
    echo "==> Update complete."
fi
