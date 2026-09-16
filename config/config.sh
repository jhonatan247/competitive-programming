ln -s ./cp/config/.vimrc ~/.vimrc
curl -fLo ~/.vim/autoload/plug.vim --create-dirs \
    https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
LINE='export PATH=$PATH:~/cp/scripts/'

grep -qxF "$LINE" ~/.zshrc || echo "$LINE" >> ~/.zshrc
