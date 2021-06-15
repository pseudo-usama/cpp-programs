include Irvine32.inc

.data
	InputStr1 db "Enter first number  : ", 0
	InputStr2 db "Enter second number  : ", 0
	InputStr3 db "Enter third number  : ", 0
	InputStr4 db "Enter forth number  : ", 0
	OutputStr db "The comparasion between the numbers is", 0ah, 0

	Array dd 4 dup(?)

.code
	main Proc
		;Print the comparasion between four Numbers

		lea edx, InputStr1	;First Input
		call writestring
		call readdec
		mov Array, eax

		lea edx, InputStr2	;Second Input
		call writestring
		call readdec
		mov Array + 4, eax

		lea edx, InputStr3	;Third Input
		call writestring
		call readdec
		mov Array + 8, eax

		lea edx, InputStr4	;Forth Input
		call writestring
		call readdec
		mov Array + 12, eax

		;Now we Sort the Array in accending Order to make the comparasion

		mov eax, 0	;For Outer Loop	

		OuterLabel:
			mov ebx, 0	;For Inner Loop

			InnerLabel:
			
				mov ecx, [Array + ebx]
				cmp ecx, [Array + ebx + 4]
				JBE Skip

				mov ecx, [Array + ebx]
				mov edx, [Array + ebx + 4]
				mov [Array + ebx], edx
				mov [Array + ebx + 4], ecx

				Skip:

				add ebx, 4

			cmp ebx, 9
			JB InnerLabel

			add eax, 4

		cmp eax, 13
		JB OuterLabel

		;Now we have sorted the Array in accending
		;Now we print the comparasion

		mov ecx, 0
	
		OutputLabel:
			mov eax, [Array + ecx]
			call writedec

			cmp eax, [Array + ecx + 4]
			JE EqualLabel

			mov eax, '<'
			Jmp Skip2

			EqualLabel:
				mov eax, '='

			Skip2:

			call writechar

			add ecx, 4

		cmp ecx, 9
		JB OutputLabel

		mov eax, Array + 12
		call writedec

		call crlf

	exit
	main endP

end
