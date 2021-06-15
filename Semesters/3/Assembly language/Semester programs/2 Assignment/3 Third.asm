include irvine32.inc

.data
	str1 byte "Factorial is  : ", 0
	str3 byte "Enter a number from 0 to 12 to find factorial   : "

.code
omain proc
	;print factorial of n
	
	lea edx, str3
	call writestring	;print string

	call readdec		;input from user

	lea edx, str1
	call writestring
	
	mov ecx, eax

	mov eax, 1

	Again:
		mul ecx
	loop Again

	call writedec
	call crlf

omain endp
exit

end