// i)factorial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	long a, b = 1;

	cout << "Enter the number less than 17.        =   ";
	cin >> a;

	for (; a > 0; a--)

	{
		b = b * a;
	}

	cout << "The factorial is                      =   " << b;

	return 0;
}
