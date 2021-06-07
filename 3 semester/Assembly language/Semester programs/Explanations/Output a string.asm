include irvine32.inc

.data
	str1 db "My String", 0
	str2 byte "You are Good", 0ah, 0

	;Here 0ah is used for printing end line after printing the string
	;Here 0 is used for ending the string if we dont put 0 after an string then all string below this strings will print

.code

main proc
	
	lea edx, str1

	call writestring

	lea edx, str2

	call writestring

main endp
exit

end