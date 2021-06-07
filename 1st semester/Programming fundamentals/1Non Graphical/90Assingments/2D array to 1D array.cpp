// 2D array to 1D array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int a[3][3], b[9], n = 0, holder;
	bool decider = 1;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "Enter the " << i << "*" << j << "'s index number   = ";
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			b[n] = a[i][j];
			n++;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 8 - i; j++)
		{
			if (b[j] > b[j + 1])
			{
				holder = b[j];
				b[j] = b[j + 1];
				b[j + 1] = holder;
				decider = 0;
			}
		}
		if (decider) { break; }
		decider = 1;
	}

	cout << endl << "After converting the values in assinding order 1 Dimentional array. The result is" << endl << endl;

	for (int i = 0; i < 9; i++)
	{
		cout << "The " << i << " number is " << b[i] << endl;
	}

	cout << endl << endl;

	return 0;
}

