#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <iostream.h>
#include <stdlib.h>

void button (int x1, int y1, int x2, int y2, int a) {
	if(a) { setcolor(8); }
	line(x1,y1,x2,y1);
	line(x1,y1,x1,y2);
	setcolor(15);
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
	button(x1, y1, x2, y2, 1);
	nosound();
	delay(400);
}

void main() {
	int gdriver = DETECT,gmode;
	initgraph(&gdriver,&gmode,"C:\\TC\\BGI");

	int x, y, m=1;

	x=getmaxx();
	y=getmaxy();

	start:

	int player1=0, player2=0, floap=0, decider;

	decider=0;

	decider=decider%2;

	cleardevice();

	char mode;

	outtextxy(x/2-70, y/2, "SELECT YOUR MODE");

	button(2*x/5-50, y/2+20, 2*x/5+50, y/2+50, 1);
	outtextxy(2*x/5-30, y/2+33, "1 PLAYER");
	line(2*x/5-31, y/2+42, 2*x/5-24, y/2+42);

	button(3*x/5-50, y/2+20, 3*x/5+50, y/2+50, 1);
	outtextxy(3*x/5-30, y/2+33, "2 PLAYER");
	line(3*x/5-31, y/2+42, 3*x/5-24, y/2+42);

	while(1) {
		mode = getch();
		if(mode=='1'||mode=='2') { break; }
		else {
			sound(400);
			delay(400);
			nosound();
		}
	}
	if(mode=='1') { press(2*x/5-50, y/2+20, 2*x/5+50, y/2+50); }
	else          { press(3*x/5-50, y/2+20, 3*x/5+50, y/2+50); }

	start1:

	cleardevice();

	m++;

	if(mode=='2') {
		outtextxy(x/10, 68, "FIRST PLAYER:");
		window(22, 5, 80, 25);
		cout << player2;

		outtextxy(7.5*x/10, 68, "SECOND PLAYER:");
		window(75, 5, 80, 25);
		cout << player1;
	}
	else {
		outtextxy(2*x/10, 68, "YOU:");
		window(22, 5, 80, 25);
		cout << player2;

		outtextxy(7.5*x/10, 68, "COMPUTER:");
		window(70, 5, 80, 25);
		cout << player1;
	}
	outtextxy(x/2-20, 68, "FLOAP:");
	window(45, 5, 80, 25);
	cout << floap;

	char selector;
	int i, j, p, q=0, counter=0;
	int data[3][3]= {
				{0,6,3},
				{4,5,0},
				{7,8,9},
			};

	outtextxy(x/2-120, y-20, "PRESS ANY NUMBER TO MARK IT");
	outtextxy(x/2-80, y-10, "OR PRESS 'R' OR 'E'");

	button(x/6-35, 6*y/7-10, x/6+35, 6*y/7+10, 1);
	outtextxy(x/6-26, 6*y/7-2, "RESTART");
	line(x/6-26, 6*y/7+7, x/6-21, 6*y/7+7);

	button(5*x/6-35, 6*y/7-10, 5*x/6+35, 6*y/7+10, 1);
	outtextxy(5*x/6-17, 6*y/7-2, "EXIT");
	line(5*x/6-17, 6*y/7+7, 5*x/6-12, 6*y/7+7);

	line(x/2-150, y/2-50 , x/2+150, y/2-50 );
	line(x/2-150, y/2+50 , x/2+150, y/2+50 );
	line(x/2-50 , y/2-150, x/2-50 , y/2+150);
	line(x/2+50 , y/2-150, x/2+50 , y/2+150);

	outtextxy(x/2-100, y/2-100, "1");
	outtextxy(x/2    , y/2-100, "2");
	outtextxy(x/2+100, y/2-100, "3");
	outtextxy(x/2-100, y/2    , "4");
	outtextxy(x/2    , y/2    , "5");
	outtextxy(x/2+100, y/2    , "6");
	outtextxy(x/2-100, y/2+100, "7");
	outtextxy(x/2    , y/2+100, "8");
	outtextxy(x/2+100, y/2+100, "9");

	for(;; counter++) {
		setfillstyle(1, 0);
		bar(x/2-45, 30, x/2+100, 37);

		if(mode=='2') {
			if(decider%2) { outtextxy(x/2-45, 30, "SECOND PLAYER TURN") ;  p=2; }
			else          { outtextxy(x/2-45, 30, "FIRST PLAYER TURN");  p=1; }
		}
		else {
			if(decider%2) { outtextxy(x/2-45, 30, "COMPUTER TURN"); p=2; }
			else          { outtextxy(x/2-45, 30, "YOUR TURN")    ; p=1; }
		}

		if(counter==9) {
			setfillstyle(1, 0);
			bar(x/2-45, 30, x/2+100, 37);

			button(x/2-35, 6*y/7-10, x/2+35, 6*y/7+10, 1);
			outtextxy(x/2-25, 6*y/7-2, "DISCARD");
			line(x/2-25, 6*y/7+7, x/2-20, 6*y/7+7);

			floap++;
			if(decider==10) { decider=0; }
			else            { decider=1; }
			goto inputer;
		}

		again:
		if(decider%2==0 && mode=='1') { selector = getch(); }

		else if(decider%2 && mode=='1') {

			if(q)
			for(int a=0; a<3; a++) {
				if     (a==0) { i='1'; j='2'; selector='3'; }
				else if(a==1) { i='4'; j='5'; selector='6'; }
				else          { i='7'; j='8'; selector='9'; }

				if     (data[a][0]==2&&data[a][1]==2 && data[a][2]!=1) {             q=0; break; }
				else if(data[a][1]==2&&data[a][2]==2 && data[a][0]!=1) { selector=i; q=0; break; }
				else if(data[a][0]==2&&data[a][2]==2 && data[a][1]!=1) { selector=j; q=0; break; }
			}

			if(q)
			for(int a=0; a<3; a++) {
				if     (a==0) { i='1'; j='4'; selector='7'; }
				else if(a==1) { i='2'; j='5'; selector='8'; }
				else          { i='3'; j='6'; selector='9'; }

				if     (data[0][a]==2&&data[1][a]==2 && data[2][a]!=1) {             q=0; break; }
				else if(data[1][a]==2&&data[2][a]==2 && data[0][a]!=1) { selector=i; q=0; break; }
				else if(data[0][a]==2&&data[2][a]==2 && data[1][a]!=1) { selector=j; q=0; break; }
			}

			if(q) {
				if     (data[0][0]==2&&data[2][2]==2 && data[1][1]!=1) { selector='5'; q=0; }
				else if(data[0][2]==2&&data[2][0]==2 && data[1][1]!=1) { selector='5'; q=0; }

				else if(data[0][0]==2&&data[1][1]==2 && data[2][2]!=1) { selector='9'; q=0; }
				else if(data[1][1]==2&&data[2][2]==2 && data[0][0]!=1) { selector='1'; q=0; }

				else if(data[0][2]==2&&data[1][1]==2 && data[2][0]!=1) { selector='7'; q=0; }
				else if(data[1][1]==2&&data[2][0]==2 && data[0][2]!=1) { selector='3'; q=0; }
			}


			if(q)
			for(int a=0; a<3; a++) {
				if     (a==0) { i='1'; j='2'; selector='3'; }
				else if(a==1) { i='4'; j='5'; selector='6'; }
				else          { i='7'; j='8'; selector='9'; }

				if     (data[a][0]==data[a][1] && data[a][2]!=1&&data[a][2]!=2) {             q=0; break; }
				else if(data[a][1]==data[a][2] && data[a][0]!=1&&data[a][0]!=2) { selector=i; q=0; break; }
				else if(data[a][0]==data[a][2] && data[a][1]!=1&&data[a][1]!=2) { selector=j; q=0; break; }
			}

			if(q)
			for(int a=0; a<3; a++) {
				if     (a==0) { i='1'; j='4'; selector='7'; }
				else if(a==1) { i='2'; j='5'; selector='8'; }
				else          { i='3'; j='6'; selector='9'; }

				if     (data[0][a]==data[1][a] && data[2][a]!=1&&data[2][a]!=2) {             q=0; break; }
				else if(data[1][a]==data[2][a] && data[0][a]!=1&&data[0][a]!=2) { selector=i; q=0; break; }
				else if(data[0][a]==data[2][a] && data[1][a]!=1&&data[1][a]!=2) { selector=j; q=0; break; }
			}

			if(q) {
				if     (data[0][0]==data[2][2] && data[1][1]!=1&&data[1][1]!=2) { selector='5'; q=0; }
				else if(data[0][2]==data[2][0] && data[1][1]!=1&&data[1][1]!=2) { selector='5'; q=0; }

				else if(data[0][0]==data[1][1] && data[2][2]!=1&&data[2][2]!=2) { selector='9'; q=0; }
				else if(data[1][1]==data[2][2] && data[0][0]!=1&&data[0][0]!=2) { selector='1'; q=0; }

				else if(data[0][2]==data[1][1] && data[2][0]!=1&&data[2][0]!=2) { selector='7'; q=0; }
				else if(data[1][1]==data[2][0] && data[0][2]!=1&&data[0][2]!=2) { selector='3'; q=0; }
			}


			if(counter==1 && (data[0][0]==1||data[0][2]==1||data[2][0]==1||data[2][2]==1)) { selector='5'; q=0; }

			else if(counter==3 && ((data[0][0]==1&&data[2][2]==1) || (data[0][2]==1&&data[2][0]==1)) ) {
				 if     (!(m%2)) { selector='2'; }
				 else if(!(m%3)) { selector='8'; }
				 else if(!(m%4)) { selector='6'; }
				 else if(!(m%5)) { selector='4'; }

				 q=0;
			}


			else if(counter==0) {
				 if     (!(m%2)) { selector='1'; }
				 else if(!(m%3)) { selector='7'; }
				 else if(!(m%4)) { selector='3'; }
				 else if(!(m%5)) { selector='9'; }

				 q=0;
			}
			else if(counter==2 && data[1][1]==1) {
				 if     (!(m%2)) { selector='9'; }
				 else if(!(m%3)) { selector='3'; }
				 else if(!(m%4)) { selector='7'; }
				 else if(!(m%5)) { selector='1'; }
			}


			if(q) {
				q=rand() % 10;
				if(q==1)      { selector='1'; }
				else if(q==2) { selector='2'; }
				else if(q==3) { selector='3'; }
				else if(q==4) { selector='4'; }
				else if(q==5) { selector='5'; }
				else if(q==6) { selector='6'; }
				else if(q==7) { selector='7'; }
				else if(q==8) { selector='8'; }
				else if(q==9) { selector='9'; }
			}
			delay(500);
		}
		else {
			inputer:
			selector = getch();
		}

		cout << selector << endl;

		if(selector=='r'||selector=='R') {
			press(x/6-35, 6*y/7-10, x/6+35, 6*y/7+10);
			goto start;
		}
		else if(selector=='d'||selector=='D') {
			press(x/2-35, 6*y/7-10, x/2+35, 6*y/7+10);
			goto start1;
		}
		else if(selector=='e'||selector=='E') { break; }
		else if(selector=='1') { if(data[0][0]==1||data[0][0]==2) goto wrong; i=x/2-100; j=y/2-100; data[0][0]=p; }
		else if(selector=='2') { if(data[0][1]==1||data[0][1]==2) goto wrong; i=x/2    ; j=y/2-100; data[0][1]=p; }
		else if(selector=='3') { if(data[0][2]==1||data[0][2]==2) goto wrong; i=x/2+100; j=y/2-100; data[0][2]=p; }
		else if(selector=='4') { if(data[1][0]==1||data[1][0]==2) goto wrong; i=x/2-100; j=y/2    ; data[1][0]=p; }
		else if(selector=='5') { if(data[1][1]==1||data[1][1]==2) goto wrong; i=x/2    ; j=y/2    ; data[1][1]=p; }
		else if(selector=='6') { if(data[1][2]==1||data[1][2]==2) goto wrong; i=x/2+100; j=y/2    ; data[1][2]=p; }
		else if(selector=='7') { if(data[2][0]==1||data[2][0]==2) goto wrong; i=x/2-100; j=y/2+100; data[2][0]=p; }
		else if(selector=='8') { if(data[2][1]==1||data[2][1]==2) goto wrong; i=x/2    ; j=y/2+100; data[2][1]=p; }
		else if(selector=='9') { if(data[2][2]==1||data[2][2]==2) goto wrong; i=x/2+100; j=y/2+100; data[2][2]=p; }
		else {
			wrong:
			if((mode=='2')||(mode=='1' && decider%2==0)) {
				sound(400);
				delay(400);
				nosound();
			}
			goto again;
		}
		sound(600);

		setfillstyle(1, 0);
		bar(i-4, j-4, i+6, j+6);

		if(decider%2) {
			for(int a=25; a<30; a++) { arc(i, j, 0, 360, a); }
		}
		else
		{
			for(int a=25; a<30; a++) { button(i-a, j-a, i+a, j+a, 0); }
		}

		delay(400);
		nosound();

		if     (data[0][0]==data[0][1]&&data[0][1]==data[0][2]) { i=1; break; }
		else if(data[1][0]==data[1][1]&&data[1][1]==data[1][2]) { i=2; break; }
		else if(data[2][0]==data[2][1]&&data[2][1]==data[2][2]) { i=3; break; }

		else if(data[0][0]==data[1][0]&&data[1][0]==data[2][0]) { i=4; break; }
		else if(data[0][1]==data[1][1]&&data[1][1]==data[2][1]) { i=5; break; }
		else if(data[0][2]==data[1][2]&&data[1][2]==data[2][2]) { i=6; break; }

		else if(data[0][0]==data[1][1]&&data[1][1]==data[2][2]) { i=7; break; }
		else if(data[0][2]==data[1][1]&&data[1][1]==data[2][0]) { i=8; break; }

		decider++;
	}

	if(selector!='e' && selector!='E') {
		if     (i==1) { i=x/2-100; j=y/2-100; p=x/2+100; q=y/2-100; }
		else if(i==2) { i=x/2-100; j=y/2    ; p=x/2+100; q=y/2    ; }
		else if(i==3) { i=x/2-100; j=y/2+100; p=x/2+100; q=y/2+100; }
		else if(i==4) { i=x/2-100; j=y/2-100; p=x/2-100; q=y/2+100; }
		else if(i==5) { i=x/2    ; j=y/2-100; p=x/2    ; q=y/2+100; }
		else if(i==6) { i=x/2+100; j=y/2-100; p=x/2+100; q=y/2+100; }
		else if(i==7) { i=x/2-100; j=y/2-100; p=x/2+100; q=y/2+100; }
		else if(i==8) { i=x/2+100; j=y/2-100; p=x/2-100; q=y/2+100; }

		for(int a=0; a<3; a++) { line(i+a, j+a, p+a, q+a); }

		delay(1000);

		cleardevice();

		if(mode=='2') {
			if(decider%2) { outtextxy(x/2-50, y/2-2, "SECOND PLAYER WINS"); player1++; decider=1; }
			else          { outtextxy(x/2-50, y/2-2, "FIRST PLAYER WINS");  player2++; decider=0; }
		}
		else {
			if(decider%2) { outtextxy(x/2-50, y/2-2, "COMPUTER WINS"); player1++; decider=1; }
			else          { outtextxy(x/2-40, y/2-2, "YOU WINS");      player2++; decider=0; }
		}

		delay(2000);
		goto start1;
	}
	press(5*x/6-35, 6*y/7-10, 5*x/6+35, 6*y/7+10);

	cleardevice();
}