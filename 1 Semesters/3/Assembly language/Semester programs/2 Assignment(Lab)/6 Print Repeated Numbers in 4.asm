include irvine32.inc
.data
	InputStr1 db "Enter First Number  : ", 0
	InputStr2 db "Enter Second Number  : ", 0
	InputStr3 db "Enter Third Number  : ", 0
	InputStr4 db "Enter Fourth Number  : ", 0

	RepeatedStr db " repeated ", 0
	TimesStr db " times", 0ah, 0
	NotFoundStr db "There is no repeated number", 0ah, 0

	Array dd 4 dup(?)
	temp dd ?

.code
	main proc
		;Print the Repeated Numbers in Four Numbers

		lea edx, InputStr1		;First Input
		call writestring
		call readdec
		mov Array, eax

		lea edx, InputStr2		;Second Input
		call writestring
		call readdec
		mov Array + 4, eax

		lea edx, InputStr3		;Third Input
		call writestring
		call readdec
		mov Array + 8, eax

		lea edx, InputStr4		;Forth Input
		call writestring
		call readdec
		mov Array + 12, eax

		;Now we Rearrange the data in Ascending Order in Array

		mov eax, 0	;For outer Loop

		OuterLabel:
		
			mov ebx, 0	;For Inner Loop
		
			InnerLabel:
			
				mov ecx, [Array + ebx]

				cmp ecx, [Array + ebx + 4]
				JA SwapLabel

				Jmp Skip

				SwapLabel:
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

		;Now we check for repeated Nembers
		mov ebx, 0	;For Index
		mov ecx, 1	;For Counting

		.while ebx < 9
			mov eax, [Array + ebx]
			.if eax == [Array + ebx + 4]
				inc ecx
				mov edx, [Array + ebx]
			.else
				.if ecx > 1
					mov ebx, 9	;Breaking the Loop
				.endif
			.endif

			add ebx, 4
		.endw

		.if ecx == 1
			lea edx, NotFoundStr
			call writestring
			Jmp GoEnd
		.endif

		mov temp, edx	;It will use in coming loop So that we check weather the repeated number is not the prev number

		mov eax, edx
		call writedec
		lea edx, RepeatedStr
		call writestring
		mov eax, ecx
		call writedec
		lea edx, TimesStr
		call writestring
		
		.if ecx == 2	;if ecx is 2 then this means that may be there is another pair of numbers so we check it here
			mov ebx, 0		;For Indexing
			mov ecx, 1		;For counting			
			.while ebx < 9
				mov eax, [Array + ebx]
				.if eax == [Array + ebx + 4]
					.if eax != temp
						mov edx, [Array + ebx]
						inc ecx
					.endif
				.endif
				add ebx, 4
			.endw
		.else
			Jmp GoEnd
		.endif

		.if ecx > 1
			mov eax, edx
			call writedec
			lea edx, RepeatedStr
			call writestring
			mov eax, ecx
			call writedec
			lea edx, TimesStr
			call writestring
		.endif

		GoEnd:

	exit
	main endp

end