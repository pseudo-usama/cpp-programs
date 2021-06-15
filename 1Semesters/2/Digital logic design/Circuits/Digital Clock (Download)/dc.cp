#line 1 "J:/upload edi/clock digital/ZZZZ CLOCK NEW/CLOCK C CODE FILE/dc.c"










unsigned short i, l, DD0, DD1, DD2, DD3, DD4;
unsigned char send_data0;
int j = 0;
int k = 1;
int m = 0;
int n = 0;
int a = 0;
int b = 0;
unsigned short Count1, Count2, count3, second, second1, hour, minute, hour1, minute1;

unsigned short set_count = 0;
short set;

unsigned short number [10] = {
 0xA0, 0xF9, 0x64, 0x70, 0x39, 0x32, 0x22, 0xF8,
 0x20, 0x30
};



 void display(unsigned char send_data)
 {
 if (i==0)
 { PORTB.F1  =0;
  PORTB.F0  =0;
 }
 { unsigned char bit_mask;
 for (bit_mask = 1; bit_mask; bit_mask <<= 1)
 {
 if((send_data & bit_mask))
  PORTB.F2  = 0;

 else
 {  PORTB.F2  = 1;
 }
  PORTB.F0  =1;
 delay_us(10);
  PORTB.F0 =0;
 i++; }
 }
 if(i==8)
 {

 i=0; }
 }

 void display1(unsigned char send_data1)
 {
 if (i==0)
 { PORTB.F1  =0;
  PORTB.F0  =0;
 }
 { unsigned char bit_mask1;
 for (bit_mask1 = 1; bit_mask1; bit_mask1 <<= 1)
 {
 if((send_data1 & bit_mask1))
  PORTB.F2  = 0;

 else
 {  PORTB.F2  = 1;
 }
  PORTB.F0  =1;
 delay_us(10);
  PORTB.F0 =0;
 i++; }
 }
 if(i==8)
 {

 i=0; }
 }

 void display2(unsigned char send_data2)
 {
 if (i==0)
 { PORTB.F1  =0;
  PORTB.F0  =0;
 }
 { unsigned char bit_mask2;
 for (bit_mask2 = 1; bit_mask2; bit_mask2 <<= 1)
 {
 if((send_data2 & bit_mask2))
  PORTB.F2  = 0;

 else
 {  PORTB.F2  = 1;
 }
  PORTB.F0  =1;
 delay_us(10);
  PORTB.F0 =0;
 i++; }
 }
 if(i==8)
 {

 i=0; }
 }

 void display3(unsigned char send_data3)
 {
 if (i==0)
 { PORTB.F1  =0;
  PORTB.F0  =0;
 }
 { unsigned char bit_mask3;
 for (bit_mask3 = 1; bit_mask3; bit_mask3 <<= 1)
 {
 if((send_data3 & bit_mask3))
  PORTB.F2  = 0;

 else
 {  PORTB.F2  = 1;
 }
  PORTB.F0  =1;
 delay_us(10);
  PORTB.F0 =0;
 i++; }
 }
 if(i==8)
 {
  PORTB.F1 =1;
 i=0; }
 }
void display0(unsigned num)
 {
 {PORTD.RD4 = 0;}
if (k==num+1)
 {

 if(num==0 && j==0)
 {  PORTD.F0  = 1;
 j = 1; }
 else
 { if (num==0 && j==1)
 { PORTD.F0  = 0;
 j = 0; } }
 n++;

  PORTD.F1  =1;
 delay_us(10);
  PORTD.F1  =0;

 PORTD.RD4 = 1;

 k++;
 if (k==61){
 k = 1;
 }
 }


 }
 unsigned short read_ds1307(unsigned short address)
{
 unsigned short r_data;
 I2C1_Start();
 I2C1_Wr(0xD0);
 I2C1_Wr(address);
 I2C1_Repeated_Start();
 I2C1_Wr(0xD1);
 r_data=I2C1_Rd(0);
 I2C1_Stop();
 return(r_data);
}


void write_ds1307(unsigned short address,unsigned short w_data)
{
 I2C1_Start();

 I2C1_Wr(0xD0);
 I2C1_Wr(address);
 I2C1_Wr(w_data);
 I2C1_Stop();


}




int Binary2BCD(int a)
{
 int t1, t2;
 t1 = a%10;
 t1 = t1 & 0x0F;
 a = a/10;
 t2 = a%10;
 t2 = 0x0F & t2;
 t2 = t2 << 4;
 t2 = 0xF0 & t2;
 t1 = t1 | t2;
 return t1;
}




void main()
{

I2C1_Init(100000);

 CMCON = 0x07;
 ADCON1 = 0x06;

 TRISA = 0x07;
 PORTA = 0x00;
 TRISB = 0x00;
 PORTB = 0x00;
 TRISD = 0x00;
 PORTD = 0x00;

 PORTB.F3 = 1 ;



 do {

 set = 0;
 if(PORTA.F0 == 0)
 {
 Delay_ms(100);
 if(PORTA.F0 == 0)
 {
 set_count++;



 if(set_count >= 4)
 {
 set_count = 0;
 }
 }
 }
 if(set_count)
 {
 if(PORTA.F1 == 0)
 {
 Delay_ms(100);
 if(PORTA.F1 == 0)
 set = 1;
 }

 if(PORTA.F2 == 0)
 {
 Delay_ms(100);
 if(PORTA.F2 == 0)
 set = -1;
 }
 if(set_count && set)
 {
 switch(set_count)
 {
 case 1:

 hour1= (hour>>4)*10+(hour&0x0F);
 hour1 = hour1 +set;
 hour1 = Binary2BCD(hour1);

 if((hour1 ) >= 0x24)
 hour1 = 0x00;

 write_ds1307(2,hour1);

 break;
 case 2:

 minute1= (minute>>4)*10+(minute&0x0F);
 minute1 = minute1 + set;

 if(minute1 >= 59)
 minute1 = 0;
 if(minute1 <= 0)
 minute1 = 59;

 minute1 = Binary2BCD(minute1);
 write_ds1307(1, minute1);

 break;
 case 3:
 if(abs(set))
 write_ds1307(0,0x00);
 break;
 }
 }
 }



 second = read_ds1307(0);
 minute = read_ds1307(1);
 hour = read_ds1307(2);
 second1= (second>>4)*10+(second&0x0F);
 minute1= (minute>>4)*10+(minute&0x0F);
 hour1= (hour>>4)*10+(hour&0x0F);
 if(hour1==0)
 hour1+=12;
 else if(hour1>=13)
 hour1-=12;
 Count1 = minute1;
 Count2 = hour1;
 count3 = second1;


 DD0 = (Count1)%10;
 display(number[DD0]);
 DD1 = (Count1/10)%10;
 display1(number[DD1]);
 DD2 = (Count2)%10;
 display2(number[DD2]);
 DD3 = (Count2/10)%10;
 if( DD3>0)
 {display3(number[DD3]); }
 else
 {display3(0xFF); }


 DD4= (count3);
 display0(DD4);

 Delay_ms(500);






 }while(1);
 }
