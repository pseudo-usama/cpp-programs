include Irvine32.inc

.data
	var dd 5

.code
	main Proc
		;Built in Stack

		;We use Push keyword to insert an number into Stack
		;We use registers, variables and constants to Push

		mov eax, 2

		Push eax
		Push var
		Push 3

		;And to remove and getting the value from Stack we use Pop keyword

		Pop eax
		call writedec

		Pop eax
		call writedec

		Pop eax
		call writedec

	exit
	main endP

end
