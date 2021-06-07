// Change color.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include "iostream"

int _tmain(int argc, _TCHAR* argv[])
{
	HANDLE m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(m_hConsole,
		FOREGROUND_RED |
		FOREGROUND_GREEN |
		FOREGROUND_BLUE |
		FOREGROUND_INTENSITY);

	std::cout << "Whassupp\n";

	SetConsoleTextAttribute(m_hConsole,
		BACKGROUND_RED |
		BACKGROUND_GREEN |
		BACKGROUND_BLUE);

	std::cout << "I mean, how you doin?\n";

	SetConsoleTextAttribute(m_hConsole,
		FOREGROUND_BLUE |
		FOREGROUND_INTENSITY |
		BACKGROUND_GREEN |
		BACKGROUND_INTENSITY);

	std::cout << "Dude, where's my car? DUDE??\n";

	SetConsoleTextAttribute(m_hConsole,
		FOREGROUND_RED |
		FOREGROUND_GREEN |
		FOREGROUND_BLUE);

	std::cout << "Credit: google, msdn.microsoft.com\n";


	return 0;
}

