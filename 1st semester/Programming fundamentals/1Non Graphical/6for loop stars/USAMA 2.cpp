// USAMA 2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	for (int a = 1; a <= 8; a++)
	{
		for (int b = 1; b <= 18; b++)
		{
			if ((((a == 7 && b != 16 && b != 8 && b != 2 && b != 18) || (b == 9 && a != 8) || (b == 17 && a != 8))
				|| (a == 6 && b != 2 && b != 4 && b != 6 && b != 8 && b != 10 && b != 12 && b != 14 && b != 16 && b != 18))
				|| (a == 5 && b != 4 && b != 8 && b != 10 && b != 12 && b != 14 && b != 16 && b != 18))
			{
				cout << "* ";
			}
			else
			{
				cout << "  ";
			}
		}
		cout << endl;
	}

	return 0;
}


