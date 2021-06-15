include irvine32.inc
.data
	var dd 01011001010101010111110001101111b
	      ;0101 1001 0101 0101 0111 1100 0110 1111
.code
	main proc
		;Program to print the al, ah and ax parts of register
		
		mov eax, var
		movzx eax, al	;Last byte
		call writebin
		call crlf

		mov eax, var
		movzx eax, ah	;Second Last byte
		call writebin
		call crlf

		mov eax, var
		movzx eax, ax	;Last 2 bytes
		call writebin
		call crlf

		mov eax, var	;All 4 bytes
		call writebin
		call crlf

	exit
	main endp
end