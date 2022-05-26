#!/bin/bash
#Brian Kim, byk6q, 10/29/21, averagetime.sh
total=0;
average=0;

echo "enter the exponent for counter.cpp:"
read x
if [[$x == "quit"]]
then
    exit
else  
    for i in 1 2 3 4 5
    do
	echo "Running iteration $i..."
	runtime=`./a.out $x | tail -1`
	echo "time taken:" $runtime "ms"
	total=$((total + runtime))
    done
    

average=$((total / 5))
echo "Five iterations took" $total "ms"
echo "Average time was" $average "ms"
fi
