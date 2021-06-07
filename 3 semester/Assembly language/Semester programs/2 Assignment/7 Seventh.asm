include irvine32.inc

.data
	str1 byte "Enter a number  : ", 0
	str2 byte "Sum of Squares is  : ", 0
.code
rmain proc
	
	lea edx, str1
	call writestring

	call readdec
	mov ecx, eax

	mov ebx, 0	;This will store the Sum

	Again:
		mov eax, ecx
		mul ecx

		add ebx, eax
	loop Again
	
	lea edx, str2
	call writestring

	mov eax, ebx
	call writedec

	call crlf

rmain endp
exit

end