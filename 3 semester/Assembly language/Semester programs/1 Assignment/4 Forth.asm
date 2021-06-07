include irvine32.inc

.data

.code

ymain proc
	;30 - 5 - 3*4 + 10*30 - 2 - 5 + 30*5
	
	mov ebx, 30
	sub ebx, 5
	sub ebx, 2
	sub ebx, 5

	mov eax, 3
	mov ecx, 4
	mul ecx

	sub ebx, eax

	mov eax, 10
	mov ecx, 30
	mul ecx

	add ebx, eax

	mov eax, 30
	mov ecx, 5
	mul ecx

	add eax, ebx

	call writeint

ymain endp
exit

end