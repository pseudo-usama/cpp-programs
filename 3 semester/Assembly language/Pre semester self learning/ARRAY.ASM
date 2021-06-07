;print Array

.model small
.stack 100h
.data
        Arr db '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'

.code

main proc

        mov ax, @data
        mov ds, ax

        mov cl, 10
        mov si, offset Arr
        mov dl, [si]

        L1:

                mov ah, 2
                int 21h

                inc dl
                
        loop L1

        mov ah, 4ch
        int 21h

main endp
end main
