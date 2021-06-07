include Irvine32.inc

.data
	Array dd 10 dup(0)

	InputStr db "Enter numbers one by one", 0ah, 0
	OutputStr db "Even Number you enter are", 0ah, 0

.code
main Proc
	;Print Even numbers which user enter
	
	lea edx, InputStr
	call writestring
		
	mov ebx, 0	;For Array Indexing
		
	Input:
		call readdec
		mov [Array + ebx], eax

		add ebx, 4

	cmp ebx, 40
	JB Input	

	;Now we print the inputed Array
		
	lea edx, OutputStr
	call writestring

	mov ebx, 0

	Output:
		mov eax, [Array + ebx]

		mov ebp, 2
		mov edx, 0
		div ebp

		cmp edx, 0
		JNE Skip

		mov eax, [Array + ebx]
		call writedec
		call crlf

		Skip:

		add ebx, 4

	cmp ebx, 40
	JB Output

exit
main endp

end
