include Irvine32.inc

.data
	Array dd 10 dup(0)

	InputStr db "Enter numbers one by one", 0ah, 0
	OutputStr db "Your inputed numbers are", 0ah, 0

.code
main Proc
	;Program to Explain use and syntex of an 32 bit Array
	
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

	mov ebx, 0	;For Index

	Output:
		mov eax, [Array + ebx]
		call writedec
		call crlf

		add ebx, 4

	cmp ebx, 40
	JB Output

exit
main endp

end
