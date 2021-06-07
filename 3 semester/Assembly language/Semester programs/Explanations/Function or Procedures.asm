include Irvine32.inc

.data

.code
	main Proc
		;Functions or Procedure Syntex

		;We can declare an function where ever we want (means main sa pahla ya baad ma b)
		;Agara ham function main k baad declare karain tu calling koi ma koi error ni fu ga
		;There are no Parameters in Function

		call myProcedure

	exit
	main endP

	myProcedure Proc
		
		mov eax, 0

		Again:

			.if eax < 11
				call writedec
				call crlf
				inc eax

				Jmp Again
			.endif

	myProcedure endP

end