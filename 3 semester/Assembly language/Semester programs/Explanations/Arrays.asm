include Irvine32.inc

.data
	ArrayDeplicate db 5 dup(4)			;This array has size 5 and all elements initialized with 4
	ArrayEmpty db 5 dup(?)				;This array has size 5 and all elements are not initialized
	ArrayDifferent db 5, 4, 1, 3, 7		;This array has size 5 and all elements are initialized with different values

	InputStr db "Enter numbers one by one  : ", 0
	OutputStr db "Your inputed numbers are  : ", 0

.code
main Proc
	;Declaration, Initiazation, printing and inputing of Arrays

	;First we input the Array

	lea edx, InputStr
	call writestring
	
	mov ecx, 5	;For loop
	mov ebx, 0	;For Array Indexing

	LabelInput:
		
		call readdec
		mov [ArrayEmpty + ebx], al

		inc ebx

	loop LabelInput


	;Now we print the inputed Array
		
	lea edx, OutputStr
	call writestring

	mov ecx, 5	;For loop
	mov ebx, 0	;For Array Indexing

	LabelOutput:
		movzx eax, [ArrayEmpty + ebx]
		call writedec
		call crlf

		inc ebx
	loop LabelOutput

exit
main endp

end
