#include <iostream.h>
#include <graphics.h>
#include <fstream.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

int x, y, i=45, j=45, ex=80;
char ID[20], IDE[20], PASSWORD[20], s[20];

void xy(int a, int b) { x=a; y=b; }
void IDFn(char b[20]) { strcpy(IDE, b); }

struct profiles {
	char FirstName[20], LastName[20], id[20], password[20];
	char gender[10], address[50], number[20];
};
profiles profile;

char LOGIN     ();
char CONFIRMING();
char STRUCTURE ();
char MWK       ();
char MEN       (int);
char WOMEN     (int);
char KIDS      (int);
char SETTINGS  (int);
char EXIT      (int);
char THREEPIC  (int);
char SHIRTS    (int);
char PANTS     (int);
char KAMIZ     (int);
char BRIDAL    (int);
char FASHION   (int);
char BOY       (int);
char GIRL      (int);
char PROFILE   (int);
char DEACTIVATE(int);
char SIGNOUT   (int);
char EDIT      (int);

void box (int x1, int y1, int x2, int y2, int d) {
	if(d) { setcolor(15); }
	else  { setcolor(0); }
	line(x1,y1,x2,y1);
	line(x1,y1,x1,y2);
	line(x1,y2,x2,y2);
	line(x2,y1,x2,y2);
}

void button (int x1, int y1, int x2, int y2) {
	setcolor(15);
	line(x1,y1,x2,y1);
	line(x1,y1,x1,y2);
	setcolor(BLACK);
	line(x1,y2,x2,y2);
	line(x2,y1,x2,y2);
}

void press (int x1, int y1, int x2, int y2) {
	setcolor(BLACK);
	line(x1,y1,x2,y1);
	line(x1,y1,x1,y2);
	setcolor(15);
	line(x1,y2,x2,y2);
	line(x2,y1,x2,y2);

	sound(600);
	delay(500);
	button(x1, y1, x2, y2);
	nosound();
	delay(400);
}

void sound() {
	sound(400);
	setfillstyle(1, 15);
	bar(x/2-205, y-25, x/2+205, y-10);
	outtextxy(x/2-100, y-20, "PLEASE PRESS A VALID KEY");
	delay(300);
	nosound();
}

void fix(int a1, int a2, int a3, int a4) {
	cleardevice();
	setfillstyle(1,8);
	bar(0, 0, x, y);

	if(a4) {
		settextstyle(10, HORIZ_DIR, 3);
		outtextxy(0, 0, "WEARHOUSE");
		settextstyle(0, HORIZ_DIR, 0);
	}


	if(a1) {
		button(x/7-33, 9*y/10-12, x/7+33, 9*y/10+12);
		outtextxy(x/7-30, 9*y/10-2, "PREVIOUS");
		line(x/7-30, 9*y/10+7, x/7-25, 9*y/10+7);
	}

	if(a2) {
		button(2*x/7-33, 9*y/10-12, 2*x/7+33, 9*y/10+12);
		outtextxy(2*x/7-30, 9*y/10-2, "SETTINGS");
		line(2*x/7-30, 9*y/10+7, 2*x/7-25, 9*y/10+7);
	}

	if(a3) {
		button(6*x/7-33, 9*y/10-12, 6*x/7+33, 9*y/10+12);
		outtextxy(6*x/7-15, 9*y/10-2, "EXIT");
		line(6*x/7-15, 9*y/10+7, 6*x/7-10, 9*y/10+7);
	}
}

void wait() {
	int z=1;
	while(z<4) {
		fix(0, 0, 0, 0);

		outtextxy(x/2-28, y/2-2, "Please wait");
		delay(400);
		outtextxy(x/2-28, y/2-2, "Please wait.");
		delay(400);
		outtextxy(x/2-28, y/2-2, "Please wait..");
		delay(400);
		outtextxy(x/2-28, y/2-2, "Please wait...");
		delay(400);
		z++;
	}
}

char sure() {
	fix(1, 0, 0, 1);

	char a;

	outtextxy(x/2-50, y/2-2, "Are you sure?");

	button(x/2-50, y/2+20, x/2+50, y/2+50);
	outtextxy(x/2-10, y/2+32, "YES");
	line(x/2-9, y/2+40, x/2-4, y/2+40);

	while(1) {
		a=getch();
		if(a=='y'||a=='Y'||a=='p'||a=='P') { break; }
		else { sound(); }
	}
	return a;
}

void boxer(char n) {
	if(n=='1')      { box(x/4-i  , y/4-j  , x/4+i  , y/4+j  , 1); }
	else if(n=='2') { box(2*x/4-i, y/4-j  , 2*x/4+i, y/4+j  , 1); }
	else if(n=='3') { box(3*x/4-i, y/4-j  , 3*x/4+i, y/4+j  , 1); }
	else if(n=='4') { box(x/4-i  , 2*y/4-j, x/4+i  , 2*y/4+j, 1); }
	else if(n=='5') { box(2*x/4-i, 2*y/4-j, 2*x/4+i, 2*y/4+j, 1); }
	else if(n=='6') { box(3*x/4-i, 2*y/4-j, 3*x/4+i, 2*y/4+j, 1); }
	else if(n=='7') { box(x/4-i  , 3*y/4-j, x/4+i  , 3*y/4+j, 1); }
	else if(n=='8') { box(2*x/4-i, 3*y/4-j, 2*x/4+i, 3*y/4+j, 1); }
	else if(n=='9') { box(3*x/4-i, 3*y/4-j, 3*x/4+i, 3*y/4+j, 1); }

	sound(600);

	delay(500);

	nosound();

	if(n=='1')      { box(x/4-i  , y/4-j  , x/4+i  , y/4+j  , 0); }
	else if(n=='2') { box(2*x/4-i, y/4-j  , 2*x/4+i, y/4+j  , 0); }
	else if(n=='3') { box(3*x/4-i, y/4-j  , 3*x/4+i, y/4+j  , 0); }
	else if(n=='4') { box(x/4-i  , 2*y/4-j, x/4+i  , 2*y/4+j, 0); }
	else if(n=='5') { box(2*x/4-i, 2*y/4-j, 2*x/4+i, 2*y/4+j, 0); }
	else if(n=='6') { box(3*x/4-i, 2*y/4-j, 3*x/4+i, 2*y/4+j, 0); }
	else if(n=='7') { box(x/4-i  , 3*y/4-j, x/4+i  , 3*y/4+j, 0); }
	else if(n=='8') { box(2*x/4-i, 3*y/4-j, 2*x/4+i, 3*y/4+j, 0); }
	else if(n=='9') { box(3*x/4-i, 3*y/4-j, 3*x/4+i, 3*y/4+j, 0); }

	delay(400);
}

void no() {
	fix(0, 0, 0, 1);

	outtextxy(x/2-160, 4*y/9-2, "Enter Adderss:");

	setfillstyle(1, 0);
	bar(x/2+50, 4*y/9-8 , x/2+210, 4*y/9+12 );

	window(ex/2+10, 14, ex/2+30, 14);
	cin >> s;
}

char buyer(char d) {
	fix(1, 1, 1, 1);

	char a;

	outtextxy(x/2-155, y/2-70, "At this address you should recieve your order");

	outtextxy(x/2-150, 4*y/9-2, "Adderss:");

	setfillstyle(1, 0);
	bar(x/2+50, 4*y/9-8 , x/2+210, 4*y/9+12 );

	window(ex/2+10, 14, ex/2+30, 14);
	cout << profile.address;

	button(x/3-50, 2*y/3-15, x/3+50, 2*y/3+15);
	outtextxy(x/3-5, 2*y/3-2, "YES");
	line(x/3-5, 2*y/3+6, x/3, 2*y/3+6);

	button(2*x/3-50, 2*y/3-15, 2*x/3+50, 2*y/3+15);
	outtextxy(2*x/3-5, 2*y/3-2, "NO");
	line(2*x/3-5, 2*y/3+6, 2*x/3, 2*y/3+6);

	while(1) {
		a=getch();
		if((a=='p'||a=='P'||a=='e'||a=='E'||a=='s'||a=='S')
		||(a=='y'||a=='Y'||a=='n'||a=='N'))
			{ break; }
		else { sound(); }
	}
	if(a=='n'||a=='N') {
		press(2*x/3-50, 2*y/3-15, 2*x/3+50, 2*y/3+15);
		no(); wait(); a=d;
	}
	else if(a=='y'||a=='Y') {
		press(x/3-50, 2*y/3-15, x/3+50, 2*y/3+15);
		wait(); a=d;
	}

	return a;
}

void main()
{
	int gdriver = DETECT,gmode;
	initgraph(&gdriver,&gmode,"C:\\tc\\bgi");

	cleardevice();

	xy(getmaxx(), getmaxy());

	setfillstyle(1, 15);
	outtextxy(x/2-30, y/2-30, "LOADING");
	box(x/2-205, y/2-15, x/2+205, y/2+15, 1);

	for(int a=x/2-200;a<=x/2+200;a++) {
		if(a%150==0)      { delay(700); }
		else if(a%100==0) { delay(600); }
		else if(a%70==0)  { delay(400); }
		delay(3);
		bar(x/2-200, y/2-12, a, y/2+12);
	}

	cleardevice();

	settextstyle(10, HORIZ_DIR, 7);
	outtextxy(x/2-305, y/2, "WEARHOUSE");

	delay(2500);
	settextstyle(0, HORIZ_DIR, 0);
	setcolor(0);

	int inc;
	char back[10], z='f';

	do{
		int decider=1;

		if(back[inc]==z) { decider=0; }

		if(z!='r'&& z!='R'&& z!='l'&& z!='L' &&back[inc]!=z) {
			inc++;
			back[inc]=z;
		}

		if(z=='p'||z=='P') {
			decider=0;
			inc-=2;
			z=back[inc];
			press(x/7-33, 9*y/10-12, x/7+33, 9*y/10+12);
		}

		if(z=='f') 	        { z=LOGIN();             }
		else if(z=='r'||z=='R') { z=STRUCTURE();         }
		else if(z=='l'||z=='L') { z=CONFIRMING(); 	 }
		else if(z=='=')         { z=MWK();               }
		else if(z=='m'||z=='M') { z=MEN(decider);        }
		else if(z=='w'||z=='W') { z=WOMEN(decider);      }
		else if(z=='k'||z=='K') { z=KIDS(decider);       }
		else if(z=='s'||z=='S') { z=SETTINGS(decider);   }
		else if(z=='t'||z=='T') { z=THREEPIC(decider);   }
		else if(z=='h'||z=='H') { z=SHIRTS(decider);     }
		else if(z=='a'||z=='A') { z=PANTS(decider);      }
		else if(z=='!') 	{ z=KAMIZ(decider);      }
		else if(z=='b'||z=='B') { z=BRIDAL(decider);     }
		else if(z=='.') 	{ z=FASHION(decider);    }
		else if(z==',') 	{ z=BOY(decider);        }
		else if(z=='g'||z=='G') { z=GIRL(decider);       }
		else if(z=='d'||z=='D') { z=DEACTIVATE(decider); }
		else if(z=='@')         { z=SIGNOUT(decider);    }
		else if(z=='v'||z=='V') { z=PROFILE(decider);    }
		else if(z=='%')         { z=EDIT(decider);       }
		else if(z=='e'||z=='E') {
			press(6*x/7-33, 9*y/10-12, 6*x/7+33, 9*y/10+12);
			z=sure();
		}
	}while(z!='y' && z!='Y');

	press(x/2-50, y/2+20, x/2+50, y/2+50);

	cleardevice();
}

char LOGIN()
{
	fix(0, 0, 1, 1);

	static int b=1;
	if(b) {
		setfillstyle(1, 15);
		bar(x/2-205, y-25, x/2+205, y-10);
		outtextxy(x/2-200, y-20, "PRESS THE UNDER LINE CHARACTER TO PRESS THE BUTTON");
		b=0;
	}
	char a;

	button (x/2-50, 3*y/6-15, x/2+50 , 3*y/6+15);
	outtextxy(x/2-28, 3*y/6-2, "REGISTER");
	line(x/2-28, 3*y/6+7, x/2-23, 3*y/6+7);

	button (x/2-50, 4*y/6-15, x/2+50, 4*y/6+15);
	outtextxy(x/2-20, 4*y/6-2, "LOGIN");
	line(x/2-20, 4*y/6+7, x/2-15, 4*y/6+7);

	while(1) {
		a=getch();
		if(a=='l'||a=='L'||a=='r'||a=='R'||a=='e'||a=='E')
			{ break; }
		else { sound(); }
	}
	return a;
}

char CONFIRMING()
{
	press (x/2-50, 2*y/3-15, x/2+50, 2*y/3+15);
	fix(0, 0, 0, 1);

	char z='f', g;

	outtextxy(x/2-150, 3*y/7-2, "Enter USERNAME/ID");
	outtextxy(x/2-150, 4*y/7-2, "Enter PASSWORD");

	setfillstyle(1, 0);
	bar(x/2+50, 3*y/7-14, x/2+210, 3*y/7+6);
	bar(x/2+50, 4*y/7-14, x/2+210, 4*y/7+6);

	window(ex/2+10, 13, ex/2+30, 13);
	cin >> ID;

	window(ex/2+10, 17, ex/2+30, 17);
	cin >> PASSWORD;

	ifstream a;
	a.open("C://Data.txt");

	while(!a.eof()) {
		a >> profile.FirstName ;
		a >> profile.LastName  ;
		a >> profile.id        ;
		a >> profile.password  ;
		a >> profile.gender    ;
		a >> profile.number    ;
		a >> profile.address   ;
		a >> g                 ;

		if(strcmp(ID, profile.id)==0) {
			if(strcmp(PASSWORD, profile.password)==0) {
				z='=';
				wait();
				IDFn(ID);
				break;
			}
		}
	}
	a.close();

       if(z=='f') {
	       fix(0, 0, 0, 0);
	       outtextxy(x/2-110, y/2-5, "USERNAME or PASSWORD is incorrect");
	       outtextxy(x/2-90, y/2+7, "try again or REGISTER firstly");
	       delay(1500);
       }

       return z;
}

char STRUCTURE()
{
	char z='=', g;
	int deci=1;

	press (x/2-50, 3*y/6-15, x/2+50 , 3*y/6+15);
	fix(0, 0, 0, 1);

	outtextxy(x/2-150, y/9-2  , "Enter your First Name:"   );
	outtextxy(x/2-150, 2*y/9-2, "Enter your Last Name:"    );
	outtextxy(x/2-150, 3*y/9-5, "Enter your ID:"           );
	outtextxy(x/2-150, 4*y/9-2, "Enter your Password:"     );
	outtextxy(x/2-150, 5*y/9-2, "Enter your Gender:"       );
	outtextxy(x/2-150, 6*y/9  , "Enter your PHONE number:" );
	outtextxy(x/2-150, 7*y/9  , "Enter your Addrees:"      );

	setfillstyle(1, 0);
	bar(x/2+50, y/9-6   ,  x/2+210, y/9+12   );
	bar(x/2+50, 2*y/9-6 ,  x/2+210, 2*y/9+12 );
	bar(x/2+50, 3*y/9-14,  x/2+210, 3*y/9+6  );
	bar(x/2+50, 4*y/9-8 ,  x/2+210, 4*y/9+12 );
	bar(x/2+50, 5*y/9-10,  x/2+210, 5*y/9+10 );
	bar(x/2+50, 6*y/9-6 ,  x/2+210, 6*y/9+14 );
	bar(x/2+50, 7*y/9-10,  x/2+210, 7*y/9+10 );

	window(ex/2+10, 4, ex/2+30, 4);
	gets( profile.FirstName );

	window(ex/2+10, 7, ex/2+30, 7);
	gets( profile.LastName );

	window(ex/2+10, 10, ex/2+30, 10);
	gets( profile.id );

	ifstream a;
	a.open("C://Data.txt");

	while(!a.eof()) {
		a >> ID                ;
		a >> ID                ;
		a >> ID                ;
		a >> profile.password  ;
		a >> profile.gender    ;
		a >> profile.number    ;
		a >> profile.address   ;
		a >> g                 ;

		if(strcmp(ID, profile.id)==0) {
			fix(0, 0, 0, 0);
		       outtextxy(x/2-110, y/2-5, "This ID has been already used");
		       outtextxy(x/2-45, y/2+7, "try a DIFFERENT");
		       deci=0;
		       z='f';
		       delay(3000);
		}
	}
	a.close();

	if(deci) {
		IDFn(profile.id);

		window(ex/2+10, 14, ex/2+30, 14);
		gets( profile.password );

		window(ex/2+10, 17, ex/2+30, 17);
		gets( profile.gender );

		window(ex/2+10, 21, ex/2+30, 21);
		gets( profile.number );

		window(ex/2+10, 24, ex/2+30, 24);
		gets( profile.address );

		ofstream a;
		a.open("C://Data.txt", ios::app);

		a << profile.FirstName  << endl  << profile.LastName  << endl;
		a << profile.id         << endl  << profile.password  << endl;
		a << profile.gender     << endl  << profile.number    << endl;
		a << profile.address    << endl  << '.'               << endl;

		a.close();

		fix(0, 0, 0, 0);
		settextstyle(10, HORIZ_DIR, 1);
		outtextxy(x/2-85, y/2-20, "WELCOME to");

		settextstyle(10, HORIZ_DIR, 7);
		outtextxy(x/2-305, y/2, "WEARHOUSE");

		delay(3000);
		fix(0, 0, 0, 0);
		settextstyle(10, HORIZ_DIR, 1);
		outtextxy(x/2-300, y/2-50, "Here you have a lot of variety of garments");
		outtextxy(x/2-190, y/2, "of MEN, WOMEN and KIDS");

		delay(3000);
		fix(0, 0, 0, 0);
		outtextxy(x/2-145, y/2-50, "You can order online");
		outtextxy(x/2-245, y/2, "on very low cast of home delivery");

		delay(3000);
		settextstyle(0, HORIZ_DIR, 0);
	}
	return z;
}

char SETTINGS(int decider)
{
	if(decider) { press(2*x/7-33, 9*y/10-12, 2*x/7+33, 9*y/10+12); }
	fix(1, 0, 1, 1);

	char a;

	button(x/2-50, 2*y/6-15, x/2+50, 2*y/6+15);
	outtextxy(x/2-12, 2*y/6-8, "VIEW");
	outtextxy(x/2-24, 2*y/6+3, "PROFILE");
	line(x/2-12, 2*y/6, x/2-7, 2*y/6);

	button(x/2-50, 3*y/6-15, x/2+50, 3*y/6+15);
	outtextxy(x/2-25, 3*y/6-2, "SIGNOUT");
	line(x/2-25, 3*y/6+7, x/2-20, 3*y/6+7);

	button(x/2-50, 4*y/6-15, x/2+50, 4*y/6+15);
	outtextxy(x/2-37, 4*y/6-8, "DEACTIVATE");
	outtextxy(x/2-27, 4*y/6+3, "ACCOUNT");
	line(x/2-37, 4*y/6, x/2-32, 4*y/6);

	while(1) {
		a=getch();
		if((a=='v'||a=='V'||a=='d'||a=='D')
		  ||(a=='s'||a=='S'||a=='p'||a=='P')
		  ||(a=='e'||a=='E'))
			  { break; }
		else { sound(); }
	}
	if(a=='s'||a=='S') { a='@'; }

	return a;
}

char SIGNOUT(int decider)
{
	char a;

	if(decider) { press(x/2-50, 3*y/6-15, x/2+50, 3*y/6+15); }

	a=sure();

	if(a=='y'||a=='Y') {
		press(x/2-50, y/2+20, x/2+50, y/2+50);
		wait();
		a='f';
	}
	else { a='p';}

	return a;
}

char DEACTIVATE(int decider)
{
	char a, g;

	if(decider) { press(x/2-50, 4*y/6-15, x/2+50, 4*y/6+15); }

	a=sure();

	if(a=='y'||a=='Y') {
		press(x/2-50, y/2+20, x/2+50, y/2+50);
		wait();
		a='f';

		fix(0, 0, 0, 1);

		box (x/2-25, y/2-30, x/2+25, y/2+30, 0);
		line(x/2-15, y/2-15, x/2-10, y/2-10);
		line(x/2+15, y/2-15, x/2+10, y/2-10);
		line(x/2-10, y/2+10, x/2+10, y/2+10);
		line(x/2-10, y/2+10, x/2-15, y/2+15);
		line(x/2+10, y/2+10, x/2+15, y/2+15);

		outtextxy(x/2-110, y/2+35, "WE ARE SORRY TO SEE YOU GONE.");
		delay(5000);

		ofstream q, e;
		ifstream w, r;
		q.open("C://Temp.txt", ios::out);
		w.open("C://Data.txt", ios::in);

		while(!w.eof()) {
			w >> profile.FirstName ;
			w >> profile.LastName  ;
			w >> profile.id        ;
			w >> profile.password  ;
			w >> profile.gender    ;
			w >> profile.number    ;
			w >> profile.address   ;
			w >> g                 ;

			if(strcmp(IDE, profile.id)!=0) {
				q << profile.FirstName  << endl  << profile.LastName  << endl;
				q << profile.id         << endl  << profile.password  << endl;
				q << profile.gender     << endl  << profile.number    << endl;
				q << profile.address    << endl  << '.'               << endl;
			}
			else {}
		}

		q.close();
		w.close();

		e.open("C://Data.txt", ios::out);
		r.open("C://Temp.txt", ios::in);

		while(!r.eof()) {
			r >> profile.FirstName ;
			r >> profile.LastName  ;
			r >> profile.id        ;
			r >> profile.password  ;
			r >> profile.gender    ;
			r >> profile.number    ;
			r >> profile.address   ;
			r >> g                 ;

			e << profile.FirstName  << endl  << profile.LastName  << endl;
			e << profile.id         << endl  << profile.password  << endl;
			e << profile.gender     << endl  << profile.number    << endl;
			e << profile.address    << endl  << '.'               << endl;
		}
		e.close();
		r.close();
	}
	return a;
}

char PROFILE(int decider)
{
	if(decider) { press(x/2-50, 2*y/6-15, x/2+50, 2*y/6+15); }

	char a, g;
	fix(1, 0, 1, 1);

	button(2*x/7-33, 9*y/10-12, 2*x/7+33, 9*y/10+12);
	outtextxy(2*x/7-15, 9*y/10-2, "EDIT");
	line(2*x/7-8, 9*y/10+7, 2*x/7-3, 9*y/10+7);

	ifstream v;
	v.open("C://Data.txt", ios::in);

	while(!v.eof()) {
		if(strcmp(IDE, profile.id)==0) { break; }

		v >> profile.FirstName ;
		v >> profile.LastName  ;
		v >> profile.id        ;
		v >> profile.password  ;
		v >> profile.gender    ;
		v >> profile.number    ;
		v >> profile.address   ;
		v >> g                 ;
	}
	v.close();

	outtextxy(x/2-150, 2*y/9-2, "First name:"   );
	outtextxy(x/2-150, 3*y/9-5, "Last name:"    );
	outtextxy(x/2-150, 4*y/9-2, "Id:"           );
	outtextxy(x/2-150, 5*y/9-2, "Gender:"       );
	outtextxy(x/2-150, 6*y/9  , "PHONE number:" );
	outtextxy(x/2-150, 7*y/9  , "Addrees:"      );

	setfillstyle(1, 0);

	bar(x/2+50, 2*y/9-6 , x/2+210, 2*y/9+12 );
	bar(x/2+50, 3*y/9-14, x/2+210, 3*y/9+6  );
	bar(x/2+50, 4*y/9-8 , x/2+210, 4*y/9+12 );
	bar(x/2+50, 5*y/9-10, x/2+210, 5*y/9+10 );
	bar(x/2+50, 6*y/9-6 , x/2+210, 6*y/9+14 );
	bar(x/2+50, 7*y/9-10, x/2+210, 7*y/9+10 );

	window(ex/2+10, 7, ex/2+30, 7);
	cout << profile.FirstName;

	window(ex/2+10, 10, ex/2+30, 10);
	cout << profile.LastName;

	window(ex/2+10, 14, ex/2+30, 14);
	cout << profile.id;

	window(ex/2+10, 17, ex/2+30, 17);
	cout << profile.gender;

	window(ex/2+10, 21, ex/2+30, 21);
	cout << profile.number;

	window(ex/2+10, 24, ex/2+30, 24);
	cout << profile.address;

	while(1) {
		a=getch();
		if(a=='p'||a=='P'||a=='e'||a=='E'||a=='d'||a=='D') { break; }
		else { sound(); }
	}

	if(a=='d'||a=='D') { a='%'; }

	return a;
}

char EDIT(int decider) {

	if(decider) { press(2*x/7-33, 9*y/10-12, 2*x/7+33, 9*y/10+12); }

	char a, g;
	fix(1, 0, 1, 1);

	ifstream v;
	v.open("C://Data.txt", ios::in);

	while(!v.eof()) {
		if(strcmp(IDE, profile.id)==0) { break; }

		v >> profile.FirstName ;
		v >> profile.LastName  ;
		v >> profile.id        ;
		v >> profile.password  ;
		v >> profile.gender    ;
		v >> profile.number    ;
		v >> profile.address   ;
		v >> g                 ;
	}
	v.close();

	setfillstyle(1, 15);
	bar(x/2-190, y-50, x/2+190, y-35);
	outtextxy(x/2-130, y-45, "PRESS THE NUMBER TO EDIT THAT DATA");


	outtextxy(x/2-150, y/9-2  , "1)First name:"   );
	outtextxy(x/2-150, 2*y/9-2, "2)Last name:"    );
	outtextxy(x/2-150, 3*y/9-5, "3)id:"           );
	outtextxy(x/2-150, 4*y/9-2, "4)Password:"     );
	outtextxy(x/2-150, 5*y/9-2, "5)Gender:"       );
	outtextxy(x/2-150, 6*y/9  , "6)PHONE number:" );
	outtextxy(x/2-150, 7*y/9  , "7)Addrees:"      );

	setfillstyle(1, 0);
	bar(x/2+50, y/9-6   , x/2+210, y/9+12   );
	bar(x/2+50, 2*y/9-6 , x/2+210, 2*y/9+12 );
	bar(x/2+50, 3*y/9-14, x/2+210, 3*y/9+6  );
	bar(x/2+50, 4*y/9-8 , x/2+210, 4*y/9+12 );
	bar(x/2+50, 5*y/9-10, x/2+210, 5*y/9+10 );
	bar(x/2+50, 6*y/9-6 , x/2+210, 6*y/9+14 );
	bar(x/2+50, 7*y/9-10, x/2+210, 7*y/9+10 );

	window(ex/2+10, 4, ex/2+30, 4);
	cout << profile.FirstName;

	window(ex/2+10, 7, ex/2+30, 7);
	cout << profile.LastName;

	window(ex/2+10, 10, ex/2+30, 10);
	cout << profile.id;

	window(ex/2+10, 14, ex/2+30, 14);
	cout << "******";

	window(ex/2+10, 17, ex/2+30, 17);
	cout << profile.gender;

	window(ex/2+10, 21, ex/2+30, 21);
	cout << profile.number;

	window(ex/2+10, 24, ex/2+30, 24);
	cout << profile.address;

	while(1) {
		a=getch();
		if((a=='p'||a=='P'||a=='e'||a=='E'||a=='d'||a=='D')
		||(a=='1'||a=='2'||a=='3'||a=='4'||a=='5'||a=='6'||a=='7'))
			 { break; }
		else { sound(); }
	}

	if(a=='1') {
		setcolor(15);
		sound(600);
		outtextxy(x/2-150, y/9-2  , "1)First name:"  );
		delay(400);
		nosound();
		setcolor(0);
		fix(0, 0, 0, 1);

		setfillstyle(1, 0);
		bar(x/2+50, 4*y/9-8 , x/2+210, 4*y/9+12 );

		outtextxy(x/2-150, 4*y/9-2, "Enter First Name:");
		window(ex/2+10, 14, ex/2+30, 14);
		gets( s );
		a='%';
	}
	else if(a=='2') {
		setcolor(15);
		sound(600);
		outtextxy(x/2-150, 2*y/9-2, "2)Last name:"   );
		delay(400);
		nosound();
		setcolor(0);
		fix(0, 0, 0, 1);

		setfillstyle(1, 0);
		bar(x/2+50, 4*y/9-8 , x/2+210, 4*y/9+12 );

		outtextxy(x/2-150, 4*y/9-2, "Enter Last Name:");
		window(ex/2+10, 14, ex/2+30, 14);
		gets( s );
		a='%';
	}
	else if(a=='3') {
		setcolor(15);
		sound(600);
		outtextxy(x/2-150, 3*y/9-5, "3)id:"          );
		delay(400);
		nosound();
		setcolor(0);
		fix(0, 0, 0, 1);

		outtextxy(x/2-150, 4*y/9-2, "Sorry ID cannot be change.");
		window(ex/2+10, 14, ex/2+30, 14);
		delay(2000);
		a='%';
	}
	else if(a=='4') {
		setcolor(15);
		sound(600);
		outtextxy(x/2-150, 4*y/9-2, "4)Password:"    );
		delay(400);
		nosound();
		setcolor(0);
		fix(0, 0, 0, 1);

		setfillstyle(1, 0);
		bar(x/2+50, 4*y/9-8 , x/2+210, 4*y/9+12 );

		outtextxy(x/2-150, 4*y/9-2, "Enter Password:");
		window(ex/2+10, 14, ex/2+30, 14);
		gets( s );
		a='%';
	}
	else if(a=='5') {
		setcolor(15);
		sound(600);
		bar(x/2+50, 5*y/9-10, x/2+210, 5*y/9+10 );
		delay(400);
		nosound();
		setcolor(0);
		fix(0, 0, 0, 1);

		setfillstyle(1, 0);
		bar(x/2+50, 4*y/9-8 , x/2+210, 4*y/9+12 );

		outtextxy(x/2-150, 4*y/9-2, "Enter Gender:");
		window(ex/2+10, 14, ex/2+30, 14);
		gets( s );
		a='%';
	}
	else if(a=='6') {
		setcolor(15);
		sound(600);
		outtextxy(x/2-150, 6*y/9  , "6)PHONE number:");
		delay(400);
		nosound();
		setcolor(0);
		fix(0, 0, 0, 1);

		setfillstyle(1, 0);
		bar(x/2+50, 4*y/9-8 , x/2+210, 4*y/9+12 );

		outtextxy(x/2-150, 4*y/9-2, "Enter Phone number:");
		window(ex/2+10, 14, ex/2+30, 14);
		gets( s );
		a='%';
	}
	else if(a=='7') {
		setcolor(15);
		sound(600);
		outtextxy(x/2-150, 7*y/9  , "7)Addrees:"     );
		delay(400);
		nosound();
		setcolor(0);
		fix(0, 0, 0, 1);

		setfillstyle(1, 0);
		bar(x/2+50, 4*y/9-8 , x/2+210, 4*y/9+12 );

		outtextxy(x/2-150, 4*y/9-2, "Enter Address:");
		window(ex/2+10, 14, ex/2+30, 14);
		gets( s );
		a='%';
	}

	ofstream q, e;
	ifstream w, r;
	q.open("C://Temp.txt");
	w.open("C://Data.txt");

	while(!w.eof()) {
		w >> profile.FirstName ;
		w >> profile.LastName  ;
		w >> profile.id        ;
		w >> profile.password  ;
		w >> profile.gender    ;
		w >> profile.number    ;
		w >> profile.address   ;
		w >> g                 ;

		if(strcmp(IDE, profile.id)==0) {
			if(a=='1')      { strcpy(profile.FirstName, s); }
			else if(a=='2') { strcpy(profile.LastName, s) ; }
			else if(a=='3') { strcpy(profile.id, s)       ; }
			else if(a=='4') { strcpy(profile.password, s) ; }
			else if(a=='5') { strcpy(profile.gender, s)   ; }
			else if(a=='6') { strcpy(profile.number, s)   ; }
			else if(a=='7') { strcpy(profile.address, s)  ; }
		}
		q << profile.FirstName  << endl  << profile.LastName  << endl;
		q << profile.id         << endl  << profile.password  << endl;
		q << profile.gender     << endl  << profile.number    << endl;
		q << profile.address    << endl  << '.'               << endl;
	  }

	q.close();
	w.close();

	e.open("C://Data.txt");
	r.open("C://Temp.txt", ios::in);

	while(!r.eof()) {
		r >> profile.FirstName ;
		r >> profile.LastName  ;
		r >> profile.id        ;
		r >> profile.password  ;
		r >> profile.gender    ;
		r >> profile.number    ;
		r >> profile.address   ;
		r >> g                 ;

		e << profile.FirstName  << endl  << profile.LastName  << endl;
		e << profile.id         << endl  << profile.password  << endl;
		e << profile.gender     << endl  << profile.number    << endl;
		e << profile.address    << endl  << '.'               << endl;
	}
	e.close();
	r.close();

	return a;
}

char MWK()
{
	fix(0, 1, 1, 1);

	char a;

	button(x/2-50, 2*y/6-15, x/2+50, 2*y/6+15);
	outtextxy(x/2-10, 2*y/6-2, "MEN");
	line(x/2-10, 2*y/6+7, x/2-5, 2*y/6+7);

	button(x/2-50, 3*y/6-15, x/2+50, 3*y/6+15);
	outtextxy(x/2-20, 3*y/6-2, "WOMEN");
	line(x/2-20, 3*y/6+7, x/2-15, 3*y/6+7);

	button(x/2-50, 4*y/6-15, x/2+50, 4*y/6+15);
	outtextxy(x/2-15, 4*y/6-2, "KIDS");
	line(x/2-15, 4*y/6+7, x/2-10, 4*y/6+7);

	while(1) {
		a=getch();
		if((a=='m'||a=='M'||a=='w'||a=='W'||a=='k'||a=='K')
		||(a=='e'||a=='E'||a=='s'||a=='S'))
			{ break; }
		else { sound(); }
	}
	return a;
}

char MEN(int decider)
{
	if(decider) { press(x/2-50, 2*y/6-15, x/2+50, 2*y/6+15); }
	fix(1, 1, 1, 1);

	char a;

	button(x/2-50, 2*y/6-15, x/2+50, 2*y/6+15);
	outtextxy(x/2-43, 2*y/6-2, "THREE PIECE");
	line(x/2-43, 2*y/6+7, x/2-38, 2*y/6+7);

	button(x/2-50, 3*y/6-15, x/2+50, 3*y/6+15);
	outtextxy(x/2-19, 3*y/6-2, "SHIRTS");
	line(x/2-10, 3*y/6+7, x/2-5, 3*y/6+7);

	button(x/2-50, 4*y/6-15, x/2+50, 4*y/6+15);
	outtextxy(x/2-18, 4*y/6-2, "PANTS");
	line(x/2-10, 4*y/6+7, x/2-5, 4*y/6+7);

	while(1) {
		a=getch();
		if((a=='t'||a=='T'||a=='h'||a=='H'||a=='a'||a=='A')
		||(a=='s'||a=='S'||a=='p'||a=='P'||a=='e'||a=='E'))
			{ break; }
		else { sound(); }
	}

	return a;
}

char WOMEN(int decider)
{
	if(decider) { press(x/2-50, 2*y/4-15, x/2+50, 2*y/4+15); }
	fix(1, 1, 1, 1);

	char a;

	button(x/2-50, 2*y/6-15, x/2+50, 2*y/6+15);
	outtextxy(x/2-25, 2*y/6-8, "SHALWAR");
	outtextxy(x/2-18, 2*y/6+2, "KAMIZ");
	line(x/2-17, 2*y/6, x/2-11, 2*y/6);

	button(x/2-50, 3*y/6-15, x/2+50, 3*y/6+15);
	outtextxy(x/2-18, 3*y/6-2, "BRIDAL");
	line(x/2-18, 3*y/6+7, x/2-13, 3*y/6+7);

	button(x/2-50, 4*y/6-15, x/2+50, 4*y/6+15);
	outtextxy(x/2-25, 4*y/6-8, "FASHION");
	outtextxy(x/2-25, 4*y/6+3, "DRESSES");
	line(x/2-17, 4*y/6, x/2-12, 4*y/6);

	while(1) {
		a=getch();
		if((a=='h'||a=='H'||a=='e'||a=='E')
		||(a=='b'||a=='B'||a=='a'||a=='A')
		||(a=='s'||a=='S'||a=='p'||a=='P'))
			{ break; }
		else { sound(); }
	}
	if(a=='a'||a=='A') { a='.'; }
	else if(a=='h'||a=='H') { a='!'; }

	return a;
}

char KIDS(int decider)
{
	if(decider) { press(x/2-50, 4*y/6-15, x/2+50, 4*y/6+15); }
	fix(1, 1, 1, 1);

	char a;

	button(x/2-50, 3*y/6-15, x/2+50, 3*y/6+15);
	outtextxy(x/2-15, 3*y/6-2, "BOYS");
	line(x/2-15, 3*y/6+7, x/2-9, 3*y/6+7);

	button(x/2-50, 4*y/6-15, x/2+50, 4*y/6+15);
	outtextxy(x/2-15, 4*y/6-2, "GIRLS");
	line(x/2-15, 4*y/6+7, x/2-10, 4*y/6+7);

	while(1) {
		a=getch();
		if((a=='b'||a=='B'||a=='g'||a=='G')
		||(a=='p'||a=='P'||a=='e'||a=='E')
		||(a=='s'||a=='S'))
			{ break; }
		else { sound(); }
	}
	if(a=='b'||a=='B') { a=','; }

	return a;
}

char THREEPIC(int decider)
{
	static int g=1;

	if(decider && g) { press(x/2-50, 2*y/6-15, x/2+50, 2*y/6+15); }
	fix(1, 1, 1, 1);

	char a;

	box(x/4-i  , y/4-j  , x/4+i  , y/4+j  , 0);
	box(2*x/4-i, y/4-j  , 2*x/4+i, y/4+j  , 0);
	box(3*x/4-i, y/4-j  , 3*x/4+i, y/4+j  , 0);
	box(x/4-i  , 2*y/4-j, x/4+i  , 2*y/4+j, 0);
	box(2*x/4-i, 2*y/4-j, 2*x/4+i, 2*y/4+j, 0);
	box(3*x/4-i, 2*y/4-j, 3*x/4+i, 2*y/4+j, 0);
	box(x/4-i  , 3*y/4-j, x/4+i  , 3*y/4+j, 0);
	box(2*x/4-i, 3*y/4-j, 2*x/4+i, 3*y/4+j, 0);
	box(3*x/4-i, 3*y/4-j, 3*x/4+i, 3*y/4+j, 0);

	outtextxy(x/4-i-10  , y/4+j+3  , "1)Code:100; 100$" );
	outtextxy(2*x/4-i-10, y/4+j+3  , "2)Code:101; 50$"  );
	outtextxy(3*x/4-i-10, y/4+j+3  , "3)Code:102; 10$"  );
	outtextxy(x/4-i-10  , 2*y/4+j+3, "4)Code:103; 1000$");
	outtextxy(2*x/4-i-10, 2*y/4+j+3, "5)Code:104; 70$"  );
	outtextxy(3*x/4-i-10, 2*y/4+j+3, "6)Code:105; 20$"  );
	outtextxy(x/4-i-10  , 3*y/4+j+3, "7)Code:106; 30$"  );
	outtextxy(2*x/4-i-10, 3*y/4+j+3, "8)Code:107; 200$" );
	outtextxy(3*x/4-i-10, 3*y/4+j+3, "9)Code:108; 300$" );

	while(1) {
		a=getch();
		if((a=='p'||a=='P'||a=='s'||a=='S'||a=='e'||a=='E')
		||(a=='1'||a=='2'||a=='3'||a=='4'||a=='5'||a=='6')
		||(a=='7'||a=='8'||a=='9'))
			{ break; }
		else { sound(); }
	}
	if((a=='1'||a=='2'||a=='3'||a=='4'||a=='5'||a=='6')
	||(a=='7'||a=='8'||a=='9')) {
		boxer(a);
		a=buyer('t');
		g=0;
		if(a=='p'||a=='P') { a='t'; press(x/7-33, 9*y/10-12, x/7+33, 9*y/10+12); }
	}
	else { g=1; }

	return a;
}

char SHIRTS(int decider)
{
	static int g=1;

	if(decider && g) { press(x/2-50, 3*y/6-15, x/2+50, 3*y/6+15); }
	fix(1, 1, 1, 1);

	char a;

	box(x/4-i  , y/4-j  , x/4+i  , y/4+j  , 0);
	box(2*x/4-i, y/4-j  , 2*x/4+i, y/4+j  , 0);
	box(3*x/4-i, y/4-j  , 3*x/4+i, y/4+j  , 0);
	box(x/4-i  , 2*y/4-j, x/4+i  , 2*y/4+j, 0);
	box(2*x/4-i, 2*y/4-j, 2*x/4+i, 2*y/4+j, 0);
	box(3*x/4-i, 2*y/4-j, 3*x/4+i, 2*y/4+j, 0);
	box(x/4-i  , 3*y/4-j, x/4+i  , 3*y/4+j, 0);
	box(2*x/4-i, 3*y/4-j, 2*x/4+i, 3*y/4+j, 0);
	box(3*x/4-i, 3*y/4-j, 3*x/4+i, 3*y/4+j, 0);

	outtextxy(x/4-i-10  , y/4+j+3  , "1)Code:109; 100$" );
	outtextxy(2*x/4-i-10, y/4+j+3  , "2)Code:110; 50$"  );
	outtextxy(3*x/4-i-10, y/4+j+3  , "3)Code:111; 10$"  );
	outtextxy(x/4-i-10  , 2*y/4+j+3, "4)Code:112; 1000$");
	outtextxy(2*x/4-i-10, 2*y/4+j+3, "5)Code:113; 70$"  );
	outtextxy(3*x/4-i-10, 2*y/4+j+3, "6)Code:114; 20$"  );
	outtextxy(x/4-i-10  , 3*y/4+j+3, "7)Code:115; 30$"  );
	outtextxy(2*x/4-i-10, 3*y/4+j+3, "8)Code:116; 200$" );
	outtextxy(3*x/4-i-10, 3*y/4+j+3, "9)Code:117; 300$" );

	while(1) {
		a=getch();
		if((a=='p'||a=='P'||a=='s'||a=='S'||a=='e'||a=='E')
		||(a=='1'||a=='2'||a=='3'||a=='4'||a=='5'||a=='6')
		||(a=='7'||a=='8'||a=='9'))
			{ break; }
		else { sound(); }
	}
	if((a=='1'||a=='2'||a=='3'||a=='4'||a=='5'||a=='6')
	||(a=='7'||a=='8'||a=='9')) {
		boxer(a);
		a=buyer('h');
		g=0;
		if(a=='p'||a=='P') { a='h'; press(x/7-33, 9*y/10-12, x/7+33, 9*y/10+12); }
	}
	else { g=1; }

	return a;
}

char PANTS(int decider)
{
	static int g=1;

	if(decider && g) {  press(x/2-50, 4*y/6-15, x/2+50, 4*y/6+15); }
	fix(1, 1, 1, 1);

	char a;

	box(x/4-i  , y/4-j  , x/4+i  , y/4+j  , 0);
	box(2*x/4-i, y/4-j  , 2*x/4+i, y/4+j  , 0);
	box(3*x/4-i, y/4-j  , 3*x/4+i, y/4+j  , 0);
	box(x/4-i  , 2*y/4-j, x/4+i  , 2*y/4+j, 0);
	box(2*x/4-i, 2*y/4-j, 2*x/4+i, 2*y/4+j, 0);
	box(3*x/4-i, 2*y/4-j, 3*x/4+i, 2*y/4+j, 0);
	box(x/4-i  , 3*y/4-j, x/4+i  , 3*y/4+j, 0);
	box(2*x/4-i, 3*y/4-j, 2*x/4+i, 3*y/4+j, 0);
	box(3*x/4-i, 3*y/4-j, 3*x/4+i, 3*y/4+j, 0);

	outtextxy(x/4-i-10  , y/4+j+3  , "1)Code:118; 100$" );
	outtextxy(2*x/4-i-10, y/4+j+3  , "2)Code:119; 50$"  );
	outtextxy(3*x/4-i-10, y/4+j+3  , "3)Code:120; 10$"  );
	outtextxy(x/4-i-10  , 2*y/4+j+3, "4)Code:121; 1000$");
	outtextxy(2*x/4-i-10, 2*y/4+j+3, "5)Code:122; 70$"  );
	outtextxy(3*x/4-i-10, 2*y/4+j+3, "6)Code:123; 20$"  );
	outtextxy(x/4-i-10  , 3*y/4+j+3, "7)Code:124; 30$"  );
	outtextxy(2*x/4-i-10, 3*y/4+j+3, "8)Code:125; 200$" );
	outtextxy(3*x/4-i-10, 3*y/4+j+3, "9)Code:126; 300$" );

	while(1) {
		a=getch();
		if((a=='p'||a=='P'||a=='s'||a=='S'||a=='e'||a=='E')
		||(a=='1'||a=='2'||a=='3'||a=='4'||a=='5'||a=='6')
		||(a=='7'||a=='8'||a=='9'))
			{ break; }
		else { sound(); }
	}
	if((a=='1'||a=='2'||a=='3'||a=='4'||a=='5'||a=='6')
	||(a=='7'||a=='8'||a=='9')) {
		boxer(a);
		a=buyer('a');
		g=0;
		if(a=='p'||a=='P') { a='a'; press(x/7-33, 9*y/10-12, x/7+33, 9*y/10+12); }
	}
	else { g=1; }

	return a;
}

char KAMIZ(int decider)
{
	static int g=1;
	if(decider && g) { press(x/2-50, 2*y/6-15, x/2+50, 2*y/6+15); }
	fix(1, 1, 1, 1);

	char a;
	box(x/4-i  , y/4-j  , x/4+i  , y/4+j  , 0);
	box(2*x/4-i, y/4-j  , 2*x/4+i, y/4+j  , 0);
	box(3*x/4-i, y/4-j  , 3*x/4+i, y/4+j  , 0);
	box(x/4-i  , 2*y/4-j, x/4+i  , 2*y/4+j, 0);
	box(2*x/4-i, 2*y/4-j, 2*x/4+i, 2*y/4+j, 0);
	box(3*x/4-i, 2*y/4-j, 3*x/4+i, 2*y/4+j, 0);
	box(x/4-i  , 3*y/4-j, x/4+i  , 3*y/4+j, 0);
	box(2*x/4-i, 3*y/4-j, 2*x/4+i, 3*y/4+j, 0);
	box(3*x/4-i, 3*y/4-j, 3*x/4+i, 3*y/4+j, 0);

	outtextxy(x/4-i-10  , y/4+j+3  , "1)Code:127; 100$" );
	outtextxy(2*x/4-i-10, y/4+j+3  , "2)Code:128; 50$"  );
	outtextxy(3*x/4-i-10, y/4+j+3  , "3)Code:129; 10$"  );
	outtextxy(x/4-i-10  , 2*y/4+j+3, "4)Code:130; 1000$");
	outtextxy(2*x/4-i-10, 2*y/4+j+3, "5)Code:131; 70$"  );
	outtextxy(3*x/4-i-10, 2*y/4+j+3, "6)Code:132; 20$"  );
	outtextxy(x/4-i-10  , 3*y/4+j+3, "7)Code:133; 30$"  );
	outtextxy(2*x/4-i-10, 3*y/4+j+3, "8)Code:134; 200$" );
	outtextxy(3*x/4-i-10, 3*y/4+j+3, "9)Code:135; 300$" );

	while(1) {
		a=getch();
		if((a=='p'||a=='P'||a=='s'||a=='S'||a=='e'||a=='E')
		||(a=='1'||a=='2'||a=='3'||a=='4'||a=='5'||a=='6')
		||(a=='7'||a=='8'||a=='9'))
			{ break; }
		else { sound(); }
	}
	if((a=='1'||a=='2'||a=='3'||a=='4'||a=='5'||a=='6')
	||(a=='7'||a=='8'||a=='9')) {
		boxer(a);
		a=buyer('!');
		g=0;
		if(a=='p'||a=='P') { a='!'; press(x/7-33, 9*y/10-12, x/7+33, 9*y/10+12); }
	}
	else { g=1; }

	return a;
}

char BRIDAL(int decider)
{
	static int g=1;

	if(decider && g) {  	press(x/2-50, 3*y/6-15, x/2+50, 3*y/6+15); }
	fix(1, 1, 1, 1);

	char a;

	box(x/4-i  , y/4-j  , x/4+i  , y/4+j  , 0);
	box(2*x/4-i, y/4-j  , 2*x/4+i, y/4+j  , 0);
	box(3*x/4-i, y/4-j  , 3*x/4+i, y/4+j  , 0);
	box(x/4-i  , 2*y/4-j, x/4+i  , 2*y/4+j, 0);
	box(2*x/4-i, 2*y/4-j, 2*x/4+i, 2*y/4+j, 0);
	box(3*x/4-i, 2*y/4-j, 3*x/4+i, 2*y/4+j, 0);
	box(x/4-i  , 3*y/4-j, x/4+i  , 3*y/4+j, 0);
	box(2*x/4-i, 3*y/4-j, 2*x/4+i, 3*y/4+j, 0);
	box(3*x/4-i, 3*y/4-j, 3*x/4+i, 3*y/4+j, 0);

	outtextxy(x/4-i-10  , y/4+j+3  , "1)Code:136; 100$" );
	outtextxy(2*x/4-i-10, y/4+j+3  , "2)Code:137; 50$"  );
	outtextxy(3*x/4-i-10, y/4+j+3  , "3)Code:138; 10$"  );
	outtextxy(x/4-i-10  , 2*y/4+j+3, "4)Code:139; 1000$");
	outtextxy(2*x/4-i-10, 2*y/4+j+3, "5)Code:140; 70$"  );
	outtextxy(3*x/4-i-10, 2*y/4+j+3, "6)Code:141; 20$"  );
	outtextxy(x/4-i-10  , 3*y/4+j+3, "7)Code:142; 30$"  );
	outtextxy(2*x/4-i-10, 3*y/4+j+3, "8)Code:143; 200$" );
	outtextxy(3*x/4-i-10, 3*y/4+j+3, "9)Code:144; 300$" );

	while(1) {
		a=getch();
		if((a=='p'||a=='P'||a=='s'||a=='S'||a=='e'||a=='E')
		||(a=='1'||a=='2'||a=='3'||a=='4'||a=='5'||a=='6')
		||(a=='7'||a=='8'||a=='9'))
			{ break; }
		else { sound(); }
	}

	if((a=='1'||a=='2'||a=='3'||a=='4'||a=='5'||a=='6')
	||(a=='7'||a=='8'||a=='9')) {
		boxer(a);
		a=buyer('b');
		g=0;
		if(a=='p'||a=='P') { a='b'; press(x/7-33, 9*y/10-12, x/7+33, 9*y/10+12); }
	}
	else { g=1; }

	return a;
}

char FASHION(int decider)
{
	static int g=1;

	if(decider && g) { press(x/2-50, 4*y/6-15, x/2+50, 4*y/6+15); }
	fix(1, 1, 1, 1);

	char a;

	box(x/4-i  , y/4-j  , x/4+i  , y/4+j  , 0);
	box(2*x/4-i, y/4-j  , 2*x/4+i, y/4+j  , 0);
	box(3*x/4-i, y/4-j  , 3*x/4+i, y/4+j  , 0);
	box(x/4-i  , 2*y/4-j, x/4+i  , 2*y/4+j, 0);
	box(2*x/4-i, 2*y/4-j, 2*x/4+i, 2*y/4+j, 0);
	box(3*x/4-i, 2*y/4-j, 3*x/4+i, 2*y/4+j, 0);
	box(x/4-i  , 3*y/4-j, x/4+i  , 3*y/4+j, 0);
	box(2*x/4-i, 3*y/4-j, 2*x/4+i, 3*y/4+j, 0);
	box(3*x/4-i, 3*y/4-j, 3*x/4+i, 3*y/4+j, 0);

	outtextxy(x/4-i-10  , y/4+j+3  , "1)Code:145; 100$" );
	outtextxy(2*x/4-i-10, y/4+j+3  , "2)Code:146; 50$"  );
	outtextxy(3*x/4-i-10, y/4+j+3  , "3)Code:147; 10$"  );
	outtextxy(x/4-i-10  , 2*y/4+j+3, "4)Code:148; 1000$");
	outtextxy(2*x/4-i-10, 2*y/4+j+3, "5)Code:149; 70$"  );
	outtextxy(3*x/4-i-10, 2*y/4+j+3, "6)Code:150; 20$"  );
	outtextxy(x/4-i-10  , 3*y/4+j+3, "7)Code:151; 30$"  );
	outtextxy(2*x/4-i-10, 3*y/4+j+3, "8)Code:152; 200$" );
	outtextxy(3*x/4-i-10, 3*y/4+j+3, "9)Code:153; 300$" );

	while(1) {
		a=getch();
		if((a=='p'||a=='P'||a=='s'||a=='S'||a=='e'||a=='E')
		||(a=='1'||a=='2'||a=='3'||a=='4'||a=='5'||a=='6')
		||(a=='7'||a=='8'||a=='9'))
			{ break; }
		else { sound(); }
	}
	if((a=='1'||a=='2'||a=='3'||a=='4'||a=='5'||a=='6')
	||(a=='7'||a=='8'||a=='9')) {
		boxer(a);
		a=buyer('.');
		g=0;
		if(a=='p'||a=='P') { a='.'; press(x/7-33, 9*y/10-12, x/7+33, 9*y/10+12); }
	}
	else { g=1; }

	return a;
}

char BOY(int decider)
{
	static int g=1;

	if(decider && g) { press(x/2-50, 3*y/6-15, x/2+50, 3*y/6+15); }
	fix(1, 1, 1, 1);

	char a;

	box(x/4-i  , y/4-j  , x/4+i  , y/4+j  , 0);
	box(2*x/4-i, y/4-j  , 2*x/4+i, y/4+j  , 0);
	box(3*x/4-i, y/4-j  , 3*x/4+i, y/4+j  , 0);
	box(x/4-i  , 2*y/4-j, x/4+i  , 2*y/4+j, 0);
	box(2*x/4-i, 2*y/4-j, 2*x/4+i, 2*y/4+j, 0);
	box(3*x/4-i, 2*y/4-j, 3*x/4+i, 2*y/4+j, 0);
	box(x/4-i  , 3*y/4-j, x/4+i  , 3*y/4+j, 0);
	box(2*x/4-i, 3*y/4-j, 2*x/4+i, 3*y/4+j, 0);
	box(3*x/4-i, 3*y/4-j, 3*x/4+i, 3*y/4+j, 0);

	outtextxy(x/4-i-10  , y/4+j+3  , "1)Code:154; 100$" );
	outtextxy(2*x/4-i-10, y/4+j+3  , "2)Code:155; 50$"  );
	outtextxy(3*x/4-i-10, y/4+j+3  , "3)Code:156; 10$"  );
	outtextxy(x/4-i-10  , 2*y/4+j+3, "4)Code:157; 1000$");
	outtextxy(2*x/4-i-10, 2*y/4+j+3, "5)Code:158; 70$"  );
	outtextxy(3*x/4-i-10, 2*y/4+j+3, "6)Code:159; 20$"  );
	outtextxy(x/4-i-10  , 3*y/4+j+3, "7)Code:160; 30$"  );
	outtextxy(2*x/4-i-10, 3*y/4+j+3, "8)Code:161; 200$" );
	outtextxy(3*x/4-i-10, 3*y/4+j+3, "9)Code:162; 300$" );

	while(1) {
		a=getch();
		if((a=='p'||a=='P'||a=='s'||a=='S'||a=='e'||a=='E')
		||(a=='1'||a=='2'||a=='3'||a=='4'||a=='5'||a=='6')
		||(a=='7'||a=='8'||a=='9'))
			{ break; }
		else { sound(); }
	}
	if((a=='1'||a=='2'||a=='3'||a=='4'||a=='5'||a=='6')
	||(a=='7'||a=='8'||a=='9')) {
		boxer(a);
		a=buyer(',');
		g=0;
		if(a=='p'||a=='P') { a=','; press(x/7-33, 9*y/10-12, x/7+33, 9*y/10+12); }
	}
	else {g=1; }

	return a;
}

char GIRL(int decider)
{
	static int g=1;

	if(decider && g) { press(x/2-50, 4*y/6-15, x/2+50, 4*y/6+15); }
	fix(1, 1, 1, 1);

	char a;

	box(x/4-i  , y/4-j  , x/4+i  , y/4+j  , 0);
	box(2*x/4-i, y/4-j  , 2*x/4+i, y/4+j  , 0);
	box(3*x/4-i, y/4-j  , 3*x/4+i, y/4+j  , 0);
	box(x/4-i  , 2*y/4-j, x/4+i  , 2*y/4+j, 0);
	box(2*x/4-i, 2*y/4-j, 2*x/4+i, 2*y/4+j, 0);
	box(3*x/4-i, 2*y/4-j, 3*x/4+i, 2*y/4+j, 0);
	box(x/4-i  , 3*y/4-j, x/4+i  , 3*y/4+j, 0);
	box(2*x/4-i, 3*y/4-j, 2*x/4+i, 3*y/4+j, 0);
	box(3*x/4-i, 3*y/4-j, 3*x/4+i, 3*y/4+j, 0);

	outtextxy(x/4-i-10  , y/4+j+3  , "1)Code:163; 100$" );
	outtextxy(2*x/4-i-10, y/4+j+3  , "2)Code:164; 50$"  );
	outtextxy(3*x/4-i-10, y/4+j+3  , "3)Code:165; 10$"  );
	outtextxy(x/4-i-10  , 2*y/4+j+3, "4)Code:166; 1000$");
	outtextxy(2*x/4-i-10, 2*y/4+j+3, "5)Code:167; 70$"  );
	outtextxy(3*x/4-i-10, 2*y/4+j+3, "6)Code:168; 20$"  );
	outtextxy(x/4-i-10  , 3*y/4+j+3, "7)Code:169; 30$"  );
	outtextxy(2*x/4-i-10, 3*y/4+j+3, "8)Code:170; 200$" );
	outtextxy(3*x/4-i-10, 3*y/4+j+3, "9)Code:171; 300$" );

	while(1) {
		a=getch();
		if((a=='p'||a=='P'||a=='s'||a=='S'||a=='e'||a=='E')
		||(a=='1'||a=='2'||a=='3'||a=='4'||a=='5'||a=='6')
		||(a=='7'||a=='8'||a=='9'))
			{ break; }
		else { sound(); }
	}
	if((a=='1'||a=='2'||a=='3'||a=='4'||a=='5'||a=='6')
	||(a=='7'||a=='8'||a=='9')) {
		boxer(a);
		a=buyer('g');
		g=0;
		if(a=='p'||a=='P') { a='g'; press(x/7-33, 9*y/10-12, x/7+33, 9*y/10+12); }
	}
	else { g=1; }

	return a;
}