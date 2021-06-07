include irvine32.inc
.data
	String_REBELS_Group	 BYTE	"					*REBELS GROUPS*"			,0ah,0ah
	String_002			 BYTE	"				17114119-002	->	Haider Ali"		,0ah
	String_029			 BYTE	"				17114119-029	->	Haris Naveed"	,0ah
	String_030			 BYTE	"				17114119-030	->	Gulfam Sidhu"	,0ah
	String_043			 BYTE	"				17114119-043	->	Nabeel "		,0ah
	String_057			 BYTE	"				17114119-057	->	Almas Butt"		,0ah,0ah,0ah,0

	String_Addition			BYTE	"Press 2 for ADDITION operations between registers."			,0ah
	String_Subtraction		BYTE	"Press 3 for SUBTRACTION operations between registers."			,0ah
	String_Multiplication	BYTE	"Press 4 for MULTIPLICATION operations between registers."		,0ah
	String_Division			BYTE	"Press 5 for DIVISION operations between registers."			,0ah
	String_Loop_Stack_Array BYTE	"Press 6 for operations related to LOOP, ARRAY and STACK"		,0ah
	String_Exit				BYTE	"Press 0 for EXIT program execution"							,0ah,0ah,0ah,0

	String_No1	BYTE	"Enter First No = "	,0
	String_No2	BYTE	"Enter Second No = ",0
	String_NO	BYTE	"Enter A NUMBER = "	,0

	String_Choose	BYTE	"Enter Your Choice = ",0

	String_Invalid	BYTE	"Worning, INVALID NUMBER PLEASE TRY AGAIN....",0ah,0

	TAB_KEY BYTE	"	",0

	STRING_EVEN	BYTE	"EVEN NUMBER = ",0
	STRING_ODD	BYTE	"ODD NUMBER = "	,0
	EVEN_ARRAY	dd	10 DUP(0)
	ODD_ARRAY	dd	10 DUP(0)

	EVEN_SIZE	dd 0
	ODD_SIZE	dd 0
	VAR_POP		dd 0
.code
	main proc

		Lea edx,String_REBELS_Group
		Call WriteString

		Lea edx,String_Addition
		Call WriteString
	
		Lea edx,String_Choose
		Call WriteString
		Call ReadDec
			.if		eax == 0
				Call EXIT_MAIN
			.elseif eax == 2
				Call ADDITION
			.elseif eax == 3
				Call SUBTRACTION
			.elseif eax == 4
				Call MULTIPLICATION
			.elseif eax == 5
				Call DIVISION
			.elseif eax == 6
				Call STACK_ARRAY
			.else
				Lea edx , String_Invalid
				Call WriteString

				Call Main
			.endif
	main endp

	;ADDITION FUNCTION

	ADDITION proc

		Lea edx,String_No1
		Call WriteString

		Call ReadInt
		MOV bl,al
	
		Lea edx,String_No2
		Call WriteString

		Call ReadInt
	
		ADD al,bl

		Call DumpRegs

		Call Main

	ADDITION endp

	;SUBTRACTION FUNCTION

	SUBTRACTION proc

		Lea edx,String_No1
		Call WriteString

		Call ReadInt
		MOV bl,al
	
		Lea edx,String_No2
		Call WriteString

		Call ReadInt
	
		SUB al,bl

		Call DumpRegs

		Call Main

	SUBTRACTION endp

			
			;MULTIPLICATION FUNCTION

	MULTIPLICATION proc

		Lea edx,String_No1
		Call WriteString

		Call ReadInt
		MOV bl,al
	
		Lea edx,String_No2
		Call WriteString

		Call ReadInt
	
		MUL bl

		Call DumpRegs

		Call Main

	MULTIPLICATION endp
	
			;DIVISION FUNCTION

	DIVISION proc

		Lea edx,String_No1
		Call WriteString

		Call ReadInt
		MOV bl,al
	
		Lea edx,String_No2
		Call WriteString
		MOV edx,0
		Call ReadInt
	
		DIV bl

		Call DumpRegs

		Call Main

	DIVISION endp

	
				;STACK_ARRAY_LOOP FUNCTION
	
	STACK_ARRAY proc

		MOV ecx,0

		.while ecx < 10
			Lea edx, String_NO
			Call WriteString
			
			call ReadINT	
			PUSH eax
			inc ecx
		.endw
		mov ecx,0
		.while ecx < 10
			POP VAR_POP
			
			MOV eax,VAR_POP
			MOV edx,0
			MOV esi,2
			div	esi

			.if edx == 0
				Mov	ebx,EVEN_SIZE
				Mov eax,VAR_POP
				Mov [EVEN_ARRAY+ebx],eax
				Add ebx,4
				Mov EVEN_SIZE,ebx
			.else
				Mov	ebx,ODD_SIZE
				Mov eax,VAR_POP
				Mov [ODD_ARRAY+ebx],eax
				Add ebx,4
				Mov ODD_SIZE,ebx
			.endif
			inc ecx
		.endw
		
		Lea edx, STRING_EVEN
		Call WriteString
		mov ebx,0
		CALL TAB_FUN
		.while ebx<EVEN_SIZE
			Mov eax,[EVEN_ARRAY+ebx]
			Call WriteINT
			ADD ebx,4
			CALL TAB_FUN
		.endw
		
		CALL CRLF

		Lea edx, STRING_ODD
		Call WriteString
		mov ebx,0
		CAll TAB_FUN
		.while ebx<ODD_SIZE
			Mov eax,[ODD_ARRAY+ebx]
			Call WriteINT
			ADD ebx,4
			Call TAB_FUN
		.endw

		Call Main
	STACK_ARRAY endp

	TAB_FUN proc
		Lea edx,TAB_KEY
		Call WriteString
		RET
	TAB_FUN endp

				;EXIT_MAIN FUNCTION

	EXIT_MAIN proc
		Lea edx,String_REBELS_Group
		Call WriteString
	exit
	EXIT_MAIN endp
end