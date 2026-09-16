"General editor settings
set tabstop=4
set nocompatible
set shiftwidth=4
set expandtab
set autoindent
set smartindent
set ruler
set showcmd
set incsearch
set shellslash
set number
set relativenumber
set cino+=L0 
syntax on
filetype indent on
filetype off
setlocal indentkeys-=:

"keybindings for { completion, "jk" for escape, ctrl-a to select all
inoremap {<CR>  {<CR>}<Esc>O
inoremap {}     {}
imap jk         <Esc>
map <C-a> <esc>ggVG<CR>
set belloff=all

"Append template to new C++ files
autocmd BufNewFile *.cpp 0r ~/cp/library/template.cpp


"Compile and run
"Note that this line requires the build.sh script!
autocmd FileType cpp nnoremap <F9> :w <bar> !build.sh %:r <CR> 
autocmd FileType cpp nnoremap <buffer> <F10> :!./%:t:r < in<CR>
autocmd FileType cpp nnoremap <buffer> <F8>
  \ :w <bar> execute '!build.sh ' . shellescape(expand('%:r')) . ' && ./' . shellescape(expand('%:t:r')) . ' < in'<CR>

"LaTeX settings
autocmd FileType tex :NoMatchParen
autocmd FileType tex :set tw=110

 
" Plugin Management Settings
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()

" Declare your plugin here
Plugin 'VundleVim/Vundle.vim'
Plugin 'lervag/vimtex'
Plugin 'octol/vim-cpp-enhanced-highlight'

call vundle#end()
filetype plugin indent on

" VimTeX Configuration
let g:vimtex_view_general_viewer = 'SumatraPDF'
let g:vimtex_view_general_options = '-reuse-instance @pdf'
let g:vimtex_view_general_options_latexmk = '-reuse-instance'
let g:tex_flavor = 'latex'
let g:vimtex_motion_matchparen = 0
let g:vimtex_fold_manual = 1
let g:vimtex_matchparen_enabled = 0
