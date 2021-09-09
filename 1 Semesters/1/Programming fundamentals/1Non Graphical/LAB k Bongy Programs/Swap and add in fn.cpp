// Swap and add in fn.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

void fn(int a, int b)
{
	int holder;

	holder = a;
	a = b;
	b = holder;

	cout << endl << "The sum is   = " << a + b;
}

int main()
{
	int a, b;

	cout << "Enter the first number.    = ";
	cin >> a;

	cout << "Enter the second number.   = ";
	cin >> b;

	fn(a, b);

	return 0;
}

