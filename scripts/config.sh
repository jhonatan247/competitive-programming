ln -s ~/cp/config/.vimrc ~/.vimrc
ln -s ~/cp/config/cpp.snippets ~/.vim/UltiSnips/cpp.snippets

curl -fLo ~/.vim/autoload/plug.vim --create-dirs \
    https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim


LINE='export PATH=$PATH:~/cp/scripts/'

grep -qxF "$LINE" ~/.zshrc || echo "$LINE" >> ~/.zshrc

chmod +x ~/cp/scripts/build.sh
chmod +x ~/cp/scripts/interact.sh
chmod +x ~/cp/scripts/stress.sh
chmod +x ~/cp/scripts/validate.sh
chmod +x ~/cp/scripts/runner.py

