include irvine32.inc

.data

.code

bmain proc
	;30 + 40 - 3*4 + 2*30 - 10 + 50

	mov ebx, 30
	add ebx, 40
	add ebx, 50
	sub ebx, 10

	mov eax, 3
	mov edx, 4

	mul edx

	sub ebx, eax

	mov eax, 2
	mov edx, 30

	mul edx

	add eax, ebx

	call writeint

bmain endp
exit

end