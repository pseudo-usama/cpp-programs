include Irvine32.inc

.data
	max dd 10
	str1 db 10 dup(?)	;Declaring the String

.code
main Proc
	
	mov ecx, max		;This is necessery for input of string because the readstring Function will always input the char as no in (ecx-1)
	lea edx, str1		;Moving the Address of string

	call readstring

	call writestring

exit
main endP

end
