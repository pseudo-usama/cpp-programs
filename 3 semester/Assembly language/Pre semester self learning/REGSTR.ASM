;Try to Print a String without using a Variable

.model small
.stack 100h
.data

.code
main proc

        mov dx, '89$'

        mov ah, 2
        int 21h

        mov ah, 4ch
        int 21h

main endp
end main
