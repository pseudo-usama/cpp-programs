// a b greater value.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include"iostream"
using namespace std;

int main()
{
	int a, b;
	cout << "Enter the first value ";
	cin >> a;

	cout << endl;

	cout << "Enter the second value  ";
	cin >> b;

	cout << endl << endl;




	if (a == b)
	{
		cout << "Both the values are equal." << endl;
	}
	else if (a > b)
	{
		cout << "The greater value is ";
		cout << a << endl;
		cout << "The lesser value is ";
		cout << b << endl;
	}
	else
	{
		cout << "The greater value is ";
		cout << b << endl;
		cout << "The lesser value is ";
		cout << a << endl;
	}
	return 0;
}


