// back slash.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{

	int length;
	cout << "Please enter the length";
	cin >> length;

	for (int a = 1; a <= length; a++)
	{

		for (int b = 1; b <= length; b++)
		if (a == b)
		{
			cout << " *";
		}
		else
		{
			cout << "  ";
		}
		cout << endl;

	}
	return 0;
}


