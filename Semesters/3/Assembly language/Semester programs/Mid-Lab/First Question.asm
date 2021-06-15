include Irvine32.inc

.data
 	first db "enter first number ", 0
	second byte "enter second number ", 0
	third byte "Enter third number ", 0
	forth byte "enter fourth number ", 0
	result byte "the result is ", 0
	var1 dd ?
	var2 dd ?
	var3 dd ?
	var4 dd ?

.code
main Proc

	lea edx, first
	call writestring
	call readdec
	mov var1, eax

	lea edx, second
	call writestring
	call readdec
	mov var2, eax

	lea edx, third
	call writestring
	call readdec
	mov var3, eax

	lea edx, forth
	call writestring
	call readdec
	mov var4, eax

	mov eax, var1
	mov ebx, var2
	mov edx, 0
	div ebx

	mov ecx, var3
	sub ecx, var4
	mul ecx

	lea edx, result
	call writestring
	call writedec


exit
main endP

end
