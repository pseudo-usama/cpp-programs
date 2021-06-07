;Addtion of two numbers with user input

.model
.data
.code

main proc

mov ah, 1
int 21h

mov dl, al

mov ah, 1
int 21h

mov cl, al

add dl, cl
sub dl, 48

mov ah, 2
int 21h

mov ah, 4ch
int 21h

main endp
end main
