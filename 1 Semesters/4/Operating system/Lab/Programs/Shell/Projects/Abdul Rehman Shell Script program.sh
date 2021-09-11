#!/bin/bash

#arrays to store data 
name=()
maths=()
eng=()
urdu=()

totalRecords=0
while [ 1 ]
do
clear
echo -n "1-Add new Record.
2-Delete Record.
3-Update Record.
4-Search Record.
5-Show all Records.
6-Exit.
You Choice:"
read choice
	case $choice in
	1)
		clear
		echo "====***Insertion Menu***===="
		read -p "How Many Records you want to add in System:" noOfRecords
		noOfRecords=$((totalRecords+noOfRecords))
		for ((i=totalRecords;i<noOfRecords;i++))
		do
			echo "========Enter Record of Student $((i+1))========"
			read -p "Enter a name:" name[$i]
			read -p "Enter a marks [maths]:" maths[$i]
			read -p "Enter a marks [eng]:" eng[$i]
			read -p "Enter a marks [urdu]:" urdu[$i]
			totalRecords=$((totalRecords+1))
			echo "Record Inserted Successfully."
		done
		read
	;;
	2)
		clear
		echo "====***Deletion Menu***===="
		if [ $totalRecords -eq 0 ]
		then
			echo "No Records Exists"
		else
		flag=0
		index=-1
		read -p "Enter name you want to delete:" nameToDelete
		for ((i=0;i<totalRecords;i++))
		do
			if [ "$nameToDelete" = "${name[i]}" ]
			then
				index=$i
				flag=1
			fi
		done
		if [ $flag -eq 1 ]
		then
			for ((i=index;i<totalRecords-1;i++))
			do
				name[$i]=${name[i+1]}
				maths[$i]=${maths[i+1]}
				eng[$i]=${eng[i+1]}
				urdu[$i]=${urdu[i+1]}
			done
			totalRecords=$((totalRecords-1))
		else
			echo "Record not Found."
		fi
		fi
		read
	;;
	3)
		clear
		echo "====***Updation Menu***===="
		if [ $totalRecords -eq 0 ]
		then
			echo "No Records Exists"
		else
		flag=0
		index=-1
		read -p "Enter name you want to update:" nameToUpdate
		for ((i=0;i<totalRecords;i++))
		do
			if [ "$nameToUpdate" = "${name[i]}" ]
			then
				index=$i
				flag=1
			fi
		done
		if [ $flag -eq 1 ]
		then
			read -p "Enter a name:" name[$index]
			read -p "Enter a marks [maths]:" maths[$index]
			read -p "Enter a marks [eng]:" eng[$index]
			read -p "Enter a marks [urdu]:" urdu[$index]
		else
			echo "Record not Found."
		fi
		fi
		read

	;;
	4)
		clear
		echo "====***Searching Menu***===="
		if [ $totalRecords -eq 0 ]
		then
			echo "No Records Exists"
		else
		flag=0
		index=-1
		read -p "Enter name you want to search:" nameToSearch
		for ((i=0;i<totalRecords;i++))
		do
			if [ "$nameToSearch" = "${name[i]}" ]
			then
				index=$i
				flag=1
			fi
		done
		if [ $flag -eq 1 ]
		then
			echo "Name:" name[$index]
			echo "Marks [maths]:" maths[$index]
			echo "Marks [eng]:" eng[$index]
			echo "Marks [urdu]:" urdu[$index]
		else
			echo "Record not Found."
		fi
		fi
		read

	;;
	5)
		clear
		echo "====***Records Menu***===="
		if [ $totalRecords -eq 0 ]
		then
			echo "No Records Exists"
		else
		for ((i=0;i<totalRecords;i++))
		do
			echo "========Showing Record of Student $((i+1))========"
			echo "Name:" ${name[i]}
			echo "Marks [maths]:" ${maths[i]}
			echo "Marks [eng]:" ${eng[i]}
			echo "Marks [urdu]:" ${urdu[i]}
		done
		fi
		read
	;;
	6)
		clear
		exit
	;;
	esac

done

