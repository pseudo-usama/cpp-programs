include irvine32.inc

.data
	
.code
main proc
	;Unsigned Conditional Jumps

	;There are two types of Jumps Conditional and Unconditional

	;Conditioal Jumps are further divided into two types

	;One is for Signed values(both +ve and -ve)
	;Seond is for UnSigned values(only +ve)

	;Unsigned Conditional Jumps are

		;JE	 / JZ      Jump Equal           /  Jump Zero
		;JNE / JNZ     Jump not Equal       /  Jump not Zero
		;JA  / JNBE    Jump Above           /  Jump not Below and Equal
		;JAE / JNB     Jump Above or Equal  /  Jump not Below
		;JB  / JNAE    Jump Below           /  Jump not Above and Equal
		;JBE / JNA     Jump Below or Equal  /  Jump not Above

	;To use these conditions we use Compare keyword
	;Example
		; cmp eax, ebx
		;These two operans could be registers, variables or numbers		

	;For more Details visit
	;https://www.tutorialspoint.com/assembly_programming/assembly_conditions.htm

exit
main endp

end