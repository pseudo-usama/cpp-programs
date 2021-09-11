#!/bin/bash

for x in *.txt;
do
	mv "$x" "${x%.txt}.123";
done
