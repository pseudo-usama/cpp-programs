// 3Even Odd Triangle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int length, i, j = 1;

	do{
		cout << "Enter the length.       =   ";
		cin >> length;
	} while (length % 2 == 0);

	while (j <= length)
	{
		i = 1;
		while (i <= 2 * length - 1)
		{
			if (j == length || (i % 2 != 0 && j % 2 != 0) && (i + j == length + 1))
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

