include irvine32.inc

.data
	FirstTerm dd ?
	SecondTerm dd ?

.code

umain proc
	;100 - 5 + 2 + (4/2 - 3 + 5 - 5*2) - (8/2 - 2*4) + 10/5

	mov ebx, 100
	sub ebx, 5
	add ebx, 2

	mov eax, 10
	mov ecx, 5
	mov edx, 0

	div ecx

	add ebx, eax

	;Now Solving First Bracket
	mov FirstTerm, 5
	sub FirstTerm, 3

	mov eax, 4
	mov ecx, 2
	mov edx, 0

	div ecx

	add FirstTerm, eax

	mov eax, 5
	mov ecx, 2

	mul ecx

	sub FirstTerm, eax

	add ebx, FirstTerm			;Adding First Bracket Answer to overall Equation
	
	;Now Solving Second Bracket
	mov eax, 8
	mov ecx, 2
	mov edx, 0

	div ecx

	mov SecondTerm, eax

	mov eax, 2
	mov ecx, 4

	mul ecx

	sub SecondTerm, eax

	sub ebx, SecondTerm			;Substracting Second Bracket Answer to overall Equaation

	mov eax, ebx

	call writeint

umain endp
exit

end