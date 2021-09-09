include Irvine32.inc

.data
	Array dd 100, 12, 45, 21, 45, 89, 90, 0, 10, 56

	AscendingStr db "Array in Ascending Order is  : ", 0
	DescendingStr db "Array in Descending Order is  : ", 0
	InputStr db "Enter a Number to Search  : ", 0
	FoundStr db "Number found at index  : ", 0
	NotFoundStr db "Number not found", 0

	
.code
	main Proc
		;Arrange array in Aascending Order
		;Arrange array in Descending Order
		;Search user input in Array

		;Rearranging Array in Ascending Order

		mov eax, 0	;For Outer Loop

		OuterLabel:
		
			mov ebx, 0	;For Inner Loop
		
			InnerLabel:
			
				mov ecx, [Array + ebx]

				cmp ecx, [Array + ebx + 4]
				JBE Skip

				mov edx, [Array + ebx + 4]	;Swaping values
				mov [Array + ebx], edx
				mov [Array + ebx + 4], ecx

				Skip:

				add ebx, 4

			cmp ebx, 36
			JB InnerLabel

			add eax, 4

		cmp eax, 40
		JB OuterLabel

		;Now we Print the Array

		mov ebx, 0	;For Indexing

		OutputAscendingLabel:
		
			mov eax, [Array + ebx]
			call writedec
			mov eax, 32	;Space
			call writechar

			add ebx, 4

		cmp ebx, 40
		JB OutputAscendingLabel

		call crlf

		;Now we Rearrange the Array in Descending Order

		mov eax, 0	;For Outer Loop

		OuterReverseLabel:
		
			mov ebx, 0	;For Inner Loop
		
			InnerReverseLabel:
			
				mov ecx, [Array + ebx]

				cmp ecx, [Array + ebx + 4]
				JAE Skip2

				mov edx, [Array + ebx + 4]	;Swaping values
				mov [Array + ebx], edx
				mov [Array + ebx + 4], ecx

				Skip2:

				add ebx, 4

			cmp ebx, 36
			JB InnerReverseLabel

			add eax, 4

		cmp eax, 40
		JB OuterReverseLabel

		;Now we Print the Array

		mov ebx, 0	;For Indexing

		OutputDescendingLabel:
		
			mov eax, [Array + ebx]
			call writedec
			mov eax, 32	;Space
			call writechar

			add ebx, 4

		cmp ebx, 40
		JB OutputDescendingLabel

		call crlf

		;Now we Input a Number from user and Search it in Array
		lea edx, Inputstr
		call writestring
		call readdec

		mov ebx, 0

		SearchLabel:
		
			cmp eax, [Array + ebx]
			JE FoundLabel

			add ebx, 4

		cmp ebx, 40
		JB SearchLabel

		lea edx, NotFoundStr
		call writestring
		Jmp Skip3

		FoundLabel:
			lea edx, FoundStr
			call writestring

			mov edx, 0
			mov eax, ebx
			mov ecx, 4	;As dd type takes 4 Bytes
			div ecx
		
			call writedec
	
		Skip3:

		call crlf

	exit
	main endP

end
