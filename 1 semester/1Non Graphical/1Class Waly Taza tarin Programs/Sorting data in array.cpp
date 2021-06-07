// Sorting data in array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{

	int n[10], holder, decider = 1;

	for (int a = 0; a < 10; a++)
	{
		cout << "Enter value  = ";
		cin >> n[a];
	}

	for (int a = 0; a < 10; a++)
	{
		for (int b = 0; b < 9 - a; b++)
		{
			if (n[b] > n[b + 1])
			{
				holder = n[b];
				n[b] = n[b + 1];
				n[b + 1] = holder;
				decider = 0;
			}
		}
		if (decider) { break; }
		decider = 0;
	}

	for (int a = 0; a < 10; a++)
	{
		cout << " Value  = " << n[a] << endl;
	}

	return 0;
}

