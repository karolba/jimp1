#!/bin/bash
if [[ $# == 0 ]]; then
    set -- solution.c
fi
exec vim +':map <CR> :!./run.sh<CR>' +'map \<CR> :!./run.sh line<CR>' "$@"
