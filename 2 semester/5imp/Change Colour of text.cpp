// Change Colour of text.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "windows.h"
using namespace std;

/*
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGREY 7
#define DARKGREY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15
#define BLINK 128
*/

void Fn1() {	//Only Text
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //replace the 0 with a number for the color you want

	cout << "Your text here" << endl;

}

void Fn2() {	//With Back Ground
	HANDLE a = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(a, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Bright red text\n";
	//SetConsoleTextAttribute(a, 4 | FOREGROUND_INTENSITY);
	//cout << "\n\nBright red text\n";
	SetConsoleTextAttribute(a, FOREGROUND_RED | BACKGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY);
	cout << "\n\nBack to normal white text\n";
	//SetConsoleTextAttribute(a, 4 | 2 | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY );
	//cout << "\n\nBack to normal white text\n";
	cout << "\n\nPress any key to exit program.....";
	cin.get();

}

void main() {
	
	Fn1();
	Fn2();



	

}



