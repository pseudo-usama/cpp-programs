// 3Even Odd Triangle 2 Nestd Lop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int length, j = 1, spacer1, spacer2, SpacerHelper1, SpacerHelper2;
	do{
		cout << "Enter the length of the the triangle                  =   ";
		cin >> length;

		if (length % 2 == 0)
		{
			cout << "Enter an odd number." << endl;
		}
		if (length < 0)
		{
			cout << "Length can never -ve.Enter an +ve number." << endl;
		}

	} while (!(length % 2 == 1)  || length < 0);

	while (j <= length - 1)
	{
		spacer1 = length - j;
		spacer2 = j * 2 - 3;
		SpacerHelper1 = 1;
		SpacerHelper2 = 1;
		if (j % 2 != 0)
		{

			while (SpacerHelper1 <= spacer1)
			{
				cout << "  ";
				SpacerHelper1++;
			}

			if (j != 1)
			{
				cout << "* ";
			}

			while (SpacerHelper2 <= spacer2)
			{
				cout << "  ";
				SpacerHelper2++;
			}

			cout << "* ";

		}
		cout << endl;
		j++;
	}

	length = length + length - 1;
	j = 1;
	while (j <= length)
	{
		cout << "* ";
		j++;
	}

	cout << endl << "Remember that the length entered is the height of that triangle.";

	return 0;
}

