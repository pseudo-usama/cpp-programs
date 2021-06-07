include Irvine32.inc

.data
	Array dd 10 dup(0)

	InputStr db "Enter numbers one by one", 0ah, 0
	OutputStr db "Array in Reverse Order is", 0ah, 0

.code
main Proc
	;Program to print Array data in reverse order

	lea edx, InputStr
	call writestring

	mov ebx, 0	;For Index

	Input:
		
		call readdec
		mov [Array + ebx], eax

		add ebx, 4	;Because 32 bits takes 4 bytes

	cmp ebx, 40
	JB Input

	lea edx, OutputStr
	call writestring

	mov ebx, 36		;For Index

	Output:
		
		mov eax, [Array + ebx]
		call writedec
		call crlf

		sub ebx, 4

	cmp ebx, 0
	JGE Output

exit
main endp

end
