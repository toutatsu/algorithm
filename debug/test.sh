#!/bin/bash

# for((i=0;i<20;i++)); do ./test.sh $i; done

#until a WA case is found
# echo a>result_ac.out;echo a>result_wa.out;for((i=0;! -n "`diff result_ac.out result_wa.out`"  ;i++)); do ./test.sh $i; done
echo "///////////////////////////////////////////////////////////////////////////////////////"
echo ""

if [ $# = 0 ];then
    echo "usage : ./test seed compile"
    exit
fi
if [ $# -gt 1 ];then
    if [ $2 = 1 ];then
        g++ source.cpp
        g++ AC.cpp -o AC
        g++ testcase.cpp -o testcase
    fi
fi

echo "seed : $1"
echo "input :"
./testcase $1

./testcase $1 | ./a.out > result_wa.out
./testcase $1 | ./AC > result_ac.out

echo -n "result :"
if [ -z "`diff result_ac.out result_wa.out`" ];then
    echo -n -e "\033[1m \x1b[1m \x1b[32m"
    echo "AC"
    echo -e "\x1b[0m"
else
    echo -n -e "\033[1m \x1b[1m \x1b[33m "
    echo "WA"
    echo -e "\x1b[0m"

    echo "result_ac.out                                                   result_wa.out -u"
    diff result_ac.out result_wa.out -y
    echo "---------------------------------------------------------------------------------------"
    diff result_ac.out result_wa.out -u
    echo "---------------------------------------------------------------------------------------"
    #vimdiff result_ac.out result_wa.out
    colordiff result_ac.out result_wa.out

fi

echo "///////////////////////////////////////////////////////////////////////////////////////"
echo -e "\n\n"
