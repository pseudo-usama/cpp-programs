// Even and Odd in 2 Array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int n1[10] = { 0 }, n2[10] = { 0 }, input, e= 0, o = 0;

	for (int a = 0; a < 10; a++)
	{
		cout << "Enter the value of " << a + 1 << " number   = ";
		cin >> input;
		if (input % 2 != 0)
		{
			n1[e] = input;
			e++;
		}
		else
		{
			n2[o] = input;
			o++;
		}
	}

	cout << endl << "The even numbers are" << endl;

	for (int a = 0; a < 10; a++)
	{
		cout << n2[a] << ",";
	}

	cout << endl << endl << "The odd numbers are" << endl;

	for (int a = 0; a < 10; a++)
	{
		cout << n1[a] << ",";
	}
	return 0;
}

