include irvine32.inc

.data

.code

main proc
	
	call readchar	;this will read one character and save in RAM and save its address in al

	call writechar
	
main endp
exit

end