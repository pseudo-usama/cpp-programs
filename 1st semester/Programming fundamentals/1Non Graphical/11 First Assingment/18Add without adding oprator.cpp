// 18Add without adding oprator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int a, b;

	cout << "Enter the first number.        =   ";
	cin >> a;

	cout << "Enter the second number.       =   ";
	cin >> b;

	cout << endl;

	cout << "According to this formula." << endl;
	cout << "     -(-a - b)" << endl;
	cout << "     Where  a = First Number" << endl;
	cout << "     And    b = Second Number" << endl << endl;

	cout << "The sum of " << a << " and " << b << " is           =   ";

	cout << -(-a - b);

	return 0;
}

