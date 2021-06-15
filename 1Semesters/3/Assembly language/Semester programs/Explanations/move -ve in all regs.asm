include irvine32.inc

.data

.code
main proc

	mov eax, -16
	mov ebx, -17
	mov ecx, -19
	mov edx, -25
	mov edi, -30
	mov ebp, -70
	mov esi, -1000

	call dumpregs
	
	;When we move a negative number in register it will pass through a special calculation because the register store Hexadecimal values and in Hexadacimal the nagitive numbers pass through special calculations
	;To calculate this calculation Manually we first ignore the negative sign and convert the number into Hexadacimal
	;Now we Subtract the most Right number from 16 and other numbers from 15
	;Now this is the converted Number

exit
main endp

end