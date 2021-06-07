include irvine32.inc

.code

main proc
	;These are the registers in Computers

	mov eax, 16
	mov ebx, 17
	mov ecx, 19
	mov edx, 25
	mov edi, 30
	mov ebp, 70
	mov esi, 1000

	call dumpregs

exit
main endp

end