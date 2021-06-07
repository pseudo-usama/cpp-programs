// 12nCr Factor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{

	int a = 0, n = 0, r = 1, nMinusr;
	double long  nFactorial = 1, rFactorial = 1, nMinusrFactorial = 1;

	for (;r > n || r <= 0 || n <= 0 || n > 170;)
	{

		if (a != 0)
		{
			cout << "ERROR. r cannot be greater" << endl;
			cout << "than n nor either can be -ve. " << endl;
			cout << "And enter n less than 171." << endl;
		}

		cout << "Enter the number(n).          =    ";
		cin >> n;

		cout << "Enter the (r).                =    ";
		cin >> r;

		a = 1;

	}
	nMinusr = n - r;

	for (; nMinusr > 0; nMinusr--)

	{
		nMinusrFactorial = nMinusrFactorial * nMinusr;
	}

	for (; n > 0; n--)

	{
		nFactorial = nFactorial * n;
	}

	for (; r > 0; r--)

	{
		rFactorial = rFactorial * r;
	}

	cout << "The nCr factor is             =    " << (nFactorial / rFactorial) / nMinusrFactorial;


	return 0;
}

