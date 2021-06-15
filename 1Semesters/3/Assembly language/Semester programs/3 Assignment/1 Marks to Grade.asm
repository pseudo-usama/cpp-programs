include irvine32.inc
.data
	InputStr db "Enter your Marks  : ", 0

	ExcellentStr db "Excellent", 0ah, 0
	VeryGoodStr db "Very Good", 0ah, 0
	GoodStr db "Good", 0ah, 0
	FailStr db "Fail", 0ah, 0
	IncorrectStr db "You enter incorrect numbers", 0ah, 0

.code
main proc
	;Program to print the Grade when user enter its percentage
	;  >85                    Excellent
	;  75 <= marks => 85      Very Good
	;  50 <= marks => 74      Good
	;  <50                    Fail
	;  <0 or >100             Incorrect

	lea edx, InputStr
	call writestring
	call readint

	.if eax > 100
		lea edx, IncorrectStr
		Jmp GoEnd
	.else
		.if eax < 0
			lea edx, IncorrectStr
			Jmp GoEnd
		.endif
	.endif

	.if eax > 85
		lea edx, ExcellentStr
	.else
		.if eax >= 75
			lea edx, VeryGoodStr
		.else
			.if eax >= 50
				lea edx, GoodStr
			.else
				.if eax >= 0
					lea edx, FailStr
				.endif
			.endif
		.endif
	.endif	

	GoEnd:

	call writestring

exit
main endp
end