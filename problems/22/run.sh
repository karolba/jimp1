#!/bin/bash
cwdiff() { wdiff -n -w $'\033[31m' -x $'\033[0m' -y $'\033[32m' -z $'\033[0m' "$@"; }
if ! command -v wdiff &>/dev/null || [[ $1 == line ]]; then
    cwdiff() { cat "$1" | git diff -w --color=always --text --no-index -- - "$2" | tail -n+5 | awk '1; END{ if(NR) exit 1 }'; }
fi
failed_input() { echo -en '\e[100mInput:\e[0m\n\e[36m'; cat "$1"; echo -en '\e[0m'; return 1; }


set -uve
gcc -O2 -static -pipe -Wall solution.c -lm -o solution
cwdiff <(./solution < test_1_in) test_1_out || failed_input test_1_in
cwdiff <(./solution < test_2_in) test_2_out || failed_input test_2_in
cwdiff <(./solution < test_3_in) test_3_out || failed_input test_3_in
cwdiff <(./solution < test_4_in) test_4_out || failed_input test_4_in
cwdiff <(./solution < test_5_in) test_5_out || failed_input test_5_in
cwdiff <(./solution < test_6_in) test_6_out || failed_input test_6_in
cwdiff <(./solution < test_7_in) test_7_out || failed_input test_7_in
cwdiff <(./solution < test_8_in) test_8_out || failed_input test_8_in
cwdiff <(./solution < test_9_in) test_9_out || failed_input test_9_in
cwdiff <(./solution < test_10_in) test_10_out || failed_input test_10_in
cwdiff <(./solution < test_11_in) test_11_out || failed_input test_11_in
