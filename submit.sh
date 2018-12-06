#!/bin/bash
if [[ ! -f ~/.netrc ]]; then
    read -r -p'DOMJudge username: ' user
    read -r -s -p'DOMJudge password: ' pass; echo
    echo "machine 10.156.207.151 login $user password $pass" > ~/.netrc
    chmod 600 ~/.netrc
fi

if [[ $# == 0 ]]; then
    set -- solution.c
fi

PATH="$PATH:$(dirname "$(readlink -f "$0"))/.exodus/bin"

export SUBMITBASEURL='http://10.156.207.151/domjudge/'

id=$(basename "$(pwd)")

short_name=$(curl -s 'http://10.156.207.151/domjudge/api/problems' | jq -r '.[] | select(.["id"] == "'"$id"'").short_name')

echo "==== Submitting for id=$id and problem='$short_name'"

submit --contest=JMP1 --language=C --problem="$short_name" "$@"
