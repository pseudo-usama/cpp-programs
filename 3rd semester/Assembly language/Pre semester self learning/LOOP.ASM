;print 0 tp 9 using loop

.model small
.stack 100h
.data
.code

main proc
        mov cl, 10
        mov dl, 48

        L1:
                mov ah, 2
                int 21h

                inc dl
        loop L1

        mov ah, 4ch
        int 21h
main endp
end main
