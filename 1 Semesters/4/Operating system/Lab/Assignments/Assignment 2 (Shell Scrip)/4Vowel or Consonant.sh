#!/bin/bash

read -p "Enter an Alphabet  : " Alphabet

case $Alphabet in
        a) echo "$Alphabet is an Vowel." ;;
        e) echo "$Alphabet is an Vowel." ;;
        i) echo "$Alphabet is an Vowel." ;;
        o) echo "$Alphabet is an Vowel." ;;
        u) echo "$Alphabet is an Vowel." ;;
        A) echo "$Alphabet is an Vowel." ;;
        E) echo "$Alphabet is an Vowel." ;;
        I) echo "$Alphabet is an Vowel." ;;
        O) echo "$Alphabet is an Vowel." ;;
	U) echo "$Alphabet is an Vowel." ;;
	[0-9]*) echo "Invalid input." ;;
	*) echo "$Alphabet is an Consonent." ;;
esac
