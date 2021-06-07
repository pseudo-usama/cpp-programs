// Factorial 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int input, a1, a2, a3, a4, a5, a6, a7;

	cout << "Enter the number less than nine.   ";
	cin >> input;

	a1 = input - 1;
	a2 = a1 - 1;
	a3 = a2 - 1;
	a4 = a3 - 1;       // these all equations are making numbers 
	a5 = a4 - 1;       // in sequence that are less then one to
	a6 = a5 - 1;       // its earlier one.
	a7 = a6 - 1;

	cout << endl;

	if (input < 8 || input > 1)                  // find that input number is in between 0 and 9.
	{

		cout << "The fictorial of " << input << " is ";

		if (a7 > 0)              
		{                         
			cout << input * a1 * a2 * a3 * a4 * a5 *a6 * a7;
		}
		else if (a6 > 0)
		{
			cout << input * a1 * a2 * a3 * a4 * a5 *a6;
		}
		else if (a5 > 0)                         // These all conditions find that if the number is zero than 
		{                                        // the previous result is final
			cout << input * a1 * a2 * a3 * a4 * a5;
		}
		else if (a4 > 0)
		{
			cout << input * a1 * a2 * a3 * a4;
		}
		else if (a3 > 0)
		{
			cout << input * a1 * a2 * a3;
		}
		else if (a2 > 0)
		{
			cout << input * a1 * a2;
		}
		else if (a1 > 0)
		{
			cout << input * a1;
		}
		else
		{
			cout << input;
		}
		cout << ".";
	}

	else
	{
		cout << "Please enter a number in between 0 and 9.";
	}

	cout << endl << endl << endl;

	return 0;
}