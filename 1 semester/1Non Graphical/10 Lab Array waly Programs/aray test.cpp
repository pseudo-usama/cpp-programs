// aray test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int number[10];

	for (int a = 0; a < 10; a++)
	{
		cout << "Enter the " << a + 1 <<  " number  = ";
		cin >> number[a];
	}

	cout << endl;

	for (int a = 0; a < 10; a++)
	{
		cout << "The " << a + 1 << " number is     = ";
		cout << number[a] << "\n";
	}

	return 0;
}

