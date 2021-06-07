include irvine32.inc

.data
	InputStr1 db "Enter first number  : ", 0
	InputStr3 db "Enter second number  : ", 0
	InputStr2 db "Enter third number  : ", 0

	GreaterNumStr db "Greatest number is  : ", 0

.code
	main proc
		;Print Largest number in three
	
		lea edx, InputStr1		;First number Input
		call writestring
		call readdec
		mov ebx, eax

		lea edx, InputStr2		;Second number Input
		call writestring
		call readdec

		cmp eax, ebx
		JA AboveLabel
	
		mov ecx, ebx
		Jmp SkipLabel

		AboveLabel:
			mov ecx, eax

		SkipLabel:

		lea edx, InputStr3		;Third number Input
		call writestring
		call readdec

		cmp ecx, eax
		JA AboveLabel2

		Jmp SkipLabel2

		AboveLabel2:
			mov eax, ecx
	
		SkipLabel2:

		lea edx, GreaterNumStr
		call writestring
		call writedec

		call crlf

	exit
	main endp
end