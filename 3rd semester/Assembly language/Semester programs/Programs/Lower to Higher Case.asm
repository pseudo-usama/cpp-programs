include Irvine32.inc

.data
	Input db "Enter an small chacter  : ", 0
	OutPut db " in capital is ", 0

.code
main Proc
	;Program to Print Heigher Case Letter when user enter Lower Case Latter
	
	lea edx, Input
	call writestring	;Printing String

	call readchar		;Input
	call writechar		;Printing the inputed char as input
	call crlf			;End line

	call writechar		;Output the inputed char for output string

	sub al, 32			;Calculating the Upper case inputed char

	lea edx, OutPut
	call writestring	;Output String

	call writechar		;This is Converted char

	call crlf			;Ending line

exit
main endP

end
