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
"   Save current file
    nnoremap <Leader>w :write<CR>
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
"   Pasate yanked text into ~/in
    nnoremap <Leader>p :call writefile(split(substitute(getreg('+'), "\r", '', 'g'), "\n"), expand('~/in')) \| echom "~\/in updated"<CR>
"   Reset ~/in to a single line containing 0
    nnoremap <Leader>r :call writefile(['0'], expand('~/in')) \| echom "~\/in reset to 0"<CR>
"   Add a test case to ~/in
    function! s:CPNextTest() abort
      let l:path  = expand('~/in')
      " Read existing lines (if any), stripping any stray CRs from the file itself
      let l:lines = filereadable(l:path)
            \ ? map(readfile(l:path), 'substitute(v:val, "\r", "", "g")')
            \ : []
      " Current counter (0 if file is empty/missing or first line isn't a number)
      let l:n    = empty(l:lines) ? 0 : str2nr(l:lines[0])
      let l:rest = empty(l:lines) ? [] : l:lines[1:]
      " Clipboard contents, CR-stripped and split into lines
      let l:clip = split(substitute(getreg('+'), "\r", '', 'g'), "\n")
      " split() leaves one trailing '' when the clipboard ends with a newline; drop it
      " (only one, so intentional blank lines inside/at the end are preserved)
      if !empty(l:clip) && l:clip[-1] ==# ''
        call remove(l:clip, -1)
      endif
      call writefile([string(l:n + 1)] + l:rest + l:clip, l:path)
      echom printf('~/in: case %d, +%d line(s)', l:n + 1, len(l:clip))
    endfunction
    nnoremap <Leader>t :call <SID>CPNextTest()<CR>

" Comands

"   Debug build
    command! Gdb !g++ -std=c++17 -O0 -g -o %< % && ./%<


" Autocmd

"   Append template to new C++ files
    autocmd BufNewFile *.cpp 0r ~/cp/library/template.cpp | 
        \ if get(g:, 'test_cases', 0) | 36delete | 34delete | endif | 
        \ execute "normal! 26Gi\<Tab>" | 
        \ startinsert!
"   C++ compile & run (using your build.sh workflow)
    autocmd FileType cpp setlocal makeprg=g++\ -std=c++17\ -O2\ -Wall\ -Wextra\ -o\ %:r\ %
    function! BuildCpp(flags, run) abort
        update
        let l:src = shellescape(expand('%:r'))   " filename without extension
        let l:bin = shellescape(expand('%:t:r')) " basename without extension
        let l:cmd = '!build.sh ' . l:src . ' ' . a:flags
        if a:run
            let l:cmd .= ' && ./' . l:bin . ' < ~/in'
        endif
        execute l:cmd
    endfunction
    autocmd FileType cpp nnoremap <buffer> <F10> <Cmd>call BuildCpp('--debug', 1)<CR>
    autocmd FileType cpp inoremap <buffer> <F10> <Cmd>call BuildCpp('--debug', 1)<CR>
    autocmd FileType cpp vnoremap <buffer> <F10> <Cmd>call BuildCpp('--debug', 1)<CR>
    autocmd FileType cpp nnoremap <buffer> <F9>  <Cmd>call BuildCpp('--verbose --debug', 1)<CR>
    autocmd FileType cpp inoremap <buffer> <F9>  <Cmd>call BuildCpp('--verbose --debug', 1)<CR>
    autocmd FileType cpp vnoremap <buffer> <F9>  <Cmd>call BuildCpp('--verbose --debug', 1)<CR>
    autocmd FileType cpp nnoremap <buffer> <F8>  <Cmd>call BuildCpp('', 0)<CR>
    autocmd FileType cpp inoremap <buffer> <F8>  <Cmd>call BuildCpp('', 0)<CR>
    autocmd FileType cpp vnoremap <buffer> <F8>  <Cmd>call BuildCpp('', 0)<CR>
"   Stress tests
    function! RunStress(compile) abort
        update
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
    autocmd FileType cpp nnoremap <buffer> <F7>  <Cmd>call RunStress(0)<CR>
    autocmd FileType cpp inoremap <buffer> <F7>  <Cmd>call RunStress(0)<CR>
    autocmd FileType cpp vnoremap <buffer> <F7>  <Cmd>call RunStress(0)<CR>
    autocmd FileType cpp nnoremap <buffer> <F6>  <Cmd>call RunStress(1)<CR>
    autocmd FileType cpp inoremap <buffer> <F6>  <Cmd>call RunStress(1)<CR>
    autocmd FileType cpp vnoremap <buffer> <F6>  <Cmd>call RunStress(1)<CR>


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

