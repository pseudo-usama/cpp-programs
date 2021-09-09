include irvine32.inc

.data
	InputStr db "Enter a number  : ", 0
	EvenStr db "The number is Even", 0ah, 0
	OddStr db "The number is Odd", 0ah, 0

.code
	main proc
		;Print that the number is Even or Odd
	
		lea edx, InputStr
		call writestring
		call readdec

		mov ebx, 2
		mov edx, 0
		div ebx
		
		.if edx == 0
			lea edx, EvenStr
		.else
			lea edx, OddStr
		.endif
	
		call writestring

	exit
	main endp
end