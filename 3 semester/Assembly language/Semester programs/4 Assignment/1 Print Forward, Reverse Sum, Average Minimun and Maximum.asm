include Irvine32.inc

.data
	InputStr db "Enter 10 numbers", 0ah, 0
	ForwardOrderStr db "Input array is  : ", 0
	ReverseStr db "Input array in Reverse Order is  : ", 0
	SumStr db "Sum of all numbers is  : ", 0
	AverageStr db "Average of all numbers is  : ", 0
	MiniStr db "Minimum Number is  : ", 0
	MaxiStr db "Maximum Number is  : ", 0

	Array dd 10 dup(?)
	min dd ?
	max dd ?
	sum dd 0

.code
	main Proc
		;Print the elements of Array in Forward Order
		;Print the elements of Array in Reverse Order
		;Print Sum and Average
		;Print Minimum
		;Print Maximum

		lea edx, InputStr
		call writestring

		mov ebx, 0

		InputLabel:
		
			call readdec
			mov [Array + ebx], eax

			add ebx, 4

		cmp ebx, 40
		JB InputLabel

		lea edx, ForwardOrderStr
		call writestring

		mov ebx, 0		;For Indexing
		mov eax, Array
		mov min, eax	;First element
		mov max, eax	;First element

		;During printing Array we also calculate sum, min and max
		ForwardOrderLabel:
		
			mov eax, [Array + ebx]
			call writedec
			mov eax, 32	;Space
			call writechar

			mov eax, [Array + ebx]
			.if eax < min
				mov min, eax
			.else
				.if eax > max
					mov max, eax
				.endif
			.endif
			
			Skip:

			add sum, eax

			add ebx, 4

		cmp ebx, 40
		JB ForwardOrderLabel

		call crlf

		;Now we print in reverse order
		lea edx, ReverseStr
		call writestring

		mov ebx, 36		;For Indexing
	
		ReverseLabel:
		
			mov eax, [Array + ebx]
			call writedec
			mov eax, 32	;Space
			call writechar

			sub ebx, 4

		cmp ebx, 0
		JGE ReverseLabel

		call crlf

		;Now we print Sum and Average
		lea edx, SumStr
		call writestring

		mov eax, sum
		call writedec	;Sum
		call crlf

		lea edx, AverageStr
		call writestring

		mov ebx, 10
		mov edx, 0
		div ebx
		call writedec	;Average
		call crlf

		;Now print Minimum Number
		lea edx, MiniStr
		call writestring

		mov eax, min
		call writedec	;Mini
		call crlf

		;Now print Maximum Number
		lea edx, MaxiStr
		call writestring

		mov eax, max
		call writedec	;Max
		call crlf

	exit
	main endP

end
