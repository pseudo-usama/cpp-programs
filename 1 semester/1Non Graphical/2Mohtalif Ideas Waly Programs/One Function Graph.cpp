// One Function Graph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int x, y, constant, abc = 1;
	char reloader;

	do{

		cout << system("CLS");

		cout << "Enter the x Coefficient        =   ";
		cin >> x;

		cout << "Enter the y Coefficient        =   ";
		cin >> y;

		cout << "Enter the constant             =   ";
		cin >> constant;

		cout << "           " << x << "x";
		if (y > 0) { cout << " + "; }
		cout << y << "y" << " = " << constant << endl;

		cout << "This is the equation." << endl;
		cout << "To continue enter 'Y' or to enter values again enter 'N'.   = ";
		cin >> reloader;

		while (reloader != 'n' && reloader != 'N' && reloader != 'y' && reloader != 'Y')
		{
			cout << "Enter 'Y' or 'N'.   = ";
			cin >> reloader;
		}

	} while (reloader == 'n' || reloader == 'N');

	for (int a = 10; a >= -10; a--)
	{
		for (int b = -10; b <= 10; b++)
		{
			if (x * a + y * b == constant)
			{
				cout << "* ";
				abc = 0;
			}
			else if (a == 0)
			{
				if (b != -10 && b != 10) { cout << " "; }
				if (b > -1) { cout << " "; }
				cout << b;
			}
			else if (b == 0)
			{
				if (b != -10 && b != 10) { cout << " "; }
				if (b > -1) { cout << " "; }
				cout << a;
				if (a > -1) { cout << " "; }
			}
			else
			{
				cout << "   ";
			}
		}
		cout << endl;
	}

	if (abc)
	{
		cout << "There is no line in this range of graph." << endl;
		cout << "Enter an equation of limited range.";
	}

	return 0;
}


