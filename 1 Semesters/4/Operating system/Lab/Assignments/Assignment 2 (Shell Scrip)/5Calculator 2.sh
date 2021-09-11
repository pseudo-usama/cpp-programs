#!/bin/bash

read -p "Enter first number  : " a
read -p "Enter second number : " b
read -p "Enter the operator  : " Operator

case $Operator in
	+) echo "The result is  : " $((a + b)) ;;
	-) echo "The result is  : " $((a - b)) ;;
	*) echo "The result is  : " $((a * b)) ;;
	/) echo "The result is  : " $((a / b)) ;;
esac
