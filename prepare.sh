#!/bin/bash

set -u
shopt -s nullglob
mydir=$(dirname "$(readlink -f "$0")")
PATH="$PATH:$mydir/.exodus/bin"

curl_testcase() {
    # args: testcase_id, <in|out>

    local testfile="$pdir/test_$1_$2"

    curl "http://$ip/domjudge/public/problem.php?id=$id&testcase=$1&type=$2" -o "$testfile"

    # DOMJudge zwraca '200 OK' jak nie jest ok
    if [[ "$(cat "$testfile")" == '<fieldset class="error"><legend>ERROR</legend>'* ]]; then
        rm -f "$testfile"
        return 1
    fi
}

if [[ $# != 1 ]]; then
    echo "Usage: $0 <problem id>" >&2
    exit 1
fi

id=$1
ip=10.156.207.151
pdir=problems/$id

mkdir -p $pdir

problem_txt_is_header=0
problem_text=$(curl "http://$ip/domjudge/public/problem.php?id=$id")
problem_text_type=$(file - <<<"$problem_text")
if echo "$problem_text_type" | grep -qi '[^a-z]pdf[^a-z]'; then
    echo "$problem_text" > "$pdir/problem.pdf"
else
    echo "$problem_text" > "$pdir/problem.txt"
    if file -b "$pdir/problem.txt" | grep -q ' CRLF '; then
        dos2unix "$pdir/problem.txt"
    fi
    if grep -q '^#ifdef ' "$pdir/problem.txt" && grep -q '^#endif' "$pdir/problem.txt"; then
        problem_txt_is_header=1
        ln -s problem.txt "$pdir/problem.h"
    fi
fi

(( testcase_n = 1 ))
while curl_testcase $testcase_n 'in' && curl_testcase $testcase_n 'out'; do
    (( testcase_n += 1 ))
done

solution_file=$pdir/solution.c
if ! [[ -f $solution_file ]]; then
    echo "// author: $(getent passwd $USER | cut -d ':' -f 5 | cut -d ',' -f 1)" > "$solution_file"
    cat >> "$solution_file" <<EOF

#include <stdio.h>$( [[ $problem_txt_is_header == 1 ]] && echo -e '\n\n#include "problem.h"' )

int main() {
    return 0;
}
EOF
fi

cat > $pdir/vim.sh << 'EOF'
#!/bin/bash
if [[ $# == 0 ]]; then
    set -- solution.c
fi
if vim --version | grep -q '^NVIM'; then
    exec vim +':map <CR> :w<CR>:te ./run.sh<CR>a' +'map \<CR> :w<CR>:te ./run.sh line<CR>a' "$@"
else
    exec vim +':map <CR> :w<CR>:!./run.sh<CR>' +'map \<CR> :w<CR>:!./run.sh line<CR>' "$@"
fi
EOF

cat > $pdir/run.sh <<'EOF'
#!/bin/bash
cwdiff() { wdiff -n -w $'\033[31m' -x $'\033[0m' -y $'\033[32m' -z $'\033[0m' "$@"; }
if ! command -v wdiff &>/dev/null || [[ $1 == line ]]; then
    cwdiff() { cat "$1" | git diff -w --color=always --text --no-index -- - "$2" | tail -n+5 | awk '1; END{ if(NR) exit 1 }'; }
fi
failed_input() { echo -en '\e[100mInput:\e[0m\n\e[36m'; cat "$1"; echo -en '\e[0m'; return 1; }


set -uve
EOF

if grep -q '^#include <gtest' $pdir/test_1_in; then
    if file $pdir/test_1_in | grep -q 'C++ source'; then
        dos2unix $pdir/test_1_in
        echo -e '\n// vim: ft=cpp' >> $pdir/test_1_in
        {
            echo "g++ -xc++ -std=c++17 test_1_in solution.c -I ../../gtest/include -L ../../gtest/lib -lgtest -lgtest_main -pthread -osolution_test"
            echo './solution_test'
        } >> $pdir/run.sh
    fi
else
    echo 'gcc -O2 -static -pipe -Wall solution.c -lm -o solution' >> $pdir/run.sh
    {
        test_in=
        for test_in in $pdir/test_*_in; do # nullglob is set
            test_in=$(basename "$test_in")
            test_out="${test_in%_in}_out"
            echo "cwdiff <(./solution < $test_in) $test_out || failed_input $test_in"
        done
        if [[ -z $test_in ]]; then
            echo "#cwdiff <(./solution < test_1_in) test_1_out || failed_input test_1_in"
        fi
    } | sort --version-sort >> $pdir/run.sh
fi

chmod +x $pdir/run.sh $pdir/vim.sh
ln -sf ../../submit.sh $pdir/submit.sh

# vim: expandtab
