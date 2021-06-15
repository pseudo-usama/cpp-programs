include irvine32.inc

.data
	str1 byte "Product of Odd numbs from 1 to 10 is  : ", 0

.code
fmain proc
	;Print Sum of Odd Numbers from 1 to 10

	mov eax, 1
	mov ecx, 5
	mov ebx, 1

	Again:
		mul ebx

		add ebx, 2
	loop Again

	lea edx, str1
	call writestring

	call writedec
	call crlf

fmain endp
exit

end