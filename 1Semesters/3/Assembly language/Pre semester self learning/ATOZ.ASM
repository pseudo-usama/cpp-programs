;Print A to Z

.model small
.stack 100h
.data
.code

main proc

        mov cl, 26
        mov dl, 65

        L1:
                mov ah, 2
                int 21h

                inc dl
        loop L1

        mov ah, 4ch
        int 21h

main endp
end main
