#!/bin/bash

for i in 0 1 2 3 4 5 6 7 8 9
do
	read -p "Enter an Number  : " arr[i]
done


Sum=0
Product=1


for i in 0 1 2 3 4 5 6 7 8 9
do
	Sum=$((Sum + arr[i]))
	Product=$((Product*arr[i]))
done

echo "The Sum of Array is  : $Sum"
echo "The Product of Array is  : $Product"
