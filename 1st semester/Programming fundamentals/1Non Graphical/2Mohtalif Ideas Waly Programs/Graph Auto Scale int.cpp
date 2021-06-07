// Graph Auto Scale int.cpp : Defines the entry point for the console application.
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

	for (int a = y / 10 * 10 + 10; a >= -y / 10 * 10 - 10; a = a - y / 10 - 1)
	{
		for (int b = -x / 10 * 10 - 10; b <= x / 10 * 10 + 10; b = b + x / 10 + 1)
		{
			if (x == b && y == a)
			{
				cout << "* ";
			}
			else if (a == 0)
			{
				if (b > -1) { cout << " "; }
				cout << b;
			}
			else if (b == 0)
			{
				cout << a;
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


