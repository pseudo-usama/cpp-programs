// admi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;


int main()
{

	for (int x = 1; x <= 9; x++)
	{
		for (int y = 1; y <= 10; y++)
		{
			int a = x;
			int b = y;

			if ((((((a == 2 && b == 5) || (a == 2 && b == 6) || (a == 3 && b == 4) || (a == 3 && b == 5) || (a == 3 && b == 6))
				|| (a == 3 && b == 7) || (a == 4 && b == 4) || (a == 4 && b == 5) || (a == 4 && b == 6) || (a == 4 && b == 8))
				|| (a == 5 && b == 4) || (a == 5 && b == 5) || (a == 5 && b == 6) || (a == 5 && b == 9))
				|| (a == 6 && b == 4) || (a == 6 && b == 6) || (a == 7 && b == 3) || (a == 7 && b == 6))
				|| (a == 8 && b == 2) || (a == 8 && b == 6))
			{
				cout << " *";
			}
			else
			{
				cout << "  ";
			}
		}
		cout << endl;
	}
}