#!/bin/bash

$choice

TotalRecords=0

RollNo=()
Name=()
FName=()
CNIC=()
CGPA=()

while [ 1 ]
do
	clear

	echo "1) Teacher"
	echo "2) Student"
	echo "3) Exit"
	read -p "Enter your Choice :  " choice

	clear

	if [ $choice -eq 1 ]
	then
		while [ 1 ]
		do
			clear

			echo "1) Print Data"
			echo "2) Insert Data"
			echo "3) Update Data"
			echo "4) Delete Data"
			echo "5) Home Page"
			echo "6) Exit"
			read -p "Enter you Choice :  " choice

			clear

			case $choice in
				1)	# Printing
					echo "========Printing Data========"
					echo ""

					if [ $TotalRecords -eq 0 ]
					then
						echo "No Record found."
					else
						for ((i=0; i<TotalRecords; i++))
						do
							echo "========Student $i Record========"
							echo "Roll No.    : " ${RollNo[i]}
							echo "Name        : " ${Name[i]}
							echo "Father Name : " ${FName[i]}
							echo "CNIC        : " ${CNIC[i]}
							echo "CGPA        : " ${CGPA[i]}
							echo ""
						done
					fi
				;;	# Ending Print

				2)	# Inserting
					echo "========Inserting Data========"
					echo ""

					read -p "Enter Roll No.    : " RollNo[$TotalRecords]
					read -p "Enter Name        : " Name[$TotalRecords]
					read -p "Enter Father Name : " FName[$TotalRecords]
					read -p "Enter CNIC        : " CNIC[$TotalRecords]
					read -p "Enter CGPA        : " CGPA[$TotalRecords]

					TotalRecords=$((TotalRecords+1))
				;;	# Ending Insert

				3)	# Updating
					echo "========Updating Data========"
					echo ""

					if [ $TotalRecords -eq 0 ]
					then
						echo "No Record Found."
					else
						read -p "Enter RollNo to Update  : " rollno
						echo ""

						for ((i=0; i<TotalRecords; i++))
						do
							if [ $rollno -eq ${RollNo[$i]} ]
							then
								read -p "Enter Name        : " Name[$i]
								read -p "Enter Father Name : " FName[$i]
								read -p "Enter CNIC        : " CNIC[$i]
								read -p "Enter CGPA        : " CGPA[$i]

								break
							elif [ $i -eq $((TotalRecords-1)) ]
							then
								echo "No Data found for RollNo " $rollno
							fi
						done
					fi
				;;	# Ending Update

				4)	# Deleting Data
					echo "========Deleting Data========"
					echo ""

					if [ $TotalRecords -eq 0 ]
					then
						echo "No Data Found."
					else
						read -p "Enter RollNo to Delete : " rollno
						echo ""

						for ((i=0; i<TotalRecords; i++))
						do
							if [ $rollno -eq ${RollNo[$i]} ]
							then
								if [ $i -ne $(($TotalRecords-1)) ]
								then
									for ((j=i; j<$((TotalRecords-1)); j++))
									do
										RollNo[$j]=${RollNo[$((j+1))]}
										Name[$j]=${Name[$((j+1))]}
										FName[$j]=${FName[$((j+1))]}
										CNIC[$j]=${CNIC[$((j+1))]}
										CGPA[$j]=${CGPA[$((j+1))]}
									done
								fi

								TotalRecords=$((TotalRecords-1))
								echo "Data Deleted"
								break
							elif [ $i -eq $((TotalRecords-1)) ]
							then
								echo "No Data found for RollNo : " $rollno
							fi
						done
					fi
				;;	# Ending Delete

				5) break ;;

				6)
					clear
					exit
				;;

				*) continue ;;
			esac

			echo ""
			read -p "Press Enter to continue..."
		done	# Inner Teacher while loop

	elif [ $choice -eq 2 ]
	then
		read -p "Enter your RollNo  : " rollno
		echo ""

		clear
		flag=0
		index=0

		for ((i=0; i<TotalRecords; i++))
		do
			if [ $rollno -eq ${RollNo[$i]} ]
			then
				flag=1
				index=$i
				break
			fi
		done

		if [ $flag -eq 1 ]
		then
			while [ 1 ]
			do
				clear

				echo "1) View my Record"
				echo "2) Update my Record"
				echo "3) Home Page"
				echo "4) Exit"
				read -p "Enter your Choice  : " choice

				clear

				case $choice in
					1)	# Print Data
						echo "RollNo.      : " ${RollNo[$index]}
						echo "Name         : " ${Name[$index]}
						echo "Father Name  : " ${FName[$index]}
						echo "CNIC         : " ${CNIC[$index]}
						echo "CGPA         : " ${CGPA[$index]}
					;;

					2)
						echo "Note: You cannot change your RollNo, CGPA(Updating CGPA athority is only for Teacher)."
						read -p "Enter your Name         : " Name[$index]
						read -p "Enter your Father Name  : " FName[$index] 
						read -p "Enter your CNIC         : " CNIC[$index]
					;;

					3) break ;;
					4)
						clear
						exit
					;;

					*) continue ;;
				esac

				echo ""
				read -p "Press Enter to continue..."
			done
		else
			echo "No Data found for RollNo  : " $rollno
			read -p "Press Enter to continue..."
		fi
		# Ending Student Choice
	elif [ $choice -eq 3 ]
	then
		clear
		exit
	else
		continue
	fi	# Ending Choice
done	# Ending outer while loop
