// 5Dimond.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int length, spacer, stars;

	do{
		cout << "Enter the length of the dimond.             =    ";
		cin >> length;

		if (length < 0)
		{
			cout << "Length can never be zero." << endl;
		}
	} while (length < 0);

	for (int j = 1;j <= length; j++)
	{
		spacer = length - j;
		stars = 2 * j - 1;

		for (int a = 1; a <= spacer; a++)
		{
			cout << "  ";
		}
		for (int a = 1; a <= stars; a++)
		{
			cout << "* ";
		}
		cout << endl;
	}

	length = length - 1;
	 
	for (int j = 1; j <= length;j++)
	{
		spacer = j;
		stars = (length - j) * 2 + 1;

		for (int a = 1; a <= spacer; a++)
		{
			cout << "  ";
		}
		for (int a = 1; a <= stars; a++)
		{
			cout << "* ";
		}
		cout << endl;
	}

	cout << endl << "Remember that the length entered is the length of dimond  from its center to its any corner.";
	
	return 0;
}

