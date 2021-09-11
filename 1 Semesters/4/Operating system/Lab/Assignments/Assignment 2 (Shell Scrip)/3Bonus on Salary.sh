#!/bin/bash

read -p "Enter your Salary  : " Salary
read -p "Enter your Scale   : " Scale

if [ $Scale -gt 15 ]
then
	echo "Your total Salary with Bonus is  : " $((Salary + Salary/100 * 50))
else
	echo "Your total Salary with Bonus is  : " $((Salary + Salary/100 * 25))
fi

