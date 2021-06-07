include irvine32.inc

.data
	InputStr db "Press an character  : ", 0
	LowerCaseStr db " in Lower case is ", 0
	UpperCaseStr db " in Upper case is ", 0

.code
	main proc
		;Input a character then 
			;Print it
			;Print *
			;Print Lower case if it is Upper case
			;Print Upper case if it is Lower case
		
		lea edx, InputStr
		call writestring
		call readchar
		call writechar
		call crlf
	
		movzx ebx, al	;Saving the character
		mov eax, 42		;Ascii of *
		call writechar	;Printing *
		call crlf

		mov eax, ebx
		call writechar

		cmp eax, 91
		JB UpperCaseLabel

		lea edx, UpperCaseStr
		call writestring
		sub eax, 32
		call writechar
		Jmp Skip

		UpperCaseLabel:
			lea edx, LowerCaseStr
			call writestring
			add eax, 32
			call writechar

		Skip:
		call crlf

	exit
	main endp

end