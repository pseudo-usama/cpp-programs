// Hide input.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "windows.h"
#include "string"
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{

	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(hStdin, &mode);
	SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));

	string s;
	getline(cin, s);

	cout << s << endl;

	return 0;
}

