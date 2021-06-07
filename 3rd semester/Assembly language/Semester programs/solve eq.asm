include irvine32.inc
.code
main proc

mov eax,10
mov ebx,2
mov edx,0
div ebx
mov ebx,10
mul ebx
mov esi,eax
mov eax,50
mov ebx,5
mov edx,0
div ebx
mov ebx,100
add ebx,5
add ebx,esi
sub ebx,40
add  ebx,2
sub ebx,eax
call dumpregs
main endp
exit
end