include irvine32.inc

.data

.code
main proc

	mov eax, 7
	mov ebx, 2
	mov edx, 0

	div ebx
	
	;For division atleast two register is used which are eax and edx And the third one should be variable or register
	;It is compulsory to mov Numinator in eax and denomenator in register/variable
	;It is necessory to mov 0 in edx
	;And when we use div then it will divide eax with second number and store the result in eax
	;And then it will store the reminder in edx
	
	call writedec

	call crlf			;Ending line

	mov eax, edx		;For printing edx value(Reminder)
	call writedec

	

exit
main endp

end