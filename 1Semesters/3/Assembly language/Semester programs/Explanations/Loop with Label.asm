include irvine32.inc

.data
	str1 db "Usama", 0ah, 0

.code

main proc
	
	lea edx, str1

	mov ecx, 10

	;Here we put some number in ecx so that the loop will itrate ecx 's times	

	Again:
		call writestring

		call crlf
	loop Again			;After each iteration it will decrement ecx by one and the loop end when ecx becomes zero

	

	;For make enter after every itration there is two ways
	;First write 0ah after giving value to string at declaration
	;Second use method call crlf


main endp
exit

end