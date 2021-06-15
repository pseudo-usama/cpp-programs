// box.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int length, width;

	cout << "Please enter the leght.";
	cin >> length;

	cout << "Please enter the width.";
	cin >> width;

	for (int a = 1; a <= width; a++)
	{
		for (int b = 1; b <= length; b++)
		{
			if (a == 1 || a == width || b == 1 || b == length)
			{
				cout << " *";
			}
			else
			{
				cout << "  ";
			}
		}
		cout << endl;
	}

	return 0;
}

