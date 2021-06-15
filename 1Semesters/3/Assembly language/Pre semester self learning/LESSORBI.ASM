;Find which number is greaten then other by input

.model medium
.stack 100h
.data
        Equal db 'The numbers are equal$'
        Smaller db 'First is Lesser then Second$'
        Greater db 'First is Greater then Second$'

.code

main proc
        mov ax, @data
        mov ds, ax

        mov ah, 1
        int 21h

        mov bl, al

        mov ah, 1
        int 21h

        mov cl, al

        mov dl, 13
        mov ah, 2
        int 21h

        mov dl, 10
        mov ah, 2
        int 21h

        cmp cl, bl
        je L1
        jl L2     
        jg L3

        L1:                             ;if equal
                lea dx, Equal
                mov ah, 9
                int 21h
        
                mov ah, 4ch
                int 21h

        L2:                             ;if smaller
                lea dx, Greater
                mov ah, 9
                int 21h
        
                mov ah, 4ch
                int 21h

        L3:                             ;if greater
                lea dx, Smaller
                mov ah, 9
                int 21h
        
                mov ah, 4ch
                int 21h

main endp
end main
