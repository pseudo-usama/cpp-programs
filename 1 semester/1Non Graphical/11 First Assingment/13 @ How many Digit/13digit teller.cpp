// 13digit teller.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{

	int input, a1, a2, a3, a4, a5, a6, a7, a8, a9;

	cout << "Enter the number(maximum 9 digits).         =    ";
	cin >> input;

	for (; input > 999999999;)
	{
		cout << "ERROR." << endl;
		cout << "Please enter a number of maximum nine digits=    ";
		cin >> input;
	}

	a9 = input % 10;
	input = input / 10;

	a8 = input % 10;
	input = input / 10;

	a7 = input % 10;
	input = input / 10;

	a6 = input % 10;
	input = input / 10;

	a5 = input % 10;
	input = input / 10;

	a4 = input % 10;
	input = input / 10;

	a3 = input % 10;
	input = input / 10;

	a2 = input % 10;
	input = input / 10;

	a1 = input % 10;
	input = input / 10;

	if (a1 == 0)
	{
		if (a2 == 0)
		{
			if (a3 == 0)
			{
				if (a4 == 0)
				{
					if (a5 == 0)
					{
						if (a6 == 0)
						{
							if (a7 == 0)
							{
								if (a8 == 0)
								{
									cout << "There are one digit.";
								}
								else
								{
									cout << "There are two digits.";
								}
							}
							else
							{
								cout << "There are three digits.";
							}
						}
						else
						{
							cout << "There are four digits.";
						}
					}
					else
					{
						cout << "There are five digits.";
					}
				}
				else
				{
					cout << "There are six digits.";
				}
			}
			else
			{
				cout << "There are sevse digits.";
			}

		}
		else
		{
			cout << "There are eight digits.";
		}
	}
	else
	{
		cout << "There are nine digits.";
	}
	return 0;
}

