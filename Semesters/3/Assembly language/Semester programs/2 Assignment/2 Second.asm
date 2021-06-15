include irvine32.inc

.data
	str1 db "'s square is ", 0

.code
gmain proc
	;First five numbers and their squares

	mov ecx, 5	;for run loop
	mov eax, 1	;for print numbers

	Again:
		call writedec	;print 1 to 5
		lea edx, str1
		call writestring

		mov ebx, eax	;find square
		mul ebx

		call writedec	;print square
		call crlf

		mov eax, ebx	;mov orignal value in eax
		add eax, 1		;incement 1
	loop Again
gmain endp
exit

end