#!/usr/bin/env bash

echo "STRESS TESTING OF $1.cpp"
echo "----------------------"

for ((testNum=0;testNum<$4;testNum++))
do
    echo "Test: " $testNum
    ./$3 > input
    ./$2 < input > outSlow
    ./$1 < input > outWrong
    H1=`md5sum outWrong`
    H2=`md5sum outSlow`
    if ! diff -w -s "outWrong" "outSlow" > /dev/null; then
        echo "Error found!"
        echo "Input:"
        cat input
        echo "Wrong Output:"
        cat outWrong
        echo "Expected Output:"
        cat outSlow
        exit
    fi
    printf '\033[0;32mPassed\033[0m\n'
    echo "----------------------"
done
echo "Passed $4 tests"
