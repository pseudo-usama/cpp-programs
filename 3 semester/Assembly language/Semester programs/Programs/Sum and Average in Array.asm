include Irvine32.inc

.data
	Array dd 10 dup(0)

	InputStr db "Enter numbers one by one", 0ah, 0
	AverageStr db "Average of Numbers are  : ", 0
	SumStr db "Sum of all Numbers are  : ", 0

.code
main Proc
	;Print Average and Sum of Numbers in Array
	
	lea edx, InputStr
	call writestring
		
	mov ebx, 0	;For Array Indexing
		
	Input:
		call readdec
		mov [Array + ebx], eax

		add ebx, 4
	cmp ebx, 40
	JB Input

	mov ecx, 10	;For Loop
	mov eax, 0	;For Sum
	mov ebx, 0	;For Index

	Calculations:			
		add eax, [Array + ebx]
		add ebx, 4
	loop Calculations

	lea edx, SumStr
	call writestring

	call writedec

	mov edx, 0
	mov ebx, 10
	div ebx

	call crlf
	lea edx, AverageStr
	call writestring

	call writedec
	call crlf

exit
main endp

end
