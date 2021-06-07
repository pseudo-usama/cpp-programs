include Irvine32.inc

.data
	
.code
	main Proc
		;While Loop Syntex

		mov eax, 0

		.while eax < 11
			call writedec
			call crlf

			inc eax
		.endw

	exit
	main endP

end
