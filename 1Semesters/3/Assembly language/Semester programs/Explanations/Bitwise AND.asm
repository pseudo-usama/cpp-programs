include irvine32.inc
.data
	var dd 18

.code
	main proc
		;Bitwise AND

		;Bitwise AND do and operation with the every bit in memory
		;We use Registers, Variables or Constant values

		mov eax, 10001010b
		AND al, 11100011b
		call writebin
		call crlf
		call writedec
		call crlf

		mov eax, 10111001b
		AND al, 0ABh	;In binary -> 1010 1011
		call writebin
		call crlf

		mov eax, 55		;In binary -> 0011 0111
		AND eax, var	;In binary -> 0001 0010
		call writebin
		call crlf

	exit
	main endp
end