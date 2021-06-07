include irvine32.inc

.code

main proc
	
	mov eax, 2
	mov ebx, 3

	mul ebx

	;We use mul for multiplication
	;For multiplication it is necerry to mov one number into eax and second in any register or variable
	;And when we use mul it will multiply eax value to other register/variable and then store the result in eax

	call writedec

exit
main endp

end