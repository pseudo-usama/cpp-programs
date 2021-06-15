include Irvine32.inc

.data
 
	first byte "enter first char ", 0
	second byte "enter second char ", 0
	third byte "enter third char ", 0
	forth byte "enter forth char ", 0
	result byte "second char is :", 0

.code
kmain Proc

	lea edx, first
	call writestring
	call readchar
	call writechar
	call crlf

	lea edx, second
	call writestring
	call readchar
	call writechar
	mov ebx, eax
	call crlf

	lea edx, third
	call writestring
	call readchar
	call writechar
	call crlf

	lea edx, forth
	call writestring
	call readchar
	call writechar
	call crlf

	lea edx, result
	call writestring
	mov eax, ebx
	call writechar


exit

kmain endP

end
