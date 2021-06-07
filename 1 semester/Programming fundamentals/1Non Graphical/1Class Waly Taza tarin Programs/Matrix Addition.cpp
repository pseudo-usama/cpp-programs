// Matrix Addition.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

bool checker(int row1, int row2, int coloum1, int coloum2, char oprator)
{
	if ((oprator == '+' || oprator == '-') && row1 == row2 && coloum1 == coloum2) { return 1; }
	else if (oprator == '*' && coloum1 == row2) { return 1; }
	else { return 0; }
}

int main()
{
	int holder, i, j, iC, jC, row1, row2, coloum1, coloum2, a[50][50], b[50][50], c[50][50];
	char oprator;


	cout << "Enter the numbers of row of first matrix        = ";
	cin >> row1;

	cout << "Enter the numbers of coloums of first matrix    = ";
	cin >> coloum1;

	cout << endl;

	for (i = 0; i < row1; i++)
	{
		for (j = 0; j < coloum1; j++)
		{
			cout << "Enter a value of " << i + 1 << "*" << j + 1 << "  = ";
			cin >> a[i][j];
		}
	}

	cout << endl;

	cout << "Enter the numbers of row of second matrix       = ";
	cin >> row2;

	cout << "Enter the numbers of coloums of seconds matrix  = ";
	cin >> coloum2;

	cout << endl;

	for (i = 0; i < row2; i++)
	{
		for (j = 0; j < coloum2; j++)
		{
			cout << "Enter a value of " << i + 1 << "*" << j + 1 << "  = ";
			cin >> b[i][j];
		}
	}

	cout << endl << endl;

	cout << "Enter the OPTATOR to be used.   = ";
	cin >> oprator;

	for (; oprator != '+' && oprator != '-' && oprator != '*';)
	{
		cout << "Please enter '+', '-' or '*'.";
		cin >> oprator;
	}

	cout << endl << endl << endl;

	if (checker(row1, row2, coloum1, coloum2, oprator))
	{
		if (oprator != '*')
		{
			for (i = 0; i < row1; i++)
			{
				for (j = 0; j < coloum1; j++)
				{
					if (oprator == '+') { cout << a[i][j] + b[i][j] << " "; }
					else { cout << a[i][j] - b[i][j] << " "; }
				}
				cout << endl;
			}
		}
		else
		{
			for (i = 0; i < row1; i++)
			{
				holder = 0;

				for (j = 0; j < coloum1; j++)
				{
						holder = holder + a[j][i] * b[i][j]; 
						if (j < coloum2) { j--; }
				}
				c[i][j - 1] = holder;
			}

			for (i = 0; i < row1; i++)
			{
				for (j = 0; j < coloum1; j++)
				{
					cout << c[i][j] << " ";
				}
				cout << endl;
			}
		}
	}
	else
	{
		cout << "Opration is not possible as both matrixs have not required order.";
	}

	cout << endl << endl;

	return 0;
}

