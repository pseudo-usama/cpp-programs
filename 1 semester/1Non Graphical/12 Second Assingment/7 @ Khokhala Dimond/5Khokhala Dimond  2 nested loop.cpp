// 5Khokhala Dimond  2 nested loop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int length, j = 1, spacer1, spacer2, SpacerHelper1, SpacerHelper2;
	do{
		cout << "Enter the length.           =   ";
		cin >> length;

		if (length < 0)
		{
			cout << "Length can never be zero." << endl;
		}
	} while (length < 0); 
	if (length != 0)
	{

		do{
			spacer1 = length - j;
			spacer2 = j * 2 - 3;
			SpacerHelper1 = 1;
			SpacerHelper2 = 1;
			if (j != length)
			{
				do
				{

					cout << "  ";
					SpacerHelper1++;
				} while (SpacerHelper1 <= spacer1);
			}
			cout << "* ";

			if (j != 1)
			{

				do{

					cout << "  ";
					SpacerHelper2++;
				} while (SpacerHelper2 <= spacer2);

				cout << "* ";
			}

			cout << endl;

			j++;

		} while (j <= length);

		if (length != 1)
		{

			j = 1;
			length = length - 1;

			do{
				spacer1 = j;
				spacer2 = (length - j) * 2 - 1;
				SpacerHelper1 = 1;
				SpacerHelper2 = 1;

				do
				{

					cout << "  ";
					SpacerHelper1++;
				} while (SpacerHelper1 <= spacer1);
				cout << "* ";

				if (j != length)
				{

					do{

						cout << "  ";
						SpacerHelper2++;
					} while (SpacerHelper2 <= spacer2);

					cout << "* ";
				}

				cout << endl;

				j++;

			} while (j <= length);

		}
		cout << "Remember that the length entered is length of dimond from its center to its any corner.";

	}
	return 0;
}

