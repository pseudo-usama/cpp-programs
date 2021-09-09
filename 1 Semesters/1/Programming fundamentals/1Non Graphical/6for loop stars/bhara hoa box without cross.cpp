// bhara hoa box without cross.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{

	int length;

	cout << "Enter the number of rows.          =     ";
	cin >> length;

	for (int a = 1; a <= length; a++)
	{
		for (int b = 1; b <= length; b++)
		if (a == b || a + b == length + 1)
		{
			cout << "  ";
		}
		else
		{
			cout << " *";
		}

		cout << endl;

	}

	cout << endl << endl;

	return 0;
}