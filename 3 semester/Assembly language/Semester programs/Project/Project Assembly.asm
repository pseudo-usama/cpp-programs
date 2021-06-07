include irvine32.inc
.data
	MenuStr1 db "Press 2 for ADDITION operations between registers.", 0ah, 0
	MenuStr2 db "Press 3 for SUBTRACTION operations between registers.", 0ah, 0
	MenuStr3 db "Press 4 for MULTIPLICATION operations between registers.", 0ah, 0
	MenuStr4 db "Press 5 for DIVISION operations between registers.", 0ah, 0
	MenuStr5 db "Press 6 for operations related to LOOP, ARRAY and STACK.", 0ah, 0
	MenuStr6 db "Press 0 for EXIT program execution", 0ah, 0
	MenuStr7 db "Enter your choice  : ", 0

	InputStr1 db "Enter First number  : ", 0
	InputStr2 db "Enter Second number  : ", 0
	SeeAdditionStr db "See the Addition in the eax register", 0ah, 0
	SeeSubtractionStr db "See the Subtraction in the eax register", 0ah, 0
	SeeMultiplicationStr db "See the Multiplication in the eax register", 0ah, 0
	SeeDivisionStr db "See the Dividion in the eax and Modulas in edx registers", 0ah, 0
	
	E_ARRAY dd 10 dup(?)
	O_ARRAY dd 10 dup(?)

	InputArrayStr db "Input 10 numbers one by one", 0ah, 0
	EvenArrayStr db "Elements in the Even Array are  :", 0
	OddArrayStr  db "Elements in the Odd Array are   :", 0

.code
	main proc
		
		mov eax, 1

		.while eax == 1
		
			lea edx, MenuStr1		;Printing Menu String 1
			call writestring
			lea edx, MenuStr2		;Printing Menu String 2
			call writestring
			lea edx, MenuStr3		;Printing Menu String 3
			call writestring
			lea edx, MenuStr4		;Printing Menu String 4
			call writestring
			lea edx, MenuStr5		;Printing Menu String 5
			call writestring
			lea edx, MenuStr6		;Printing Menu String 6
			call writestring
			lea edx, MenuStr7		;Printing Menu String 7
			call writestring
		
			call readdec
			
			call crlf
			call crlf

			.if eax == 2
				call ADDITION
			.elseif eax == 3
				call SUBTRACTION
			.elseif eax == 4
				call MULTIPLICATION
			.elseif eax == 5
				call DIVISION
			.elseif eax == 6
				call ARRAY
			.elseif eax == 0
				Jmp GoEnd
			.endif
		
			call crlf
			call crlf
			call crlf

			mov eax, 1
		.endw

		GoEnd:

	exit
	main endp

	ADDITION proc
		
		mov ebx, 0

		lea edx, InputStr1		;First Input
		call writestring
		call readint
		mov bl, al

		lea edx, InputStr2		;Second Input
		call writestring
		call readint
		
		add eax, ebx
				
		lea edx, SeeAdditionStr
		call writestring
		call dumpregs

	RET
	ADDITION endp

	SUBTRACTION proc
		
		mov ebx, 0

		lea edx, InputStr1
		call writestring
		call readint
		mov bl, al

		lea edx, InputStr2
		call writestring
		call readint
		
		sub ebx, eax
		mov eax, ebx

		lea edx, SeeSubtractionStr
		call writestring
		call dumpregs

	RET
	SUBTRACTION endp

	MULTIPLICATION proc
		
		lea edx, InputStr1		;First Input
		call writestring
		call readdec
		mov bl, al

		lea edx, InputStr2		;Second Input
		call writestring
		call readdec

		mul bl

		lea edx, SeeMultiplicationStr
		call writestring
		call dumpregs

	RET
	MULTIPLICATION endp

	DIVISION proc
		
		lea edx, InputStr1		;First Input
		call writestring
		call readdec
		mov bl, al

		lea edx, InputStr2		;Second Input
		call writestring
		call readdec

		movzx ecx, al	;Second value
		movzx eax, bl	;First value

		mov edx, 0
		div ecx

		mov ecx, edx
		lea edx, SeeDivisionStr
		call writestring

		mov edx, ecx
		call dumpregs

	RET
	DIVISION endp
	
	ARRAY proc
		
		lea edx, InputArrayStr
		call writestring

		mov ebx, 0
		.while ebx < 10
			call readdec
			Push eax

			inc ebx
		.endw

		mov ebx, 0	;For Counting
		mov esi, 0	;For E_Array
		mov edi, 0	;For O_Array
		mov ecx, 2	;Divisor

		.while ebx < 10
			Pop eax
			mov ebp, eax	;Saving it

			mov edx, 0
			div ecx

			.if edx == 0
				mov [E_Array + esi], ebp
				add esi, 4
			.else
				mov [O_Array + edi], ebp
				add edi, 4
			.endif

			inc ebx
		.endw

		lea edx, EvenArrayStr
		call writestring

		mov ebx, 0
		.while ebx < esi
			mov eax, [E_Array + ebx]
			call writedec
			mov eax, ' '
			call writechar

			add ebx, 4
		.endw

		call crlf
		lea edx, OddArrayStr
		call writestring

		mov ebx, 0
		.while ebx < edi
			mov eax, [O_Array + ebx]
			call writedec
			mov eax, ' '
			call writechar

			add ebx, 4
		.endw

		call crlf

	RET
	ARRAY endp

end