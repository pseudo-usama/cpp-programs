// Give value and see Location in ARAY.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int n[10], a = 0, selector, decider = 1;

	while (a < 10)
	{
		cout << "Enter the " << a + 1 << " value.   = ";
		cin >> n[a];
		a++;
	}

	cout << "Enter any value you entered to see its location.   = ";
	cin >> selector;

	a = 0;

	while (a < 10)
	{
		if (selector == a[n - 1])
		{
			if (decider){ cout << "The location/s are" << endl; }
			cout << "You enter this value " << n + 1 << "]";
			decider = 0;
		}
	}

	if (!decider)
	{
		cout << "You cannot enter this value.";
	}

	return 0;
}

