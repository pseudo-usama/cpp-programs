// 10Palindrome number or not.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{

	int input, reverse, a, a1, a2, a3, a4, a5;

	cout << "Enter a number of five digits.          =     ";
	cin >> input;
	for (;  input < 10000 || input > 99999;)
	{
		cout << "Enter a number of five digits.          =     ";
		cin >> input;
	}
	a5 = input % 10;
	a  = input / 10;

	a4 = a % 10;
	a  = a / 10;

	a3 = a % 10;
	a  = a / 10;

	a2 = a % 10;
	a1 = a / 10;

	cout << endl;
	reverse = a5 * 10000 + a4 * 1000 + a3 * 100 + a2 * 10 + a1;


	cout << endl;

	if (input == reverse)
	{
		cout << "The number is PALINDROME.";
	}
	else
	{
		cout << "NO THE NUMBER IS NOT PALINDROME.";
	}

	return 0;
}

