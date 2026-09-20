" ~/.vimrc — Competitive Programming C++ (macOS + Ubuntu)

" Basic setup
set nocompatible
filetype plugin indent on
syntax on


" General editing
set tabstop=4
set shiftwidth=4
set softtabstop=4
set expandtab
set autoindent
set smartindent
set cino+=L0
set backspace=indent,eol,start
set ruler
set showcmd
set number
set relativenumber
set scrolloff=999
set hidden
set noswapfile
set nobackup
set nowritebackup
set undofile
set undodir=~/.vim/undo//
set autoread
set belloff=all
set noerrorbells
set visualbell
set t_vb=
set mouse=a
set incsearch
set hlsearch
set ignorecase
set smartcase
set wildmenu
set wildmode=longest:full,full
set splitright
set splitbelow
set completeopt=menuone,noinsert,noselect
set shortmess+=c
set updatetime=300
set timeoutlen=300
set ttimeoutlen=10
set pastetoggle=<F2>


" Cross-platform clipboard
if has('mac')
    set clipboard=unnamed
else
    set clipboard=unnamedplus
endif


" Create undo directory if missing
if !isdirectory($HOME.'/.vim/undo')
    call mkdir($HOME.'/.vim/undo', 'p')
endif


" Netrw improvements
let g:netrw_keepdir = 0
let g:netrw_localrmdir = 'rm -r'


" Keybindings
inoremap {<CR> {<CR>}<Esc>O
inoremap {} {}
inoremap jk <Esc>
nnoremap <C-a> ggVG
nnoremap <Tab> %


" Leader mappings

    let mapleader = "\<Space>"
"   Quick comment
    nnoremap <Leader>/ 0i//<ESC>
"   Select all
    nnoremap <Leader>a ggVG
"   Open netrw
    nnoremap <Leader>e :e .<CR>
"   Vertical split
    nnoremap <Leader>n :vs<CR>
"   Jump list
    nnoremap <Leader>o <C-O>
    nnoremap <Leader>i <C-I>
"   First non-blank
    nnoremap <Leader>b ^
"   Reload vimrc
    nnoremap <Leader>s :source ~/.vimrc<CR>


" Comands

"   Debug build
    command! Gdb !g++ -std=c++17 -O0 -g -o %< % && ./%<


" Autocmd

"   Append template to new C++ files
    autocmd BufNewFile *.cpp 0r ~/cp/library/template.cpp
"   C++ compile & run (using your build.sh workflow)
    autocmd FileType cpp setlocal makeprg=g++\ -std=c++17\ -O2\ -Wall\ -Wextra\ -o\ %:r\ %
    autocmd FileType cpp nnoremap <buffer> <F10> :w <bar> execute 
        \ '!build.sh ' . 
        \ shellescape(expand('%:r')) . 
        \ ' --verbose --debug && ./' . 
        \ shellescape(expand('%:t:r')) . 
        \ ' < in'<CR>
    autocmd FileType cpp nnoremap <buffer> <F9> :w <bar> execute 
        \ '!build.sh ' . 
        \ shellescape(expand('%:r')) . 
        \ ' --verbose --debug && ./' . 
        \ shellescape(expand('%:t:r'))<CR>
    autocmd FileType cpp nnoremap <buffer> <F8> :w <bar> execute 
        \ '!build.sh ' . shellescape(expand('%:r')) . 
        \ ' --verbose --debug'<CR>
"   Stress tests
    function! RunStress(compile)
        let n = input('tests: ', '100')
        if n !~# '^\d\+$' | let n = '100' | endif

        let base = split(expand('%:t:r'), '_')[0]
        let dir  = expand('%:p:h')
        let cmd  = '!cd ' . dir

        if a:compile
            let cmd .= ' && build.sh ' . base
                  \ . ' && build.sh ' . base . '_slow'
                  \ . ' && build.sh ' . base . '_gen'
        endif

        let cmd .= ' && stress.sh ' . base . ' ' . base . '_slow ' . base . '_gen ' . n
        execute cmd
    endfunction
    autocmd FileType cpp nnoremap <F7> :w <bar> call RunStress(0)<CR>
    autocmd FileType cpp nnoremap <F6> :w <bar> call RunStress(1)<CR>


" Plugin management (vim-plug only)
call plug#begin('~/.vim/plugged')
Plug 'bfrg/vim-c-cpp-modern'
Plug 'tpope/vim-commentary'
Plug 'tpope/vim-surround'
Plug 'tpope/vim-repeat'
Plug 'junegunn/fzf', { 'do': { -> fzf#install() } }
Plug 'junegunn/fzf.vim'
Plug 'sirver/ultisnips'
    let g:UltiSnipsExpandTrigger = '<tab>'
    let g:UltiSnipsJumpForwardTrigger = '<tab>'
    let g:UltiSnipsJumpBackwardTrigger = '<s-tab>'
call plug#end()

