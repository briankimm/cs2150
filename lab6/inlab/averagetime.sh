#Brian Kim, byk6q, 10/19/21, averagetime.sh
#!/bin/bash
read dict
read grid
RUNNING_TIME_1=`./a.out $dict $grid | tail -1`
RUNNING_TIME_2=`./a.out $dict $grid | tail -1`
RUNNING_TIME_3=`./a.out $dict $grid | tail -1`
RUNNING_TIME_4=`./a.out $dict $grid | tail -1`
RUNNING_TIME_5=`./a.out $dict $grid | tail -1`
TOTAL=$(($RUNNING_TIME_1 + $RUNNING_TIME_2 + $RUNNING_TIME_3 + $RUNNING_TIME_4 + $RUNNING_TIME_5))
echo "Average runtime is "$((TOTAL/5))" milliseconds"
