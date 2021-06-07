include Irvine32.inc

.data
	
.code
main Proc
	;Increment and Decrement

	mov eax, 4
	call writedec
	call crlf

	inc eax				;This will increment the value by one
	call writedec
	call crlf

	dec eax				;This will decrement the value by one
	call writedec
	call crlf

exit
main endP

end
