include irvine32.inc

.data
	sum dd ?

.code

tmain proc

	;100 + 5 + 10/2*10 - 40 + 2 - 50/5

	mov eax, 100
	add eax, 5
	sub eax, 40
	add eax, 2

	mov sum, eax			;save sum in variable

	mov eax, 10
	mov ebx, 2
	mov edx, 0
	div ebx

	mov ebx, 10

	mul ebx

	add sum, eax

	mov eax, 50
	mov ebx, 5
	mov edx, 0

	div ebx

	sub sum, eax

	mov eax, sum

	call writeint

tmain endp
exit

end