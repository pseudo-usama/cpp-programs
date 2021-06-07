// 2 Functon Graph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int x1, x2, y1, y2, constant1, constant2, abc = 1, decider;
	char reloader;

	do{

		cout << system("CLS");

		cout << "Enter the values of 1st Functon." << endl << endl;

		cout << "Enter the x Coefficient        =   ";
		cin >> x1;

		cout << "Enter the y Coefficient        =   ";
		cin >> y1;

		cout << "Enter the constant             =   ";
		cin >> constant1;

		cout << endl << "Enter the values of 2nd Functon." << endl << endl;

		cout << "Enter the x Coefficient        =   ";
		cin >> x2;

		cout << "Enter the y Coefficient        =   ";
		cin >> y2;

		cout << "Enter the constant             =   ";
		cin >> constant2;

		cout << endl << "First Function   " << x1 << "x";
		if (y1 > 0) { cout << " + "; }
		cout << y1 << "y" << " = " << constant1 << endl;

		cout << "Second Function  " << x2  << "x";
		if (y2 > 0) { cout << " + "; }
		cout << y2 << "y" << " = " << constant2 << endl << endl;

		cout << "To show muctual point enter 1." << endl;
		cout << "Or enter 2 to show both lnes.     = ";
		cin >> decider;

		while (decider != 1 && decider != 2)
		{
			cout << "Enter 1 or 2.         = ";
			cin >> decider;
		}

		cout << "This is the equations." << endl;
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
			if (x1 * a + y1 * b == constant1 && x2 * a + y2 * b == constant2 && decider == 1)
			{
				cout << "* ";
				abc = 0;
			}
			else if (x1 * a + y1 * b == constant1 || x2 * a + y2 * b == constant2 && decider == 2)
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
		cout << "Or there is no mutual point.";
	}

	return 0;
}




