// sum upto n.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int range, sum = 0;

	cout << "Enter the rangr          =   ";
	cin >> range;

	cout << "The sum is" << endl;

	for (int a = 1; a <= range; a++)
	{
		cout << a << "+";
		sum = sum + a;
	}

	cout << " = " << sum;

	return 0;
}

