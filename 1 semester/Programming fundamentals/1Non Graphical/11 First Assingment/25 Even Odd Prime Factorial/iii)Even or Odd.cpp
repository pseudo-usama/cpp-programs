// iii)Even or Odd.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int a, b;

	cout << "Enter a number.     =    ";
	cin >> a;

	b = a % 2;

	cout << endl;

	if (b == 1)
	{
		cout << "Your digit is ODD.";
	}
	else
	{
		cout << "Your digit is EVEN.";
	}

	return 0;
}