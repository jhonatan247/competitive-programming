#!/usr/bin/env bash

echo "INTERACTION TESTING OF $1.cpp"
echo "----------------------"

for ((testNum=0;testNum<$3;testNum++))
do
    echo "Test: $testNum"
    python3 ~/cp/scripts/runner.py --command1-stdout-prefix "Pro: " --command2-stdout-prefix "Int: " ./$1 ./$2 > out
 
    if [ "$(awk 'NF{p=$0}END{print p}' out)" != "Int: OK" ] 
    then
        echo "Error found!"
        echo "Interaction:"
        cat out
        exit
    fi
    printf '\033[0;32mPassed\033[0m\n'
    echo "----------------------"
done
echo "Passed $3 tests"
 
