include Irvine32.inc

.data
	
.code
	main Proc
		;if else Statement

		mov eax, 66
		
		.if eax == 65
			call writedec
		.else
			call writechar
		.endif

	exit
	main endP

end
