// 13Digit teller asan tarika.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int input, a = 1;

	cout << "Enter a number          =   ";
	cin >> input;

	if (input == 0)
	{
		cout << "The digits is 1";
	}
	else
	{
		for (; input != 0; a++)
		{
			input = input / 10;
		}

		cout << "The digits is " << a - 1;
	}
	return 0;
}

