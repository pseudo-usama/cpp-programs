#!/bin/bash

read -p "Enter a year  : " Year

if [ $((Year % 4)) -eq 0 ]
then
	if [ $((Year % 100)) -eq 0 ]
	then
		if [ $((Year % 400)) -eq 0 ]
		then
			echo "This is a LEAP Year."
		else
			echo "This is not a leap Year"
		fi
	else
		echo "This is a LEAP Year."
	fi
else
	echo "This is not Leap Year."
fi
