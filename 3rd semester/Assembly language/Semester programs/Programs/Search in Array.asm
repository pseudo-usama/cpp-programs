include Irvine32.inc

.data
	Array dd 10 dup(0)

	InputStr db "Enter numbers one by one", 0ah, 0
	InputNum db "Enter number to Search  : ", 0
	FoundStr db "Number found at index  : ", 0
	NotFoundStr db "Number not found", 0

.code
main Proc
	;Program to find an number in Array

	lea edx, InputStr
	call writestring

	mov ebx, 0	;For Index

	Input:		
		call readdec
		mov [Array + ebx], eax

		add ebx, 4
	cmp ebx, 40
	JL Input

	lea edx, InputNum
	call writestring
	call readdec

	mov ebx, 0	;For Index

	Calculations:
		
		cmp eax, [Array + ebx]
		JE Found

		add ebx, 4

	cmp ebx, 40
	JL Calculations

	lea edx, NotFoundStr
	call writestring

	Jmp GoEnd	;So that if no one match then it go to end

	Found:
		lea edx, FoundStr
		call writestring

		mov eax, ebx
		mov ebx, 4	;Because dd 32 bit variable which takes 4 bytes
		mov edx, 0
		div ebx
		call writedec	;This is the index

	GoEnd:

	call crlf

exit
main endp

end
