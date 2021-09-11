#!/bin/bash

for i in 0 1 2 3 4 5 6 7 8 9
do
	read -p "Enter an Number  : " arr[i]
done

read -p "Enter an Number to Search in Array  : " n

checker=0

for i in 0 1 2 3 4 5 6 7 8 9
do
	if [ ${arr[i]} -eq $n ]
	then
		echo "Number found at $i index."
		checker=$((checker+1))
	fi
done

if [ $checker -eq 0 ]
then
	echo "Number not Found."
fi
