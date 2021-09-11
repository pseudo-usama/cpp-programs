#!/bin/bash

read -p "Enter First Number    : " a
read -p "Enter Second Number   : " b

clear

if [ $a -gt $b ]
then
	echo "$a is Greater Number"
elif [ $b -gt $a ]
then
	echo "$b is Greater Number"
else
	echo "Both Numbers are Equal"
fi
