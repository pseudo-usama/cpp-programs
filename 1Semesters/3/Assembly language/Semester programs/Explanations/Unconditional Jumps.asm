include irvine32.inc

.data

.code
main proc
	;Unconditional Jump

	;There are two types of Jumps Conditional and Unconditional

	;Unconditioal Jumps are simple
	;To use this we need an Label and Jmp keyword

	mov eax, 3

	Jmp GoEnd

		call writedec

	GoEnd:	

exit
main endp

end