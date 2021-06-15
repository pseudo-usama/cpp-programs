// mohsin riaz.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	for (int j = 1; j <= 12; j++)
	{
		for (int i = 1; i <= 40; i++)
		{
			if ((((i == 14 && j > 4 && j != 12) || (i == 16 && j > 8 && j != 12) || (i == 2 && j < 12 && j > 6) || (j == 10 && ((i < 1 && i < 9) || (i < 27))))
				|| ((j == 2 || j == 3) && (i == 37 || i == 38)) || ((j == 4 || j == 6 || j == 7) && i == 36) || ((j == 5 || j == 7 || j == 8) && i == 35) || (j == 7 && i == 37))
				|| (j == 8 && i > 26 && i < 35) || ((i == 33 || i == 31 || i == 29 || i == 27) && (j == 7 || j == 8)))
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

