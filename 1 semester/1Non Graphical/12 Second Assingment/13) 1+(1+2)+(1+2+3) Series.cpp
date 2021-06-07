// 13) 1+(1+2)+(1+2+3) Series.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int range, sum = 0, a = 1, b;

	cout << "Enter the maximum point.            =   ";
	cin >> range;

	cout << endl << "   The sum of series  " << endl << "          ";

	while (a <= range)
	{
		cout << "(";
		b = 1;
		while (b < a)
		{
			cout << b << "+";
			sum = sum + b;
			b++;
		}

		cout << b;
		sum = sum + b;

		cout << ") + ";
		a++;
	}

	cout << endl << "            is  = " << sum;

	return 0;
}

