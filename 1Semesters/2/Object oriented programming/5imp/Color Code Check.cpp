// Color Code Check.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"iostream"
#include "windows.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	for (int colour = 0x00; colour <= 0xff; colour++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour), std::cout << "Using colour:" << colour << std::endl;
		cin.get();
	}



	return 0;
}

