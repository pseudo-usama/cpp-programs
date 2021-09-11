#!/bin/bash

for i in 0 1 2 3 4 5 6 7 8 9
do
	read -p "Enter an Number  : " arr[i]
done

Min=${arr[0]}
Max=${arr[0]}

for i in 0 1 2 3 4 5 6 7 8 9
do
	if [ ${arr[i]} -lt $Min ]
	then
		Min=${arr[i]}
	elif [ ${arr[i]} -gt $Max ]
	then
		Max=${arr[i]}
	fi
done

echo "Smallest number in Array  : $Min"
echo "Greatest number in Array  : $Max"
