// 15Polinomial series sum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int base, power, coefficient, a = 1;
	double sum = 0;

	cout << "Enter the value of base.                 =    ";
	cin >> base;

	cout << "Enter the value of maximum power         =    ";
	cin >> power;

	cout << "Enter the value of coefficient.          =    ";
	cin >> coefficient;

	cout << endl << "The sum of the series " << endl << "        ";

	while (a < power)
	{
		cout << coefficient << "(" << base << ")^" << a;
		if (a % 2 != 0)
		{
			cout << " - ";
			sum = sum + coefficient * pow(base, a);
		}
		else
		{
			cout << " + ";
			sum = sum - coefficient * pow(base, a);
		}
		a++;
	}

	cout << coefficient << "*" << "(" << base << ")^" << a;
	if (a % 2 != 0)
	{
		sum = sum + coefficient * pow(base, a);
	}
	else
	{
		sum = sum - coefficient * pow(base, a);
	}
	cout << endl << endl;
	cout << "              is     =  " << sum;

	return 0;
}

