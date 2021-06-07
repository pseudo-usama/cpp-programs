// 15Convert each digit of number to word.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int input, output, number = 0, ZeroStoper = 0;

	cout << "Enter the number(maximum nine digits).       =   ";
	cin >> input;

	for (; input > 999999999; )
	{
		cout << "ERROR" << endl;
		cout << "Enter the number(maximum nine digits).       =   ";
		cin >> input;
	}
	if (input < 0)
	{
		cout << " MINUS";
		input = input * -1;
	}

//	input = input * 10 + 2;
	for (int a = 1; a < 10; a++)
	{
		output = input % 10;
		input = input / 10;

		number = number * 10 + output;
	}

	for (int a = 1; a < 10; a++)
	{
		output = number % 10;
		number = number / 10;
		if (output != 0)
		{
			ZeroStoper = 1;
		}
		if (ZeroStoper == 1)
		{
			if (output == 0)
			{
				cout << " ZERO";
			}
			else if (output == 1)
			{
				cout << " ONE";
			}
			else if (output == 2)
			{
				cout << " TWO";
			}
			else if (output == 3)
			{
				cout << " THREE";
			}
			else if (output == 4)
			{
				cout << " FOUR";
			}
			else if (output == 5)
			{
				cout << " FIVE";
			}
			else if (output == 6)
			{
				cout << " SIX";
			}
			else if (output == 7)
			{
				cout << " SEVEN";
			}
			else if (output == 8)
			{
				cout << " EIGHT";
			}
			else if (output == 9)
			{
				cout << " NINE";
			}
		}

	}
	return 0;
}

