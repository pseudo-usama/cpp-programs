// Change Font.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include "iostream"
using namespace std;

void Fn1() {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 10;                   // Width of each character in the font
	cfi.dwFontSize.Y = 100;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

void Fn2(int x , int y){
	// Obtain the Console handle
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Obtain the Console handle

	PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();

	// set the size of the CONSOLE_FONT_INFOEX
	lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);

	// get the current value
	GetCurrentConsoleFontEx(hConsole, 0, lpConsoleCurrentFontEx);

	// set size to be 8x18, the default size is 8x16
	lpConsoleCurrentFontEx->dwFontSize.X = x;
	lpConsoleCurrentFontEx->dwFontSize.Y = y;

	// submit the settings
	SetCurrentConsoleFontEx(hConsole, 0, lpConsoleCurrentFontEx);

}

void main() {

	

}



