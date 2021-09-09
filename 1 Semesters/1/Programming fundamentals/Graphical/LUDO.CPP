//	settextstyle(1, HORIZ_DIR, 2);
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <iostream.h>
#include <stdlib.h>

//defining boolean possibilities
#define true  1
#define false 0
typedef int bool;

//Defining CTRL key to use in to see Data
#ifndef CTRL
#define CTRL(c) ((c) & 037)
#endif

int x, y;	 	//Values of getmaxx() and getmaxy()
void Set(int a, int b) {
	x=a;
	y=b;
}

const int i=160;	//Ludo Board distance from left side of screen
const int j=0;		//Ludo Board distance from top of screen
const int o=29;		//Small Box Size
const int B=o*6;	//Big Side
const int b=o*3;	//Small Side
const int s=o/3;	//Space between boxes
const int c=0;		//color of lines

const int f=o;		//Side of bar use in Home for Goots
const int N=90;		//Location of upper side of notification bar
const int O=230;	//Upper location of options bar
const int G=290;	//Location of upper side of goots bar
const int C=7;		//color of notification bars
const int CC=3;		//back ground color of ludu board

bool Sound = 1;		//Mute or UnMute

int Toss(int Decider);	//Perform Toss
inline void WrongKey();	//Play sound if Wrong key is pressed
inline void Mute();	//Set Mute or Unmute the Sound
inline void Exit();	//This Function is call when user want to exitnline void Goot(int , int , int, int, int);

void button (int x1, int y1, int x2, int y2, int a, int b);

void Notification();	//Draws all commen things in notification bar
void Fix();

void Home1();		//All these Homes makes homes(Green, Yellow, Red & Blue)
void Home2();
void Home3();
void Home4();
void Home(int, int, int, int);	//Makes Goots on all Homes

void End();			//Makes ending point of Goots

void Way();			//Makes the Ways

void WayGootMaker(int, int, int = 0, int = 1);	//Makes Goots on Ways

int ErrorChecker();
void DataViewer();
/*----------------------MENU PAGES----------------------*/
void thgtxt(int x, int y, char* a);
void Logo();
int Menu();
int Play();
void Help();
void Credits();
void BackGround();
void PlayHover(int x, int y, int ShowOrHide, int HoverDecider, int Color, char* Option, int OptColor);	//For Play Function
void Logos(int x, int y, int No);
void Hover(int i, int j, int Decider);		//For Menu

class DataBase{
public:
	int Green[57][4]  ;	//To Store Data of Green Goots
	int Yellow[57][4] ;	//To Store Data of Yellow Goots
	int Red[57][4]    ;	//To Store Data of Red Goots
	int Blue[57][4]   ;	//To Store Data of Blue Goots

	int H_Green     ;	//Number of Goots in Green House
	int H_Yellow    ;	//Number of Goots in Yellow House
	int H_Red       ;	//Number of Goots in Red House
	int H_Blue      ;	//Number of Goots in blue House

	int n           ;	//Toss return value
	int Tosses[1000];	//Saves Toss values
	int TossUse[1000];	//Saves that where the toss value is used

public:
	void Controller(int Color[56][4], int *H_Color) {
		int Decider=0, SorryDecider=1;
		int y=0;
		int i=0;

		n = Toss(1);

/*		static int a=0;
		if(a<4) {n=6;}
		else if(a==15*4+3) {n=6;}
		else if(a==15*4+1) {n=6;}
		else {n=1;}
		a++;
*/
		if(n==6 && *H_Color!=-1) {
			setfillstyle(1, ::C);
			bar(10, N, 150, N+100);

			outtextxy(12, N+5 , " Use new DIE.");
			outtextxy(12, N+15, " Press   Y/N");

			AGAIN:
			char S=getch();		//selector
			if     (S=='n'||S=='N'||S=='y'||S=='Y') { sound(600*Sound); delay(50); nosound(); }
			else if(S=='e'||S=='E')                 { Exit();     goto AGAIN; }
			else if(S=='m'||S=='M')                 { Mute();     goto AGAIN; }
			else                                    { WrongKey(); goto AGAIN; }

			if(S=='y'||S=='Y') {
				setfillstyle(1, ::C);
				bar(10, N, 150, N+100);

				outtextxy(12, N+5  , " Success draw new");
				outtextxy(12, N+15 , " DIE from Home.");

				delay(1000);
				*H_Color=*H_Color+1;
				Color[0][*H_Color] = 1;

				WayGootIdentifier(Color, 0);

				SorryDecider=0;
			}
			else {
				Decider=1;
			}
		}

		if(*H_Color>-1 && (Decider || n!=6)) {
			if(*H_Color==0) {
				for(i=0; i<56; i++) {
					if(Color[i][0]) {
						if(i+n<57) {
							if(i+n<51) { WayGootIdentifier(Color, i+n); }

								Color[i][0]=0;
								Color[i+n][0]=1;

								if(i+n==56) {
									setfillstyle(1, ::C);
									bar(10, N, 150, N+100);

									outtextxy(12, N+5 , " Congratulations");
									outtextxy(12, N+15, " Die has been");
									outtextxy(12, N+25, " reached at end");
									outtextxy(12, N+35, " point.  ;-)");

									sound(600*Sound);
									delay(300);
									nosound();
									delay(1700);
								}

								SorryDecider=0;
								break;
						}
						else{
							setfillstyle(1, ::C);
							bar(10, N, 150, N+100);

							outtextxy(12, N+5 , " Sorry you cannot");
							outtextxy(12, N+15, " move the die ;-(");

							if(n!=6) { outtextxy(12, N+25 , " Try next time!"); }

							sound(300*Sound);
							delay(300);
							nosound();
							delay(700);
							break;
						}
					}
				}
			}
			else {
				setfillstyle(1, ::C);
				bar(10, N, 150, N+100);

				outtextxy(12, N+5 , " Use ARROW keys &");
				outtextxy(12, N+15, " Enter to Select");
				outtextxy(12, N+25, " DIE you want to");
				outtextxy(12, N+35, " move...");

				int color, s, L[4]={0, 0, 0, 0};	//L=Locations s=Size of Location
				if     (Color==*Green)  { color=2;  }
				else if(Color==*Yellow) { color=14; }
				else if(Color==*Red)    { color=4;  }
				else                    { color=1;  }

				for(int y=0, z=0; y<4; y++) {
					for(int i=0; i<56; i++) {
						if(Color[i][y]) { L[z]=i; z++; }
					}
				}
				s=z-1;
				z=0;

				for(;;) {
					WayGootMaker(L[z], color, 1, 1);

					Repeat:
					char S=getch();		//Selector
					if     (S==13||S==char(72)||S==char(80)) {}
					else if(S==char(75))                     { S=80; }
					else if(S==char(77))                     { S=72; }
					else if(S=='e'||S=='E') { Exit(); goto Repeat; }
					else if(S=='m'||S=='M') { Mute(); goto Repeat; }
					else                    { WrongKey(); goto Repeat; }

					WayGootMaker(L[z], color, 1, 0);

					sound(600*Sound);
					if     (S==72 && z<s)  { z++; }	//Up Key
					else if(S==72 && z==s) { z=0; }	//Up Key
					else if(S==80 && z!=0) { z--; }	//Down Key
					else if(S==80 && z==0) { z=s; }	//Down Key
					else if(S==13)         { break; }//Enter Key

					delay(50);
					nosound();
				}
				delay(50);
				nosound();

				y=z;
				i=L[z];

				if(i+n<51) { WayGootIdentifier(Color, i+n); }

				Color[i][y]=0;
				Color[i+n][y]=1;

				SorryDecider=0;
			}
		}
		else if(n==6 && *H_Color==-1) {
			*H_Color=*H_Color+1;
			Color[0][*H_Color] = 1;

			WayGootIdentifier(Color, 0);

			SorryDecider=0;
		}
		else if(SorryDecider) {
			setfillstyle(1, ::C);
			bar(10, N, 150, N+100);

			sound(300*Sound);

			outtextxy(12, N+5 , "Sorry! You failed");
			outtextxy(12, N+15, "to move any die.");
			outtextxy(12, N+25, "Try next time...");

			delay(300);
			nosound();

			delay(1700);
		}

		Home(H_Green, H_Yellow, H_Red, H_Blue);
		Way();
	}
	Auto_Controller(int Color[56][4], int *H_Color) {
		int SorryDecider=1;

		n=Toss(0);

		if(kbhit()) {
			char S=getch();

			if     (S=='e' || S=='E') { Exit(); }
			else if(S=='m' || S=='M') { Mute(); }
		}

		if(n==6 && *H_Color!=3) {
			*H_Color=*H_Color+1;
			Color[0][*H_Color] = 1;

			WayGootIdentifier(Color, 0);

			SorryDecider=0;
		}
		else if(*H_Color!=-1) {
			for(int i=0; i<56; i++) {
				if(Color[i][0]) {
					if(i+n<57) {
						if(i+n<51) { WayGootIdentifier(Color, i+n); }

							Color[i][0]=0;
							Color[i+n][0]=1;

							if(i+n==56) {
								setfillstyle(1, ::C);
								bar(10, N, 150, N+100);

								outtextxy(12, N+5 , " Die has been");
								outtextxy(12, N+15, " reached at end");
								outtextxy(12, N+25, " point.  ;-(");

								sound(600*Sound);
								delay(300);
								nosound();
								delay(1700);
							}

							SorryDecider=0;
							break;
					}
					else{
						setfillstyle(1, ::C);
						bar(10, N, 150, N+100);

						outtextxy(12, N+5 , " Computer is failed");
						outtextxy(12, N+15, " to move any die ;-)");

						sound(300*Sound);
						delay(300);
						nosound();
						delay(700);
						break;
					}
				}
			}
		}

		if(SorryDecider) {
			setfillstyle(1, ::C);
			bar(10, N, 150, N+100);

			outtextxy(12, N+5 , " Computer is failed");
			outtextxy(12, N+15, " to move any die"   );
			outtextxy(12, N+25, " ;-)"               );

			sound(600*Sound);
			delay(200);
			nosound();
			delay(400);
		}

		Home(H_Green, H_Yellow, H_Red, H_Blue);
		Way();
	}

private:
		void WayGootIdentifier(int Color[56][4], int Position) {
		int Decider=0;

		if(Color==Green) {
			//Check Yellow for Green
			for(int y=0; y<4; y++) {
				if(Position>=13 && Yellow[Position-13][y]) {	//Detects the Yellow //Equal Green==Yellow
					Yellow[Position-13][y]=0;
					H_Yellow=H_Yellow-1;
					Decider=1;
					break;
				}
				else if(Yellow[39+Position][y]) {	//Detects the Yellow //Yellow early and green late
					Yellow[39+Position][y]=0;
					H_Yellow=H_Yellow-1;
					Decider=1;
					break;
				}
			}
			if(Decider) {	//Shift the array to its early line if Yellow is detected
				for(; y!=3; y++) {
					for(int i=0; i<56; i++) {
						Yellow[i][y]=Yellow[i][y+1];
					}
				}
				for(int i=0; i<56; i++) { Yellow[i][3]=0; }	//Saves 0's in last 2nd dimension of array
				goto END;
			}
			//Check Blue for Green
			for(y=0; y<4; y++) {
				if(Blue[Position-26][y]) {
					Blue[Position-26][y]=0;
					H_Blue=H_Blue-1;
					Decider=1;
					break;
				}
				else if(Position<29 && Blue[Position+26][y]) {
				cout<<Blue[Position+26][y];
					Blue[Position+26][y]=0;
					H_Blue=H_Blue-1;
					Decider=1;
					break;
				}
			}
			if(Decider) {	//Shift the array to its early line if Yellow is detected
				for(; y!=3; y++) {
					for(int i=0; i<56; i++) {
						Blue[i][y]=Blue[i][y+1];
					}
				}
				for(int i=0; i<56; i++) { Blue[i][3]=0; }	//Saves 0's in last 2nd dimension of array
				goto END;
			}
			//Check Red for Green
			for(y=0; y<4; y++) {
				if(Red[Position-39][y]) {
					Red[Position-39][y]=0;
					H_Red=H_Red-1;
					Decider=1;
					break;
				}
				else if(Red[Position+13][y]) {
					Red[Position+13][y]=0;
					H_Red=H_Red-1;
					Decider=1;
					break;
				}
			}
			if(Decider) {	//Shift the array to its early line if Red is detected
				for(; y!=3; y++) {
					for(int i=0; i<56; i++) {
						Red[i][y]=Red[i][y+1];
					}
				}
				for(int i=0; i<56; i++) { Red[i][3]=0; }	//Saves 0's in last 2nd dimension of array
				goto END;
			}
		}
		else if(Color==Yellow) {
			//Check Blue for Yellow
			for(int y=0; y<4; y++) {
				if(Blue[Position-13][y]) {
					Blue[Position-13][y]=0;
					H_Blue=H_Blue-1;
					Decider=1;
					break;
				}
				else if(Position<17 && Blue[Position+39][y]) {
					Blue[Position+39][y]=0;
					H_Blue=H_Blue-1;
					Decider=1;
					break;
				}
			}
			if(Decider) {	//Shift the array to its early line if Blue is detected
				for(; y!=3; y++) {
					for(int i=0; i<56; i++) {
						Blue[i][y]=Blue[i][y+1];
					}
				}
				for(int i=0; i<56; i++) { Blue[i][3]=0; }	//Saves 0's in last 2nd dimension of array
				goto END;
			}
			//Check Red for Yellow
			for(y=0; y<4; y++) {
				if(Position>25 && Red[Position-26][y]) {
					Red[Position-26][y]=0;
					H_Red=H_Red-1;
					Decider=1;
					break;
				}
				else if(Position<27 && Red[Position+26][y]) {
					Red[Position+26][y]=0;
					H_Red=H_Red-1;
					Decider=1;
					break;
				}
			}
			if(Decider) {	//Shift the array to its early line if Red is detected
				for(; y!=3; y++) {
					for(int i=0; i<56; i++) {
						Red[i][y]=Red[i][y+1];
					}
				}
				for(int i=0; i<56; i++) { Red[i][3]=0; }	//Saves 0's in last 2nd dimension of array
				goto END;
			}
			//Check Green for Yellow
			for(y=0; y<4; y++) {
				if(Position>=39 && Green[Position-39][y]) {
					Green[Position-39][y]=0;
					H_Green=H_Green-1;
					Decider=1;
					break;
				}
				else if(Position<=42 && Green[Position+13][y]) {
					Green[Position+13][y]=0;
					H_Green=H_Green-1;
					Decider=1;
					break;
				}
			}
			if(Decider) {	//Shift the array to its early line if Green is detected
				for(; y!=3; y++) {
					for(int i=0; i<56; i++) {
						Green[i][y]=Green[i][y+1];
					}
				}
				for(int i=0; i<56; i++) { Green[i][3]=0; }	//Saves 0's in last 2nd dimension of array
				goto END;
			}
		}
		else if(Color==Red) {
			//Check Green for Red
			for(int y=0; y<4; y++) {
				if(Position>=13 && Green[Position-13][y]) {
					Green[Position-13][y]=0;
					H_Green=H_Green-1;
					Decider=1;
					break;
				}
				else if(Position<=16 && Green[Position+39][y]) {
					Green[Position+39][y]=0;
					H_Green=H_Green-1;
					Decider=1;
					break;
				}
			}
			if(Decider) {	//Shift the array to its early line if Green is detected
				for(; y!=3; y++) {
					for(int i=0; i<56; i++) {
						Green[i][y]=Green[i][y+1];
					}
				}
				for(int i=0; i<56; i++) { Green[i][3]=0; }	//Saves 0's in last 2nd dimension of array
				goto END;
			}
			//Check Yellow for Red
			for(y=0; y<4; y++) {
				if(Position>=26 && Yellow[Position-26][y]) {
					Yellow[Position-26][y]=0;
					H_Yellow=H_Yellow-1;
					Decider=1;
					break;
				}
				else if(Position<=26 && Yellow[Position+26][y]) {
					Yellow[Position+26][y]=0;
					H_Yellow=H_Yellow-1;
					Decider=1;
					break;
				}
			}
			if(Decider) {	//Shift the array to its early line if Yellow is detected
				for(; y!=3; y++) {
					for(int i=0; i<56; i++) {
						Yellow[i][y]=Yellow[i][y+1];
					}
				}
				for(int i=0; i<56; i++) { Yellow[i][3]=0; }	//Saves 0's in last 2nd dimension of array
				goto END;
			}
			//Check Blue for Red
			for(y=0; y<4; y++) {
				if(Position>=39 && Blue[Position-39][y]) {
					Blue[Position-39][y]=0;
					H_Blue=H_Blue-1;
					Decider=1;
					break;
				}
				else if(Position<=42 && Blue[Position+13][y]) {
					Blue[Position+13][y]=0;
					H_Blue=H_Blue-1;
					Decider=1;
					break;
				}
			}
			if(Decider) {	//Shift the array to its early line if Blue is detected
				for(; y!=3; y++) {
					for(int i=0; i<56; i++) {
						Blue[i][y]=Blue[i][y+1];
					}
				}
				for(int i=0; i<56; i++) { Blue[i][3]=0; }	//Saves 0's in last 2nd dimension of array
				goto END;
			}
		}
		else if(Color==Blue) {
			//Check Red for Blue
			for(int y=0; y<4; y++) {
				if(Red[Position-13][y]) {
					Red[Position-13][y]=0;
					H_Red=H_Red-1;
					Decider=1;
					break;
				}
				else if(Red[Position+39][y]) {
					Red[Position+39][y]=0;
					H_Red=H_Red-1;
					Decider=1;
					break;
				}
			}
			if(Decider) {	//Shift the array to its early line if Red is detected
				for(; y!=3; y++) {
					for(int i=0; i<56; i++) {
						Red[i][y]=Red[i][y+1];
					}
				}
				for(int i=0; i<56; i++) { Red[i][3]=0; }	//Saves 0's in last 2nd dimension of array
				goto END;
			}
			//Check Green for Blue
			for(y=0; y<4; y++) {
				if(Position>=26 && Green[Position-26][y]) {
					Green[Position-26][y]=0;
					H_Green=H_Green-1;
					Decider=1;
					break;
				}
				else if(Position<=26 && Green[Position+26][y]) {
					Green[Position+26][y]=0;
					H_Green=H_Green-1;
					Decider=1;
					break;
				}
			}
			if(Decider) {	//Shift the array to its early line if Green is detected
				for(; y!=3; y++) {
					for(int i=0; i<56; i++) {
						Green[i][y]=Green[i][y+1];
					}
				}
				for(int i=0; i<56; i++) { Green[i][3]=0; }	//Saves 0's in last 2nd dimension of array
				goto END;
			}
			//Check Yellow for Blue
			for(y=0; y<4; y++) {
				if(Position>=39 && Yellow[Position-39][y]) {
					Yellow[Position-39][y]=0;
					H_Yellow=H_Yellow-1;
					Decider=1;
					break;
				}
				else if(Position<=42 && Yellow[Position+13][y]) {
					Yellow[Position+13][y]=0;
					H_Yellow=H_Yellow-1;
					Decider=1;
					break;
				}
			}
			if(Decider) {	//Shift the array to its early line if Yellow is detected
				for(; y!=3; y++) {
					for(int i=0; i<56; i++) {
						Yellow[i][y]=Yellow[i][y+1];
					}
				}
				for(int i=0; i<56; i++) { Yellow[i][3]=0; }	//Saves 0's in last 2nd dimension of array
				goto END;
			}
		}

		END:
		if(Decider) {
			setfillstyle(1, ::C);
			bar(10, N, 150, N+100);

			sound(300*Sound);
			outtextxy(12, N+5  , " Wow...!!!");
			outtextxy(12, N+15 , " What a Short.");
			delay(200);
			nosound();
			delay(1000);
		}
	}
};

DataBase Ob;		//Global Object

void Initializer() {
		//Initializing member variables
		for(int i=0; i<57; i++) {
			for(int y; y<4; y++) {
				Ob.Green[i][y]  = 0;
				Ob.Yellow[i][y] = 0;
				Ob.Red[i][y]    = 0;
				Ob.Blue[i][y]   = 0;
			}
		}

		Ob.H_Green  = -1;
		Ob.H_Yellow = -1;
		Ob.H_Blue   = -1;
		Ob.H_Red    = -1;

		Ob.n       = 0;

		for(i=0; i<1000; i++) {
			Ob.Tosses[i]=0;
			Ob.TossUse[i]=0;
		}
	}


void Goot(int x_Com, int y_Com, int Color, int Decider, int Hide) {
	if(Hide==0) {
		button(x_Com, y_Com, x_Com+o, y_Com+o, 0, 0);
		return;
	}
	if(Decider) {
		button(x_Com, y_Com, x_Com+o, y_Com+o, Color, Color);
		return;
	}

	setfillstyle(1, Color);

	circle(x_Com+o/2, y_Com+o/2, 10);

	floodfill(x_Com+o/2, y_Com+o/2, 0);

	circle(x_Com+o/2, y_Com+o/2+1, 11);

	circle(x_Com+o/2, y_Com+o/2, 5);
	circle(x_Com+o/2, y_Com+o/2, 4);
	circle(x_Com+o/2, y_Com+o/2, 3);
	circle(x_Com+o/2, y_Com+o/2, 2);
	circle(x_Com+o/2, y_Com+o/2, 1);
}

void button (int x1, int y1, int x2, int y2, int a, int b) {
	setcolor(a);
	line(x1,y1,x2,y1);
	line(x1,y1,x1,y2);
	setcolor(b);
	line(x1,y2,x2,y2);
	line(x2,y1,x2,y2);
}

void press (int x1, int y1, int x2, int y2) {
	setcolor(15);
	line(x1,y1,x2,y1);
	line(x1,y1,x1,y2);
	setcolor(8);
	line(x1,y2,x2,y2);
	line(x2,y1,x2,y2);

	sound(600);
	delay(500);
	button(x1, y1, x2, y2, 1, 1);
	nosound();
	delay(400);
}

int Toss(int Decider) {
	int n;
	char S;	//Selector

	setfillstyle(1, ::C);
	bar(10, N, 150, N+100);

	if(Decider) {
		outtextxy(12, N+5, " Start TOSS   :S");

		AGAIN:
		S=getch();
		if     (S=='s'||S=='S') {}
		else if(S=='e'||S=='E') { Exit();     }
		else if(S=='m'||S=='M') { Mute(); goto AGAIN;         }
		else                    { WrongKey(); goto AGAIN;     }
	}
	else {
		outtextxy(12, N+5, " Waiting for Toss");
		delay(700);
	}

	bar(10, N, 150, N+100);
	if(Decider) { outtextxy(12, N+5, " Stop TOSS    :S"); }
	else {
		outtextxy(12, N+5 , " Computer is doing");
		outtextxy(12, N+15, " TOSS...");
	}

	int Repeat = 20+rand()%20;
	int a=0;

	do {
		if(Decider==0) { a++; }

		sound(600*Sound);
		n=1+rand()%6;

		setfillstyle(1, ::C);
		bar(116, y-31, 134, y-13);

		if(n==1) {
			circle(125, y-22, 1); circle(125, y-22, 2);
		}
		else if(n==2) {
			circle(120, y-22, 1); circle(120, y-22, 2);
			circle(130, y-22, 1); circle(130, y-22, 2);
		}
		else if(n==3) {
			circle(125, y-27, 1); circle(125, y-27, 2);
			circle(120, y-17, 1); circle(120, y-17, 2);
			circle(130, y-17, 1); circle(130, y-17, 2);
		}
		else if(n==4) {
			circle(120, y-27, 1); circle(120, y-27, 2);
			circle(130, y-27, 1); circle(130, y-27, 2);
			circle(120, y-17, 1); circle(120, y-17, 2);
			circle(130, y-17, 1); circle(130, y-17, 2);
		}
		else if(n==5) {
			circle(120, y-27, 1); circle(120, y-27, 2);
			circle(130, y-27, 1); circle(130, y-27, 2);
			circle(125, y-22, 1); circle(125, y-22, 2);
			circle(120, y-17, 1); circle(120, y-17, 2);
			circle(130, y-17, 1); circle(130, y-17, 2);
		}
		else {
			circle(119, y-27, 1); circle(119, y-27, 2);
			circle(125, y-27, 1); circle(125, y-27, 2);
			circle(131, y-27, 1); circle(131, y-27, 2);
			circle(119, y-17, 1); circle(119, y-17, 2);
			circle(125, y-17, 1); circle(125, y-17, 2);
			circle(131, y-17, 1); circle(131, y-17, 2);
		}
		delay(30);
		nosound();
		delay(20);

		if(Decider) { if(kbhit()) { S=getch(); if(S=='s'||S=='S') { break; } } }
		else { if(a==Repeat) { break; } }
	} while(true);

	static int w=0;

	if(w<4) {n=6;}
	w++;

	static int I=0;
	Ob.Tosses[I]=n;
	I++;

	return(n);
}

void WrongKey() {
	sound(200*Sound);
	delay(200);
	nosound();
}

void Mute() {
	Sound = !Sound;

	setfillstyle(1, ::C);
	bar(10, O+14, 150, O+22);

	setcolor(0);
	if(Sound) { outtextxy(20, O+15, "MUTE:        M"); }
	else      { outtextxy(20, O+15, "UNMUTE:      M"); }

	sound(500*Sound);
	delay(300);
	nosound();
}

void Exit() {
	cleardevice();

	exit(0);
}

void main() {
	int gdriver = DETECT,gmode;
	initgraph(&gdriver,&gmode,"C:\\TC\\BGI");

	cleardevice();

	Set(getmaxx(), getmaxy());

	int FirstPlayer, SecondPlayer, ThirdPlayer, ForthPlayer;
DataViewer();
	Logo();			//To form logo

	ErrorPlayAgain:		//When an error is found is game then the game is restarts

	FirstPlayer = Menu();	//Call menu

	Initializer();		//Initialize the values of object variables

	settextstyle(0, 0, 0);
	settextjustify(0, 2);

	Notification();		//Forms the notification bar
	Fix();                  //Form fix things like Background color
	Home1();		//These Homes forms four Homes except Goots
	Home2();
	Home3();
	Home4();

	End();			//Forms the ending point of game (Four triangles)

	Way();			//This function form the four ways of Ludo

	Home(-1, -1, -1, -1);	//Forms the Goots on each Home

	ForthPlayer = FirstPlayer%10;		//These equations saves the playing modes
	FirstPlayer /= 10;

	ThirdPlayer = FirstPlayer%10;
	FirstPlayer /= 10;

	SecondPlayer = FirstPlayer%10;

	FirstPlayer /= 10;

	char *No[4] = { "1st", "2nd", "3rd", "4th" };

	{
		settextjustify(1, 2);

		int i=-1;

		if (FirstPlayer)  { i++; outtextxy(::i+s+B/2, ::j+s+B/2-40, No[i]);                              }
		else              {      outtextxy(::i+s+B/2, ::j+s+B/2-40, "No") ; Ob.H_Green=3;                }

		if (SecondPlayer) { i++; outtextxy(::i+s+B+s+b+s+B/2, ::j+s+B/2-40, No[i]);                      }
		else              {      outtextxy(::i+s+B+s+b+s+B/2, ::j+s+B/2-40, "No" ); Ob.H_Yellow=3;       }

		if (ThirdPlayer)  { i++; outtextxy(::i+s+B/2, ::j+s+B+s+b+s+B/2-40, No[i]);                      }
		else              {      outtextxy(::i+s+B/2, ::j+s+B+s+b+s+B/2-40, "No" ); Ob.H_Red=3;          }

		if (ForthPlayer)  { i++; outtextxy(::i+s+B+s+b+s+B/2, ::j+s+B+s+b+s+B/2-40, No[i]);              }
		else              {      outtextxy(::i+s+B+s+b+s+B/2, ::j+s+B+s+b+s+B/2-40, "No" ); Ob.H_Blue=3; }

		Home(Ob.H_Green, Ob.H_Yellow, Ob.H_Red, Ob.H_Blue);

		outtextxy(::i+s+B/2        , ::j+s+B/2-30        , "Player");
		outtextxy(::i+s+B+s+b+s+B/2, ::j+s+B/2-30        , "Player");
		outtextxy(::i+s+B/2        , ::j+s+B+s+b+s+B/2-30, "Player");
		outtextxy(::i+s+B+s+b+s+B/2, ::j+s+B+s+b+s+B/2-30, "Player");

		if     (FirstPlayer==0) { Logos(::i+s+B/2, ::j+s+B/2, 5  ); }
		else if(FirstPlayer==1) { Logos(::i+s+B/2, ::j+s+B/2-5, 302); setcolor(0); outtextxy(::i+s+B/2, ::j+s+B-60, "User"    ); }
		else                    { Logos(::i+s+B/2, ::j+s+B/2-5, 4  ); setcolor(0); outtextxy(::i+s+B/2, ::j+s+B-67, "Computer"); }

		if     (SecondPlayer==0) { Logos(::i+s+B+s+b+s+B/2, ::j+s+B/2, 5  ); }
		else if(SecondPlayer==1) { Logos(::i+s+B+s+b+s+B/2, ::j+s+B/2-5, 314); setcolor(0); outtextxy(::i+s+B+s+b+s+B/2, ::j+s+B-60, "User"    ); }
		else                     { Logos(::i+s+B+s+b+s+B/2, ::j+s+B/2-5, 4  ); setcolor(0); outtextxy(::i+s+B+s+b+s+B/2, ::j+s+B-67, "Computer"); }

		if     (ThirdPlayer==0) { Logos(::i+s+B/2, ::j+s+B+s+b+s+B/2, 5  ); }
		else if(ThirdPlayer==1) { Logos(::i+s+B/2, ::j+s+B+s+b+s+B/2-5, 304); setcolor(0); outtextxy(::i+s+B/2, ::j+s+B+s+b+s+B-60, "User"    ); }
		else                    { Logos(::i+s+B/2, ::j+s+B+s+b+s+B/2-5, 4  ); setcolor(0); outtextxy(::i+s+B/2, ::j+s+B+s+b+s+B-67, "Computer"); }

		if     (ForthPlayer==0) { Logos(::i+s+B+s+b+s+B/2, ::j+s+B+s+b+s+B/2, 5  ); }
		else if(ForthPlayer==1) { Logos(::i+s+B+s+b+s+B/2, ::j+s+B+s+b+s+B/2-5, 301); setcolor(0); outtextxy(::i+s+B+s+b+s+B/2, ::j+s+B+s+b+s+B-60, "User"    ); }
		else                    { Logos(::i+s+B+s+b+s+B/2, ::j+s+B+s+b+s+B/2-5, 4  ); setcolor(0); outtextxy(::i+s+B+s+b+s+B/2, ::j+s+B+s+b+s+B-67, "Computer"); }
	}

	settextjustify(0, 2);
	setcolor(0);

	No[0] = "First Player Turn" ;
	No[1] = "Second Player Turn";
	No[2] = "Third Player Turn" ;
	No[3] = "Forth Player Turn" ;

	for(int i=0, a=0; ; i++) {
		setfillstyle(1, ::C);
		bar(8, 13, 152, 28);
		outtextxy(11, 18,  No[a]);

		if(i==0 && FirstPlayer) {
			if(FirstPlayer==1) { Ob.Controller     (Ob.Green, &Ob.H_Green); }
			else               { Ob.Auto_Controller(Ob.Green, &Ob.H_Green); }

			a++;
		}
		else if(i==1 && SecondPlayer) {
			if(SecondPlayer==1) { Ob.Controller     (Ob.Yellow, &Ob.H_Yellow); }
			else                { Ob.Auto_Controller(Ob.Yellow, &Ob.H_Yellow); }

			if(ErrorChecker()) { goto ErrorPlayAgain; }
			a++;
		}
		else if(i==2 && ThirdPlayer) {
			if(ThirdPlayer==1) { Ob.Controller     (Ob.Red, &Ob.H_Red); }
			else               { Ob.Auto_Controller(Ob.Red, &Ob.H_Red); }

			if(ErrorChecker()) { goto ErrorPlayAgain; }
			a++;
		}
		else if(i==3 && ForthPlayer) {
			if(ForthPlayer==1) { Ob.Controller     (Ob.Blue, &Ob.H_Blue); }
			else               { Ob.Auto_Controller(Ob.Blue, &Ob.H_Blue); }

			if(ErrorChecker()) { goto ErrorPlayAgain; }
			a++;
		}

		if(i==3) { i=0; a=0; }
	}
}

void Home(int Green, int Yellow, int Red, int Blue) {
	static int GREEN=9, YELLOW=9, RED=9, BLUE=9;	//Storing Garbige value

	if(Green!=GREEN) {	//First Green
		setfillstyle(1, 15);

		bar(i+s+B-s-f, ::j+s+B-s, i+s+B-s, ::j+s+B-s-f);
		bar(i+s+s    , ::j+s+s  , i+s+s+f, ::j+s+s+f  );
		bar(i+s+B-s-f, ::j+s+s  , i+s+B-s, ::j+s+s+f  );
		bar(i+s+s    , ::j+s+B-s, i+s+s+f, ::j+s+B-s-f);

		if(Green==2) {
			Goot(i+s+s    , ::j+s+s    , 2, 0, 1);
		}
		else if(Green==1) {
			Goot(i+s+s    , ::j+s+s    , 2, 0, 1);
			Goot(i+s+B-s-f, ::j+s+s    , 2, 0, 1);
		}
		else if(Green==0) {
			Goot(i+s+s    , ::j+s+s    , 2, 0, 1);
			Goot(i+s+B-s-f, ::j+s+s    , 2, 0, 1);
			Goot(i+s+s    , ::j+s+B-s-f, 2, 0, 1);
		}
		else if(Green==-1) {
			Goot(i+s+B-s-f, ::j+s+B-s-f, 2, 0, 1);
			Goot(i+s+s    , ::j+s+s    , 2, 0, 1);
			Goot(i+s+B-s-f, ::j+s+s    , 2, 0, 1);
			Goot(i+s+s    , ::j+s+B-s-f, 2, 0, 1);
		}
		GREEN=Green;
	}
	if(Yellow!=YELLOW) {	//Second Yellow
		setfillstyle(1, 15);

		bar(i+s+B+s+b+s+s    , ::j+s+s  , i+s+B+s+b+s+s+f, ::j+s+s+f  );
		bar(i+s+B+s+b+s+B-s-f, ::j+s+s  , i+s+B+s+b+s+B-s, ::j+s+s+f  );
		bar(i+s+B+s+b+s+s    , ::j+s+B-s, i+s+B+s+b+s+s+f, ::j+s+B-s-f);
		bar(i+s+B+s+b+s+B-s-f, ::j+s+B-s, i+s+B+s+b+s+B-s, ::j+s+B-s-f);

		if(Yellow==2) {
			Goot(i+s+B+s+b+s+s    , ::j+s+s    , 14, 0, 1);
		}
		else if(Yellow==1) {
			Goot(i+s+B+s+b+s+s    , ::j+s+s    , 14, 0, 1);
			Goot(i+s+B+s+b+s+B-s-f, ::j+s+s    , 14, 0, 1);
		}
		else if(Yellow==0) {
			Goot(i+s+B+s+b+s+s    , ::j+s+s    , 14, 0, 1);
			Goot(i+s+B+s+b+s+B-s-f, ::j+s+s    , 14, 0, 1);
			Goot(i+s+B+s+b+s+s    , ::j+s+B-s-f, 14, 0, 1);
		}
		else if(Yellow==-1) {
			Goot(i+s+B+s+b+s+s    , ::j+s+s    , 14, 0, 1);
			Goot(i+s+B+s+b+s+B-s-f, ::j+s+s    , 14, 0, 1);
			Goot(i+s+B+s+b+s+s    , ::j+s+B-s-f, 14, 0, 1);
			Goot(i+s+B+s+b+s+B-s-f, ::j+s+B-s-f, 14, 0, 1);
		}
		YELLOW=Yellow;
	}
	if(Red!=RED) {  	//Third Red
		setfillstyle(1, 15);

		bar(i+s+s    , ::j+s+B+s+b+s+s   , i+s+s+f, ::j+s+B+s+b+s+s+f  );
		bar(i+s+B-s-f, ::j+s+B+s+b+s+s   , i+s+B-s, ::j+s+B+s+b+s+s+f  );
		bar(i+s+s    , ::j+s+B+s+b+s+B-s , i+s+s+f, ::j+s+B+s+b+s+B-s-f);
		bar(i+s+B-s-f, ::j+s+B+s+b+s+B-s , i+s+B-s, ::j+s+B+s+b+s+B-s-f);

		if(Red==2) {
			Goot(i+s+s    , ::j+s+B+s+b+s+s     , 4, 0, 1);
		}
		else if(Red==1) {
			Goot(i+s+s    , ::j+s+B+s+b+s+s     , 4, 0, 1);
			Goot(i+s+B-s-f, ::j+s+B+s+b+s+s     , 4, 0, 1);
		}
		else if(Red==0) {
			Goot(i+s+s    , ::j+s+B+s+b+s+s     , 4, 0, 1);
			Goot(i+s+B-s-f, ::j+s+B+s+b+s+s     , 4, 0, 1);
			Goot(i+s+s    , ::j+s+B+s+b+s+B-s-f , 4, 0, 1);
		}
		else if(Red==-1) {
			Goot(i+s+s    , ::j+s+B+s+b+s+s     , 4, 0, 1);
			Goot(i+s+B-s-f, ::j+s+B+s+b+s+s     , 4, 0, 1);
			Goot(i+s+s    , ::j+s+B+s+b+s+B-s-f , 4, 0, 1);
			Goot(i+s+B-s-f, ::j+s+B+s+b+s+B-s-f , 4, 0, 1);
		}
		RED=Red;
	}
	if(Blue!=BLUE) {	//Forth Blue
		setfillstyle(1, 15);

		bar(i+s+B+s+b+s+s    , ::j+s+B+s+b+s+s  , i+s+B+s+b+s+s+f, ::j+s+B+s+b+s+s+f  );
		bar(i+s+B+s+b+s+B-s-f, ::j+s+B+s+b+s+s  , i+s+B+s+b+s+B-s, ::j+s+B+s+b+s+s+f  );
		bar(i+s+B+s+b+s+s    , ::j+s+B+s+b+s+B-s, i+s+B+s+b+s+s+f, ::j+s+B+s+b+s+B-s-f);
		bar(i+s+B+s+b+s+B-s-f, ::j+s+B+s+b+s+B-s, i+s+B+s+b+s+B-s, ::j+s+B+s+b+s+B-s-f);

		if(Blue==2) {
			Goot(i+s+B+s+b+s+s    , ::j+s+B+s+b+s+s    , 1, 0, 1);
		}
		else if(Blue==1) {
			Goot(i+s+B+s+b+s+s    , ::j+s+B+s+b+s+s    , 1, 0, 1);
			Goot(i+s+B+s+b+s+B-s-f, ::j+s+B+s+b+s+s    , 1, 0, 1);
		}
		else if(Blue==0) {
			Goot(i+s+B+s+b+s+s    , ::j+s+B+s+b+s+s    , 1, 0, 1);
			Goot(i+s+B+s+b+s+B-s-f, ::j+s+B+s+b+s+s    , 1, 0, 1);
			Goot(i+s+B+s+b+s+s    , ::j+s+B+s+b+s+B-s-f, 1, 0, 1);
		}
		else if(Blue==-1) {
			Goot(i+s+B+s+b+s+s    , ::j+s+B+s+b+s+s    , 1, 0, 1);
			Goot(i+s+B+s+b+s+B-s-f, ::j+s+B+s+b+s+s    , 1, 0, 1);
			Goot(i+s+B+s+b+s+s    , ::j+s+B+s+b+s+B-s-f, 1, 0, 1);
			Goot(i+s+B+s+b+s+B-s-f, ::j+s+B+s+b+s+B-s-f, 1, 0, 1);
		}
		BLUE=Blue;
	}
}

void Notification() {
	setfillstyle(1, 3);
	bar(0, 0, 160, y);

	button(4, 4, i-4, y-4, c, c);
	button(5, 5, i-5, y-5, c, c);
	button(6, 6, i-6, y-6, c, c);
}

void Way() {
	static int YELLOW[56] = { -1 };
	static int GREEN[56]  = { -1 };
	static int BLUE[56]   = { -1 };
	static int RED[56]    = { -1 };

//	if(YELLOW!=Yellow || GREEN!=Green || BLUE!=Blue || RED!=Red) {
		//Way1
		setfillstyle(1, ::CC);
		bar(i+s+B+s, ::j+s, i+s+B+s+b, ::j+s+B);

		setfillstyle(1, 14);
		bar(::i+s+B+s+o, ::j+s+o, ::i+s+B+s+o+o, ::j+s+o+5*o);

		button(::i+s+B+s, ::j+s, ::i+s+B+s+b, ::j+s+B, c, c);

		setcolor(c);
		line(::i+s+B+s    , ::j+s+o  , ::i+s+B+s+b  , ::j+s+o  );
		line(::i+s+B+s    , ::j+s+2*o, ::i+s+B+s+b  , ::j+s+2*o);
		line(::i+s+B+s    , ::j+s+3*o, ::i+s+B+s+b  , ::j+s+3*o);
		line(::i+s+B+s    , ::j+s+4*o, ::i+s+B+s+b  , ::j+s+4*o);
		line(::i+s+B+s    , ::j+s+5*o, ::i+s+B+s+b  , ::j+s+5*o);

		line(::i+s+B+s+o  , ::j+s    , ::i+s+B+s+o  , ::j+s+B  );
		line(::i+s+B+s+2*o, ::j+s    , ::i+s+B+s+2*o, ::j+s+B  );

		for(int i=0 ; i<5 ; i++) { for(int y=0; y<4; y++) { if(Ob.Yellow[i][y]) { WayGootMaker(i, 14); } } }
		for(    i=5 ; i<18; i++) { for(int y=0; y<4; y++) { if(Ob.Green[i][y] ) { WayGootMaker(i, 2);  } } }
		for(    i=18; i<31; i++) { for(int y=0; y<4; y++) { if(Ob.Red[i][y]   ) { WayGootMaker(i, 4);  } } }
		for(    i=44; i<56; i++) { for(int y=0; y<4; y++) { if(Ob.Yellow[i][y]) { WayGootMaker(i, 14); } } }
		for(    i=31; i<44; i++) { for(int y=0; y<4; y++) { if(Ob.Blue[i][y])   { WayGootMaker(i, 1);  } } }
//	}

//	if(YELLOW!=Yellow || GREEN!=Green || BLUE!=Blue || RED!=Red) {
	//	Way2
		setfillstyle(1, ::CC);
		bar(::i+s, ::j+s+B+s, ::i+s+B, ::j+s+B+s+b);
		setfillstyle(1, 2);
		bar(::i+s+o, ::j+s+B+s+o, ::i+s+6*o, ::j+s+B+s+o+o);

		button(::i+s, ::j+s+B+s, ::i+s+B, ::j+s+B+s+b, c, c);

		setcolor(c);
		line(::i+s    , ::j+s+B+s+o  , ::i+s+B  , ::j+s+B+s+o  );
		line(::i+s    , ::j+s+B+s+2*o, ::i+s+B  , ::j+s+B+s+2*o);

		line(::i+s+o  , ::j+s+B+s    , ::i+s+o  , ::j+s+B+s+b  );
		line(::i+s+2*o, ::j+s+B+s    , ::i+s+2*o, ::j+s+B+s+b  );
		line(::i+s+3*o, ::j+s+B+s    , ::i+s+3*o, ::j+s+B+s+b  );
		line(::i+s+4*o, ::j+s+B+s    , ::i+s+4*o, ::j+s+B+s+b  );
		line(::i+s+5*o, ::j+s+B+s    , ::i+s+5*o, ::j+s+B+s+b  );

		for(i=0 ; i<5 ; i++) { for(int y=0; y<4; y++) { if(Ob.Green[i][y] ) { WayGootMaker(i, 2 ); } } }
		for(i=44; i<56; i++) { for(int y=0; y<4; y++) { if(Ob.Green[i][y] ) { WayGootMaker(i, 2 ); } } }
		for(i=5 ; i<18; i++) { for(int y=0; y<4; y++) { if(Ob.Red[i][y]   ) { WayGootMaker(i, 4 ); } } }
		for(i=18; i<31; i++) { for(int y=0; y<4; y++) { if(Ob.Blue[i][y]  ) { WayGootMaker(i, 1 ); } } }
		for(i=31; i<44; i++) { for(int y=0; y<4; y++) { if(Ob.Yellow[i][y]) { WayGootMaker(i, 14); } } }
//	}

//	if(YELLOW!=Yellow || GREEN!=Green || BLUE!=Blue || RED!=Red) {
		//Way3
		setfillstyle(1, ::CC);
		bar(::i+s+B+s+b+s, ::j+s+B+s, ::i+s+B+s+b+s+B, ::j+s+B+s+b);

		setfillstyle(1, 1);
		bar(::i+s+B+s+b+s, ::j+s+B+s+o, ::i+s+B+s+b+s+5*o, ::j+s+B+s+2*o);

		button(::i+s+B+s+b+s, ::j+s+B+s, ::i+s+B+s+b+s+B, ::j+s+B+s+b, c, c);

		setcolor(c);
		line(::i+s+B+s+b+s    , ::j+s+B+s+o  , ::i+s+B+s+b+s+B  , ::j+s+B+s+o  );
		line(::i+s+B+s+b+s    , ::j+s+B+s+2*o, ::i+s+B+s+b+s+B  , ::j+s+B+s+2*o);

		line(::i+s+B+s+b+s+o  , ::j+s+B+s    , ::i+s+B+s+b+s+o  , ::j+s+B+s+b  );
		line(::i+s+B+s+b+s+2*o, ::j+s+B+s    , ::i+s+B+s+b+s+2*o, ::j+s+B+s+b  );
		line(::i+s+B+s+b+s+3*o, ::j+s+B+s    , ::i+s+B+s+b+s+3*o, ::j+s+B+s+b  );
		line(::i+s+B+s+b+s+4*o, ::j+s+B+s    , ::i+s+B+s+b+s+4*o, ::j+s+B+s+b  );
		line(::i+s+B+s+b+s+5*o, ::j+s+B+s    , ::i+s+B+s+b+s+5*o, ::j+s+B+s+b  );

		for(i=0 ; i<5 ; i++) { for(int y=0; y<4; y++) { if(Ob.Blue[i][y]  ) { WayGootMaker(i, 1);  } } }
		for(i=5 ; i<18; i++) { for(int y=0; y<4; y++) { if(Ob.Yellow[i][y]) { WayGootMaker(i, 14); } } }
		for(i=18; i<31; i++) { for(int y=0; y<4; y++) { if(Ob.Green[i][y] ) { WayGootMaker(i, 2 ); } } }
		for(i=31; i<44; i++) { for(int y=0; y<4; y++) { if(Ob.Red[i][y]   ) { WayGootMaker(i, 4);  } } }
		for(i=44; i<56; i++) { for(int y=0; y<4; y++) { if(Ob.Blue[i][y]  ) { WayGootMaker(i, 1);  } } }
//	}

//	if(YELLOW!=Yellow || GREEN!=Green || BLUE!=Blue || RED!=Red) {
		//Way4
		setfillstyle(1, ::CC);
		bar(::i+s+B+s, ::j+s+B+s+b+s, ::i+s+B+s+b, ::j+s+B+s+b+s+B);

		setfillstyle(1, 4);
		bar(::i+s+B+s+o, ::j+s+B+s+b+s, ::i+s+B+s+o+o, ::j+s+B+s+b+s+5*o);

		button(::i+s+B+s, ::j+s+B+s+b+s, ::i+s+B+s+b, ::j+s+B+s+b+s+B, c, c);

		setcolor(c);
		line(::i+s+B+s    , ::j+s+B+s+b+s+o  , ::i+s+B+s+b  , ::j+s+B+s+b+s+o  );
		line(::i+s+B+s    , ::j+s+B+s+b+s+2*o, ::i+s+B+s+b  , ::j+s+B+s+b+s+2*o);
		line(::i+s+B+s    , ::j+s+B+s+b+s+3*o, ::i+s+B+s+b  , ::j+s+B+s+b+s+3*o);
		line(::i+s+B+s    , ::j+s+B+s+b+s+4*o, ::i+s+B+s+b  , ::j+s+B+s+b+s+4*o);
		line(::i+s+B+s    , ::j+s+B+s+b+s+5*o, ::i+s+B+s+b  , ::j+s+B+s+b+s+5*o);

		line(::i+s+B+s+o  , ::j+s+B+s+b+s    , ::i+s+B+s+o  , ::j+s+B+s+b+s+B  );
		line(::i+s+B+s+2*o, ::j+s+B+s+b+s    , ::i+s+B+s+2*o, ::j+s+B+s+b+s+B  );

		for(i=0 ; i<5 ; i++) { for(int y=0; y<4; y++) { if(Ob.Red[i][y]   ) { WayGootMaker(i, 4);  } } }
		for(i=44; i<56; i++) { for(int y=0; y<4; y++) { if(Ob.Red[i][y]   ) { WayGootMaker(i, 4);  } } }
		for(i=5 ; i<18; i++) { for(int y=0; y<4; y++) { if(Ob.Blue[i][y]  ) { WayGootMaker(i, 1);  } } }
		for(i=18; i<31; i++) { for(int y=0; y<4; y++) { if(Ob.Yellow[i][y]) { WayGootMaker(i, 14); } } }
		for(i=31; i<44; i++) { for(int y=0; y<4; y++) { if(Ob.Green[i][y] ) { WayGootMaker(i, 2);  } } }

//	}
/*	for(i=1; i<56; i++) {
		YELLOW[i]=Yellow[i];
		GREEN[i] =Green[i] ;
		BLUE[i]  =Blue[i]  ;
		RED[i]   =Red[i]   ;
	}*/
}

void WayGootMaker(int n, int C, int Decider, int Hide) {
	//Way1
	//First section
		 //Yellow         //Green          //Red           //Blue
	if     ((n==0&&C==14) || (n==13&&C==2) || (n==26&&C==4) || (n==39&&C==1))
	 { Goot(i+s+B+s+o+o, ::j+s+o  , C, Decider, Hide); }
	else if((n==1&&C==14) || (n==14&&C==2) || (n==27&&C==4) || (n==40&&C==1))
	 { Goot(i+s+B+s+o+o, ::j+s+2*o, C, Decider, Hide); }
	else if((n==2&&C==14) || (n==15&&C==2) || (n==28&&C==4) || (n==41&&C==1))
	 { Goot(i+s+B+s+o+o, ::j+s+3*o, C, Decider, Hide); }
	else if((n==3&&C==14) || (n==16&&C==2) || (n==29&&C==4) || (n==42&&C==1))
	 { Goot(i+s+B+s+o+o, ::j+s+4*o, C, Decider, Hide); }
	else if((n==4&&C==14) || (n==17&&C==2) || (n==30&&C==4) || (n==43&&C==1))
	 { Goot(i+s+B+s+o+o, ::j+s+5*o, C, Decider, Hide); }
	 //Second Section
		//Green          //Red             //Yellow         //Blue
	else if((n==5&&C==2)  || (n==18&&C==4) || (n==44&&C==14) || (n==31&&C==1))
	 { Goot(i+s+B+s, ::j+s+5*o, C, Decider, Hide); }
	else if((n==6&&C==2)  || (n==19&&C==4) || (n==45&&C==14) || (n==32&&C==1))
	 { Goot(i+s+B+s, ::j+s+4*o, C, Decider, Hide); }
	else if((n==7&&C==2)  || (n==20&&C==4) || (n==46&&C==14) || (n==33&&C==1))
	 { Goot(i+s+B+s, ::j+s+3*o, C, Decider, Hide); }
	else if((n==8&&C==2)  || (n==21&&C==4) || (n==47&&C==14) || (n==34&&C==1))
	 { Goot(i+s+B+s, ::j+s+2*o, C, Decider, Hide); }
	else if((n==9&&C==2)  || (n==22&&C==4) || (n==48&&C==14) || (n==35&&C==1))
	 { Goot(i+s+B+s, ::j+s+o  , C, Decider, Hide); }
	else if((n==10&&C==2) || (n==23&&C==4) || (n==49&&C==14) || (n==36&&C==1))
	 { Goot(i+s+B+s, ::j+s    , C, Decider, Hide); }
	 //Center Bared
	else if(n==51&&C==14)
	 { Goot(i+s+B+s+o, ::j+s+o  , C, Decider, Hide); }
	else if(n==52&&C==14)
	 { Goot(i+s+B+s+o, ::j+s+2*o, C, Decider, Hide); }
	else if(n==53&&C==14)
	 { Goot(i+s+B+s+o, ::j+s+3*o, C, Decider, Hide); }
	else if(n==54&&C==14)
	 { Goot(i+s+B+s+o, ::j+s+4*o, C, Decider, Hide); }
	else if(n==55&&C==14)
	 { Goot(i+s+B+s+o, ::j+s+5*o, C, Decider, Hide); }
	 //Mid Location
	       //Green            //Yellow          //Red            //Blue
	else if((n==11&&C==2) || (n==50&&C==14) || (n==24&&C==4) || (n==37&&C==1))
	 { Goot(i+s+B+s+o, ::j+s, C, Decider, Hide); }
	 //Special
		//Green           //Red            //Blue
	else if((n==12&&C==2) || (n==25&&C==4) || (n==38&&C==1))
	 { Goot(i+s+B+s+o+o, ::j+s, C, Decider, Hide); }

	 //Way2
	 //First Section
	       //Green        //Red            //Yellow             //Blue
	else if((n==0&&C==2) || (n==13&&C==4) || (n==39&&C==14) || (n==26&&C==1))
	 { Goot(i+s+o  , ::j+s+B+s, C, Decider, Hide); }
	else if((n==1&&C==2) || (n==14&&C==4) || (n==40&&C==14) || (n==27&&C==1))
	 { Goot(i+s+2*o, ::j+s+B+s, C, Decider, Hide); }
	else if((n==2&&C==2) || (n==15&&C==4) || (n==41&&C==14) || (n==28&&C==1))
	 { Goot(i+s+3*o, ::j+s+B+s, C, Decider, Hide); }
	else if((n==3&&C==2) || (n==16&&C==4) || (n==42&&C==14) || (n==29&&C==1))
	 { Goot(i+s+4*o, ::j+s+B+s, C, Decider, Hide); }
	else if((n==4&&C==2) || (n==17&&C==4) || (n==43&&C==14) || (n==30&&C==1))
	 { Goot(i+s+5*o, ::j+s+B+s, C, Decider, Hide); }
	 //Second Section
		//Red             //Blue           //Green          //Yellow
	else if((n==5&&C==4)  || (n==18&&C==1) || (n==44&&C==2) || (n==31&&C==14))
	 { Goot(i+s+5*o, ::j+s+B+s+o+o, C, Decider, Hide); }
	else if((n==6&&C==4)  || (n==19&&C==1) || (n==45&&C==2) || (n==32&&C==14))
	 { Goot(i+s+4*o, ::j+s+B+s+o+o, C, Decider, Hide); }
	else if((n==7&&C==4)  || (n==20&&C==1) || (n==46&&C==2) || (n==33&&C==14))
	 { Goot(i+s+3*o, ::j+s+B+s+o+o, C, Decider, Hide); }
	else if((n==8&&C==4)  || (n==21&&C==1) || (n==47&&C==2) || (n==34&&C==14))
	 { Goot(i+s+2*o, ::j+s+B+s+o+o, C, Decider, Hide); }
	else if((n==9&&C==4)  || (n==22&&C==1) || (n==48&&C==2) || (n==35&&C==14))
	 { Goot(i+s+o  , ::j+s+B+s+o+o, C, Decider, Hide); }
	else if((n==10&&C==4) || (n==23&&C==1) || (n==49&&C==2) || (n==36&&C==14))
	 { Goot(i+s    , ::j+s+B+s+o+o, C, Decider, Hide); }
	 //Inner Bared
	else if(n==51&&C==2)
	 { Goot(i+s+o  , ::j+s+B+s+o, C, Decider, Hide); }
	else if(n==52&&C==2)
	 { Goot(i+s+2*o, ::j+s+B+s+o, C, Decider, Hide); }
	else if(n==53&&C==2)
	 { Goot(i+s+3*o, ::j+s+B+s+o, C, Decider, Hide); }
	else if(n==54&&C==2)
	 { Goot(i+s+4*o, ::j+s+B+s+o, C, Decider, Hide); }
	else if(n==55&&C==2)
	 { Goot(i+s+5*o, ::j+s+B+s+o, C, Decider, Hide); }

	 //Mid Location
	       //Red             //Green          //Yellow           //Blue
	else if((n==11&&C==4) || (n==50&&C==2) || (n==37&&C==14) || (n==24&&C==1))
	 { Goot(i+s, ::j+s+B+s+o, C, Decider, Hide); }
	 //Special
	       //Red             //Yellow            //Blue
	else if((n==12&&C==4) || (n==38&&C==14) || (n==25&&C==1))
	 { Goot(i+s, ::j+s+B+s  , C, Decider, Hide); }

	 //Way3
	 //First Section
		//Blue           //Yellow          //Green          //Red
	else if((n==0&&C==1) || (n==13&&C==14) || (n==26&&C==2) || (n==39&&C==4))
	 { Goot(i+s+B+s+b+s+4*o, ::j+s+B+s+o+o, C, Decider, Hide); }
	else if((n==1&&C==1) || (n==14&&C==14) || (n==27&&C==2) || (n==40&&C==4))
	 { Goot(i+s+B+s+b+s+3*o, ::j+s+B+s+o+o, C, Decider, Hide); }
	else if((n==2&&C==1) || (n==15&&C==14) || (n==28&&C==2) || (n==41&&C==4))
	 { Goot(i+s+B+s+b+s+2*o, ::j+s+B+s+o+o, C, Decider, Hide); }
	else if((n==3&&C==1) || (n==16&&C==14) || (n==29&&C==2) || (n==42&&C==4))
	 { Goot(i+s+B+s+b+s+o  , ::j+s+B+s+o+o, C, Decider, Hide); }
	else if((n==4&&C==1) || (n==17&&C==14) || (n==30&&C==2) || (n==43&&C==4))
	 { Goot(i+s+B+s+b+s    , ::j+s+B+s+o+o, C, Decider, Hide); }
	 //Second Section
	       //Yellow           //Green          //Red            //Blue
	else if((n==5&&C==14)  || (n==18&&C==2) || (n==31&&C==4) || (n==44&&C==1))
	 { Goot(i+s+B+s+b+s    , ::j+s+B+s, C, Decider, Hide); }
	else if((n==6&&C==14)  || (n==19&&C==2) || (n==32&&C==4) || (n==45&&C==1))
	 { Goot(i+s+B+s+b+s+o  , ::j+s+B+s, C, Decider, Hide); }
	else if((n==7&&C==14)  || (n==20&&C==2) || (n==33&&C==4) || (n==46&&C==1))
	 { Goot(i+s+B+s+b+s+2*o, ::j+s+B+s, C, Decider, Hide); }
	else if((n==8&&C==14)  || (n==21&&C==2) || (n==34&&C==4) || (n==47&&C==1))
	 { Goot(i+s+B+s+b+s+3*o, ::j+s+B+s, C, Decider, Hide); }
	else if((n==9&&C==14)  || (n==22&&C==2) || (n==35&&C==4) || (n==48&&C==1))
	 { Goot(i+s+B+s+b+s+4*o, ::j+s+B+s, C, Decider, Hide); }
	else if((n==10&&C==14) || (n==23&&C==2) || (n==36&&C==4) || (n==49&&C==1))
	 { Goot(i+s+B+s+b+s+5*o, ::j+s+B+s, C, Decider, Hide); }
	 //Center Bared
	else if(n==51&&C==1)
	 { Goot(i+s+B+s+b+s+4*o, ::j+s+B+s+o, C, Decider, Hide); }
	else if(n==52&&C==1)
	 { Goot(i+s+B+s+b+s+3*o, ::j+s+B+s+o, C, Decider, Hide); }
	else if(n==53&&C==1)
	 { Goot(i+s+B+s+b+s+2*o, ::j+s+B+s+o, C, Decider, Hide); }
	else if(n==54&&C==1)
	 { Goot(i+s+B+s+b+s+o  , ::j+s+B+s+o, C, Decider, Hide); }
	else if(n==55&&C==1)
	 { Goot(i+s+B+s+b+s    , ::j+s+B+s+o, C, Decider, Hide); }
	 //Mid Location
		//Yellow           //Green          //Red            //Blue
	else if((n==11&&C==14) || (n==24&&C==2) || (n==37&&C==4) || (n==50&&C==1))
	 { Goot(i+s+B+s+b+s+5*o, ::j+s+B+s+o, C, Decider, Hide); }
	 //Special
		//Yellow          //Green          //Red
	else if((n==12&&C==14) || (n==25&&C==2) || (n==38&&C==4))
	 { Goot(i+s+B+s+b+s+5*o, ::j+s+B+s+o+o, C, Decider, Hide); }

	 //Way4
	 //First Section
		//Red            //Blue          //Green           //Yellow
	else if((n==0&&C==4) || (n==13&&C==1) || (n==39&&C==2) || (n==26&&C==14))
	 { Goot(i+s+B+s, ::j+s+B+s+b+s+4*o, C, Decider, Hide); }
	else if((n==1&&C==4) || (n==14&&C==1) || (n==40&&C==2) || (n==27&&C==14))
	 { Goot(i+s+B+s, ::j+s+B+s+b+s+3*o, C, Decider, Hide); }
	else if((n==2&&C==4) || (n==15&&C==1) || (n==41&&C==2) || (n==28&&C==14))
	 { Goot(i+s+B+s, ::j+s+B+s+b+s+2*o, C, Decider, Hide); }
	else if((n==3&&C==4) || (n==16&&C==1) || (n==42&&C==2) || (n==29&&C==14))
	 { Goot(i+s+B+s, ::j+s+B+s+b+s+o  , C, Decider, Hide); }
	else if((n==4&&C==4) || (n==17&&C==1) || (n==43&&C==2) || (n==30&&C==14))
	 { Goot(i+s+B+s, ::j+s+B+s+b+s    , C, Decider, Hide); }
	 //Second Section
		//Blue            //Yellow          //Green          //Red
	else if((n==5&&C==1)  || (n==18&&C==14) || (n==31&&C==2) || (n==44&&C==4))
	 { Goot(i+s+B+s+2*o, ::j+s+B+s+b+s    , C, Decider, Hide); }
	if((n==6&&C==1)  || (n==19&&C==14) || (n==32&&C==2) || (n==45&&C==4))
	 { Goot(i+s+B+s+2*o, ::j+s+B+s+b+s+o  , C, Decider, Hide); }
	else if((n==7&&C==1)  || (n==20&&C==14) || (n==33&&C==2) || (n==46&&C==4))
	 { Goot(i+s+B+s+2*o, ::j+s+B+s+b+s+2*o, C, Decider, Hide); }
	else if((n==8&&C==1)  || (n==21&&C==14) || (n==34&&C==2) || (n==47&&C==4))
	 { Goot(i+s+B+s+2*o, ::j+s+B+s+b+s+3*o, C, Decider, Hide); }
	else if((n==9&&C==1)  || (n==22&&C==14) || (n==35&&C==2) || (n==48&&C==4))
	 { Goot(i+s+B+s+2*o, ::j+s+B+s+b+s+4*o, C, Decider, Hide); }
	else if((n==10&&C==1) || (n==23&&C==14) || (n==36&&C==2) || (n==49&&C==4))
	 { Goot(i+s+B+s+2*o, ::j+s+B+s+b+s+5*o, C, Decider, Hide); }
	 //Mid Bared
	else if(n==51&&C==4)
	 { Goot(i+s+B+s+o, ::j+s+B+s+b+s+4*o, C, Decider, Hide); }
	else if(n==52&&C==4)
	 { Goot(i+s+B+s+o, ::j+s+B+s+b+s+3*o, C, Decider, Hide); }
	else if(n==53&&C==4)
	 { Goot(i+s+B+s+o, ::j+s+B+s+b+s+2*o, C, Decider, Hide); }
	else if(n==54&&C==4)
	 { Goot(i+s+B+s+o, ::j+s+B+s+b+s+o  , C, Decider, Hide); }
	else if(n==55&&C==4)
	 { Goot(i+s+B+s+o, ::j+s+B+s+b+s    , C, Decider, Hide); }
	 //Mid Location
	       //Blue            //Green          //Yellow      //Red
	else if((n==11&&C==1) || (n==37&&C==2) || (n==24&&C==14) || (n==50&&C==4))
	 { Goot(i+s+B+s+o, ::j+s+B+s+b+s+5*o, C, Decider, Hide); }
	 //Special
		//Blue            //Green          //Yellow
	else if((n==12&&C==1) || (n==38&&C==2) || (n==25&&C==14))
	 { Goot(i+s+B+s  , ::j+s+B+s+b+s+5*o, C, Decider, Hide); }
}

void Fix() {
	setfillstyle(1, ::CC);
	bar(i, 0, x, y);

	button(i+4, 4, x-3, y-3, c, c);
	button(i+5, 5, x-5, y-5, c, c);
	button(i+6, 6, x-4, y-4, c, c);

	setcolor(0);
	//Notification bar
	setfillstyle(1, ::C);
	bar(10, N-17, 150, N-2);
	outtextxy(12, N-12, "Notifications:");

	//Options bar
	setfillstyle(1, ::C);
	bar(10, O-17, 150, O-2);
	outtextxy(12, O-12, "Options:");
	bar(10, O, 150, O+50);

	outtextxy(20, O+5,  "Exit:        E");
	outtextxy(20, O+15, "MUTE:        M");

	//Goot Bar
	setfillstyle(1, ::C);
	bar(10, G, 150, G+4*o+10);

	//Toss
	setfillstyle(1, ::C);
	bar(15, y-40, 145, y-10);

	//make box of toss
	button(115, y-32, 135, y-12, c, c);

	outtextxy(60, y-35, "TOOS");
	outtextxy(20, y-23, "Start/Stop:");
	line(20, y-14, 25, y-14);
	line(67, y-14, 73, y-14);
}

int ErrorChecker() {
	int GreenDecider[4]={-1, -1, -1, -1}, YellowDecider[4]={-1, -1, -1, -1};
	int RedDecider[4]={-1, -1, -1, -1}, BlueDecider[4]={-1, -1, -1, -1};
	int ErrorCounter=0;

	int H_GREEN=0, H_YELLOW=0, H_RED=0, H_BLUE=0;

	for(int y=0; y<4; y++) {
		for(int i=0; i<57; i++) {
			if(Ob.Green[i][y] ) { GreenDecider[y]++;  }
			if(Ob.Yellow[i][y]) { YellowDecider[y]++; }
			if(Ob.Red[i][y]   ) { RedDecider[y]++;    }
			if(Ob.Blue[i][y]  ) { BlueDecider[y]++;   }
		}
	}
	for(y=0; y<4; y++) { if(GreenDecider[y]  > 0) { ErrorCounter++; } }
	for(y=0; y<4; y++) { if(YellowDecider[y] > 0) { ErrorCounter++; } }
	for(y=0; y<4; y++) { if(RedDecider[y]    > 0) { ErrorCounter++; } }
	for(y=0; y<4; y++) { if(BlueDecider[y]   > 0) { ErrorCounter++; } }

	if(Ob.H_Green<-1 || Ob.H_Green>3)   { H_GREEN=1;  ErrorCounter++; }
	if(Ob.H_Yellow<-1 || Ob.H_Yellow>3) { H_YELLOW=1; ErrorCounter++; }
	if(Ob.H_Red<-1 || Ob.H_Red>3)       { H_RED=1;    ErrorCounter++; }
	if(Ob.H_Blue<-1 || Ob.H_Blue>3)     { H_BLUE=1;   ErrorCounter++; }

	if(ErrorCounter==0) { return(0); }

	cleardevice();
	clrscr();

	setfillstyle(1, 0);
	bar(0, 0, ::x, ::y);

	setcolor(15);

	settextjustify(0, 1);
	settextstyle(0, 0, 2);
	outtextxy(50 , ::y-70, "We are sorry to say that an error");
	outtextxy(190, ::y-50, "has been occured.");

	int i=150, j=-20;
	rectangle(::x/2-50+i, ::y/2-60+j, ::x/2+50+i, ::y/2+60+j);	//Rectangle
	line     (::x/2+i   , ::y/2-10+j, ::x/2+i   , ::y/2+10+j);	//nose
	line     (::x/2-25+i, ::y/2-34+j, ::x/2-32+i, ::y/2-41+j);	//Left eye
	line     (::x/2+25+i, ::y/2-34+j, ::x/2+32+i, ::y/2-41+j);	//Right eye
	line     (::x/2-20+i, ::y/2+40+j, ::x/2+20+i, ::y/2+40+j);	//Mouth Straight
	line     (::x/2-25+i, ::y/2+45+j, ::x/2-20+i, ::y/2+40+j);	//Mouth Left Tilted
	line     (::x/2+20+i, ::y/2+40+j, ::x/2+25+i, ::y/2+45+j);	//Mouth Right Tilted
	setcolor(0);
	line     (::x/2+35+i, ::y/2-60+j, ::x/2+50+i, ::y/2-60+j);	//Upper line to hide last part of rectangle
	line     (::x/2+50+i, ::y/2-60+j, ::x/2+50+i, ::y/2-45+j);	//Lower line to hide last part of rectangle
	setcolor(15);
	line     (::x/2+35+i, ::y/2-60+j, ::x/2+50+i, ::y/2-45+j);	//Tilted line on rectangle
	line     (::x/2+35+i, ::y/2-60+j, ::x/2+35+i, ::y/2-45+j);	//Left  line on rectengle to show folded page
	line     (::x/2+35+i, ::y/2-45+j, ::x/2+50+i, ::y/2-45+j);	//Right line on rectengle to show folded page

	j = ::y/2.0 - (ErrorCounter/2.0)*10.0;

	settextjustify(0, 1);
	settextstyle(0, 0, 2);
	outtextxy(20, j, "Error List:");
	j+=20;

	settextstyle(0, 0, 0);
	if(GreenDecider[0] > 0) { outtextxy(25, j, " -> Green[0]"); j+=10; }
	if(GreenDecider[1] > 0) { outtextxy(25, j, " -> Green[1]"); j+=10; }
	if(GreenDecider[2] > 0) { outtextxy(25, j, " -> Green[2]"); j+=10; }
	if(GreenDecider[3] > 0) { outtextxy(25, j, " -> Green[3]"); j+=10; }

	if(YellowDecider[0] > 0) { outtextxy(25, j, " -> Yellow[0]"); j+=10; }
	if(YellowDecider[1] > 0) { outtextxy(25, j, " -> Yellow[1]"); j+=10; }
	if(YellowDecider[2] > 0) { outtextxy(25, j, " -> Yellow[2]"); j+=10; }
	if(YellowDecider[3] > 0) { outtextxy(25, j, " -> Yellow[3]"); j+=10; }

	if(RedDecider[0] > 0) { outtextxy(25, j, " -> Red[0]"); j+=10; }
	if(RedDecider[1] > 0) { outtextxy(25, j, " -> Red[1]"); j+=10; }
	if(RedDecider[2] > 0) { outtextxy(25, j, " -> Red[2]"); j+=10; }
	if(RedDecider[3] > 0) { outtextxy(25, j, " -> Red[3]"); j+=10; }

	if(BlueDecider[0] > 0) { outtextxy(25, j, " -> Blue[0]"); j+=10; }
	if(BlueDecider[1] > 0) { outtextxy(25, j, " -> Blue[1]"); j+=10; }
	if(BlueDecider[2] > 0) { outtextxy(25, j, " -> Blue[2]"); j+=10; }
	if(BlueDecider[3] > 0) { outtextxy(25, j, " -> Blue[3]"); j+=10; }

	if(H_GREEN)  { outtextxy(25, j, " -> H_Green" ); j+=10; }
	if(H_YELLOW) { outtextxy(25, j, " -> H_Yellow"); j+=10; }
	if(H_RED)    { outtextxy(25, j, " -> H_Red"   ); j+=10; }
	if(H_BLUE)   { outtextxy(25, j, " -> H_Blue"  ); j+=10; }

	settextjustify(1, 1);
	outtextxy(2*::x/3, ::y-10, "Press enter to go to menu...");

	do { } while(getch()!=13);

	return(1);
}

void DataViewer() {
	setcolor(15);

	cleardevice();
	clrscr();
	setfillstyle(1, 0);
	bar(0, 0, ::x, ::y);

	settextjustify(0, 2);
	outtextxy(10, 40, "Green[0]");
	outtextxy(10, 50, "Green[1]");
	outtextxy(10, 60, "Green[2]");
	outtextxy(10, 70, "Green[3]");

	for(int i=0, z=0; i<57; i++, z += 7) {
		char a = Ob.Tosses[i];
		outtextxy(z, 10, a);
	}

	getch();

	exit(0);
}

void End() {
	int poly[8];
	{	//First Green Triangle
		poly[0]=i+s+B+s;
		poly[1]=s+B+s;
		poly[2]=i+s+B+s+b/2;
		poly[3]=s+B+s+b/2;
		poly[4]=i+s+B+s;
		poly[5]=s+B+s+b;
		poly[6]=i+s+B+s;
		poly[7]=s+B+s;

		setfillstyle(1, 2);
		fillpoly(4, poly);
		setcolor(c);
		drawpoly(4, poly);
	}
	{	//Second Yellow Triangle
		poly[0]=i+s+B+s;
		poly[1]=s+B+s;
		poly[2]=i+s+B+s+b;
		poly[3]=s+B+s;
		poly[4]=i+s+B+s+b/2;
		poly[5]=s+B+s+b/2;
		poly[6]=i+s+B+s;
		poly[7]=s+B+s;

		setfillstyle(1, YELLOW);
		fillpoly(4, poly);
		setcolor(c);
		drawpoly(4, poly);

	}
	{	//Third Blue Triangle
		poly[0]=i+s+B+s+b/2;
		poly[1]=s+B+s+b/2;
		poly[2]=i+s+B+s+b;
		poly[3]=s+B+s;
		poly[4]=i+s+B+s+b;
		poly[5]=s+B+s+b;
		poly[6]=i+s+B+s+b/2;
		poly[7]=s+B+s+b/2;

		setfillstyle(1, 1);
		fillpoly(4, poly);
		setcolor(c);
		drawpoly(4, poly);
	}
	{	//Forth Red Triangle
		poly[0]=i+s+B+s;
		poly[1]=s+B+s+b;
		poly[2]=i+s+B+s+b/2;
		poly[3]=s+B+s+b/2;
		poly[4]=i+s+B+s+b;
		poly[5]=s+B+s+b;
		poly[6]=i+s+B+s;
		poly[7]=s+B+s+b;

		setfillstyle(1, 4);
		fillpoly(4, poly);
		setcolor(c);
		drawpoly(4, poly);

	}
	button(i+s+B+s    , s+B+s    , i+s+B+s+b    , s+B+s+b    , c, c);
}

void Home1() {
	setfillstyle(1, 2);
	bar(i+s, s, i+s+B, s+B);

	button(i+s, s, i+s+B, s+B, c, c);

	int poly[10]={i+s, s+B/2, i+s+B/2, s, i+s+B, s+B/2, i+s+B/2, s+B, i+s, s+B/2};

	setfillstyle(1, 15);
	fillpoly(5, poly);

	setcolor(c);
	drawpoly(5, poly);

	poly[0]=i+s+o;
	poly[1]=s+B/2;
	poly[2]=i+s+B/2;
	poly[3]=s+o;
	poly[4]=i+s+B-o;
	poly[5]=s+B/2;
	poly[6]=i+s+B/2;
	poly[7]=s+B-o;
	poly[8]=i+s+o;
	poly[9]=s+B/2;

	setfillstyle(1, 2);
	fillpoly(5, poly);

	setcolor(c);
	drawpoly(5, poly);

}

void Home2() {
	setfillstyle(1, YELLOW);
	bar(i+s+B+s+b+s, s, i+s+B+s+b+s+B, s+B);

	button(i+s+B+s+b+s, s, i+s+B+s+b+s+B, s+B, c, c);

	int poly[10]={i+s+B+s+b+s, s+B/2, i+s+B+s+b+s+B/2, s, i+s+B+s+b+s+B, s+B/2, i+s+B+s+b+s+B/2, s+B, i+s+B+s+b+s, s+B/2};

	setfillstyle(1, 15);
	fillpoly(5, poly);

	setcolor(c);
	drawpoly(5, poly);

	poly[0]=i+s+B+s+b+s+o;
	poly[1]=s+B/2;

	poly[2]=i+s+B+s+b+s+B/2;
	poly[3]=s+o;

	poly[4]=i+s+B+s+b+s+B-o;
	poly[5]=s+B/2;

	poly[6]=i+s+B+s+b+s+B/2;
	poly[7]=s+B-o;

	poly[8]=i+s+B+s+b+s+o;
	poly[9]=s+B/2;

	setfillstyle(1, YELLOW);
	fillpoly(5, poly);

	setcolor(c);
	drawpoly(5, poly);
}

void Home3() {
	setfillstyle(1, 4);
	bar(i+s, s+B+s+b+s, i+s+B, s+B+s+b+s+B);

	button(i+s, s+B+s+b+s, i+s+B, s+B+s+b+s+B, c, c);

	int poly[10]={i+s, s+B+s+b+s+B/2, i+s+B/2, s+B+s+b+s, i+s+B, s+B+s+b+s+B/2, i+s+B/2, s+B+s+b+s+B, i+s, s+B+s+b+s+B/2};

	setfillstyle(1, 15);
	fillpoly(5, poly);

	setcolor(c);
	drawpoly(5, poly);

	poly[0]=i+s+o;
	poly[1]=s+B+s+b+s+B/2;
	poly[2]=i+s+B/2;
	poly[3]=s+B+s+b+s+o;
	poly[4]=i+s+B-o;
	poly[5]=s+B+s+b+s+B/2;
	poly[6]=i+s+B/2;
	poly[7]=s+B+s+b+s+B-o;
	poly[8]=i+s+o;
	poly[9]=s+B+s+b+s+B/2;

	setfillstyle(1, 4);
	fillpoly(5, poly);

	setcolor(c);
	drawpoly(5, poly);
}

void Home4() {
	setfillstyle(1, 1);
	bar(i+s+B+s+b+s, s+B+s+b+s, i+s+B+s+b+s+B, s+B+s+b+s+B);

	button(i+s+B+s+b+s, s+B+s+b+s, i+s+B+s+b+s+B, s+B+s+b+s+B, c, c);

	int poly[10]={i+s+B+s+b+s, s+B+s+b+s+B/2, i+s+B+s+b+s+B/2, s+B+s+b+s, i+s+B+s+b+s+B, s+B+s+b+s+B/2, i+s+B+s+b+s+B/2, s+B+s+b+s+B, i+s+B+s+b+s, s+B+s+b+s+B/2};

	setfillstyle(1, 15);
	fillpoly(5, poly);

	setcolor(c);
	drawpoly(5, poly);

	poly[0]=i+s+B+s+b+s+o;
	poly[1]=s+B+s+b+s+B/2;
	poly[2]=i+s+B+s+b+s+B/2;
	poly[3]=s+B+s+b+s+o;
	poly[4]=i+s+B+s+b+s+B-o;
	poly[5]=s+B+s+b+s+B/2;
	poly[6]=i+s+B+s+b+s+B/2;
	poly[7]=s+B+s+b+s+B-o;
	poly[8]=i+s+B+s+b+s+o;
	poly[9]=s+B+s+b+s+B/2;

	setfillstyle(1, 1);
	fillpoly(5, poly);

	setcolor(c);
	drawpoly(5, poly);
}
/*--------------------------------------------------------------------*/
/*--------------------------------------------------------------------*/
/*--------------------------------------------------------------------*/
/*--------------------------MENU/HELP/CREDITS/------------------------*/

void thgtxt(int x, int y, char* a) //to create a txt efect at x,y
{
	int col = getcolor(), t = 0;
	int width = textwidth("A"), height = textheight("A");
	char buf[2] = " \n";
	for (int i = 0; a[i]; i++) {
		buf[0] = a[i];
		if (buf[0] == 'i')
			t = width / 3;
		else if (buf[0] == 'I')
			t = width / 4.0;
		else
			t = 0;
		for (int tx = x + width * i + width / 2.0 + t, ty = y - 2 * height; tx > x + width * i + t && ty < y + height;) {
			setcolor(BLACK);
			outtextxy(tx, ty, buf);
			tx -= 2;
			ty += 2;
			setcolor(col);
			outtextxy(tx, ty, buf);
			delay(10);
		}
	}
}

void Logo() {
	setcolor(WHITE);
	settextstyle(1, 0, 4);
	thgtxt(130, 80, "C++ Project 2018");
	setcolor(BROWN);
	settextstyle(1, 0, 4);
	thgtxt(140, 180, "USAMA");
	thgtxt(180, 210, "IFTIKHAR");
	thgtxt(280, 240, "BUTT");
	setcolor(WHITE);
	delay(200);

	int q=220;	//q = x axis
	int w=310;	//w = y axis
	int e=50 ;	//e = size of one side

	for(e=0; e<30; e++) {
		int poly[10]={ q, w-2*e, q+e, w-e, q, w, q-e, w-e, q, w-2*e };
		setfillstyle(1, 4);
		fillpoly(4, poly);

		poly[0]=q-e  ; poly[1]=w-e;
		poly[2]=q    ; poly[3]=w  ;
		poly[4]=q-e  ; poly[5]=w+e;
		poly[6]=q-2*e; poly[7]=w  ;
		poly[8]=q-e  ; poly[9]=w-e;

		setfillstyle(1, 2);
		fillpoly(4, poly);

		poly[0]=q    ; poly[1]=w  ;
		poly[2]=q+e  ; poly[3]=w-e;
		poly[4]=q+2*e; poly[5]=w  ;
		poly[6]=q+e  ; poly[7]=w+e;
		poly[8]=q    ; poly[9]=w  ;

		setfillstyle(1, 14);
		fillpoly(4, poly);

		poly[0]=q-e  ; poly[1]=w+e  ;
		poly[2]=q    ; poly[3]=w    ;
		poly[4]=q+e  ; poly[5]=w+e  ;
		poly[6]=q    ; poly[7]=w+2*e;
		poly[8]=q-e  ; poly[9]=w+e  ;

		setfillstyle(1, 1);
		fillpoly(4, poly);

		delay(15);
	}

	setfillstyle(1, 7);

	circle(q, w-e, e/6);
	floodfill(q+1, w-e+1, 15);

	circle(q-e, w, e/6);
	floodfill(q-e+1, w+1, 15);

	circle(q+e, w, e/6);
	floodfill(q+e+1, w+1, 15);

	circle(q, w+e, e/6);
	floodfill(q+1, w+e+1, 15);

	settextstyle(2, 0, 10);

	for(int z=0; z<q+5; z++) {
		setfillstyle(1, 0);
		bar(0, w+4*e-50, getmaxx(), w+4*e+20);

		setcolor(4);
		outtextxy(z, w+2*e, "L");

		setcolor(14);
		outtextxy(z, w+2*e, " u");

		setcolor(2);
		outtextxy(z, w+2*e, "  d");

		setcolor(1);
		outtextxy(z, w+2*e, "   o");
	}
	settextstyle(0, 0, 0);

	getch();
}

int Menu() {
	Back:
	cleardevice();

	BackGround();

	settextjustify(1, 1);
	setcolor(15);

	settextstyle(1, 0, 5);
	outtextxy(::x/2, 2*::y/10, "Desi Ludo");

	settextstyle(1, 0, 3);
	outtextxy(::x/2, 5*::y/10, "PLAY");
	outtextxy(::x/2, 6*::y/10, "HELP");
	outtextxy(::x/2, 7*::y/10, "CREDITS");
	outtextxy(::x/2, 8*::y/10, "EXIT");

	int i=::x/2, j=5*::y/10, a=5;

	while(1) {
		Hover(i, j, 1);

		char S=getch();

		Hover(i, j, 0);

		if     (S==72 && j!=5*::y/10) { a--; j=a*::y/10; }
		else if(S==72 && j==5*::y/10) { a=8; j=a*::y/10; }
		else if(S==80 && j!=8*::y/10) { a++; j=a*::y/10; }
		else if(S==80 && j==8*::y/10) { a=5; j=a*::y/10; }
		else if(S==13)                { break;           }
	}

	if(j==5*::y/10) {
		int S=Play();

		if  (S) { return(S); }
	}
	else if(j==6*::y/10) { Help();    }
	else if(j==7*::y/10) { Credits(); }
	else                 { exit(0);   }

	goto Back;
}

void Hover(int i, int j, int Decider) {
	if(Decider) {
		setfillstyle(1, 0);
		bar(i-100, j-20+3, i+100, j+20+3);

		setcolor(15);
		rectangle(i-100, j-20+3, i+100, j+20+3);
		rectangle(i-98, j-18+3, i+98, j+18+3);

		settextstyle(1, 0, 4);
		if     (j==5*::y/10) { outtextxy(::x/2, 5*::y/10, "PLAY");    }
		else if(j==6*::y/10) { outtextxy(::x/2, 6*::y/10, "HELP");    }
		else if(j==7*::y/10) { outtextxy(::x/2, 7*::y/10, "CREDITS"); }
		else                 { outtextxy(::x/2, 8*::y/10, "EXIT");    }
	}
	else {
		setfillstyle(1, 0);
		bar(i-100, j-20+3, i+100, j+20+3);

		settextstyle(1, 0, 3);
		if     (j==5*::y/10) { outtextxy(::x/2, 5*::y/10, "PLAY");    }
		else if(j==6*::y/10) { outtextxy(::x/2, 6*::y/10, "HELP");    }
		else if(j==7*::y/10) { outtextxy(::x/2, 7*::y/10, "CREDITS"); }
		else                 { outtextxy(::x/2, 8*::y/10, "EXIT");    }
	}
}

int Play() {
	SelectAgain:

	cleardevice();

	BackGround();

	setcolor(15);
	settextjustify(1, 1);
	settextstyle(0, 0, 0);
	outtextxy(::x/2, 20, "Select the playing mode.");
	outtextxy(::x/2, 40, "You can vary players.");
	outtextxy(::x/2, 60, "You can also play with computer.");

	int z=150;	//width
	int j=160;	//x axis
	int k=100;	//y axis
	int v=10;	//space
	enum LOGOS { NOTHING, MAN, COMPUTER };
	int LogoX=50;

	setfillstyle(1, 2);
	bar(j, k, j+z, k+z);

	setfillstyle(1, 14);
	bar(j+z+v, k, j+z+v+z, k+z);

	setfillstyle(1, 4);
	bar(j, k+z+v, j+z, k+z+v+z);

	setfillstyle(1, 1);
	bar(j+z+v, k+z+v, j+z+v+z, k+z+v+z);

	settextstyle(0, 0, 0);
	settextjustify(1, 1);

	outtextxy(j+z/2    , k+10                   , "First Player" );
	outtextxy(j+z/2    , k+z-10    , "Not Selected");
	outtextxy(j+z+v+z/2, k+10                   , "Second Player");
	outtextxy(j+z+v+z/2, k+z-10    , "Not Selected");
	outtextxy(j+z/2    , k+z+v+10               , "Third Player" );
	outtextxy(j+z/2    , k+z+v+z-10, "Not Selected");
	outtextxy(j+z+v+z/2, k+z+v+10               , "Forth Player" );
	outtextxy(j+z+v+z/2, k+z+v+z-10, "Not Selected");

	settextjustify(0, 1);

	outtextxy(j+2*z/5, k+2*z/6, "No Player");
	outtextxy(j+2*z/5, k+3*z/6, "User");
	outtextxy(j+2*z/5, k+4*z/6, "Computer");
	Logos(j+z/2-LogoX, k+2*z/6, NOTHING);
	Logos(j+z/2-LogoX, k+3*z/6, MAN);
	Logos(j+z/2-LogoX, k+4*z/6, COMPUTER);

	outtextxy(j+z+v+2*z/5, k+2*z/6, "No Player");
	outtextxy(j+z+v+2*z/5, k+3*z/6, "User");
	outtextxy(j+z+v+2*z/5, k+4*z/6, "Computer");
	Logos(j+z+v+z/2-LogoX, k+2*z/6, NOTHING);
	Logos(j+z+v+z/2-LogoX, k+3*z/6, MAN);
	Logos(j+z+v+z/2-LogoX, k+4*z/6, COMPUTER);

	outtextxy(j+2*z/5, k+z+v+2*z/6, "No Player");
	outtextxy(j+2*z/5, k+z+v+3*z/6, "User");
	outtextxy(j+2*z/5, k+z+v+4*z/6, "Computer");
	Logos(j+z/2-LogoX, k+z+v+2*z/6, NOTHING);
	Logos(j+z/2-LogoX, k+z+v+3*z/6, MAN);
	Logos(j+z/2-LogoX, k+z+v+4*z/6, COMPUTER);

	outtextxy(j+z+v+2*z/5, k+z+v+2*z/6, "No Player");
	outtextxy(j+z+v+2*z/5, k+z+v+3*z/6, "User");
	outtextxy(j+z+v+2*z/5, k+z+v+4*z/6, "Computer");
	Logos(j+z+v+z/2-LogoX, k+z+v+2*z/6, NOTHING);
	Logos(j+z+v+z/2-LogoX, k+z+v+3*z/6, MAN);
	Logos(j+z+v+z/2-LogoX, k+z+v+4*z/6, COMPUTER);

	settextjustify(1, 1);
	settextstyle(1, 0, 3);
	outtextxy(::x/5, 14*::y/15, "BACK");
	outtextxy(4*::x/5, 14*::y/15, "START");

	int HoverDecider=1, Color;
	float I, J=2, x=j+2*z/5, y=k+J*z/6;
	char S, *Option="No Player";	//S=Selector, *Option=Saves the option
	int OptionColor[7][2]={
				{15, 15},
				{15, 15},
				{15, 15},
				{15, 15},
				{15, 15},
				{15, 15},
				{15, 15}
			      };
	int a=0, b=0, SelectedColor=6;

	while(1){
		//Hide Hover Color Decider
		if     (x==j+2*z/5     && y>=k+2*z/6    &&y<=k+4*z/6     ) { Color=2 ; }
		else if(x==j+z+v+2*z/5 && y>=k+2*z/6    &&y<=k+4*z/6     ) { Color=14; }
		else if(x==j+2*z/5     && y>=k+z+v+2*z/6&&y<=k+z+v+4*z/6 ) { Color=4 ; }
		else if(x==j+z+v+2*z/5 && y>=k+z+v+2*z/6&&y<=k+z+v+4*z/6 ) { Color=1 ; }

		PlayHover(x, y, 1, HoverDecider, Color, Option, OptionColor[a][b]);
		S=getch();
		PlayHover(x, y, 0, HoverDecider, Color, Option, OptionColor[a][b]);

		if(S==77 || S==75) {	//Left and Right Key
			if     (x==j+2*z/5    ) { x=j+z+v+2*z/5; HoverDecider=1; b=1; }
			else if(x==j+z+v+2*z/5) { x=j+2*z/5;     HoverDecider=1; b=0; }

			else if(x==4*::x/5) { x=::x/5;   HoverDecider=0; Option="BACK" ; b=0; }
			else if(x==::x/5  ) { x=4*::x/5; HoverDecider=0; Option="START"; b=1; }
		}

		else if(S==80) {	//Down Key
			if     (y==k+2*z/6    ) { y=k+3*z/6;     HoverDecider=1; Option="User"     ; a=1; }
			else if(y==k+3*z/6    ) { y=k+4*z/6;     HoverDecider=1; Option="Computer" ; a=2; }
			else if(y==k+4*z/6    ) { y=k+z+v+2*z/6; HoverDecider=1; Option="No Player"; a=3; }
			else if(y==k+z+v+2*z/6) { y=k+z+v+3*z/6; HoverDecider=1; Option="User"     ; a=4; }
			else if(y==k+z+v+3*z/6) { y=k+z+v+4*z/6; HoverDecider=1; Option="Computer" ; a=5; }

			else if(y==k+z+v+4*z/6) {
				y=14*::y/15;
				HoverDecider=0;
				a=6;

				if     (x==j+2*z/5    ) { x=::x/5;   Option="BACK" ; b=0; }
				else if(x==j+z+v+2*z/5) { x=4*::x/5; Option="START"; b=1; }
			}

			else if(y==14*::y/15) {
				y=k+2*z/6;
				HoverDecider=1;
				a=0;

				if(x==::x/5) { x=j+2*z/5;     Option="No Player"; b=0; }
				else         { x=j+z+v+2*z/5; Option="No Player"; b=1; }
			}
		}
		else if(S==72) {	//Up Key
			if(y==k+2*z/6) {
				y=14*::y/15;
				HoverDecider=0;
				a=6;

				if     (x==j+2*z/5    ) { x=::x/5;   Option="BACK" ; b=0; }
				else if(x==j+z+v+2*z/5) { x=4*::x/5; Option="START"; b=1; }
			}

			else if(y==14*::y/15) {
				y=k+z+v+4*z/6;
				HoverDecider=1;
				a=5;

				if(x==::x/5) { x=j+2*z/5;     Option="Computer"; b=0; }
				else         { x=j+z+v+2*z/5; Option="Computer"; b=1; }
			}

			else if(y==k+z+v+4*z/6) { y=k+z+v+3*z/6; HoverDecider=1; Option="User"     ; a=4; }
			else if(y==k+z+v+3*z/6) { y=k+z+v+2*z/6; HoverDecider=1; Option="No Player"; a=3; }
			else if(y==k+z+v+2*z/6) { y=k+4*z/6;     HoverDecider=1; Option="Computer" ; a=2; }
			else if(y==k+4*z/6)     { y=k+3*z/6;     HoverDecider=1; Option="User"     ; a=1; }
			else if(y==k+3*z/6)     { y=k+2*z/6;     HoverDecider=1; Option="No Player"; a=0; }
		}
		else if(S==13) {
			if(y==14*::y/15) { break; }

			//0*0
			else if(x==j+2*z/5 && y==k+2*z/6) { OptionColor[0][0]=SelectedColor; OptionColor[1][0]=15; OptionColor[2][0]=15; PlayHover(j+2*z/5, k+3*z/6, 0, 1, 2, "User"     , OptionColor[1][0]); PlayHover(j+2*z/5, k+4*z/6, 0, 1, 2, "Computer", OptionColor[2][0]); setfillstyle(1, 2); bar(j+z/2-50, k+z-10-4, j+z/2+50, k+z-10+3); settextjustify(1, 1); outtextxy(j+z/2, k+z-10, "Selected"); }
			else if(x==j+2*z/5 && y==k+3*z/6) { OptionColor[1][0]=SelectedColor; OptionColor[0][0]=15; OptionColor[2][0]=15; PlayHover(j+2*z/5, k+2*z/6, 0, 1, 2, "No Player", OptionColor[0][0]); PlayHover(j+2*z/5, k+4*z/6, 0, 1, 2, "Computer", OptionColor[2][0]); setfillstyle(1, 2); bar(j+z/2-50, k+z-10-4, j+z/2+50, k+z-10+3); settextjustify(1, 1); outtextxy(j+z/2, k+z-10, "Selected"); }
			else if(x==j+2*z/5 && y==k+4*z/6) { OptionColor[2][0]=SelectedColor; OptionColor[0][0]=15; OptionColor[1][0]=15; PlayHover(j+2*z/5, k+2*z/6, 0, 1, 2, "No Player", OptionColor[0][0]); PlayHover(j+2*z/5, k+3*z/6, 0, 1, 2, "User"    , OptionColor[1][0]); setfillstyle(1, 2); bar(j+z/2-50, k+z-10-4, j+z/2+50, k+z-10+3); settextjustify(1, 1); outtextxy(j+z/2, k+z-10, "Selected"); }
			//0*1
			else if(x==j+z+v+2*z/5 && y==k+2*z/6) { OptionColor[0][1]=SelectedColor; OptionColor[1][1]=15; OptionColor[2][1]=15; PlayHover(j+z+v+2*z/5, k+3*z/6, 0, 1, 14, "User"     , OptionColor[1][1]); PlayHover(j+z+v+2*z/5, k+4*z/6, 0, 1, 14, "Computer", OptionColor[2][1]); setfillstyle(1, 14); bar(j+z+v+z/2-50, k+z-10-4, j+z+v+z/2+50, k+z-10+3); settextjustify(1, 1); outtextxy(j+z+v+z/2, k+z-10, "Selected"); }
			else if(x==j+z+v+2*z/5 && y==k+3*z/6) { OptionColor[1][1]=SelectedColor; OptionColor[0][1]=15; OptionColor[2][1]=15; PlayHover(j+z+v+2*z/5, k+2*z/6, 0, 1, 14, "No Player", OptionColor[0][1]); PlayHover(j+z+v+2*z/5, k+4*z/6, 0, 1, 14, "Computer", OptionColor[2][1]); setfillstyle(1, 14); bar(j+z+v+z/2-50, k+z-10-4, j+z+v+z/2+50, k+z-10+3); settextjustify(1, 1); outtextxy(j+z+v+z/2, k+z-10, "Selected"); }
			else if(x==j+z+v+2*z/5 && y==k+4*z/6) { OptionColor[2][1]=SelectedColor; OptionColor[0][1]=15; OptionColor[1][1]=15; PlayHover(j+z+v+2*z/5, k+2*z/6, 0, 1, 14, "No Player", OptionColor[0][1]); PlayHover(j+z+v+2*z/5, k+3*z/6, 0, 1, 14, "User"    , OptionColor[1][1]); setfillstyle(1, 14); bar(j+z+v+z/2-50, k+z-10-4, j+z+v+z/2+50, k+z-10+3); settextjustify(1, 1); outtextxy(j+z+v+z/2, k+z-10, "Selected"); }
			//1*0
			else if(x==j+2*z/5 && y==k+z+v+2*z/6) { OptionColor[3][0]=SelectedColor; OptionColor[4][0]=15; OptionColor[5][0]=15; PlayHover(j+2*z/5, k+z+v+3*z/6, 0, 1, 4, "User"     , OptionColor[4][0]); PlayHover(j+2*z/5, k+z+v+4*z/6, 0, 1, 4, "Computer", OptionColor[5][0]); setfillstyle(1, 4); bar(j+z/2-50, k+z+v+z-10-4, j+z/2+50, k+z+v+z-10+3); settextjustify(1, 1); outtextxy(j+z/2, k+z+v+z-10, "Selected"); }
			else if(x==j+2*z/5 && y==k+z+v+3*z/6) { OptionColor[4][0]=SelectedColor; OptionColor[3][0]=15; OptionColor[5][0]=15; PlayHover(j+2*z/5, k+z+v+2*z/6, 0, 1, 4, "No Player", OptionColor[3][0]); PlayHover(j+2*z/5, k+z+v+4*z/6, 0, 1, 4, "Computer", OptionColor[5][0]); setfillstyle(1, 4); bar(j+z/2-50, k+z+v+z-10-4, j+z/2+50, k+z+v+z-10+3); settextjustify(1, 1); outtextxy(j+z/2, k+z+v+z-10, "Selected"); }
			else if(x==j+2*z/5 && y==k+z+v+4*z/6) { OptionColor[5][0]=SelectedColor; OptionColor[3][0]=15; OptionColor[4][0]=15; PlayHover(j+2*z/5, k+z+v+2*z/6, 0, 1, 4, "No Player", OptionColor[3][0]); PlayHover(j+2*z/5, k+z+v+3*z/6, 0, 1, 4, "User"    , OptionColor[4][0]); setfillstyle(1, 4); bar(j+z/2-50, k+z+v+z-10-4, j+z/2+50, k+z+v+z-10+3); settextjustify(1, 1); outtextxy(j+z/2, k+z+v+z-10, "Selected"); }
			//1*1
			else if(x==j+z+v+2*z/5 && y==k+z+v+2*z/6) { OptionColor[3][1]=SelectedColor; OptionColor[4][1]=15; OptionColor[5][1]=15; PlayHover(j+z+v+2*z/5, k+z+v+3*z/6, 0, 1, 1, "User"     , OptionColor[4][1]); PlayHover(j+z+v+2*z/5, k+z+v+4*z/6, 0, 1, 1, "Computer", OptionColor[5][1]); setfillstyle(1, 1); bar(j+z+v+z/2-50, k+z+v+z-10-4, j+z+v+z/2+50, k+z+v+z-10+3); settextjustify(1, 1); outtextxy(j+z+v+z/2, k+z+v+z-10, "Selected"); }
			else if(x==j+z+v+2*z/5 && y==k+z+v+3*z/6) { OptionColor[4][1]=SelectedColor; OptionColor[3][1]=15; OptionColor[5][1]=15; PlayHover(j+z+v+2*z/5, k+z+v+2*z/6, 0, 1, 1, "No Player", OptionColor[3][1]); PlayHover(j+z+v+2*z/5, k+z+v+4*z/6, 0, 1, 1, "Computer", OptionColor[5][1]); setfillstyle(1, 1); bar(j+z+v+z/2-50, k+z+v+z-10-4, j+z+v+z/2+50, k+z+v+z-10+3); settextjustify(1, 1); outtextxy(j+z+v+z/2, k+z+v+z-10, "Selected"); }
			else if(x==j+z+v+2*z/5 && y==k+z+v+4*z/6) { OptionColor[5][1]=SelectedColor; OptionColor[3][1]=15; OptionColor[4][1]=15; PlayHover(j+z+v+2*z/5, k+z+v+2*z/6, 0, 1, 1, "No Player", OptionColor[3][1]); PlayHover(j+z+v+2*z/5, k+z+v+3*z/6, 0, 1, 1, "User"    , OptionColor[4][1]); setfillstyle(1, 1); bar(j+z+v+z/2-50, k+z+v+z-10-4, j+z+v+z/2+50, k+z+v+z-10+3); settextjustify(1, 1); outtextxy(j+z+v+z/2, k+z+v+z-10, "Selected"); }
		}
	}

	if(x==4*::x/5) {
		int FirstPlayer=0, SecondPlayer=0, ThirdPlayer=0, ForthPlayer=0;
		int Decider=0, Decider2=1;

		if     (OptionColor[0][0]!=15) { FirstPlayer = 0   ; Decider2++; }
		else if(OptionColor[1][0]!=15) { FirstPlayer = 1000;             }
		else if(OptionColor[2][0]!=15) { FirstPlayer = 2000;             }
		else                           { Decider=1;                      }

		if     (OptionColor[0][1]!=15) { SecondPlayer = 0  ; Decider2++; }
		else if(OptionColor[1][1]!=15) { SecondPlayer = 100;             }
		else if(OptionColor[2][1]!=15) { SecondPlayer = 200;             }
		else                           { Decider=1;                      }

		if     (OptionColor[3][0]!=15) { ThirdPlayer = 0 ; Decider2++; }
		else if(OptionColor[4][0]!=15) { ThirdPlayer = 10;             }
		else if(OptionColor[5][0]!=15) { ThirdPlayer = 20;             }
		else                           { Decider=1;                    }

		if     (OptionColor[3][1]!=15) { ForthPlayer=0; Decider2++; }
		else if(OptionColor[4][1]!=15) { ForthPlayer=1;             }
		else if(OptionColor[5][1]!=15) { ForthPlayer=2;             }
		else                           { Decider=1;                 }

		if(Decider) {
			cleardevice();

			settextjustify(1, 1);
			outtextxy(::x/2, ::y/3, "Sorry.! Please select all Players.");
			outtextxy(::x/2, 2*::y/3, "Press any key to go back.");

			getch();
			goto SelectAgain;
		}
		else if(Decider2 > 3) {
			cleardevice();

			settextjustify(1, 1);
			outtextxy(::x/2, ::y/3, "Sorry.! Please select atleast two players.");
			outtextxy(::x/2, 2*::y/3, "Press any key to go back.");

			getch();
			goto SelectAgain;
		}
		else {
			return(FirstPlayer + SecondPlayer + ThirdPlayer + ForthPlayer);
		}
	}
	return(0);
}

void PlayHover(int x, int y, int ShowOrHide, int HoverDecider, int Color, char* Option, int OptColor) {
	if(HoverDecider) {
		settextstyle(0, 0, 0);
		settextjustify(0, 1);
		setfillstyle(1, Color);
		bar(x-10, y-9, x+80, y+8);
		setcolor(OptColor);
		if(ShowOrHide) { outtextxy(x-5, y, Option); y--; setcolor(15); rectangle(x-10, y-8, x+80, y+8); }
		else           { outtextxy(x, y, Option); }
	}
	else {
		y+=3;
		x++;
		settextjustify(1, 1);
		setfillstyle(1, 0);
		bar(x-52, y-17, x+52, y+17);
		setcolor(OptColor);

		if(ShowOrHide) { settextstyle(1, 0, 4); outtextxy(x, y-5, Option); rectangle(x-50, y-15, x+50, y+15); setcolor(15); rectangle(x-52, y-17, x+52, y+17); }
		else           { settextstyle(1, 0, 3); outtextxy(x, y, Option); }
	}
}

void Logos(int x, int y, int No) {
	if(No==0) {		//Small cross
		setcolor(15);

		line(x-5, y-5, x+5, y+5);
		line(x-4, y-5, x+6, y+5);
		line(x-3, y-5, x+7, y+5);

		line(x  , y, x+5, y-5);
		line(x+1, y, x+6, y-5);
		line(x+2, y, x+7, y-5);

		line(x-5, y+5, x  , y);
		line(x-4, y+5, x+1, y);
		line(x-3, y+5, x+2, y);
	}
	else if(No==1) {	//Small man
		setfillstyle(1, 15);

		y--;
		pieslice(x, y+10, 0, 180, 10);
		circle(x, y-5, 5);
		floodfill(x, y-5 ,15);
	}
	else if(No==2) {	//Small Computer
		setfillstyle(1, 15);

		y--;
		rectangle(x-10, y-7, x+10, y+7);

		bar(x-10, y+8, x+10, y+9);
		bar(x-2, y+10, x+2, y+12);
		bar(x-10, y+13, x+10, y+14);

		putpixel(x-7, y+8.5, 0);
		putpixel(x-8, y+8.5, 0);
	}
	else if(No==302 || No==314 || No==304 || No==301) {	//Big Man
		int D=7;

		setfillstyle(1, 15);
		setcolor(15);

		pieslice(x+D, y+15, 0, 180, 15);
		circle(x+D, y-7, 7);
		floodfill(x+D, y-7, 15);

		setfillstyle(1, No%100);
		setcolor(No%100);

		pieslice(x, y+15, 0, 180, 15);
		circle(x, y-7, 7);
		floodfill(x, y-7, No%100);

		setfillstyle(1, 15);
		setcolor(15);

		pieslice(x-D, y+15, 0, 180, 15);
		circle(x-D, y-7, 7);
		floodfill(x-D, y-7, 15);
	}
	else if(No==4) {	//Big Computer
		setfillstyle(1, 15);

		setcolor(15);
		rectangle(x-15, y-12, x+15, y+12);
		rectangle(x-16, y-13, x+16, y+13);

		bar(x-16, y+13, x+16, y+16);
		bar(x-4 , y+17, x+4 , y+20);
		bar(x-13, y+21, x+13, y+23);

		putpixel(x-12, y+15.5, 0);
		putpixel(x-11, y+15.5, 0);
		putpixel(x-11, y+14.5, 0);
		putpixel(x-12, y+14.5, 0);

		putpixel(x+9 , y+14.5, 0);
		putpixel(x+10, y+14.5, 0);

		putpixel(x+12, y+14.5, 0);
		putpixel(x+13, y+14.5, 0);
	}
	else if(No==5) {	//Big Cross
		setcolor(15);

		line(x-10, y-10, x+10, y+10);
		line(x-9 , y-10, x+11, y+10);
		line(x-8 , y-10, x+12, y+10);
		line(x-7 , y-10, x+13, y+10);

		line(x  , y, x+10, y-10);
		line(x+1, y, x+11, y-10);
		line(x+2, y, x+12, y-10);
		line(x+3, y, x+13, y-10);

		line(x-10, y+10, x  , y);
		line(x-9 , y+10, x+1, y);
		line(x-8 , y+10, x+2, y);
		line(x-7 , y+10, x+3, y);
	}
}

void Help() {
	AGAIN:
	cleardevice();
	clrscr();

	cout<<"Ya Page abi hali ha. Is ki Coding ni hoi"<<endl;
	cout<<"Enter dbain wapis jany k lya";

	if(getch()==13) { return; }
	else            { goto AGAIN; }
}

void Credits() {
	cleardevice();
	BackGround();

	settextjustify(0, 2);
	settextstyle(8, 0, 5);
	outtextxy(50, 5, "C++ Project 2018");

	int q=500;	//q = x axis
	int w=150;	//w = y axis
	int e=50 ;	//e = size of one side

	for(e=0; e<20; e++) {
		int poly[10]={ q, w-2*e, q+e, w-e, q, w, q-e, w-e, q, w-2*e };
		setfillstyle(1, 4);
		fillpoly(4, poly);

		poly[0]=q-e  ; poly[1]=w-e;
		poly[2]=q    ; poly[3]=w  ;
		poly[4]=q-e  ; poly[5]=w+e;
		poly[6]=q-2*e; poly[7]=w  ;
		poly[8]=q-e  ; poly[9]=w-e;

		setfillstyle(1, 2);
		fillpoly(4, poly);

		poly[0]=q    ; poly[1]=w  ;
		poly[2]=q+e  ; poly[3]=w-e;
		poly[4]=q+2*e; poly[5]=w  ;
		poly[6]=q+e  ; poly[7]=w+e;
		poly[8]=q    ; poly[9]=w  ;

		setfillstyle(1, 14);
		fillpoly(4, poly);

		poly[0]=q-e  ; poly[1]=w+e  ;
		poly[2]=q    ; poly[3]=w    ;
		poly[4]=q+e  ; poly[5]=w+e  ;
		poly[6]=q    ; poly[7]=w+2*e;
		poly[8]=q-e  ; poly[9]=w+e  ;

		setfillstyle(1, 1);
		fillpoly(4, poly);

		delay(15);
	}

	setfillstyle(1, 15);

	circle(q, w-e, e/6);
	floodfill(q+1, w-e+1, 15);

	circle(q-e, w, e/6);
	floodfill(q-e+1, w+1, 15);

	circle(q+e, w, e/6);
	floodfill(q+e+1, w+1, 15);

	circle(q, w+e, e/6);
	floodfill(q+1, w+e+1, 15);

	settextstyle(2, 0, 10);

	for(int z=0; z<q+5-30; z++) {
		setfillstyle(1, 0);
		bar(30, w+2*e+10, ::x-30, w+2*e+40);

		setcolor(4);
		outtextxy(z+30, w+2*e, "L");

		setcolor(14);
		outtextxy(z+30, w+2*e, " u");

		setcolor(2);
		outtextxy(z+30, w+2*e, "  d");

		setcolor(1);
		outtextxy(z+30, w+2*e, "   o");
	}

	setcolor(15);
	settextjustify(0, 0);
	settextstyle(8, 0, 2);

	outtextxy(70, 4*::y/8, "Develpor: Usama Iftikhar Butt");
	outtextxy(70, 5*::y/8, "University of Gujrat(UOG) Pakistan");
	outtextxy(70, 6*::y/8, "Email: buttusamaiftikhar@gmail.com");

	settextjustify(1, 1);
	settextstyle(0, 0, 0);
	outtextxy(2*::x/3, ::y-20, "Press Enter to go to back to MENU...");

	AGAIN:
	if(getch()!=13) { goto AGAIN; }
}

void BackGround() {
	setbkcolor(0);

	setfillstyle(1, 15);
	bar(0, 0, ::x, ::y);

	for(int k=0; k<1000; k++) {
		putpixel(rand()%30, rand()%::y, 0);
		putpixel(((::x/30.0-1)*30.0)+(rand()%30), rand()%::y, 0);
	}

	setfillstyle(1, 0);
	bar(30, 0, ::x-30, ::y);
}
