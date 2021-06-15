// factorial prime odd.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

void factorial(int a)
{
	int factorial = 1;

	for (int i = 0; i < a; i++)
	{
		factorial = factorial * (a - i);
	}

	cout << "The factorial is" << factorial;

}

void EVEN(int a)
{
	if (a % 2 == 0) { cout << "The number is EVEN"; }
	else { cout << "The number is ODD"; }
}

void PRIME(int a)
{
	int z = 0;

	for (int i = 2; i <= a / 2; i++)
	{
		if (a % i == 0) { z = 1; break; }
	}
	if (z) { cout << "The number is not a prime number"; }
	else { cout << "The number is a prime number"; }
}

int main()
{
	int a, selector;

	do{
		cout << endl;
		cout << "Enter the number to selecte the option" << endl << endl;
		cout << "1)  FACTORIAL" << endl;
		cout << "2)  EVEN ODD" << endl;
		cout << "3)  PRIME OR NOT" << endl;
		cout << "4)  EXIT" << endl;

		cout << "Enter here     = ";
		cin >> selector;

		system("CLS");

		if (selector != 4) {
			cout << "Enter the number   = ";
			cin >> a;

			if (selector == 1) { factorial(a); }
			if (selector == 2) { EVEN(a); }
			if (selector == 3) { PRIME(a); }
		}

	} while (selector != 4);

	return 0;
}

