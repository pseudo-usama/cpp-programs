// 7Factorial and square of its less num.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{

	int input, input2, plus;
	long b = 1;

	cout << "Enter the number less than 17.          =    ";
	cin >> input;

	for (; input < 0;)
	{
		cout << "ERROR. Enter a positive number." << endl;
		cout << "Enter the number less than 17.          =    ";
		cin >> input;

	}

	input2 = input;

	plus = input2 * input2 * -1;

	for (; input > 0; input--)
	{
		b = input * b;
		plus = plus + input * input;

	}

	cout << endl << "The foctorial of " << input2 << " number is            =    " << b << endl;
	cout << "The sum of the square of all " << endl;
	cout << "integers less than " << input2 << " is                 =    " << plus;
	 



	return 0;
}

