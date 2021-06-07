include irvine32.inc

.data
	str1 byte "Enter First number   : ", 0
	str2 byte "Enter Second number   : ", 0
	str3 byte "First number raise to the power second is   : ", 0

.code
Imain proc
	;Print first number raise to the power second

	lea edx, str1
	call writestring	;printing string

	call readdec		;read first number
	mov ebx, eax

	lea edx, str2		;printing string
	call writestring

	call readdec		;read second number
	mov ecx, eax

	mov eax, 1

	Again:
		mul ebx
	loop Again

	lea edx, str3
	call writestring

	call writedec
	call crlf
Imain endp
exit

end