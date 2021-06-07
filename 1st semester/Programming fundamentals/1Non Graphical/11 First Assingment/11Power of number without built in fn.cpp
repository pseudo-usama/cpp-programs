// 11Power of number without built in fn.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{

	int input, exponent, answer, divider = 0;

	cout << "Enter the base.             =    ";
	cin >> input;

	cout << "Enter the exponent          =    ";
	cin >> exponent;

	if (exponent < 0)
	{
		exponent = -1 * exponent;
		divider = 1;
	}

	answer = input;

	for (int stoper = 1; stoper < exponent; stoper++)
	{
		answer = answer * input;
	}

	cout << "Tne answer is ";

	if (divider == 1)
	{
		cout << "1 / " << answer;
	}
	else
	{
		cout << answer;
	}

	return 0;
}

