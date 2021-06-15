include irvine32.inc

.code

main proc
	;8 + 4 + 5 + 1

	mov eax, 8
	add eax, 4
	add eax, 5
	add eax, 1

	call writeint

main endp
exit

end