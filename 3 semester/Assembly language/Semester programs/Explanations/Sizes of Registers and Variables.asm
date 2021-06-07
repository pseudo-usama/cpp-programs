include Irvine32.inc

.data
	a db 8		; 8 bits
	b db 3		; 8 bits
	

.code
main Proc
	;Sizes of register and variables

	;  |  Size   |  Variables  |              Registers              |
	;  | 8  bits |   db, byte  |                 al                  |
	;  | 16 bits |  word ,  dw |           ax, bx, cx, dx            |
	;  | 32 bits |  dword , dd |  eax, ebx, ecx, edx, edi, ebp, esi  |
	;  | 64 bits |  qword , dq |                                     |

	;We move data in register and variables according to their size
	;We cannot move 16 bits in 8 bits and 8 bits in 32 bits
	;But there is an method to move Lower size data into Hiegher size Memory
	
	;First Mrthod
	mov eax, 0	;First we remove all the Garbage value in register
	mov al, a	;Then we move 8 bit data into its lower part

	call writedec
	call crlf

	;And the second method is very easy and simple
	movzx eax, b	;It will move b into rigister and automatically set remaining bits to zero
					;Here one thing is important that the destination should be register it could not an variable

	call writedec
	call crlf

exit
main endp

end
