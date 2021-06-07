include irvine32.inc

.data
	var1 dd 8
	var2 dd 5
	var3 dd 4
	var4 dd 1

.code

qwmain proc

	mov eax, var1

	add eax, var2
	add eax, var3
	add eax, var4

	call dumpregs

qwmain endp
exit

end