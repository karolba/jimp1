#!/bin/bash
if [[ $# == 0 ]]; then
    set -- solution.c
fi
if vim --version | grep -q '^NVIM'; then
    exec vim +':map <CR> :w<CR>:te ./run.sh<CR>a' +'map \<CR> :w<CR>:te ./run.sh line<CR>a' "$@"
else
    exec vim +':map <CR> :w<CR>:!./run.sh<CR>' +'map \<CR> :w<CR>:!./run.sh line<CR>' "$@"
fi
