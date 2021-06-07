
_display:
;dc.c,31 :: 		void display(unsigned char send_data)
;dc.c,33 :: 		if (i==0)
	MOVF       _i+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_display0
;dc.c,34 :: 		{latch =0;
	BCF        PORTB+0, 1
;dc.c,35 :: 		clock =0;
	BCF        PORTB+0, 0
;dc.c,36 :: 		}
L_display0:
;dc.c,38 :: 		for (bit_mask = 1; bit_mask; bit_mask <<= 1)
	MOVLW      1
	MOVWF      R1+0
L_display1:
	MOVF       R1+0, 0
	BTFSC      STATUS+0, 2
	GOTO       L_display2
;dc.c,40 :: 		if((send_data & bit_mask))
	MOVF       R1+0, 0
	ANDWF      FARG_display_send_data+0, 0
	MOVWF      R0+0
	BTFSC      STATUS+0, 2
	GOTO       L_display4
;dc.c,41 :: 		data = 0;
	BCF        PORTB+0, 2
	GOTO       L_display5
L_display4:
;dc.c,44 :: 		{  data = 1;               //bit0 transfer to shift register
	BSF        PORTB+0, 2
;dc.c,45 :: 		}
L_display5:
;dc.c,46 :: 		clock =1;
	BSF        PORTB+0, 0
;dc.c,47 :: 		delay_us(10);
	MOVLW      6
	MOVWF      R13+0
L_display6:
	DECFSZ     R13+0, 1
	GOTO       L_display6
	NOP
;dc.c,48 :: 		clock=0;
	BCF        PORTB+0, 0
;dc.c,49 :: 		i++; }
	INCF       _i+0, 1
;dc.c,38 :: 		for (bit_mask = 1; bit_mask; bit_mask <<= 1)
	RLF        R1+0, 1
	BCF        R1+0, 0
;dc.c,49 :: 		i++; }
	GOTO       L_display1
L_display2:
;dc.c,51 :: 		if(i==8)
	MOVF       _i+0, 0
	XORLW      8
	BTFSS      STATUS+0, 2
	GOTO       L_display7
;dc.c,54 :: 		i=0;  }
	CLRF       _i+0
L_display7:
;dc.c,55 :: 		}
	RETURN
; end of _display

_display1:
;dc.c,57 :: 		void display1(unsigned char send_data1)
;dc.c,59 :: 		if (i==0)
	MOVF       _i+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_display18
;dc.c,60 :: 		{latch =0;
	BCF        PORTB+0, 1
;dc.c,61 :: 		clock =0;
	BCF        PORTB+0, 0
;dc.c,62 :: 		}
L_display18:
;dc.c,64 :: 		for (bit_mask1 = 1; bit_mask1; bit_mask1 <<= 1)
	MOVLW      1
	MOVWF      R1+0
L_display19:
	MOVF       R1+0, 0
	BTFSC      STATUS+0, 2
	GOTO       L_display110
;dc.c,66 :: 		if((send_data1 & bit_mask1))
	MOVF       R1+0, 0
	ANDWF      FARG_display1_send_data1+0, 0
	MOVWF      R0+0
	BTFSC      STATUS+0, 2
	GOTO       L_display112
;dc.c,67 :: 		data = 0;
	BCF        PORTB+0, 2
	GOTO       L_display113
L_display112:
;dc.c,70 :: 		{  data = 1;               //bit0 transfer to shift register
	BSF        PORTB+0, 2
;dc.c,71 :: 		}
L_display113:
;dc.c,72 :: 		clock =1;
	BSF        PORTB+0, 0
;dc.c,73 :: 		delay_us(10);
	MOVLW      6
	MOVWF      R13+0
L_display114:
	DECFSZ     R13+0, 1
	GOTO       L_display114
	NOP
;dc.c,74 :: 		clock=0;
	BCF        PORTB+0, 0
;dc.c,75 :: 		i++; }
	INCF       _i+0, 1
;dc.c,64 :: 		for (bit_mask1 = 1; bit_mask1; bit_mask1 <<= 1)
	RLF        R1+0, 1
	BCF        R1+0, 0
;dc.c,75 :: 		i++; }
	GOTO       L_display19
L_display110:
;dc.c,77 :: 		if(i==8)
	MOVF       _i+0, 0
	XORLW      8
	BTFSS      STATUS+0, 2
	GOTO       L_display115
;dc.c,80 :: 		i=0;  }
	CLRF       _i+0
L_display115:
;dc.c,81 :: 		}
	RETURN
; end of _display1

_display2:
;dc.c,83 :: 		void display2(unsigned char send_data2)
;dc.c,85 :: 		if (i==0)
	MOVF       _i+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_display216
;dc.c,86 :: 		{latch =0;
	BCF        PORTB+0, 1
;dc.c,87 :: 		clock =0;
	BCF        PORTB+0, 0
;dc.c,88 :: 		}
L_display216:
;dc.c,90 :: 		for (bit_mask2 = 1; bit_mask2; bit_mask2 <<= 1)
	MOVLW      1
	MOVWF      R1+0
L_display217:
	MOVF       R1+0, 0
	BTFSC      STATUS+0, 2
	GOTO       L_display218
;dc.c,92 :: 		if((send_data2 & bit_mask2))
	MOVF       R1+0, 0
	ANDWF      FARG_display2_send_data2+0, 0
	MOVWF      R0+0
	BTFSC      STATUS+0, 2
	GOTO       L_display220
;dc.c,93 :: 		data = 0;
	BCF        PORTB+0, 2
	GOTO       L_display221
L_display220:
;dc.c,96 :: 		{  data = 1;               //bit0 transfer to shift register
	BSF        PORTB+0, 2
;dc.c,97 :: 		}
L_display221:
;dc.c,98 :: 		clock =1;
	BSF        PORTB+0, 0
;dc.c,99 :: 		delay_us(10);
	MOVLW      6
	MOVWF      R13+0
L_display222:
	DECFSZ     R13+0, 1
	GOTO       L_display222
	NOP
;dc.c,100 :: 		clock=0;
	BCF        PORTB+0, 0
;dc.c,101 :: 		i++; }
	INCF       _i+0, 1
;dc.c,90 :: 		for (bit_mask2 = 1; bit_mask2; bit_mask2 <<= 1)
	RLF        R1+0, 1
	BCF        R1+0, 0
;dc.c,101 :: 		i++; }
	GOTO       L_display217
L_display218:
;dc.c,103 :: 		if(i==8)
	MOVF       _i+0, 0
	XORLW      8
	BTFSS      STATUS+0, 2
	GOTO       L_display223
;dc.c,106 :: 		i=0;  }
	CLRF       _i+0
L_display223:
;dc.c,107 :: 		}
	RETURN
; end of _display2

_display3:
;dc.c,109 :: 		void display3(unsigned char send_data3)
;dc.c,111 :: 		if (i==0)
	MOVF       _i+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_display324
;dc.c,112 :: 		{latch =0;
	BCF        PORTB+0, 1
;dc.c,113 :: 		clock =0;
	BCF        PORTB+0, 0
;dc.c,114 :: 		}
L_display324:
;dc.c,116 :: 		for (bit_mask3 = 1; bit_mask3; bit_mask3 <<= 1)
	MOVLW      1
	MOVWF      R1+0
L_display325:
	MOVF       R1+0, 0
	BTFSC      STATUS+0, 2
	GOTO       L_display326
;dc.c,118 :: 		if((send_data3 & bit_mask3))
	MOVF       R1+0, 0
	ANDWF      FARG_display3_send_data3+0, 0
	MOVWF      R0+0
	BTFSC      STATUS+0, 2
	GOTO       L_display328
;dc.c,119 :: 		data = 0;
	BCF        PORTB+0, 2
	GOTO       L_display329
L_display328:
;dc.c,122 :: 		{  data = 1;               //bit0 transfer to shift register
	BSF        PORTB+0, 2
;dc.c,123 :: 		}
L_display329:
;dc.c,124 :: 		clock =1;
	BSF        PORTB+0, 0
;dc.c,125 :: 		delay_us(10);
	MOVLW      6
	MOVWF      R13+0
L_display330:
	DECFSZ     R13+0, 1
	GOTO       L_display330
	NOP
;dc.c,126 :: 		clock=0;
	BCF        PORTB+0, 0
;dc.c,127 :: 		i++; }
	INCF       _i+0, 1
;dc.c,116 :: 		for (bit_mask3 = 1; bit_mask3; bit_mask3 <<= 1)
	RLF        R1+0, 1
	BCF        R1+0, 0
;dc.c,127 :: 		i++; }
	GOTO       L_display325
L_display326:
;dc.c,129 :: 		if(i==8)
	MOVF       _i+0, 0
	XORLW      8
	BTFSS      STATUS+0, 2
	GOTO       L_display331
;dc.c,131 :: 		latch=1;
	BSF        PORTB+0, 1
;dc.c,132 :: 		i=0;  }
	CLRF       _i+0
L_display331:
;dc.c,133 :: 		}
	RETURN
; end of _display3

_display0:
;dc.c,134 :: 		void display0(unsigned num)
;dc.c,136 :: 		{PORTD.RD4 = 0;}
	BCF        PORTD+0, 4
;dc.c,137 :: 		if (k==num+1)
	MOVF       FARG_display0_num+0, 0
	ADDLW      1
	MOVWF      R1+0
	MOVLW      0
	BTFSC      STATUS+0, 0
	ADDLW      1
	ADDWF      FARG_display0_num+1, 0
	MOVWF      R1+1
	MOVF       _k+1, 0
	XORWF      R1+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__display076
	MOVF       R1+0, 0
	XORWF      _k+0, 0
L__display076:
	BTFSS      STATUS+0, 2
	GOTO       L_display032
;dc.c,140 :: 		if(num==0 && j==0)
	MOVLW      0
	XORWF      FARG_display0_num+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__display077
	MOVLW      0
	XORWF      FARG_display0_num+0, 0
L__display077:
	BTFSS      STATUS+0, 2
	GOTO       L_display035
	MOVLW      0
	XORWF      _j+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__display078
	MOVLW      0
	XORWF      _j+0, 0
L__display078:
	BTFSS      STATUS+0, 2
	GOTO       L_display035
L__display074:
;dc.c,141 :: 		{ data1 = 1;
	BSF        PORTD+0, 0
;dc.c,142 :: 		j = 1;  }
	MOVLW      1
	MOVWF      _j+0
	MOVLW      0
	MOVWF      _j+1
	GOTO       L_display036
L_display035:
;dc.c,144 :: 		{ if (num==0 && j==1)
	MOVLW      0
	XORWF      FARG_display0_num+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__display079
	MOVLW      0
	XORWF      FARG_display0_num+0, 0
L__display079:
	BTFSS      STATUS+0, 2
	GOTO       L_display039
	MOVLW      0
	XORWF      _j+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__display080
	MOVLW      1
	XORWF      _j+0, 0
L__display080:
	BTFSS      STATUS+0, 2
	GOTO       L_display039
L__display073:
;dc.c,145 :: 		{data1 = 0;
	BCF        PORTD+0, 0
;dc.c,146 :: 		j = 0; }  }
	CLRF       _j+0
	CLRF       _j+1
L_display039:
L_display036:
;dc.c,147 :: 		n++;
	INCF       _n+0, 1
	BTFSC      STATUS+0, 2
	INCF       _n+1, 1
;dc.c,149 :: 		clock1 =1;
	BSF        PORTD+0, 1
;dc.c,150 :: 		delay_us(10);
	MOVLW      6
	MOVWF      R13+0
L_display040:
	DECFSZ     R13+0, 1
	GOTO       L_display040
	NOP
;dc.c,151 :: 		clock1 =0;
	BCF        PORTD+0, 1
;dc.c,153 :: 		PORTD.RD4 = 1;
	BSF        PORTD+0, 4
;dc.c,155 :: 		k++;
	INCF       _k+0, 1
	BTFSC      STATUS+0, 2
	INCF       _k+1, 1
;dc.c,156 :: 		if (k==61){
	MOVLW      0
	XORWF      _k+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__display081
	MOVLW      61
	XORWF      _k+0, 0
L__display081:
	BTFSS      STATUS+0, 2
	GOTO       L_display041
;dc.c,157 :: 		k = 1;
	MOVLW      1
	MOVWF      _k+0
	MOVLW      0
	MOVWF      _k+1
;dc.c,158 :: 		}
L_display041:
;dc.c,159 :: 		}
L_display032:
;dc.c,162 :: 		}
	RETURN
; end of _display0

_read_ds1307:
;dc.c,163 :: 		unsigned short read_ds1307(unsigned short address)
;dc.c,166 :: 		I2C1_Start();
	CALL       _I2C1_Start+0
;dc.c,167 :: 		I2C1_Wr(0xD0); //address 0x68 followed by direction bit (0 for write, 1 for read) 0x68 followed by 0 --> 0xD0
	MOVLW      208
	MOVWF      FARG_I2C1_Wr_data_+0
	CALL       _I2C1_Wr+0
;dc.c,168 :: 		I2C1_Wr(address);
	MOVF       FARG_read_ds1307_address+0, 0
	MOVWF      FARG_I2C1_Wr_data_+0
	CALL       _I2C1_Wr+0
;dc.c,169 :: 		I2C1_Repeated_Start();
	CALL       _I2C1_Repeated_Start+0
;dc.c,170 :: 		I2C1_Wr(0xD1); //0x68 followed by 1 --> 0xD1
	MOVLW      209
	MOVWF      FARG_I2C1_Wr_data_+0
	CALL       _I2C1_Wr+0
;dc.c,171 :: 		r_data=I2C1_Rd(0);
	CLRF       FARG_I2C1_Rd_ack+0
	CALL       _I2C1_Rd+0
	MOVF       R0+0, 0
	MOVWF      read_ds1307_r_data_L0+0
;dc.c,172 :: 		I2C1_Stop();
	CALL       _I2C1_Stop+0
;dc.c,173 :: 		return(r_data);
	MOVF       read_ds1307_r_data_L0+0, 0
	MOVWF      R0+0
;dc.c,174 :: 		}
	RETURN
; end of _read_ds1307

_write_ds1307:
;dc.c,177 :: 		void write_ds1307(unsigned short address,unsigned short w_data)
;dc.c,179 :: 		I2C1_Start(); // issue I2C start signal
	CALL       _I2C1_Start+0
;dc.c,181 :: 		I2C1_Wr(0xD0); // send byte via I2C (device address + W)
	MOVLW      208
	MOVWF      FARG_I2C1_Wr_data_+0
	CALL       _I2C1_Wr+0
;dc.c,182 :: 		I2C1_Wr(address); // send byte (address of DS1307 location)
	MOVF       FARG_write_ds1307_address+0, 0
	MOVWF      FARG_I2C1_Wr_data_+0
	CALL       _I2C1_Wr+0
;dc.c,183 :: 		I2C1_Wr(w_data); // send data (data to be written)
	MOVF       FARG_write_ds1307_w_data+0, 0
	MOVWF      FARG_I2C1_Wr_data_+0
	CALL       _I2C1_Wr+0
;dc.c,184 :: 		I2C1_Stop(); // issue I2C stop signal
	CALL       _I2C1_Stop+0
;dc.c,187 :: 		}
	RETURN
; end of _write_ds1307

_Binary2BCD:
;dc.c,192 :: 		int Binary2BCD(int a)
;dc.c,195 :: 		t1 = a%10;
	MOVLW      10
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	MOVF       FARG_Binary2BCD_a+0, 0
	MOVWF      R0+0
	MOVF       FARG_Binary2BCD_a+1, 0
	MOVWF      R0+1
	CALL       _Div_16x16_S+0
	MOVF       R8+0, 0
	MOVWF      R0+0
	MOVF       R8+1, 0
	MOVWF      R0+1
	MOVF       R0+0, 0
	MOVWF      Binary2BCD_t1_L0+0
	MOVF       R0+1, 0
	MOVWF      Binary2BCD_t1_L0+1
;dc.c,196 :: 		t1 = t1 & 0x0F;
	MOVLW      15
	ANDWF      R0+0, 0
	MOVWF      Binary2BCD_t1_L0+0
	MOVF       R0+1, 0
	MOVWF      Binary2BCD_t1_L0+1
	MOVLW      0
	ANDWF      Binary2BCD_t1_L0+1, 1
;dc.c,197 :: 		a = a/10;
	MOVLW      10
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	MOVF       FARG_Binary2BCD_a+0, 0
	MOVWF      R0+0
	MOVF       FARG_Binary2BCD_a+1, 0
	MOVWF      R0+1
	CALL       _Div_16x16_S+0
	MOVF       R0+0, 0
	MOVWF      FARG_Binary2BCD_a+0
	MOVF       R0+1, 0
	MOVWF      FARG_Binary2BCD_a+1
;dc.c,198 :: 		t2 = a%10;
	MOVLW      10
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	CALL       _Div_16x16_S+0
	MOVF       R8+0, 0
	MOVWF      R0+0
	MOVF       R8+1, 0
	MOVWF      R0+1
;dc.c,199 :: 		t2 = 0x0F & t2;
	MOVLW      15
	ANDWF      R0+0, 0
	MOVWF      R3+0
	MOVF       R0+1, 0
	MOVWF      R3+1
	MOVLW      0
	ANDWF      R3+1, 1
;dc.c,200 :: 		t2 = t2 << 4;
	MOVLW      4
	MOVWF      R2+0
	MOVF       R3+0, 0
	MOVWF      R0+0
	MOVF       R3+1, 0
	MOVWF      R0+1
	MOVF       R2+0, 0
L__Binary2BCD82:
	BTFSC      STATUS+0, 2
	GOTO       L__Binary2BCD83
	RLF        R0+0, 1
	RLF        R0+1, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__Binary2BCD82
L__Binary2BCD83:
;dc.c,201 :: 		t2 = 0xF0 & t2;
	MOVLW      240
	ANDWF      R0+0, 1
	MOVLW      0
	ANDWF      R0+1, 1
;dc.c,202 :: 		t1 = t1 | t2;
	MOVF       Binary2BCD_t1_L0+0, 0
	IORWF      R0+0, 1
	MOVF       Binary2BCD_t1_L0+1, 0
	IORWF      R0+1, 1
	MOVF       R0+0, 0
	MOVWF      Binary2BCD_t1_L0+0
	MOVF       R0+1, 0
	MOVWF      Binary2BCD_t1_L0+1
;dc.c,203 :: 		return t1;
;dc.c,204 :: 		}
	RETURN
; end of _Binary2BCD

_main:
;dc.c,209 :: 		void main()
;dc.c,212 :: 		I2C1_Init(100000); //DS1307 I2C is running at 100KHz
	MOVLW      20
	MOVWF      SSPADD+0
	CALL       _I2C1_Init+0
;dc.c,214 :: 		CMCON = 0x07;   // To turn off comparators
	MOVLW      7
	MOVWF      CMCON+0
;dc.c,215 :: 		ADCON1 = 0x06;  // To turn off analog to digital converters
	MOVLW      6
	MOVWF      ADCON1+0
;dc.c,217 :: 		TRISA = 0x07;
	MOVLW      7
	MOVWF      TRISA+0
;dc.c,218 :: 		PORTA = 0x00;
	CLRF       PORTA+0
;dc.c,219 :: 		TRISB = 0x00;
	CLRF       TRISB+0
;dc.c,220 :: 		PORTB = 0x00;
	CLRF       PORTB+0
;dc.c,221 :: 		TRISD = 0x00;
	CLRF       TRISD+0
;dc.c,222 :: 		PORTD = 0x00;
	CLRF       PORTD+0
;dc.c,224 :: 		PORTB.F3 = 1 ;
	BSF        PORTB+0, 3
;dc.c,228 :: 		do {
L_main42:
;dc.c,230 :: 		set = 0;
	CLRF       _set+0
;dc.c,231 :: 		if(PORTA.F0 == 0)
	BTFSC      PORTA+0, 0
	GOTO       L_main44
;dc.c,233 :: 		Delay_ms(100);
	MOVLW      2
	MOVWF      R11+0
	MOVLW      4
	MOVWF      R12+0
	MOVLW      186
	MOVWF      R13+0
L_main45:
	DECFSZ     R13+0, 1
	GOTO       L_main45
	DECFSZ     R12+0, 1
	GOTO       L_main45
	DECFSZ     R11+0, 1
	GOTO       L_main45
	NOP
;dc.c,234 :: 		if(PORTA.F0 == 0)
	BTFSC      PORTA+0, 0
	GOTO       L_main46
;dc.c,236 :: 		set_count++;
	INCF       _set_count+0, 1
;dc.c,240 :: 		if(set_count >= 4)
	MOVLW      4
	SUBWF      _set_count+0, 0
	BTFSS      STATUS+0, 0
	GOTO       L_main47
;dc.c,242 :: 		set_count = 0;
	CLRF       _set_count+0
;dc.c,243 :: 		}
L_main47:
;dc.c,244 :: 		}
L_main46:
;dc.c,245 :: 		}
L_main44:
;dc.c,246 :: 		if(set_count)
	MOVF       _set_count+0, 0
	BTFSC      STATUS+0, 2
	GOTO       L_main48
;dc.c,248 :: 		if(PORTA.F1 == 0)
	BTFSC      PORTA+0, 1
	GOTO       L_main49
;dc.c,250 :: 		Delay_ms(100);
	MOVLW      2
	MOVWF      R11+0
	MOVLW      4
	MOVWF      R12+0
	MOVLW      186
	MOVWF      R13+0
L_main50:
	DECFSZ     R13+0, 1
	GOTO       L_main50
	DECFSZ     R12+0, 1
	GOTO       L_main50
	DECFSZ     R11+0, 1
	GOTO       L_main50
	NOP
;dc.c,251 :: 		if(PORTA.F1 == 0)
	BTFSC      PORTA+0, 1
	GOTO       L_main51
;dc.c,252 :: 		set = 1;
	MOVLW      1
	MOVWF      _set+0
L_main51:
;dc.c,253 :: 		}
L_main49:
;dc.c,255 :: 		if(PORTA.F2 == 0)
	BTFSC      PORTA+0, 2
	GOTO       L_main52
;dc.c,257 :: 		Delay_ms(100);
	MOVLW      2
	MOVWF      R11+0
	MOVLW      4
	MOVWF      R12+0
	MOVLW      186
	MOVWF      R13+0
L_main53:
	DECFSZ     R13+0, 1
	GOTO       L_main53
	DECFSZ     R12+0, 1
	GOTO       L_main53
	DECFSZ     R11+0, 1
	GOTO       L_main53
	NOP
;dc.c,258 :: 		if(PORTA.F2 == 0)
	BTFSC      PORTA+0, 2
	GOTO       L_main54
;dc.c,259 :: 		set = -1;
	MOVLW      255
	MOVWF      _set+0
L_main54:
;dc.c,260 :: 		}
L_main52:
;dc.c,261 :: 		if(set_count && set)
	MOVF       _set_count+0, 0
	BTFSC      STATUS+0, 2
	GOTO       L_main57
	MOVF       _set+0, 0
	BTFSC      STATUS+0, 2
	GOTO       L_main57
L__main75:
;dc.c,263 :: 		switch(set_count)
	GOTO       L_main58
;dc.c,265 :: 		case 1:
L_main60:
;dc.c,267 :: 		hour1= (hour>>4)*10+(hour&0x0F);
	MOVF       _hour+0, 0
	MOVWF      R0+0
	RRF        R0+0, 1
	BCF        R0+0, 7
	RRF        R0+0, 1
	BCF        R0+0, 7
	RRF        R0+0, 1
	BCF        R0+0, 7
	RRF        R0+0, 1
	BCF        R0+0, 7
	MOVLW      10
	MOVWF      R4+0
	CALL       _Mul_8x8_U+0
	MOVLW      15
	ANDWF      _hour+0, 0
	MOVWF      R1+0
	MOVF       R1+0, 0
	ADDWF      R0+0, 1
	MOVF       R0+0, 0
	MOVWF      _hour1+0
;dc.c,268 :: 		hour1 = hour1 +set;
	MOVF       _set+0, 0
	ADDWF      R0+0, 1
	MOVF       R0+0, 0
	MOVWF      _hour1+0
;dc.c,269 :: 		hour1 = Binary2BCD(hour1);
	MOVF       R0+0, 0
	MOVWF      FARG_Binary2BCD_a+0
	CLRF       FARG_Binary2BCD_a+1
	CALL       _Binary2BCD+0
	MOVF       R0+0, 0
	MOVWF      _hour1+0
;dc.c,271 :: 		if((hour1  ) >= 0x24)
	MOVLW      36
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 0
	GOTO       L_main61
;dc.c,272 :: 		hour1 = 0x00;
	CLRF       _hour1+0
L_main61:
;dc.c,274 :: 		write_ds1307(2,hour1); //write hour
	MOVLW      2
	MOVWF      FARG_write_ds1307_address+0
	MOVF       _hour1+0, 0
	MOVWF      FARG_write_ds1307_w_data+0
	CALL       _write_ds1307+0
;dc.c,276 :: 		break;
	GOTO       L_main59
;dc.c,277 :: 		case 2:
L_main62:
;dc.c,279 :: 		minute1= (minute>>4)*10+(minute&0x0F);
	MOVF       _minute+0, 0
	MOVWF      R0+0
	RRF        R0+0, 1
	BCF        R0+0, 7
	RRF        R0+0, 1
	BCF        R0+0, 7
	RRF        R0+0, 1
	BCF        R0+0, 7
	RRF        R0+0, 1
	BCF        R0+0, 7
	MOVLW      10
	MOVWF      R4+0
	CALL       _Mul_8x8_U+0
	MOVLW      15
	ANDWF      _minute+0, 0
	MOVWF      R1+0
	MOVF       R1+0, 0
	ADDWF      R0+0, 1
	MOVF       R0+0, 0
	MOVWF      _minute1+0
;dc.c,280 :: 		minute1 = minute1 + set;
	MOVF       _set+0, 0
	ADDWF      R0+0, 0
	MOVWF      R1+0
	MOVF       R1+0, 0
	MOVWF      _minute1+0
;dc.c,282 :: 		if(minute1 >= 59)
	MOVLW      59
	SUBWF      R1+0, 0
	BTFSS      STATUS+0, 0
	GOTO       L_main63
;dc.c,283 :: 		minute1 = 0;
	CLRF       _minute1+0
L_main63:
;dc.c,284 :: 		if(minute1 <= 0)
	MOVF       _minute1+0, 0
	SUBLW      0
	BTFSS      STATUS+0, 0
	GOTO       L_main64
;dc.c,285 :: 		minute1 = 59;
	MOVLW      59
	MOVWF      _minute1+0
L_main64:
;dc.c,287 :: 		minute1 = Binary2BCD(minute1);
	MOVF       _minute1+0, 0
	MOVWF      FARG_Binary2BCD_a+0
	CLRF       FARG_Binary2BCD_a+1
	CALL       _Binary2BCD+0
	MOVF       R0+0, 0
	MOVWF      _minute1+0
;dc.c,288 :: 		write_ds1307(1, minute1); //write min
	MOVLW      1
	MOVWF      FARG_write_ds1307_address+0
	MOVF       R0+0, 0
	MOVWF      FARG_write_ds1307_w_data+0
	CALL       _write_ds1307+0
;dc.c,290 :: 		break;
	GOTO       L_main59
;dc.c,291 :: 		case 3:
L_main65:
;dc.c,292 :: 		if(abs(set))
	MOVF       _set+0, 0
	MOVWF      FARG_abs_a+0
	MOVLW      0
	BTFSC      FARG_abs_a+0, 7
	MOVLW      255
	MOVWF      FARG_abs_a+1
	CALL       _abs+0
	MOVF       R0+0, 0
	IORWF      R0+1, 0
	BTFSC      STATUS+0, 2
	GOTO       L_main66
;dc.c,293 :: 		write_ds1307(0,0x00); //Reset second to 0 sec. and start Oscillator
	CLRF       FARG_write_ds1307_address+0
	CLRF       FARG_write_ds1307_w_data+0
	CALL       _write_ds1307+0
L_main66:
;dc.c,294 :: 		break;
	GOTO       L_main59
;dc.c,295 :: 		}
L_main58:
	MOVF       _set_count+0, 0
	XORLW      1
	BTFSC      STATUS+0, 2
	GOTO       L_main60
	MOVF       _set_count+0, 0
	XORLW      2
	BTFSC      STATUS+0, 2
	GOTO       L_main62
	MOVF       _set_count+0, 0
	XORLW      3
	BTFSC      STATUS+0, 2
	GOTO       L_main65
L_main59:
;dc.c,296 :: 		}
L_main57:
;dc.c,297 :: 		}
L_main48:
;dc.c,301 :: 		second = read_ds1307(0);
	CLRF       FARG_read_ds1307_address+0
	CALL       _read_ds1307+0
	MOVF       R0+0, 0
	MOVWF      _second+0
;dc.c,302 :: 		minute = read_ds1307(1);
	MOVLW      1
	MOVWF      FARG_read_ds1307_address+0
	CALL       _read_ds1307+0
	MOVF       R0+0, 0
	MOVWF      _minute+0
;dc.c,303 :: 		hour = read_ds1307(2);
	MOVLW      2
	MOVWF      FARG_read_ds1307_address+0
	CALL       _read_ds1307+0
	MOVF       R0+0, 0
	MOVWF      _hour+0
;dc.c,304 :: 		second1= (second>>4)*10+(second&0x0F);
	MOVF       _second+0, 0
	MOVWF      R0+0
	RRF        R0+0, 1
	BCF        R0+0, 7
	RRF        R0+0, 1
	BCF        R0+0, 7
	RRF        R0+0, 1
	BCF        R0+0, 7
	RRF        R0+0, 1
	BCF        R0+0, 7
	MOVLW      10
	MOVWF      R4+0
	CALL       _Mul_8x8_U+0
	MOVLW      15
	ANDWF      _second+0, 0
	MOVWF      R1+0
	MOVF       R1+0, 0
	ADDWF      R0+0, 0
	MOVWF      _second1+0
;dc.c,305 :: 		minute1= (minute>>4)*10+(minute&0x0F);
	MOVF       _minute+0, 0
	MOVWF      R0+0
	RRF        R0+0, 1
	BCF        R0+0, 7
	RRF        R0+0, 1
	BCF        R0+0, 7
	RRF        R0+0, 1
	BCF        R0+0, 7
	RRF        R0+0, 1
	BCF        R0+0, 7
	MOVLW      10
	MOVWF      R4+0
	CALL       _Mul_8x8_U+0
	MOVLW      15
	ANDWF      _minute+0, 0
	MOVWF      R1+0
	MOVF       R1+0, 0
	ADDWF      R0+0, 0
	MOVWF      _minute1+0
;dc.c,306 :: 		hour1= (hour>>4)*10+(hour&0x0F);
	MOVF       _hour+0, 0
	MOVWF      R0+0
	RRF        R0+0, 1
	BCF        R0+0, 7
	RRF        R0+0, 1
	BCF        R0+0, 7
	RRF        R0+0, 1
	BCF        R0+0, 7
	RRF        R0+0, 1
	BCF        R0+0, 7
	MOVLW      10
	MOVWF      R4+0
	CALL       _Mul_8x8_U+0
	MOVLW      15
	ANDWF      _hour+0, 0
	MOVWF      R1+0
	MOVF       R0+0, 0
	ADDWF      R1+0, 1
	MOVF       R1+0, 0
	MOVWF      _hour1+0
;dc.c,307 :: 		if(hour1==0)
	MOVF       R1+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_main67
;dc.c,308 :: 		hour1+=12;
	MOVLW      12
	ADDWF      _hour1+0, 1
	GOTO       L_main68
L_main67:
;dc.c,309 :: 		else if(hour1>=13)
	MOVLW      13
	SUBWF      _hour1+0, 0
	BTFSS      STATUS+0, 0
	GOTO       L_main69
;dc.c,310 :: 		hour1-=12;
	MOVLW      12
	SUBWF      _hour1+0, 1
L_main69:
L_main68:
;dc.c,311 :: 		Count1 = minute1;
	MOVF       _minute1+0, 0
	MOVWF      _Count1+0
;dc.c,312 :: 		Count2 = hour1;
	MOVF       _hour1+0, 0
	MOVWF      _Count2+0
;dc.c,313 :: 		count3 = second1;
	MOVF       _second1+0, 0
	MOVWF      _count3+0
;dc.c,316 :: 		DD0 = (Count1)%10;  // ExtRAct Ones Digit
	MOVLW      10
	MOVWF      R4+0
	MOVF       _minute1+0, 0
	MOVWF      R0+0
	CALL       _Div_8x8_U+0
	MOVF       R8+0, 0
	MOVWF      R0+0
	MOVF       R0+0, 0
	MOVWF      _DD0+0
;dc.c,317 :: 		display(number[DD0]);
	MOVF       R0+0, 0
	ADDLW      _number+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      FARG_display_send_data+0
	CALL       _display+0
;dc.c,318 :: 		DD1 = (Count1/10)%10; // ExtRAct Tens Digit
	MOVLW      10
	MOVWF      R4+0
	MOVF       _Count1+0, 0
	MOVWF      R0+0
	CALL       _Div_8x8_U+0
	MOVLW      10
	MOVWF      R4+0
	CALL       _Div_8x8_U+0
	MOVF       R8+0, 0
	MOVWF      R0+0
	MOVF       R0+0, 0
	MOVWF      _DD1+0
;dc.c,319 :: 		display1(number[DD1]);
	MOVF       R0+0, 0
	ADDLW      _number+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      FARG_display1_send_data1+0
	CALL       _display1+0
;dc.c,320 :: 		DD2 = (Count2)%10; // ExtRAct Hundreds Digit
	MOVLW      10
	MOVWF      R4+0
	MOVF       _Count2+0, 0
	MOVWF      R0+0
	CALL       _Div_8x8_U+0
	MOVF       R8+0, 0
	MOVWF      R0+0
	MOVF       R0+0, 0
	MOVWF      _DD2+0
;dc.c,321 :: 		display2(number[DD2]);
	MOVF       R0+0, 0
	ADDLW      _number+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      FARG_display2_send_data2+0
	CALL       _display2+0
;dc.c,322 :: 		DD3 = (Count2/10)%10;  // ExtRAct Thousands Digit
	MOVLW      10
	MOVWF      R4+0
	MOVF       _Count2+0, 0
	MOVWF      R0+0
	CALL       _Div_8x8_U+0
	MOVLW      10
	MOVWF      R4+0
	CALL       _Div_8x8_U+0
	MOVF       R8+0, 0
	MOVWF      R0+0
	MOVF       R0+0, 0
	MOVWF      _DD3+0
;dc.c,323 :: 		if( DD3>0)
	MOVF       R0+0, 0
	SUBLW      0
	BTFSC      STATUS+0, 0
	GOTO       L_main70
;dc.c,324 :: 		{display3(number[DD3]); }
	MOVF       _DD3+0, 0
	ADDLW      _number+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      FARG_display3_send_data3+0
	CALL       _display3+0
	GOTO       L_main71
L_main70:
;dc.c,326 :: 		{display3(0xFF); }
	MOVLW      255
	MOVWF      FARG_display3_send_data3+0
	CALL       _display3+0
L_main71:
;dc.c,329 :: 		DD4= (count3);
	MOVF       _count3+0, 0
	MOVWF      _DD4+0
;dc.c,330 :: 		display0(DD4);
	MOVF       _count3+0, 0
	MOVWF      FARG_display0_num+0
	CLRF       FARG_display0_num+1
	CALL       _display0+0
;dc.c,332 :: 		Delay_ms(500);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main72:
	DECFSZ     R13+0, 1
	GOTO       L_main72
	DECFSZ     R12+0, 1
	GOTO       L_main72
	DECFSZ     R11+0, 1
	GOTO       L_main72
	NOP
	NOP
;dc.c,339 :: 		}while(1);
	GOTO       L_main42
;dc.c,340 :: 		}
	GOTO       $+0
; end of _main
