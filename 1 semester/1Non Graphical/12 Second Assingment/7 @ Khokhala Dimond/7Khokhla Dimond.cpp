// 7Khokhla Dimond.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int length, j = 1, i, stoper = 0;

	cout << "Enter the length        =   ";
	cin >> length;

	if (length % 2 != 0)
	{
		stoper = 1;
	}

	do{
		i = 1;
		do{
			if ((i + j == length + 1) || i + j == length * 3 - 1 || (stoper == 0 && i < j && (i + j) % 2 == 0 ))
			{
				cout << "* ";
			}
			else
			{
				cout << "  ";
			}
			i++;
		} while (i <= length * 2 - 1);
		cout << endl;
		j++;
	} while (j <= length * 2 - 1);

	return 0;
}

