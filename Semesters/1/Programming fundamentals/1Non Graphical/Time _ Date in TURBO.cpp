#include <fstream.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <stdio.h>
#include <process.h>
#include <conio.h>
#include <graphics.h>
#include <string.h>
#include <dos.h>
#define BAR 0
#define THORN 1
#define ENEMY 2
#define GEM 3

void main() {

	int gdriver = DETECT,gmode;
	initgraph(&gdriver,&gmode,"C:\\TC\\BGI");

	clrscr();

	time_t z;
	z=time(NULL);
	cout<<ctime(&z);

	getch();
}

