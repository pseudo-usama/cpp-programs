;compare the user input with a fix number and print equal or not

.model small
.stack 100h
.data
        equal db 'The numbers are equal$'
        notEqual db 'The numbers are not equals$'

.code

main proc
        mov ax, @data
        mov ds, ax

        mov dl, '5'

        mov ah, 1
        int 21h

        cmp dl, al
        je L1
                mov dx, offset notEqual
                mov ah, 9
                int 21h

                mov ah, 4ch
                int 21h

        L1:
        mov dx, offset equal
        mov ah, 9
        int 21h

        mov ah, 4ch
        int 21h

main endp
end main
