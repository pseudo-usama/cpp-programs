; Subtraction with register addressing

.model tiny
.data
.code

main proc

mov cl, 4
mov dl, 7

sub dl, cl

add dl, 48

mov ah, 2
int 21h

mov ah, 4ch
int 21h

main endp
end main
