// bhari hoi triangle 3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int length, liner;

	cout << "Please enter the length.   = ";
	cin >> length;

	cout << endl << endl;

	liner = length + 1;

	for (int a = 1; a <= length; a++)
	{
		for (int b = 1; b <= length; b++)
		{
			if (a + b >= liner)
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

