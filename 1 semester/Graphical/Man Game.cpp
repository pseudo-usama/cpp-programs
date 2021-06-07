#include<dos.h>
#include<stdlib.h>
#include<constream.h>
#include<graphics.h>
#include<process.h>

void main()
{
textcolor(0);
clrscr();
int driver,mode;
driver = DETECT;
initgraph(&driver,&mode,"C:\\Turboc3\\BGI");
char key = '\M';
 int x = 0 ,y = 0 ,f1 = 0, f2 = 0,floop = 1,f2loop = 0,h = 0,h2 = 0;
 int b = 100,o = 260; // increacin x , y printing values
 float loop = 0 , m = 0 , m2 = 0;
 float speed = 0;
//////////////////////////////////////////// print  start
setfillstyle(11,2);
bar(20,345,610,380);
delay(555);
line(590,10,590,363); delay(111);  line(610,10,610,363); delay(111);  line(590,341,610,341);   delay(111);
line(590,321,610,321); delay(111); line(590,300,610,300); delay(111); line(590,280,610,280);   delay(111);
line(590,260,610,260); delay(111); line(590,240,610,240); delay(111); line(590,220,610,220);   delay(111);
line(590,200,610,200); delay(111); line(590,180,610,180); delay(111); line(590,160,610,160);   delay(111);
line(590,140,610,140); delay(111); line(590,120,610,120); delay(111); line(590,100,610,100);   delay(111);
line(590,80,610,80);  delay(111);  line(590,60,610,60);   delay(111); line(590,40,610,40);     delay(111);
line(590,20,610,20);
delay(444);
///////////////////////////////////// stairs   Left

line(40,10,40,363);  delay(111); line(20,10,20,363); delay(111);  line(20,341,40,341);         delay(111);
line(20,321,40,321); delay(111); line(20,300,40,300); delay(111); line(20,280,40,280);         delay(111);
line(20,260,40,260); delay(111); line(20,240,40,240); delay(111); line(20,220,40,220);         delay(111);
line(20,200,40,200); delay(111); line(20,180,40,180); delay(111); line(20,160,40,160);         delay(111);
line(20,140,40,140); delay(111); line(20,120,40,120); delay(111); line(20,100,40,100);         delay(111);
line(20,80,40,80);   delay(111); line(20,60,40,60);   delay(111); line(20,40,40,40);           delay(111);
line(20,20,40,20);
delay(444);
////////////////////////////////////////// PIPE
for(int pip = 1 ; pip <= 590 ; pip++)
{
 setfillstyle(1,BLUE);
 bar(20,5,20+pip,8);
 delay(1);
}
/////////////////////////////////////////KEYS
setfillstyle(9,RED);
bar3d(260,180+o,290,200+o,3,3);
settextstyle(2,0,4);
outtextxy(265,185+o,"Left");
delay(444);
bar3d(295,180+o,325,200+o,3,3);
settextstyle(2,0,4);
outtextxy(300,185+o,"DOWN");
delay(444);
bar3d(330,180+o,360,200+o,3,3);
settextstyle(2,0,4);
outtextxy(332,185+o,"RIGHT ");
delay(444);
bar3d(295,157+o,325,175+o,3,3);
settextstyle(2,0,4);
outtextxy(305,160+o,"UP");
settextstyle(8,0,2);
delay(444);
bar3d(400,175+o,450,198+o,3,3);
settextstyle(2,0,4);
outtextxy(400,185+o,"  ENTER ");
delay(444);
settextstyle(2,0,4);
outtextxy(400,175+o," to exit ");
delay(444);
 line(220,10,220,140);
 line(420,10,420,140);
 line(320,+200+10,320,200+140);
 line(520,+200+10,520,200+140);
delay(555);

settextstyle(1,0,6);
outtextxy(60,50,"READY...");
delay(1000);
settextstyle(1,0,6);
outtextxy(60,120,"SET.....");
delay(1000);
settextstyle(1,0,6);
outtextxy(60,190,"GO......");
delay(1000);

////////////////////////////////////print exit

do
{
cleardevice();
setbkcolor(0); //8
/* while(key is not pressed) */               while(!kbhit())
{

clrscr();
speed += 0.0003;
/////////////////////////////////////////////LINE CHALLANGE

 if(loop == 0 && m <= 202 )
      {
       m+=(1+speed);
       m2-=(1+speed);
       if( m >= 202 )
       {
 loop = 1;
       // getch();
       }
      }
   if(loop == 1 && m >= 0 )
      {

       m-=(1+speed);
       m2+=(1+speed);
       if( m <= 0)
       {
 loop = 0;
       }
      }


 line(220,10+m,220,140+m);
 line(420,10+m,420,140+m);
 line(320,+200+10+m2,320,200+140+m2);
 line(520,+200+10+m2,520,200+140+m2);


 if( x >=99 &&x<=137&&y ==0&&m>=96 || x >=99 &&x<=137&&y < -200 && m<=130
  || x >=299 &&x<=337&&y ==0&&m>=96|| x >=299 &&x<=337&&y < -200 && m<=130
  || x >=199 &&x<=237&&y ==0&&m2>=-103|| x >=199 &&x<=237&&y < -200 && m2<=-70
  || x >=399 &&x<=437&&y ==0&&m2>=-103|| x >=399 &&x<=437&&y < -200 && m2<=-70
)



 {
 for(int j=0; j<=30000; j++)
   {
 putpixel(random(640),random(480),4);
 delay(0);
   }
setfillstyle(11,2);
bar(20,345,610,380);

line(590,10,590,363);   line(610,10,610,363);   line(590,341,610,341);
line(590,321,610,321);  line(590,300,610,300);  line(590,280,610,280);
line(590,260,610,260);  line(590,240,610,240);  line(590,220,610,220);
line(590,200,610,200);  line(590,180,610,180);  line(590,160,610,160);
line(590,140,610,140);  line(590,120,610,120);  line(590,100,610,100);
line(590,80,610,80);    line(590,60,610,60);    line(590,40,610,40);
line(590,20,610,20);
///////////////////////////////////// stairs   Left

line(40,10,40,363);   line(20,10,20,363);   line(20,341,40,341);
line(20,321,40,321);  line(20,300,40,300);  line(20,280,40,280);
line(20,260,40,260);  line(20,240,40,240);  line(20,220,40,220);
line(20,200,40,200);  line(20,180,40,180);  line(20,160,40,160);
line(20,140,40,140);  line(20,120,40,120);  line(20,100,40,100);
line(20,80,40,80);    line(20,60,40,60);    line(20,40,40,40);
line(20,20,40,20);
////////////////////////////////////////// PIPE
setfillstyle(1,BLUE);
bar(20,5,610,8);
/////////////////////////////////////////KEYS
setfillstyle(9,RED);
bar3d(260,180+o,290,200+o,3,3);
settextstyle(2,0,4);
outtextxy(265,185+o,"Left");
bar3d(295,180+o,325,200+o,3,3);
settextstyle(2,0,4);
outtextxy(300,185+o,"DOWN");
bar3d(330,180+o,360,200+o,3,3);
settextstyle(2,0,4);
outtextxy(332,185+o,"RIGHT ");
bar3d(295,157+o,325,175+o,3,3);
settextstyle(2,0,4);
outtextxy(305,160+o,"UP");
settextstyle(8,0,2);
bar3d(400,175+o,450,198+o,3,3);
settextstyle(2,0,4);
outtextxy(400,185+o,"  ENTER ");
settextstyle(2,0,4);
outtextxy(400,175+o," to exit ");
////////////////////////////////////

   settextstyle(7,0,7);
   outtextxy(100,150,"GAME OVER");
   settextstyle(7,0,2);
   outtextxy(100,260,"You are dead");
   settextstyle(6,0,3);
   outtextxy(100,290,"Press any key to continue");

   ////////////
setfillstyle(1,BLUE);
bar(20,5,610,8);
setfillstyle(1,6);
circle(100+x,250+b,15);                 //face
floodfill(100+x,250+b,WHITE)   ;
setfillstyle(1,1);
fillellipse(98+x,247+b,2,3);
setfillstyle(1,6);
fillellipse(106+x,233+b,2,3);       //nose
line(99+x,235+b,105+x,230+b);               //nose
line(114+x,244+b,125+x,240+b);                          //nack
line(114+x,254+b,125+x,258+b);                        //nack
setfillstyle(2,1);
fillellipse(148+x,249+b,28,17);
bar(115+x,244+b,125+x,255+b);
ellipse(150+x,249+b,270,90,6,17);                  //pant

line(130+x,248+b,145+x,260+b);    //arm
setfillstyle(1,RED);
circle(147+x,261+b,3);      //hand
floodfill(147+x,261+b,WHITE)   ;
setfillstyle(1,RED);
fillellipse(151+x,264+b,3,1);                   //finger
fillellipse(151+x,262+b,3,1);                  //finger
fillellipse(151+x,260+b,3,1);                  //finger
setfillstyle(1,RED);

line(170+x,248+b,200+x,265+b);
fillellipse(203+x,258+b,2,8)   ;              //legs1
line(175+x,243+b,200+x,238+b);                     //legs2
fillellipse(203+x,230+b,2,8)   ;
loop = 0;m=0;x=0,m2 = 0;
sleep(2);
getch();

}

//////////////////////////////////////////////cHALANGE COMPLEATE



///////////////////////////////////// stairs   RIGHT


setfillstyle(11,2);
bar(20,345,610,380);

line(590,10,590,363);   line(610,10,610,363);   line(590,341,610,341);
line(590,321,610,321);  line(590,300,610,300);  line(590,280,610,280);
line(590,260,610,260);  line(590,240,610,240);  line(590,220,610,220);
line(590,200,610,200);  line(590,180,610,180);  line(590,160,610,160);
line(590,140,610,140);  line(590,120,610,120);  line(590,100,610,100);
line(590,80,610,80);    line(590,60,610,60);    line(590,40,610,40);
line(590,20,610,20);
///////////////////////////////////// stairs   Left

line(40,10,40,363);   line(20,10,20,363);   line(20,341,40,341);
line(20,321,40,321);  line(20,300,40,300);  line(20,280,40,280);
line(20,260,40,260);  line(20,240,40,240);  line(20,220,40,220);
line(20,200,40,200);  line(20,180,40,180);  line(20,160,40,160);
line(20,140,40,140);  line(20,120,40,120);  line(20,100,40,100);
line(20,80,40,80);    line(20,60,40,60);    line(20,40,40,40);
line(20,20,40,20);
////////////////////////////////////////// PIPE
setfillstyle(1,BLUE);
bar(20,5,610,8);
/////////////////////////////////////////KEYS
setfillstyle(9,RED);
bar3d(260,180+o,290,200+o,3,3);
settextstyle(2,0,4);
outtextxy(265,185+o,"Left");
bar3d(295,180+o,325,200+o,3,3);
settextstyle(2,0,4);
outtextxy(300,185+o,"DOWN");
bar3d(330,180+o,360,200+o,3,3);
settextstyle(2,0,4);
outtextxy(332,185+o,"RIGHT ");
bar3d(295,157+o,325,175+o,3,3);
settextstyle(2,0,4);
outtextxy(305,160+o,"UP");
settextstyle(8,0,2);
bar3d(400,175+o,450,198+o,3,3);
settextstyle(2,0,4);
outtextxy(400,185+o,"  ENTER ");
settextstyle(2,0,4);
outtextxy(400,175+o," to exit ");
////////////////////////////////////




if( y <-220 )
{;
y=-219;
h = 0; h2 = 0;}
else if(y > 0 && x >460 )
{y = 0; key = '\K';
h = 0; h2 = 0;}
else if (y > 0 && x <= -39)
{ y = 0; key = '\M';
h = 0; h2 = 0;;}
else if (x <= -39 && y <= -219 && key == '\K')
{key = '\P';
x = -39;}
else if (x >= 469 && y <= -219 && key == '\M')
{key = '\P';}


////////////////////////////////////////// stop at last
 if (x >= 470)
{
 h = 0; h2 = 0;
 x=469;
setfillstyle(1,6);
circle(100+x,250,15);                 //face
floodfill(100+x,250,WHITE)   ;
setfillstyle(1,1);
fillellipse(103+x,247,3,2);               //eye
ellipse(103+x,247,90,89,3,2);
setfillstyle(1,6);
fillellipse(118+x,253,2,3);       //nose
//ellipse(118+x,253,180,20,2,2);
line(115+x,246,120+x,253);               //nose
line(95+x,264,91+x,274);                          //nack
line(104+x,266,110+x,275);                        //nack
setfillstyle(2,1);
fillellipse(100+x,296,17,25);
ellipse(100+x,296,120,50,17,25);                  //body
setfillstyle(2,BLUE);
bar(95+x,266,104+x,276);                            //nack
ellipse(100+x,303,180,360,16,3);                  //pant
line(100+x,277,100+x,293);    //arm
setfillstyle(1,RED);
circle(100+x,295,3);      //hand
floodfill(100+x,295,WHITE)   ;
setfillstyle(1,RED);
ellipse(98+x,299,120,50,1,3);                  //finger
ellipse(101+x,299,120,50,1,3);                  //finger
ellipse(103+x,297,120,50,1,3);                  //finger
line(100+x,322,100+x,360);
setfillstyle(1,RED);
fillellipse(108+x,360,8,2)   ;         //legs1
line(100+x,322,100+x,360);                     //legs2
fillellipse(108+x,360,8,2)   ;
}
//////////////////////////////////////////////////////stop at begning
 if (x <= -40)
{
 x=- 39;
 h = 0; h2 = 0;
 setfillstyle(1,6);
circle(100+x,250,15);                 //face
floodfill(100+x,250,WHITE)   ;
setfillstyle(1,1);
fillellipse(97+x,247,3,2);               //eye
setfillstyle(1,6);
fillellipse(83+x,253,2,3);       //nose
line(85+x,246,80+x,253);               //nose
line(95+x,264,91+x,274);                          //nack
line(104+x,266,110+x,275);                        //nack
setfillstyle(2,1);
fillellipse(100+x,296,17,25);
//ellipse(100+x,296,120,50,17,25);                  //body
setfillstyle(2,BLUE);
bar(95+x,266,104+x,276);                            //nack
ellipse(100+x,303,180,360,16,3);                  //pant
line(100+x,277,100+x,293);    //arm
setfillstyle(1,RED);
circle(100+x,295,3);      //hand
floodfill(100+x,295,WHITE)   ;
setfillstyle(1,RED);
ellipse(98+x,299,120,50,1,3);                  //finger
ellipse(101+x,299,120,50,1,3);                  //finger
ellipse(103+x,297,120,50,1,3);                  //finger
line(100+x,322,100+x,360);
setfillstyle(1,RED);
fillellipse(91+x,360,8,2)   ;         //legs1
line(100+x,322,100+x,360);                     //legs2
fillellipse(91+x,360,8,2)   ;
}
////////////////////////////////////////////// Move towords right from up
/////////////////////////////////////////////////////////////////////////////
else if (y <= -219&& key == '\M' )
{
x++;
if(f1 <=30 && floop == 1 )
{
f1+= 2;
 h++;
}
if(f1 == 20)
{
 floop = 0;}
 if(floop == 0 )
 {f1-=2;
 h--;}
 if(f1 <= -20 )
 {floop = 1;}
// leg second
 if(f2 <=30 && f2loop == 1)
 f2+= 2;
 if(f2 == 20)
 { f2loop = 0;}
 if(f2loop == 0 )
 {f2-=2;}
 if(f2 <= -20 )
 {f2loop = 1;}
setfillstyle(1,6);
circle(100+x,250+y,15);                 //face
floodfill(100+x,250+y,WHITE)   ;
setfillstyle(1,1);
fillellipse(103+x,247+y,3,2);               //eye
setfillstyle(1,6);
fillellipse(118+x,253+y,2,3);       //nose
line(115+x,246+y,120+x,253+y);               //nose
line(95+x,264+y,91+x,274+y);                          //nack
line(104+x,266+y,110+x,275+y);                        //nack
setfillstyle(2,1);
fillellipse(100+x,296+y,17,25);
setfillstyle(2,BLUE);
bar(95+x,266+y,104+x,276+y);                            //nack
ellipse(100+x,303+y,180,360,16,3);                  //pant
line(100+x,277+y,100+x+f1,230+y);    //arm
setfillstyle(1,RED);
circle(100+x+f1,228+y,3);      //hand
floodfill(100+x+f1,228+y,WHITE)   ;
setfillstyle(1,RED);
ellipse(98+x+f1,227+y,0,180,1,3);                  //finger
ellipse(101+x+f1,227+y,0,180,1,3);                  //finger
ellipse(103+x+f1,227+y,0,180,1,3);                  //finger
line(100+x+f2,237+y,100+x+f2,230+y);    //arm   2
setfillstyle(1,RED);
circle(100+x+f2,228+y,3);      //hand  2
floodfill(100+x+f2,228+y,WHITE)   ;
setfillstyle(1,RED);
ellipse(98+x+f2,227+y,0,180,1,3);                  //finger 2
ellipse(101+x+f2,227+y,0,180,1,3);                  //finger 2
ellipse(103+x+f2,227+y,0,180,1,3);                  //finger  2
line(100+x,322+y,100+x+f2,360+y);
setfillstyle(1,RED);
fillellipse(108+x+f2,360+y,8,2)   ;                //legs1
line(100+x,322+y,100+x+f1,360+y);                     //legs2
fillellipse(108+x+f1,360+y,8,2)   ;
}
////////////////////////////////////////////////MOVE TO LEFT FROM UP
else if (y <= -219&& key == '\K' )
{
x--;
if(f1 <=30 && floop == 1 )
{
f1+= 2;
 h++;
}
if(f1 == 20)
{
 floop = 0;}
 if(floop == 0 )
 {f1-=2;
 h--;}
 if(f1 <= -20 )
 {floop = 1;}
// leg second
 if(f2 <=30 && f2loop == 1)
 f2+= 2;
 if(f2 == 20)
 { f2loop = 0;}
 if(f2loop == 0 )
 {f2-=2;}
 if(f2 <= -20 )
 {f2loop = 1;}
setfillstyle(1,6);
circle(100+x,250+y,15);                 //face
floodfill(100+x,250+y,WHITE)   ;
setfillstyle(1,1);
fillellipse(97+x,247+y,3,2);               //eye
setfillstyle(1,6);
fillellipse(83+x,253+y,2,3);       //nose
line(85+x,246+y,80+x,253+y);               //nose
line(95+x,264+y,91+x,274+y);                          //nack
line(104+x,266+y,110+x,275+y);                        //nack
setfillstyle(2,1);
fillellipse(100+x,296+y,17,25);
//ellipse(100+x,296+y,120,50,17,25);                  //body
setfillstyle(2,BLUE);
bar(95+x,266+y,104+x,276+y);                            //nack
ellipse(100+x,303+y,180,360,16,3);                  //pant
line(100+x,277+y,100+x+f1,230+y);    //arm
setfillstyle(1,RED);
circle(100+x+f1,228+y,3);      //hand
floodfill(100+x+f1,228+y,WHITE)   ;
setfillstyle(1,RED);
ellipse(98+x+f1,227+y,0,180,1,3);                  //finger
ellipse(101+x+f1,227+y,0,180,1,3);                  //finger
ellipse(103+x+f1,227+y,0,180,1,3);                  //finger
line(100+x+f2,237+y,100+x+f2,230+y);    //arm   2
setfillstyle(1,RED);
circle(100+x+f2,228+y,3);      //hand  2
floodfill(100+x+f2,228+y,WHITE)   ;
setfillstyle(1,RED);
ellipse(98+x+f2,227+y,0,180,1,3);                  //finger 2
ellipse(101+x+f2,227+y,0,180,1,3);                  //finger 2
ellipse(103+x+f2,227+y,0,180,1,3);                  //finger  2
line(100+x,322+y,100+x+f1,360+y);
setfillstyle(1,RED);
fillellipse(91+x+f1,360+y,8,2)   ;         //legs1
line(100+x,322+y,100+x+f2,360+y);                     //legs2
fillellipse(91+x+f2,360+y,8,2)   ;
}
///////////////////////////////////////////////////// move to right
else if (key == '\M'&& y >= -2)
{x++;
h = 0;
if(f1 <=30 && floop == 1 )
{
f1+= 2;
h++;
}
if(f1 == 20)
{ floop = 0;}
if(floop == 0 )
{f1-=2;
h--;}
if(f1 <= -20 )
{floop = 1;}
if(f2 <=30 && f2loop == 1)
f2+= 2;
if(f2 == 20)
{ f2loop = 0;}
if(f2loop == 0 )
{f2-=2;}
if(f2 <= -20 )
{f2loop = 1;}
setfillstyle(1,6);
circle(100+x,250,15);                 //face
floodfill(100+x,250,WHITE)   ;
setfillstyle(1,1);
fillellipse(103+x,247,3,2);               //eye
setfillstyle(1,6);
fillellipse(118+x,253,2,3);       //nose
line(115+x,246,120+x,253);               //nose
line(95+x,264,91+x,274);                          //nack
line(104+x,266,110+x,275);                        //nack
setfillstyle(2,1);
fillellipse(100+x,296,17,25);
ellipse(100+x,296,120,50,17,25);                  //body
setfillstyle(2,BLUE);
bar(95+x,266,104+x,276);                            //nack
ellipse(100+x,303,180,360,16,3);                  //pant
if(x >= 470 || x <= -40)
{
line(100+x,277,100+x+h,293);    //arm
setfillstyle(1,RED);
circle(100+x+h,295,3);      //hand
floodfill(100+x+h,295,WHITE)   ;
setfillstyle(1,RED);
ellipse(98+x+h,299,120,50,1,3);                  //finger
ellipse(101+x+h,299,120,50,1,3);                  //finger
ellipse(103+x+h,297,120,50,1,3);                  //finger
line(100+x,322,100+x,360);
if(x<=-40)
{
setfillstyle(1,RED);
fillellipse(108+x+f1,360,8,2)   ;         //legs1
line(100+x,322,100+x+f2,360);                     //legs2
fillellipse(108+x+f2,360,8,2)   ;
}
else
{
setfillstyle(1,RED);
fillellipse(108+x,360,8,2)   ;         //legs1
line(100+x,322,100+x,360);                     //legs2
fillellipse(108+x,360,8,2)   ;
}
}
else
{
line(100+x,277,100+x+h,293);    //arm
setfillstyle(1,RED);
circle(100+x+h,295,3);      //hand
floodfill(100+x+h,295,WHITE)   ;
setfillstyle(1,RED);
ellipse(98+x+h,299,120,50,1,3);                  //finger
ellipse(101+x+h,299,120,50,1,3);                  //finger
ellipse(103+x+h,297,120,50,1,3);                  //finger
line(100+x,322,100+x+f1,360);
setfillstyle(1,RED);
fillellipse(108+x+f1,360,8,2)   ;         //legs1
line(100+x,322,100+x+f2,360);                     //legs2
fillellipse(108+x+f2,360,8,2)   ;
}
}
/////////////////////////////////////////// move toords left
else if (key == '\K'&& y >= -2)
{x--;
h = 0;h2 = 0;
if(f1 <=30 && floop == 1 )
{
f1+= 2;
 h++;
}
if(f1 == 20)
{
 floop = 0;}
 if(floop == 0 )
 {f1-=2;
 h--;}
 if(f1 <= -20 )
 {floop = 1;}
// leg second
 if(f2 <=30 && f2loop == 1)
 f2+= 2;
 if(f2 == 20)
 { f2loop = 0;}
 if(f2loop == 0 )
 {f2-=2;}
 if(f2 <= -20 )
 {f2loop = 1;}
setfillstyle(1,6);
circle(100+x,250,15);                 //face
floodfill(100+x,250,WHITE)   ;
setfillstyle(1,1);
fillellipse(97+x,247,3,2);               //eye
setfillstyle(1,6);
fillellipse(83+x,253,2,3);       //nose
line(85+x,246,80+x,253);               //nose
line(95+x,264,91+x,274);                          //nack
line(104+x,266,110+x,275);                        //nack
setfillstyle(2,1);
fillellipse(100+x,296,17,25);
//ellipse(100+x,296,120,50,17,25);                  //body
setfillstyle(2,BLUE);
bar(95+x,266,104+x,276);                            //nack
ellipse(100+x,303,180,360,16,3);                  //pant
if(x >= 470 || x<= -40)
{line(100+x,277,100+x,293);    //arm
setfillstyle(1,RED);
circle(100+x,295,3);      //hand
floodfill(100+x,295,WHITE)   ;
setfillstyle(1,RED);
ellipse(98+x,299,120,50,1,3);                  //finger
ellipse(101+x,299,120,50,1,3);                  //finger
ellipse(103+x,297,120,50,1,3);                  //finger
line(100+x,322,100+x,360);
if(x<=-40)
{
setfillstyle(1,RED);
fillellipse(91+x,360,8,2)   ;         //legs1
line(100+x,322,100+x,360);                     //legs2
fillellipse(91+x,360,8,2)   ;
}
else
{
setfillstyle(1,RED);
fillellipse(108+x,360,8,2)   ;         //legs1
line(100+x,322,100+x,360);                     //legs2
fillellipse(108+x,360,8,2)   ;
}
}
else
{
line(100+x,277,100+x+h,293);    //arm
setfillstyle(1,RED);
circle(100+x+h,295,3);      //hand
floodfill(100+x+h,295,WHITE)   ;
setfillstyle(1,RED);
ellipse(98+x+h,299,120,50,1,3);                  //finger
ellipse(102+x+h,299,120,50,1,3);                  //finger
ellipse(96+x+h,297,120,50,1,3);                  //finger
line(100+x,322,100+x+f1+4,360);
if(x<=-40)
{
setfillstyle(1,RED);
fillellipse(91+x,360,8,2)   ;         //legs1
line(100+x,322,100+x,360);                     //legs2
fillellipse(91+x,360,8,2)   ;
}
else
{
setfillstyle(1,RED);
 fillellipse(91+x+f1+4,360,8,2)   ;         //legs1
 line(100+x,322,100+x+f2+4,360);                     //legs2
 fillellipse(91+x+f2+4,360,8,2)   ;
}
}
}
      /////////////////////////////////////////
      ///////////// FOR UP RIGHT///////////////
      ////////////////////////////////////////

else if(key == '\H' && x >= 468 )
{
y--;
if(f1 <=30 && floop == 1 )
{
f1+= 2;
 h++;
 h2--;
}
if(f1 == 20)
{ floop = 0;}
if(floop == 0 )
{f1-=2;
h--;
h2++;}
if(f1 <= -20 )
{floop = 1;}
if(f2 <=30 && f2loop == 1)
f2+= 2;
if(f2 == 20)
{ f2loop = 0;}
if(f2loop == 0 )
{f2-=2;}
if(f2 <= -20 )
{f2loop = 1;}
setfillstyle(1,6);
circle(100+x,250+y,15);                 //face
floodfill(100+x,250+y,WHITE)   ;
setfillstyle(1,1);
fillellipse(103+x,247+y,3,2);               //eye
//ellipse(103+x,247+y,90,89,3,2);
setfillstyle(1,6);
fillellipse(118+x,253+y,2,3);       //nose
//ellipse(118+x,253+y,180,20,2,2);
line(115+x,246+y,120+x,253+y);               //nose
line(95+x,264+y,91+x,274+y);                          //nack
line(104+x,266+y,110+x,275+y);                        //nack
setfillstyle(2,1);
fillellipse(100+x,296+y,17,25);
ellipse(100+x,296+y,120,50,17,25);                  //body
setfillstyle(2,BLUE);
bar(95+x,266+y,104+x,276+y);                            //nack
ellipse(100+x,303+y,180,360,16,3);                  //pant
line(100+x,277+y,125+x,272+y+h);    //arm
line(125+x,272+y+h,125+x,255+y+h);    //arm up
setfillstyle(1,RED);
circle(125+x,253+y+h,3);      //hand
floodfill(125+x,253+y+h,WHITE)   ;
ellipse(123+x,250+y+h,0,180,1,3);                  //finger
ellipse(126+x,250+y+h,0,180,1,3);                  //finger
ellipse(128+x,250+y+h,0,180,1,3);                  //finger
line(100+x,277+y,125+x,272+y+h2);    //arm 2
line(125+x,272+y+h2,125+x,255+y+h2);    //arm up2
setfillstyle(1,RED);
circle(125+x,253+y+h2,3);      //hand2
floodfill(125+x,253+y+h2,WHITE)   ;
ellipse(123+x,250+y+h2,0,180,1,3);                  //finger 2
ellipse(126+x,250+y+h2,0,180,1,3);                  //finger 2
ellipse(128+x,250+y+h2,0,180,1,3);                  //finger 2
line(100+x,322+y,120+x,322+y+h);            // leg 1
line(120+x,322+y+h,125+x,339+y+h);
fillellipse(131+x,339+y+h,8,2)   ;         // foot 1
line(100+x,322+y,120+x,322+y+h2);            // leg 2
line(120+x,322+y+h2,125+x,339+y+h2);
fillellipse(131+x,339+y+h2,8,2)   ;         // foot 2
}
///////////////////////////////////////////////////// to right down

else if(key == '\P' && x >= 468 )
{
y++;
if(f1 <=30 && floop == 1 )
{
f1+= 2;
 h++;
 h2--;
}
if(f1 == 20)
{ floop = 0;}
if(floop == 0 )
{f1-=2;
h--;
h2++;}
if(f1 <= -20 )
{floop = 1;}
if(f2 <=30 && f2loop == 1)
f2+= 2;
if(f2 == 20)
{ f2loop = 0;}
if(f2loop == 0 )
{f2-=2;}
if(f2 <= -20 )
{f2loop = 1;}
setfillstyle(1,6);
circle(100+x,250+y,15);                 //face
floodfill(100+x,250+y,WHITE)   ;
setfillstyle(1,1);
fillellipse(103+x,247+y,3,2);               //eye
//ellipse(103+x,247+y,90,89,3,2);
setfillstyle(1,6);
fillellipse(118+x,253+y,2,3);       //nose
//ellipse(118+x,253+y,180,20,2,2);
line(115+x,246+y,120+x,253+y);               //nose
line(95+x,264+y,91+x,274+y);                          //nack
line(104+x,266+y,110+x,275+y);                        //nack
setfillstyle(2,1);
fillellipse(100+x,296+y,17,25);
//ellipse(100+x,296+y,120,50,17,25);                  //body
setfillstyle(2,BLUE);
bar(95+x,266+y,104+x,276+y);                            //nack
ellipse(100+x,303+y,180,360,16,3);                  //pant
line(100+x,277+y,125+x,272+y+h);    //arm
line(125+x,272+y+h,125+x,255+y+h);    //arm up
setfillstyle(1,RED);
circle(125+x,253+y+h,3);      //hand
floodfill(125+x,253+y+h,WHITE)   ;
ellipse(123+x,250+y+h,0,180,1,3);                  //finger
ellipse(126+x,250+y+h,0,180,1,3);                  //finger
ellipse(128+x,250+y+h,0,180,1,3);                  //finger
line(100+x,277+y,125+x,272+y+h2);    //arm 2
line(125+x,272+y+h2,125+x,255+y+h2);    //arm up2
setfillstyle(1,RED);
circle(125+x,253+y+h2,3);      //hand2
floodfill(125+x,253+y+h2,WHITE)   ;
ellipse(123+x,250+y+h2,0,180,1,3);                  //finger 2
ellipse(126+x,250+y+h2,0,180,1,3);                  //finger 2
ellipse(128+x,250+y+h2,0,180,1,3);                  //finger 2
line(100+x,322+y,120+x,322+y+h);            // leg 1
line(120+x,322+y+h,125+x,339+y+h);
fillellipse(131+x,339+y+h,8,2)   ;         // foot 1
line(100+x,322+y,120+x,322+y+h2);            // leg 2
line(120+x,322+y+h2,125+x,339+y+h2);
fillellipse(131+x,339+y+h2,8,2)   ;         // foot 2
}
///////////////////////////////////////////////////////////////
///////////////////////////////////// FOR left up

else if(key == '\H' && x <= -39 )
{
y--;
if(f1 <=30 && floop == 1 )
{
f1+= 2;
 h++;
 h2--;
}
if(f1 == 20)
{ floop = 0;}
if(floop == 0 )
{f1-=2;
h--;
h2++;}
if(f1 <= -20 )
{floop = 1;}
if(f2 <=30 && f2loop == 1)
f2+= 2;
if(f2 == 20)
{ f2loop = 0;}
if(f2loop == 0 )
{f2-=2;}
if(f2 <= -20 )
{f2loop = 1;}
setfillstyle(1,6);
circle(100+x,250+y,15);                 //face
floodfill(100+x,250+y,WHITE)   ;
setfillstyle(1,1);
fillellipse(97+x,247+y,3,2);               //eye
setfillstyle(1,6);
fillellipse(83+x,253+y,2,3);       //nose
line(85+x,246+y,80+x,253+y);               //nose
line(95+x,264+y,91+x,274+y);                          //nack
line(104+x,266+y,110+x,275+y);                        //nack
setfillstyle(2,1);
fillellipse(100+x,296+y,17,25);
//ellipse(100+x,296+y,120,50,17,25);                  //body
setfillstyle(2,BLUE);
bar(95+x,266+y,104+x,276+y);                            //nack
ellipse(100+x,303+y,180,360,16,3);                  //pant
line(100+x,277+y,75+x,272+y+h);    //arm
line(75+x,272+y+h,75+x,255+y+h);    //arm up
setfillstyle(1,RED);
circle(75+x,253+y+h,3);      //hand
floodfill(75+x,253+y+h,WHITE)   ;
ellipse(72+x,250+y+h,0,180,1,3);                  //finger
ellipse(74+x,250+y+h,0,180,1,3);                  //finger
ellipse(76+x,250+y+h,0,180,1,3);
line(100+x,277+y,75+x,272+y+h2);    //arm 2
line(75+x,272+y+h2,75+x,255+y+h2);    //arm up2
setfillstyle(1,RED);
circle(75+x,253+y+h2,3);      //hand2
floodfill(75+x,253+y+h2,WHITE)   ;
ellipse(72+x,250+y+h2,0,180,1,3);                  //finger 2
ellipse(74+x,250+y+h2,0,180,1,3);                  //finger 2
ellipse(76+x,250+y+h2,0,180,1,3);                  //finger 2
line(100+x,322+y,80+x,322+y+h);            // leg 1
line(80+x,322+y+h,75+x,339+y+h);
fillellipse(68+x,339+y+h,8,2)   ;         // foot 1
line(100+x,322+y,80+x,322+y+h2);            // leg 1
line(80+x,322+y+h2,75+x,339+y+h2);
fillellipse(68+x,339+y+h2,8,2)   ;         // foot 1
}
////////////////////////////////////////////////// down to left
else if(key == '\P' && x <= -39 )
{
y++;
if(f1 <=30 && floop == 1 )
{
f1+= 2;
 h++;
 h2--;
}
if(f1 == 20)
{ floop = 0;}
if(floop == 0 )
{f1-=2;
h--;
h2++;}
if(f1 <= -20 )
{floop = 1;}
if(f2 <=30 && f2loop == 1)
f2+= 2;
if(f2 == 20)
{ f2loop = 0;}
if(f2loop == 0 )
{f2-=2;}
if(f2 <= -20 )
{f2loop = 1;}
setfillstyle(1,6);
circle(100+x,250+y,15);                 //face
floodfill(100+x,250+y,WHITE)   ;
setfillstyle(1,1);
fillellipse(97+x,247+y,3,2);               //eye
setfillstyle(1,6);
fillellipse(83+x,253+y,2,3);       //nose
line(85+x,246+y,80+x,253+y);               //nose
line(95+x,264+y,91+x,274+y);                          //nack
line(104+x,266+y,110+x,275+y);                        //nack
setfillstyle(2,1);
fillellipse(100+x,296+y,17,25);
//ellipse(100+x,296+y,120,50,17,25);                  //body
setfillstyle(2,BLUE);
bar(95+x,266+y,104+x,276+y);                            //nack
ellipse(100+x,303+y,180,360,16,3);                  //pant
line(100+x,277+y,75+x,272+y+h);    //arm
line(75+x,272+y+h,75+x,255+y+h);    //arm up
setfillstyle(1,RED);
circle(75+x,253+y+h,3);      //hand
floodfill(75+x,253+y+h,WHITE)   ;
ellipse(72+x,250+y+h,0,180,1,3);                  //finger
ellipse(74+x,250+y+h,0,180,1,3);                  //finger
ellipse(76+x,250+y+h,0,180,1,3);
line(100+x,277+y,75+x,272+y+h2);    //arm 2
line(75+x,272+y+h2,75+x,255+y+h2);    //arm up2
setfillstyle(1,RED);
circle(75+x,253+y+h2,3);      //hand2
floodfill(75+x,253+y+h2,WHITE)   ;
ellipse(72+x,250+y+h2,0,180,1,3);                  //finger 2
ellipse(74+x,250+y+h2,0,180,1,3);                  //finger 2
ellipse(76+x,250+y+h2,0,180,1,3);                  //finger 2
line(100+x,322+y,80+x,322+y+h);            // leg 1
line(80+x,322+y+h,75+x,339+y+h);
fillellipse(68+x,339+y+h,8,2)   ;         // foot 1
line(100+x,322+y,80+x,322+y+h2);            // leg 1
line(80+x,322+y+h2,75+x,339+y+h2);
fillellipse(68+x,339+y+h2,8,2)   ;         // foot 1
}
////////////////////////////////// stop at up right
else if (key == '\M'&& y < -2 && x >460)
{
setfillstyle(1,6);
circle(100+x,250+y,15);                 //face
floodfill(100+x,250+y,WHITE)   ;
setfillstyle(1,1);
fillellipse(103+x,247+y,3,2);               //eye
ellipse(103+x,247+y,90,89,3,2);
setfillstyle(1,6);
fillellipse(118+x,253+y,2,3);       //nose
//ellipse(118+x,253+y,180,20,2,2);
line(115+x,246+y,120+x,253+y);               //nose
line(95+x,264+y,91+x,274+y);                          //nack
line(104+x,266+y,110+x,275+y);                        //nack
setfillstyle(2,1);
fillellipse(100+x,296+y,17,25);
//ellipse(100+x,296+y,120,50,17,25);                  //body
setfillstyle(2,BLUE);
bar(95+x,266+y,104+x,276+y);                            //nack
ellipse(100+x,303+y,180,360,16,3);                  //pant
line(100+x,277+y,125+x,272+y+h);    //arm
line(125+x,272+y+h,125+x,255+y+h);    //arm up
setfillstyle(1,RED);
circle(125+x,253+y+h,3);      //hand
floodfill(125+x,253+y+h,WHITE)   ;
ellipse(123+x,250+y+h,0,180,1,3);                  //finger
ellipse(126+x,250+y+h,0,180,1,3);                  //finger
ellipse(128+x,250+y+h,0,180,1,3);                  //finger
line(100+x,277+y,125+x,272+y+h2);    //arm 2
line(125+x,272+y+h2,125+x,255+y+h2);    //arm up2
setfillstyle(1,RED);
circle(125+x,253+y+h2,3);      //hand2
floodfill(125+x,253+y+h2,WHITE)   ;
ellipse(123+x,250+y+h2,0,180,1,3);                  //finger 2
ellipse(126+x,250+y+h2,0,180,1,3);                  //finger 2
ellipse(128+x,250+y+h2,0,180,1,3);                  //finger 2
line(100+x,322+y,120+x,322+y+h);            // leg 1
line(120+x,322+y+h,125+x,339+y+h);
fillellipse(131+x,339+y+h,8,2)   ;         // foot 1
line(100+x,322+y,120+x,322+y+h2);            // leg 2
line(120+x,322+y+h2,125+x,339+y+h2);
fillellipse(131+x,339+y+h2,8,2)   ;         // foot 2
}
/////////////////////////////////// stop at left
else if ( key == '\M'||'\K'&& y < -2 && x < -38)
{
setfillstyle(1,6);
circle(100+x,250+y,15);                 //face
floodfill(100+x,250+y,WHITE)   ;
setfillstyle(1,1);
fillellipse(97+x,247+y,3,2);               //eye
setfillstyle(1,6);
fillellipse(83+x,253+y,2,3);       //nose
line(85+x,246+y,80+x,253+y);               //nose
line(95+x,264+y,91+x,274+y);                          //nack
line(104+x,266+y,110+x,275+y);                        //nack
setfillstyle(2,1);
fillellipse(100+x,296+y,17,25);
setfillstyle(2,BLUE);
bar(95+x,266+y,104+x,276+y);                            //nack
ellipse(100+x,303+y,180,360,16,3);                  //pant
line(100+x,277+y,75+x,272+y+h);    //arm
line(75+x,272+y+h,75+x,255+y+h);    //arm up
setfillstyle(1,RED);
circle(75+x,253+y+h,3);      //hand
floodfill(75+x,253+y+h,WHITE)   ;
ellipse(72+x,250+y+h,0,180,1,3);                  //finger
ellipse(74+x,250+y+h,0,180,1,3);                  //finger
ellipse(76+x,250+y+h,0,180,1,3);
line(100+x,277+y,75+x,272+y+h2);    //arm 2
line(75+x,272+y+h2,75+x,255+y+h2);    //arm up2
setfillstyle(1,RED);
circle(75+x,253+y+h2,3);      //hand2
floodfill(75+x,253+y+h2,WHITE)   ;
ellipse(72+x,250+y+h2,0,180,1,3);                  //finger 2
ellipse(74+x,250+y+h2,0,180,1,3);                  //finger 2
ellipse(76+x,250+y+h2,0,180,1,3);                  //finger 2
line(100+x,322+y,80+x,322+y+h);            // leg 1
line(80+x,322+y+h,75+x,339+y+h);
fillellipse(68+x,339+y+h,8,2)   ;         // foot 1
line(100+x,322+y,80+x,322+y+h2);            // leg 1
line(80+x,322+y+h2,75+x,339+y+h2);
fillellipse(68+x,339+y+h2,8,2)   ;         // foot 1
}

////////////////////////////////         kill       //////////////

else if(key == '\P' && x<= 468 && x >= -38 && y <= -219)
{

for (;y<= 0;y++)
{
clrscr();
setfillstyle(11,2);
bar(20,345,610,380);
line(590,10,590,363);   line(610,10,610,363);   line(590,341,610,341);
line(590,321,610,321);  line(590,300,610,300);  line(590,280,610,280);
line(590,260,610,260);  line(590,240,610,240);  line(590,220,610,220);
line(590,200,610,200);  line(590,180,610,180);  line(590,160,610,160);
line(590,140,610,140);  line(590,120,610,120);  line(590,100,610,100);
line(590,80,610,80);    line(590,60,610,60);    line(590,40,610,40);
line(590,20,610,20);
///////////////////////////////////// stairs   Left

line(40,10,40,363);   line(20,10,20,363);   line(20,341,40,341);
line(20,321,40,321);  line(20,300,40,300);  line(20,280,40,280);
line(20,260,40,260);  line(20,240,40,240);  line(20,220,40,220);
line(20,200,40,200);  line(20,180,40,180);  line(20,160,40,160);
line(20,140,40,140);  line(20,120,40,120);  line(20,100,40,100);
line(20,80,40,80);    line(20,60,40,60);    line(20,40,40,40);
line(20,20,40,20);
////////////////////////////////////////// PIPE
setfillstyle(1,BLUE);
/////////////////////////////////////////falling from pime itself
bar(20,5,610,8);
setfillstyle(1,6);
circle(100+x,250+y,15);                 //face
floodfill(100+x,250+y,WHITE)   ;
setfillstyle(1,1);
fillellipse(103+x,247+y,3,2);               //eye
ellipse(103+x,247+y,90,89,3,2);
setfillstyle(1,6);
fillellipse(118+x,253+y,2,3);       //nose
ellipse(118+x,253+y,180,20,2,2);
line(115+x,246+y,120+x,253+y);               //nose
line(95+x,264+y,91+x,274+y);                          //nack
line(104+x,266+y,110+x,275+y);                        //nack
setfillstyle(2,1);
fillellipse(100+x,296+y,17,25);
ellipse(100+x,296+y,120,50,17,25);                  //body
setfillstyle(2,BLUE);
bar(95+x,266+y,104+x,276+y);                            //nack
ellipse(100+x,303+y,180,360,16,3);                  //pant
line(100+x,277+y,100+x+f1,230+y);    //arm
setfillstyle(1,RED);
circle(100+x+f1,228+y,3);      //hand
floodfill(100+x+f1,228+y,WHITE)   ;
setfillstyle(1,RED);
ellipse(98+x+f1,227+y,0,180,1,3);                  //finger
ellipse(101+x+f1,227+y,0,180,1,3);                  //finger
ellipse(103+x+f1,227+y,0,180,1,3);                  //finger
line(100+x+f2,237+y,100+x+f2,230+y);    //arm   2
setfillstyle(1,RED);
circle(100+x+f2,228+y,3);      //hand  2
floodfill(100+x+f2,228+y,WHITE)   ;
setfillstyle(1,RED);
ellipse(98+x+f2,227+y,0,180,1,3);                  //finger 2
ellipse(101+x+f2,227+y,0,180,1,3);                  //finger 2
ellipse(103+x+f2,227+y,0,180,1,3);                  //finger  2
line(100+x,322+y,100+x,360+y);
setfillstyle(1,RED);
fillellipse(108+x,360+y,8,2)   ;         //legs1
line(100+x,322+y,100+x,360+y);                     //legs2
fillellipse(108+x,360+y,8,2)   ;
delay(1);
}
///////////////////                DEAD MAN

clrscr();
setfillstyle(11,2);
bar(20,345,610,380);

line(590,10,590,363);   line(610,10,610,363);   line(590,341,610,341);
line(590,321,610,321);  line(590,300,610,300);  line(590,280,610,280);
line(590,260,610,260);  line(590,240,610,240);  line(590,220,610,220);
line(590,200,610,200);  line(590,180,610,180);  line(590,160,610,160);
line(590,140,610,140);  line(590,120,610,120);  line(590,100,610,100);
line(590,80,610,80);    line(590,60,610,60);    line(590,40,610,40);
line(590,20,610,20);
///////////////////////////////////// stairs   Left

line(40,10,40,363);   line(20,10,20,363);   line(20,341,40,341);
line(20,321,40,321);  line(20,300,40,300);  line(20,280,40,280);
line(20,260,40,260);  line(20,240,40,240);  line(20,220,40,220);
line(20,200,40,200);  line(20,180,40,180);  line(20,160,40,160);
line(20,140,40,140);  line(20,120,40,120);  line(20,100,40,100);
line(20,80,40,80);    line(20,60,40,60);    line(20,40,40,40);
line(20,20,40,20);
////////////////////////////////////////// PIPE
/////////////////////////////////                 fall

setfillstyle(1,BLUE);
bar(20,5,610,8);
setfillstyle(1,6);
circle(100+x,250+b,15);                 //face
floodfill(100+x,250+b,WHITE)   ;
setfillstyle(1,1);
fillellipse(98+x,247+b,2,3);
setfillstyle(1,6);
fillellipse(106+x,233+b,2,3);       //nose
line(99+x,235+b,105+x,230+b);               //nose
line(114+x,244+b,125+x,240+b);                          //nack
line(114+x,254+b,125+x,258+b);                        //nack
setfillstyle(2,1);
fillellipse(148+x,249+b,28,17);
bar(115+x,244+b,125+x,255+b);
ellipse(150+x,249+b,270,90,6,17);                  //pant

line(130+x,248+b,145+x,260+b);    //arm
setfillstyle(1,RED);
circle(147+x,261+b,3);      //hand
floodfill(147+x,261+b,WHITE)   ;
setfillstyle(1,RED);
fillellipse(151+x,264+b,3,1);                   //finger
fillellipse(151+x,262+b,3,1);                  //finger
fillellipse(151+x,260+b,3,1);                  //finger
setfillstyle(1,RED);

line(170+x,248+b,200+x,265+b);
fillellipse(203+x,258+b,2,8)   ;              //legs1
line(175+x,243+b,200+x,238+b);                     //legs2
fillellipse(203+x,230+b,2,8)   ;

for(int j=0; j<=30000; j++)
   {
 putpixel(random(640),random(480),4);
 delay(0);

   }
   nosound();
   settextstyle(7,0,7);
   outtextxy(100,150,"GAME OVER");
   settextstyle(7,0,2);
   outtextxy(100,260,"You are dead");
   settextstyle(6,0,3);
   outtextxy(100,290,"Press any key to continue");

    x=- 39;
    h = 0; h2 = 0;     // start from begning
getch();
break;
}
/////////////////////////////////////////////// kill end

else
{ key = '\K';}
/////////////// end of do while loop (while key is ton hit)


delay(5);
}
key = getche();
}while(key != '\r');
getch();
}