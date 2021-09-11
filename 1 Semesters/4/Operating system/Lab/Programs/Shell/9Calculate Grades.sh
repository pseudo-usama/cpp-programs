#!/bin/bash

read -p "Enter your Marks   : " Number

if [ $Number -gt $((100)) ]
then
	echo "Don't lie."
elif [ $Number -ge $((85)) ]
then
	echo "Extraordinary A+"
elif [ $Number -ge $((80)) ]
then
	echo "Wow A"
elif [ $Number -ge $((75)) ]
then
	echo "Nice B+"
elif [ $Number -ge $((70)) ]
then
	echo "B"
elif [ $Number -ge $((65)) ]
then
	echo "B-"
elif [ $Number -ge $((60)) ]
then
	echo "C+"
elif [ $Number -ge $((55)) ]
then
	echo "C"
elif [ $Number -ge $((50)) ]
then
	echo "D"
elif [ $Number -ge $((0)) ]
then
	echo "F"
else
	echo "Don't lie"
fi
