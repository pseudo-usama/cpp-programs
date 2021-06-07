include irvine32.inc
.data
	InputStr1 db "Enter first number  : ", 0
	InputStr2 db "Enter second number  : ", 0
	Greater db " is Greater then ", 0
	Equal db "Both the numbers are Equal", 0

.code
main proc
	;Program to Print Greater number in two

	lea edx, InputStr1		;Printing first inputing String
	call writestring

	call readdec			;First Input
	mov ebx, eax

	lea edx, InputStr2		;Printing second inputing String
	call writestring

	call readdec			;Second Input
	mov ecx, eax

	cmp ebx, ecx
	ja FirstIsGreater
	je BothEqual

	mov eax, ecx			;These Statements run only when First number is Small
	call writedec

	lea edx, Greater
	call writestring

	mov eax, ebx
	call writedec

	jmp GoEnd					;Jump for avoiding the Below Statements to be run

	FirstIsGreater:
		mov eax, ebx
		call writedec

		lea edx, Greater
		call writestring

		mov eax, ecx
		call writedec

		jmp GoEnd				;Jump for avoiding the Below Statements to be run

	BothEqual:
		lea edx, Equal
		call writestring

	GoEnd:

	call crlf

exit
main endp
end