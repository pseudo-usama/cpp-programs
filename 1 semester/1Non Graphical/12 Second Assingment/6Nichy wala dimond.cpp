// 6Nichy wala dimond.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int input, spacer, j = 0, stars, SpacerHelper, StarsHelper;

	do{
		cout << "Enter the length       =   ";
		cin >> input;

		if (input < 0)
		{
			cout << "Length can never be zero." << endl;
		}
	} while (input < 0);

	input = input - 1;

	do{
		spacer = j - 1;
		stars = (input - j) * 2;
		StarsHelper = 0;
		SpacerHelper = 0;
		while (SpacerHelper <= spacer)
		{
			cout << "  ";
			SpacerHelper++;
		}
		while (StarsHelper <= stars)
		{
			cout << "* ";
			StarsHelper++;
		}
		cout << endl;
		j++;
	} while (j <= input);

	cout << endl;
	cout << "Note that the entered length is the height of the triangle.";

	return 0;
}

