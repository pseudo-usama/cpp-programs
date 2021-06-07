// 9Sum of inverse factorail series.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int limit, a = 1, FactorialDecriser;
	double factorial;
	float sum = 0;
	
	do{
		cout << "Enter the limit of the series        =   ";
		cin >> limit;

		if (limit < 0)
		{
			cout << "Enter a positive number." << endl;
		}
	} while (limit < 0);

	cout << endl;

	cout << "The sum of series " << endl;

	while (a < limit)
	{
		cout << "1/" << a << "!" << " + ";
		FactorialDecriser = a;
		factorial = 1;
		while (FactorialDecriser != 1)
		{
			factorial = factorial * FactorialDecriser;
			FactorialDecriser = FactorialDecriser - 1;
		}
		sum = sum + (1 / factorial);
		a++;
	}

	cout << "1/" << a << "!";
	FactorialDecriser = a;
	factorial = 1;
	while (FactorialDecriser != 1)
	{
		factorial = factorial * FactorialDecriser;
		FactorialDecriser = FactorialDecriser - 1;
	}
	sum = sum + (1 / factorial);

	cout << " = " <<  sum;

	return 0;
}

