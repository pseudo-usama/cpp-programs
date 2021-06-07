;Input a string and Show it

.model small
.stack 100h
.data
        Str db 100 dup('$')

.code
main proc

        mov ax, @data
        mov ds, ax

        mov si, offset Str

        Again:
                mov ah, 1
                int 21h

                cmp al, 13
                je End

                mov [si], al
                inc si

                jmp Again

        End:
                mov dx, offset Str
                mov ah, 9
                int 21h

                mov ah, 4ch
                int 21h

main endp
end main
