include Irvine32.inc

.data
	Array dd 10 dup(?)
	
	Inputstr db "Enter your Password(Max characters:10)  : ", 0
	OutputStr db "Your Password is  : ", 0

.code
main Proc
	;Input Password
	
	lea edx, InputStr	;Printing Input String
	call writestring

	mov ebx, 0			;For Loop

	.while ebx < 37
		call readchar
		mov [Array + ebx], eax

		.if eax == 7181	;if Enter Presses then break
			Jmp BreakLoop
		.else
			mov eax, '*'
			call writechar			
		.endif

		add ebx, 4
	.endw

	BreakLoop:

	call crlf

	mov ecx, ebx		;For the Length of Password
	mov ebx, 0

	.while ebx < ecx
		mov eax, [Array + ebx]
		call writechar

		add ebx, 4
	.endw

exit
main endP

end
