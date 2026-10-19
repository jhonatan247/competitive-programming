#!/bin/bash

ln -s ~/cp/config/.vimrc ~/.vimrc
ln -s ~/cp/config/cpp.snippets ~/.vim/UltiSnips/cpp.snippets

curl -fLo ~/.vim/autoload/plug.vim --create-dirs \
    https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim

LINE='export PATH=$PATH:~/cp/scripts/'
grep -qxF "$LINE" ~/.zshrc || echo "$LINE" >> ~/.zshrc

LINE='export CPLUS_INCLUDE_PATH=~/cp/library:$CPLUS_INCLUDE_PATH'
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
