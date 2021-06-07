// 8Sum Average and Product of 1 to 50.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int sum = 0;
	double product = 1, a = 1.0;

	cout << "The sum of series " << endl << endl;

	while (a < 50)
	{
		cout << a << "+";
		sum = sum + a;
		a++;
	}

	cout << "50" << endl;

	cout << " is equal to      =   " << sum + 50 << endl << endl;

	cout << "And the average is " << (sum + 50.0) / 50.0 << endl << endl;

	a = 1;

	cout << "The product of the series " << endl << endl;

	while (a < 50)
	{
		cout << a << "*";
		product = product * a;
		a++;
	}
	cout << "50";

	cout << endl << " is equal to      =   " << product * 50;
	return 0;
}

