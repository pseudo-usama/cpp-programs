// 2Khokhla box.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int length, width, a = 1, b;

	do{
		cout << "Enter the length of the box(+ve number)         =   ";
		cin >> length;
	} while (length < 0);

	do{
		cout << "Enter the width of the box(+ve number)          =   ";
		cin >> width;
	} while (width < 0);

	while (a <= width)
	{
		b = 1;
		while (b <= length)
		{
			if (a == 1 || a == width || b == 1 || b == length)
			{
				cout << "* ";
			}
			else
			{
				cout << "  ";
			}
			b++;
		}
		a++;
		cout << endl;
	}


	return 0;
}

