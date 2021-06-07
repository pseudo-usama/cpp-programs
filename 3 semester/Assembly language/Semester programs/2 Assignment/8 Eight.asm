include irvine32.inc

.data

.code
main proc
	;Print Triangle
	
	mov eax, '*'

	mov ecx, 6
	mov ebx, 6		;Work as holder for outer Loop ecx
	mov edx, 11		;Work as holder for Inner Loop ecx
	
	Outer:
		mov ebx, ecx
		mov ecx, edx

		Inner:
			call writechar
		loop Inner

		sub edx, 2
		mov ecx, ebx

		call crlf

	loop Outer

main endp
exit

end