// 14Dacimal to roman.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{

	int input, a1, a2, a3, a4, a5;

	cout << "Enter a number(maximum 50000).       =   ";
	cin >> input;

	for (; input > 50000 || input <= 0;)
	{
		cout << "ERROR." << endl;
		cout << "Please enter a number of maximum nine digits=    ";
		cin >> input;
	}

	a5 = input % 10;
	input = input / 10;

	a4 = input % 10;
	input = input / 10;

	a3 = input % 10;
	input = input / 10;

	a2 = input % 10;
	a1 = input / 10;
	

		if (a1 == 1)
		{
			cout << "X";
		}
		else if (a1 == 2)
		{
			cout << "XX";
		}
		else if (a1 == 3)
		{
			cout << "XXX";
		}
		else if (a1 == 4)
		{
			cout << "XL";
		} 
		else if (a1 == 5)
		{
			cout << "L";
		}

		if (a2 == 1)
		{
			cout << "M";
		}
		else if (a2 == 2)
		{
			cout << "MM";
		}
		else if (a2 == 3)
		{
			cout << "MMM";
		}
		else if (a2 == 4)
		{
			cout << "MV";
		}
		else if (a2 == 5)
		{
			cout << "V";
		}
		else if (a2 == 6)
		{
			cout << "VM";
		}
		else if (a2 == 7)
		{
			cout << "VMM";
		}
		else if (a2 == 8)
		{
			cout << "VMMM";
		}
		else if (a2 == 9)
		{
			cout << "MX";
		}

		if (a3 == 1)
		{
			cout << "C";
		}
		else if (a3 == 2)
		{
			cout << "CC";
		}
		else if (a3 == 3)
		{
			cout << "CCC";
		}
		else if (a3 == 4)
		{
			cout << "CD";
		}
		else if (a3 == 5)
		{
			cout << "D";
		}
		else if (a3 == 6)
		{
			cout << "DC";
		}
		else if (a3 == 7)
		{
			cout << "DCC";
		}
		else if (a3 == 8)
		{
			cout << "DCCC";
		}
		else if (a3 == 9)
		{
			cout << "CM";
		}

			if (a4 == 1)
			{
				cout << "x";
			}
			else if (a4 == 2)
			{
				cout << "xx";
			}
			else if (a4 == 3)
			{
				cout << "xxx";
			}
			else if (a4 == 4)
			{
				cout << "xL";
			}
			else if (a4 == 5)
			{
				cout << "L";
			}
			else if (a4 == 6)
			{
				cout << "Lx";
			}
			else if (a4 == 7)
			{
				cout << "Lxx";
			}
			else if (a4 == 8)
			{
				cout << "Lxxx";
			}
			else if (a4 == 9)
			{
				cout << "xC";
			}
		

	

		if (a5 == 1)
		{
			cout << "i";
		}
		else if (a5 == 2)
		{
			cout << "ii";
		}
		else if (a5 == 3)
		{
			cout << "iii";
		}
		else if (a5 == 4)
		{
			cout << "iv";
		}
		else if (a5 == 5)
		{
			cout << "v";
		}
		else if (a5 == 6)
		{
			cout << "vi";
		}
		else if (a5 == 7)
		{
			cout << "vii";
		}
		else if (a5 == 8)
		{
			cout << "viii";
		}
		else if (a5 == 9)
		{
			cout << "ix";
		}
	

	return 0;
}

