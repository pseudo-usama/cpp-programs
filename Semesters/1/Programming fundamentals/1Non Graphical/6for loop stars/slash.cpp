// slash.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int length, liner;

	cout << "Enter the length.";
	cin >> length;

	liner = length + 1;

	for (int a = 1; a <= length; a++)
	{
		for (int b = 1; b <= length; b++)
		{
			if (liner == a + b)
			{
				cout << " *";
			}
			else
			{
				cout << "  ";
			}
		}

		cout << endl;

	}

	return 0;
}

