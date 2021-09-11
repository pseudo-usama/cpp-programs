#!/bin/bash

array=(2 3 4 5)

echo ${array[0]}
echo ${array[*]}

array[4]=6
echo ${array[*]}

array[5]="usama"
echo ${array[*]}

# Editing
array[0]="Ibrahim"
echo ${array[*]}
