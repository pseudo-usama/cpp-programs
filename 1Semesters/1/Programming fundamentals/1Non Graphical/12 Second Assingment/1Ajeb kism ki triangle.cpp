// 1Ajeb kism ki triangle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int length, i = 0, j = 0, spacer, SpacerHelper, stars, StarsHelper;

	cout << "Enter the length        =   ";
	cin >> length;

	for (; length < 0;)
	{
		cout << "Length never be -ve. Enter a Positive number." << endl;
		cout << "Enter the length        =   ";
		cin >> length;
	}

	while (j <= length)
	{
		SpacerHelper = 0;
		StarsHelper = 0;
		spacer =(length - j) * 2;
		stars = 2 * (j - 1) + j;
		
		while (SpacerHelper < spacer)
		{
			cout << "  ";
			SpacerHelper++;
		}
		while (StarsHelper < stars)
		{
			cout << "* ";
			StarsHelper++;
		}
		cout << endl;
		j++;
	}

	cout << endl;
	cout << "Remember that the entered length is the height of the triangle.";

	return 0;
}

