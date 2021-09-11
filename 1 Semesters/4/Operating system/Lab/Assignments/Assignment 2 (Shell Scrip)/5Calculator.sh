#!/bin/bash

read -p "Enter first number  : " a
read -p "Enter second number : " b

echo "Enter the Option number."
echo "    1) Addition"
echo "    2) Subraction"
echo "    3) Multiplication"
echo "    4) Divition"
echo ""
read -p "Enter Choice  : " Choice

clear

case $Choice in
	1) echo "The Addition is  : $((a + b))" ;;
	2) echo "The Subtraction is  : $((a - b))" ;;
	3) echo "The Multiplication is  : $((a * b))" ;;
	4) echo "The Division is  : $((a / b))" ;;
	*) echo "Invalid choice" ;;
esac
