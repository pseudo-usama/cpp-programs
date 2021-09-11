#!/bin/bash

read -p "Enter a Number  : " Number

if [ $((Number % 2)) -eq 0 ]
then
	echo "The Number is Even."
else
	echo "The Number is Odd."
fi
