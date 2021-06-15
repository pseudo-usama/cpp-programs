include Irvine32.inc

.data
	first byte "enter first number  ", 0
	second byte "enter second  ", 0
	result1 byte "even numbers from  ", 0
	result2 byte "to ", 0
	result3 byte "are  : ", 0
	comma byte ", ", 0
	var dd ?
	var1 dd ?
	var2 dd ?

.code
tmain Proc

	lea edx, first
	call writestring
	call readdec
	mov var1, eax

	lea edx, second
	call writestring
	call readdec
	mov var2, eax
	
	mov eax, var1
	mov ebx, 2



	mov edx, 0
	div ebx
	mov eax, edx
	mov ebx, 2
	sub ebx, eax
	ADD var1, ebx

	mov eax, var2
	mov ebx, 2
	mov edx, 0
	div ebx
	mov eax, edx
	mov ebx, 2
	sub ebx, eax
	sub var2, ebx
	mov eax, var2
	sub eax, var1
	mov ecx, 2
	mov edx, 0
	div ecx
	mov var, eax


	lea edx, result1
	call writestring
	mov eax, var1
	call writedec

	lea edx, result2
	call writestring
	mov eax, var2
	call writedec

	lea edx, result3
	call writestring

	mov eax, var1
	;call writedec

	mov eax, var1
	lea edx, comma

	mov ecx, var
	add ecx, 1

	again:
		call writedec

		call writestring
		add eax, 2		
	loop again


exit
tmain endp

end
