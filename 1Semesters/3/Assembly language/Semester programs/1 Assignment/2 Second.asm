include irvine32.inc

.code

vmain proc
	;40 + 30 + 100 - 2*4 + 2*2 - 5*6 - 3
	
	mov ebx, 40
	add ebx, 30
	add ebx, 100
	sub ebx, 3

	mov eax, 2
	mov edx, 4

	mul edx

	sub ebx, eax

	mov eax, 2
	mov edx, 2

	mul edx

	add ebx, eax

	mov eax, 5
	mov edx, 6

	mul edx

	sub ebx, eax

	mov eax, ebx

	call writeint

vmain endp
exit

end