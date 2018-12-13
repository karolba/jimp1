#!/bin/bash
if [[ $# == 0 ]]; then
    set -- solution.c
fi

export SUBMITBASEURL='http://10.156.207.151/domjudge/'

id=$(basename "$(pwd)")

short_name=$(curl -s 'http://10.156.207.151/domjudge/api/problems' | jq -r '.[] | select(.["id"] == "'"$id"'").short_name')

echo "==== Submitting for id=$id and problem='$short_name'"

submit --contest=JMP1 --language=C --problem="$short_name" "$@"
