#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <iostream.h>

void background (void);
void button (void);
//LOGO
void logo (void)
{

    int i;

   setfillstyle(10,10);
   bar(20,20,getmaxx()-20,getmaxy()-20);
   for (i=0;i<=15;i=i+2)
   {
   setcolor(i);
   rectangle(i,i,getmaxx()-i,getmaxy()-i);
   }


    for(i=0;i<116;i++)
   {
    setcolor(RED);
    line(32,27+i,45+1,27+i);
    delay(8);
   }
   for(i=0;i<=68;i++)
   {
    line(32+i,27+102,32+i,27+116);
    delay(8);

   }
   setcolor(WHITE);
   settextstyle(3,HORIZ_DIR,9);
   outtextxy(130,50,"i");//190
   delay(150);
   outtextxy(159,50,"b");
   delay(150);
   outtextxy(219,50,"r");
   delay(150);
   outtextxy(260,50,"a");
   delay(150);
   outtextxy(317,50,"r");
   delay(150);
   outtextxy(359,50,"y");
   delay(150);

   setfillstyle(1,GREEN);
   for(i=116;i>=0;i--)
   {

    bar(49,162+i,32,162+i);
    delay(8);
   }

   for(i=0;i<=106;i++)
   {
    bar(42+i/4,162+10+i,40+17+i/4,162+i);
    delay(8);
    }
    for(i=0;i<=106;i++)
   {
    bar(42+17+10+i/4,162+106+10-i,40+17+10+17+i/4,162+106-i);
    delay(8);
    }
   for(i=0;i<=116;i++)
   {
    bar(104,162+i,121,162+i);
    delay(8);
    }

   setcolor(WHITE);
   outtextxy(140 ,180,"a");
   delay(150);
   outtextxy(194 ,180,"n");
   delay(150);
   outtextxy(245 ,180,"a");
   delay(150);
   outtextxy(299 ,180,"g");
   delay(150);
   outtextxy(353 ,180,"e");
   delay(150);
   outtextxy(404 ,180,"m");
   delay(150);
   outtextxy(488 ,180,"e");
   delay(150);
   outtextxy(539 ,180,"n");
   delay(150);
   outtextxy(590 ,180,"t");

   //SYSTEM

   setcolor(YELLOW);
   for(i=0;i<=20;i++)
   {
   setcolor(YELLOW);
    arc(63,333,0,270,35-i);
    arc(63,384,180,450,35-20+i);
    delay(50);
   }
   setcolor(WHITE);
   outtextxy(120 ,290,"y");
   delay(150);
   outtextxy(187 ,290,"s");
   delay(150);
   outtextxy(255 ,290,"t");
   delay(150);
   outtextxy(305 ,290,"e");
   delay(150);
   outtextxy(375 ,290,"m");
}

//BUTTON
void button(int x1,int y1,int x2,int y2)
	{
	setfillstyle(9,8);        //7  8 color LIGHT WHITE
	bar (x1,y1,x2,y2);
	setcolor (7);
	rectangle(x1,y1,x2,y2);
	setcolor(WHITE);
	}
//PRESS
void press (int x1,int y1,int x2,int y2)
	{
		setcolor (8);
		setfillstyle(9,7);
		bar (x1,y1,x2,y2);
		line(x1,y1,x2,y1);
		line(x1,y1,x1,y2);
		line(x1,y2,x2,y2);
		line(x2,y2,x2,y1);
		setcolor(WHITE);
	}
void button2(int x1,int y1,int x2,int y2)
{
		setcolor(7);
		setfillstyle(9,8);
		line(x1,y1,x2,y1);
		line(x1,y1,x1,y2);
		line(x1,y2,x2,y2);
		line(x2,y2,x2,y1);
		setcolor(WHITE);

	}
//LODOING
void loading (void)
{
	outtextxy(100,270,"Loading . . .");
	rectangle (100,300,510,350);
	delay (1000);
	for (int i=105; i <=505; i++)
	{
	setcolor(GREEN);
	if (i % 10 == 0)
		delay (20);
	if ( i % 50 == 0)
		delay (50);
	if (i % 100 == 0)
		delay (1000);
	line (i,305,i,345);

	   }
	   background ();
}
void background(void)
       {
       cleardevice ();
       int maxx, maxy,i;
       maxx= getmaxx ();
       maxy = getmaxy ();
	for(i=0;i<=10;i++)
	{
	setfillstyle(i,RED);
	bar(i*6,0,maxx-i*6,maxy);
	}
	setfillstyle(1,BLUE);
	bar(13*6,0,maxx-13*6,maxy);
	setfillstyle(11,RED);
	bar(90,0,maxx-90,90);
	setcolor(WHITE);
	settextstyle(7,HORIZ_DIR,3);
	outtextxy(110,20,"Library Management System . . .");
	line(110,60,maxx-140,60);
	//BUTTON
	setfillstyle(10,LIGHTGREEN);
	bar(90,90,maxx-90,315+45+20);
	//HINT
	setfillstyle(11 ,BLUE);
	bar(90,315+45+20,maxx-90,345+45+20);
	//FOOTER
	setfillstyle(11 ,0);
	bar(90,345+45+20,maxx-90,maxy);

	settextstyle(2,HORIZ_DIR,5);
	outtextxy(100,410,"Programming Fundametal Project:");
	settextstyle(3,HORIZ_DIR,3);
	outtextxy(125,430,"Submitted To : Mr.Mohsin Riaz");
}
void login (void)
{
   int midx;
   midx= getmaxx() / 2;
   setfillstyle(11, 4);
   button(midx-60,120,midx+65,180);
   settextstyle(10,HORIZ_DIR,3);
   outtextxy(midx-45,120,"LOGIN");
   line(midx-45,170,midx-25,170);

   button(midx-70,190,midx+80,250);
   settextstyle(4,HORIZ_DIR,4);
   outtextxy(midx-65,195,"About Us");
   line(midx-65,235,midx-40,235);

   button(midx-60,260,midx+65,320);
   settextstyle(4,HORIZ_DIR,5);
   outtextxy(midx-35,260,"Exit");
   line(midx-35,310,midx-10,310);

   settextstyle(5,HORIZ_DIR,1);
   outtextxy(100,375,"Press Underline character . . .");
  }
void LOGIN();
void pass(void)
{
	int midx;
	midx = getmaxx() / 2;
	press(midx-60,120,midx+65,180);
	settextstyle(10,HORIZ_DIR,3);
	outtextxy(midx-45,120,"LOGIN");
	delay(800);
	login();
	delay(400);
	background ();

	settextstyle(3,HORIZ_DIR,2);
	outtextxy(130,125,"Enter Password to Login . . .");
	settextstyle (3,HORIZ_DIR,3);

	outtextxy (225,175,"Password : ");
	bar(235,205,410,225);
	settextstyle(2,0,6);
	outtextxy (100,390,"Password = 1234 ");
	int pin;
	window(38,14,80,25);
	textcolor(WHITE);
	textbackground(WHITE);
	cin >>pin;
	loading ();
	if (pin == 1234)
	 {
	 LOGIN();
	}
}
void LOGIN()
{
 background();
	 settextstyle(5,HORIZ_DIR,1);
	 outtextxy (100,375,"Prees Underline Character . . .");
       //Button

	setcolor (WHITE);
	settextstyle(6,HORIZ_DIR,4);

	button(100,100,240,155);
	outtextxy(110,100,"Add New");
	line (110,140,125,140);

	button(250,175,390,230);
	outtextxy(280,175,"Search");
	line(280,215,295,215);

	button(400,100,540,155);
	outtextxy(425,100,"Remove");
	line(425,140,440,140);

	button(100,250,240,305);
	outtextxy(130,250,"Modify");
	line(130,290,145,290);

	button(400,250,540,305);
	outtextxy(445,250,"List");
	line(445,290,460,290);

	button(250,320,390,375);
	outtextxy(295,320,"Exit");
	line(295,360,310,360);

}
void book(void)
{
	 settextstyle(3,HORIZ_DIR,1);
	 setfillstyle(9,7);
	 bar(110,140,270,170);
	 outtextxy(145,140,"Book ID : ");
	 button(280,140,500,170);

	 setfillstyle(9,7);
	 bar(110,180,270,210);
	 outtextxy(135,180,"Book Name : ");
	 button(280,180,500,210);

	 setfillstyle(9,7);
	 bar(110,220,270,250);
	 outtextxy(125,220,"Arthur Name : ");
	 button(280,220,500,250);

	 setfillstyle(9,7);
	 bar(110,260,270,290);
	 outtextxy(135,260,"Categorize : ");
	 button(280,260,500,290);

	 setfillstyle(9,7);
	 bar(110,300,270,330);
	 outtextxy(145,300,"Rank No : ");
	 button(280,300,500,330);

}
void exit ()
{
		setfillstyle(1,BLACK);
		bar(90,90,getmaxx()-90,315+45+20);
		settextstyle(3,0,1);
		outtextxy(100,100,"Programing Fundamental Project:");
		outtextxy(100,135,"Writen By:");
		outtextxy(130,165,"Gulfam Sidhu  17114119-030");
		outtextxy(130,190,"Areej Fatima  17114119-047");
		outtextxy(130,215,"Saba Aziz     17114119-052");
		outtextxy(130,240,"Hina Mansha   17114119-050");
		outtextxy(130,265,"Laiba         17114119-051");
		outtextxy(130,290,"Ayesha Bibi   17114119-036");
	      }

//STRUCTURE


struct bk
{
	int id;
	char bname[25];
	char aname[20];
	char cate[25];
	int rankno;
};


int main(void)
{

   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int midx, midy, i;

   /* initialize graphics and local
      variables */
   initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error
       occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error
		  code */
   }
   midx = getmaxx() / 2;
   midy = getmaxy() /2;
   //logo();
   //delay(1000);
   background();
   bk b[100];
   //Login Button.
   login () ;


   //LOGIN ////
   char get  = getch ();
   switch (get)
   {
   case 'l':
   case 'L':
   {
       //pass();

	LOGIN();
	get = getch ();
	switch (get)
	{
	case 'A':
	case 'a':
	{
	press(100,100,240,155);
	outtextxy(110,100,"Add New");
	line (110,140,125,140);
	delay(1000);
	button(100,100,240,155);
	outtextxy(110,100,"Add New");
	line (110,140,125,140);
	delay(500);
	 background ();
	 setfillstyle(10,GREEN);
	 bar(90,90,getmaxx()-90,315+45+20);
	 setcolor(WHITE);
	 settextstyle(6,HORIZ_DIR,1);
	 outtextxy(245,100,"* * Add New Book * *");
	 line(250,130,400,130);
	 book();
	 window(38,10.5,80,25);
	 cin>>b[0].id;
	 window(38,13,80,25);
	 cin>>b[0].bname;
	 window(38,15,80,25);
	 cin>>b[0].aname;
	 window(38,18,80,25);
	 cin>>b[0].cate;
	 window(38,20,80,25);
	 cin>>b[0].rankno;


	 break;
	}
	case 's':
	case 'S':
	{
	press(250,175,390,230);
	outtextxy(280,175,"Search");
	line(280,215,295,215);
	delay(1000);
	button(250,175,390,230);
	outtextxy(280,175,"Search");
	line(280,215,295,215);
	delay(500);
	background();
	setfillstyle(9,7);
	bar(125,100,230,130);
	button(240,100,400,130);
	settextstyle(6,HORIZ_DIR,1);
	outtextxy(130,100,"SEACH by ID:");
	book();

	 break;
	}
	case 'r':
	case 'R':
	{
	press(400,100,540,155);
	outtextxy(425,100,"Remove");
	line(425,140,440,140);
	delay(1000);
	button(400,100,540,155);
	outtextxy(425,100,"Remove");
	line(425,140,440,140);
	delay(500);
	background();
	setfillstyle(9,7);
	bar(125,100,240,130);
	button(250,100,410,130);
	settextstyle(6,HORIZ_DIR,1);
	outtextxy(130,100,"REMOVE By ID:");
	book();


	 break;
	}
	case 'M':
	case 'm':
	{
	press(100,250,240,305);
	outtextxy(130,250,"Modify");
	line(130,290,145,290);
	delay(1000);
	button(100,250,240,305);
	outtextxy(130,250,"Modify");
	line(130,290,145,290);
	delay(500);
	background();
	setfillstyle(9,7);
	bar(125,100,230,130);
	button(240,100,400,130);
	settextstyle(6,HORIZ_DIR,1);
	outtextxy(130,100,"Modify by ID:");

	 break;
	}
	case 'L':
	case 'l':
	{
		break;
	}
	case 'e':
	case 'E':
	{
	press(250,320,390,375);
	outtextxy(295,320,"Exit");
	line(295,360,310,360);
	delay(1000);
	button(250,320,390,375);
	outtextxy(295,320,"Exit");
	line(295,360,310,360);
	delay(500);
	background();
	exit();
	delay(1500);

	 break;
	} //Case E: close

       }//SWITCH CLOSE

	break ;
     } //Case L: close
     case 'E':
     case 'e':
    //else if (login == 'A'|| login == 'a')
       {
	     press(midx-60,260,midx+65,320);
	     settextstyle(4,HORIZ_DIR,5);
	     outtextxy(midx-35,260,"Exit");
	     line(midx-35,310,midx-10,310);
	     delay(1000);
	     button(midx-60,260,midx+65,320);
	     settextstyle(4,HORIZ_DIR,5);
	     outtextxy(midx-35,260,"Exit");
	     line(midx-35,310,midx-10,310);
	     delay(1000);
	     background();
	     exit();
	     break;
	}
     case  'A':
     case 'a' :
	{
	     press(midx-70,190,midx+80,250);
	     settextstyle(4,HORIZ_DIR,4);
	     outtextxy(midx-65,195,"About Us");
	     line(midx-65,235,midx-40,235);
	     delay(1000);
	     button(midx-70,190,midx+80,250);
	     settextstyle(4,HORIZ_DIR,4);
	     outtextxy(midx-65,195,"About Us");
	     line(midx-65,235,midx-40,235);
	     delay(500);
	     background();
	     setfillstyle(1,BLACK);
	     bar(90,90,getmaxx()-90,315+45+20);
	     //BYE BYE
	     {
		settextstyle(3,0,1);
		outtextxy(100,100,"Programing Fundamental Project:");
		outtextxy(100,135,"Writen By:");
		outtextxy(130,165,"Gulfam Sidhu  17114119-030");
		outtextxy(130,190,"Areej Fatima  17114119-047");
		outtextxy(130,215,"Saba Aziz     17114119-052");
		outtextxy(130,240,"Hina Mansha   17114119-050");
		outtextxy(130,265,"Laiba         17114119-051");
		outtextxy(130,290,"Ayesha Bibi   17114119-036");
	      }
	     break;
       }

    }//Switch close




    getch();
   /* clean up */
   closegraph();
   return 0;
}
