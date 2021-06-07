// Point Graph int.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int x, y;

	cout << "Enter the x-intercept        =   ";
	cin >> x;

	cout << "Enter the y-intercept        =   ";
	cin >> y;

	for (int a = 5; a >= -5; a--)
	{
		for (int b = -5; b <= 5; b++)
		{
			if (a + b == 2)
			{
				cout << "* ";
			}
			else if (a == 0)
			{
				cout << b;
				if (b > -1) {cout << " ";}
			}
			else if (b == 0)
			{
				cout << a;
				if (a > -1) { cout << " "; }
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

