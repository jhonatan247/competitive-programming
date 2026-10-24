#!/bin/bash

# General Configs
set -euo pipefail


# Vim Plugins
curl -fLo ~/.vim/autoload/plug.vim --create-dirs \
    https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim


# Update ~/.zshrc
add_to_zshrc() {
    local line="$1"
    local file="$HOME/.zshrc"

    # If the exact line exists, drop it (safe fixed-string removal + atomic write)
    if grep -qxF -- "$line" "$file" 2>/dev/null; then
        local tmp
        tmp=$(mktemp "${file}.XXXXXX") || return 1
        grep -vxF -- "$line" "$file" > "$tmp"
        mv "$tmp" "$file"
    fi

    # Append at the end
    printf '%s\n' "$line" >> "$file"
}
add_to_zshrc '# CP settings added by config.sh'
add_to_zshrc 'ulimit -s unlimited'
add_to_zshrc 'export PATH=$PATH:~/cp/scripts/'
add_to_zshrc 'export CPLUS_INCLUDE_PATH=~/cp/library:$CPLUS_INCLUDE_PATH'
add_to_zshrc "alias count='count.sh'"
add_to_zshrc "alias in='in.sh'"
add_to_zshrc "alias config='bash ~/cp/scripts/config.sh'"
add_to_zshrc "alias src='source ~/.zshrc'"
add_to_zshrc "alias atc='cd ~/cp/atc'"
add_to_zshrc "alias cf='cd ~/cp/cf'"
add_to_zshrc "alias gym='cd ~/cp/gym'"
add_to_zshrc "alias lib='cd ~/cp/library && vim .'"
add_to_zshrc 'alias rpc='"'"'cd ~/cp/rpc && cd "$(ls -d */ | sort | tail -n1)"'"'"''
add_to_zshrc "alias scripts='cd ~/cp/scripts && vim .'"
add_to_zshrc "alias unal='cd ~/cp/unal'"
add_to_zshrc 'alias train='"'"'cd ~/cp/cf/training && cd "$(ls -d */ | sort | tail -n1)"'"'"''
add_to_zshrc "alias vimrc='vim ~/.vimrc'"
add_to_zshrc "alias vsrc='vim ~/.zshrc'"
add_to_zshrc "alias vtemp='vim ~/cp/library/template.cpp'"
add_to_zshrc "alias vsnip='vim ~/cp/config/cpp.snippets'"
add_to_zshrc "alias vconfig='vim ~/cp/scripts/config.sh'"
add_to_zshrc "alias vdebug='vim ~/cp/library/local/debug.h'"
add_to_zshrc "alias vimt=\"vim --cmd 'let g:test_cases=1'\""
chmod +x ~/cp/scripts/*


# Download libraries
clone_or_pull() {
    local repo_url="$1"

    # Make sure git is available
    if ! command -v git >/dev/null 2>&1; then
        echo "error: git is not installed or not in PATH" >&2
        exit 1
    fi

    local name
    name=$(basename "${repo_url%.git}")   # strip trailing .git, take last path component
    local target="$HOME/$name"

    if [ ! -e "$target" ]; then
        echo "==> '$target' not found — cloning $repo_url"
        git clone "$repo_url" "$target"
        echo "==> Clone complete."
    elif [ ! -d "$target" ]; then
        echo "error: '$target' exists but is not a directory" >&2
        exit 1
    elif [ ! -d "$target/.git" ]; then
        echo "error: '$target' exists but is not a git repository" >&2
        echo "       refusing to pull. Remove it manually if you want a fresh clone." >&2
        exit 1
    else
        echo "==> '$target' already exists — pulling latest changes"
        git -C "$target" pull --ff-only
        echo "==> Update complete."
    fi
}
#   AtCoder Library
    clone_or_pull "git@github.com:atcoder/ac-library.git"


# Link files and folders
ln -s ~/ac-library/atcoder ~/cp/library/atcoder || true
ln -s ~/cp/config/.vimrc ~/.vimrc || true
ln -s ~/cp/config/cpp.snippets ~/.vim/UltiSnips/cpp.snippets || true

echo "Config completed succesfully"
