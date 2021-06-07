include Irvine32.inc

.data
	
.code
	main Proc
		;Do While Loop Syntex

		mov eax, 0
		
		.repeat
			call writedec
			call crlf

			inc eax
		.until eax == 11

	exit
	main endP

end
