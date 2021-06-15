;addition by instant addressing

.model tiny
.data
.code

main proc

mov dl, 3
add dl, 1

add dl, 48

mov ah, 2
int 21h

mov ah, 4ch
int 21h

main endp
end main
