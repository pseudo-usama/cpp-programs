include irvine32.inc

.data
	str1 byte "Sum of Even Numbers is    : ", 0
	str2 byte "Sum of Odd  Numbers is    : ", 0
	str3 byte "Enter a number greater then 10  : ", 0

.code
vmain proc
	
	lea edx, str3
	call writestring

	call readdec

	lea edx, str1
	call writestring	;print string

	mov ecx, 2
	mov edx, 0
	div ecx
	mov ecx, eax
	mov edx, eax

	mov esi, 2
	mov eax, 0

	Evn:
		add eax, esi
		add esi, 2
	loop Evn

	call writedec
	call crlf

	mov eax, 0
	mov ecx, edx
	mov esi, 1

	Odd:
		add eax, esi
		add esi, 2
	loop Odd

	lea edx, str2
	call writestring	;print string
	call writedec
	call crlf

vmain endp
exit

end