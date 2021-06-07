// ii )Prime number or not.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{

	int input, b = 0;

	cout << "Enter the number.        =    ";
	cin >> input;

	for (int a = 1; a < input; a++)
	{
		if (input % a == 0)
		{
			b = b + 1;
		}
	}

	if (b == 1)
	{
		cout << "The number is prime.";
	}
	else
	{
		cout << "the number is not a prime.";
	}

	return 0;
}

