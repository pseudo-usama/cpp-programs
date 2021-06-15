// 4Khokhli right triangle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int length, i, j = 1;

	cout << "Enter the length" << endl;
	cout << "(Note that base and perpendicular have same length).       =  ";
	cin >> length;

	for (; length < 0;)
	{
		cout << "Enter the length. Enter a positive number.  = " << endl;
		cin >> length;
	}

	for (; j <= length;)
	{
		i = 1;
		for (; i <= length;)
		{
			if (j == length || i == 1 || i == j)
			{
				cout << "* ";
			}
			else
			{
				cout << "  ";
			}
			i++;
		}
		cout << endl;
		j++;
	}

	return 0;
}

