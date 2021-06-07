// -ve numbers in an array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int n[10], decider = 1;

	for (int a = 0; a < 10; a++)
	{
		cout << "Enter the " << a + 1 << " value    = ";
		cin >> n[a];
	}

	for (int a = 0; a < 10; a++)
	{
		if (n[a] < 0)
		{
			cout << "The  " << a + 1 << " value is -ve   = " << n[a];
			decider = 0;
		}
	}

	if (decider)
	{
		cout << endl << "There is no -ve number.";
	}

	cout << endl << endl;

	return 0;
}

