include irvine32.inc

.data
	InputStr1 db "Enter first number  : ", 0
	InputStr3 db "Enter second number  : ", 0
	InputStr2 db "Enter third number  : ", 0

	SmallestNumStr db "Smallest number is  : ", 0

.code
	main proc
		;Print Smallest number in three
	
		lea edx, InputStr1		;First number Input
		call writestring
		call readdec
		mov ebx, eax

		lea edx, InputStr2		;Second number Input
		call writestring
		call readdec

		cmp eax, ebx
		JB AboveLabel
	
		mov ecx, ebx
		Jmp SkipLabel

		AboveLabel:
			mov ecx, eax

		SkipLabel:

		lea edx, InputStr3		;Third number Input
		call writestring
		call readdec

		cmp ecx, eax
		JB AboveLabel2

		Jmp SkipLabel2

		AboveLabel2:
			mov eax, ecx
	
		SkipLabel2:

		lea edx, SmallestNumStr
		call writestring
		call writedec

		call crlf

	exit
	main endp
end