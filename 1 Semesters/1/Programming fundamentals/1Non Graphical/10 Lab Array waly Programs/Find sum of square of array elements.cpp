// Find sum of square of array elements.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int n[10], sum = 0;

	for (int a = 0; a < 10; a++)
	{
		cout << "Enter the value of " << a + 1 << " value    = ";
		cin >> n[a];
		sum = sum + n[a] * n[a];
	}

	cout << endl << "The sum of square of all array elements is  = " << sum << endl;

	return 0;
}

