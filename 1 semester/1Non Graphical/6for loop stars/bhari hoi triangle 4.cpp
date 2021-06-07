// bhari hoi triangle 4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int length;

//	cout << "Please enter the length.";
//	cin >> length;

	for (int a = 1; a <= 5; a++)
	{
		for (int b = 1; b <= 5; b++)
		{
			if (a == b || b < a)
			{
				cout << a << "*";
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

