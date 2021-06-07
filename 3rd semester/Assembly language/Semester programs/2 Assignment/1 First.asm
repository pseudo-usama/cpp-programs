include irvine32.inc

.data
	str1 db "Sum is  : ", 0
.code
xmain proc
	;Printing first five numbers and their sum

	mov eax, 1	;For showing numbers 1 to 5
	mov ecx, 5	;For loop
	mov edx, 0	;For Sum

	Again:
		call writedec	;print the numbers from 1 to 5

		add edx, ecx	;Sum numbers
		add eax, 1		;Set next number

		call crlf
	loop Again

	mov eax, edx		;Move sum to eax

	lea edx, str1
	call writestring
	
	call writedec		;showing Sum

	call crlf

xmain endp
exit

end