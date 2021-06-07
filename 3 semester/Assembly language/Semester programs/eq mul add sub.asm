include irvine32.inc

.data
	var1 dd -40
	var2 dd 30
	var3 dd 100
	var4 dd -2
	var5 dd 4
	var6 dd 2
	var7 dd -5

.code

main proc

	mov ebx, var1

	add ebx, var2
	add ebx, var3
	add ebx, var6
	add ebx, var7

	mov eax, var4

	mul var5

	add eax,ebx

	call dumpregs

main endp
exit

end