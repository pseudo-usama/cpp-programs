#!/bin/bash

read -p "Enter an three digit Number  : " Number


c=$((Number % 10))
Number=$((Number / 10))

b=$((Number % 10))
Number=$((Number / 10))

Number=$((c*100 + b*10 + Number))

echo "The entered Number in Reverse order is  : $Number"
