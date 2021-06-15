include irvine32.inc

.data
	FirstTerm dd ?
	SecondTerm dd ?

.code

jmain proc
	
	;3 + 5 + (3 + 5 - 5*2) - (8/2 - 2) + 10/5

	mov ebx, 3
	add ebx, 5
	
	mov eax, 10
	mov ecx, 5
	mov edx, 0

	div ecx

	add ebx, eax

	;Now Solving First Bracket
	mov FirstTerm, 3
	add FirstTerm, 5

	mov eax, 5
	mov ecx, 2

	mul ecx

	sub FirstTerm, eax

	add ebx, FirstTerm		;Addind First Bracket Answer into overall Equation

	;Now Solving Second Bracket
	mov SecondTerm, 2

	mov eax, 8
	mov ecx, 2
	mov edx, 0

	div ecx

	sub eax, SecondTerm

	sub ebx, SecondTerm		;Subtracting Second Bracket Answer from overall Equation

	mov eax, ebx

	call writeint

jmain endp
exit

end