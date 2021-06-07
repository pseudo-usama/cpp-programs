;Print a Box of * using jump

.model small
.stack 100h
.data

.code
main proc

        mov cl, 0
        mov ch, 5
                
        mov bh, 5

        Loop1:

        mov cl, 0
                Loop2:

                        mov dl, '*'
                        mov ah, 2
                        int 21h

                        inc cl

                cmp cl, ch
                jl Loop2

                mov dl, 10
                mov ah, 2
                int 21h
                mov dl, 13
                mov ah, 2
                int 21h

                inc bl

        cmp bl, bh
        jl Loop1

        mov ah, 4ch
        int 21h
        
main endp
end main

