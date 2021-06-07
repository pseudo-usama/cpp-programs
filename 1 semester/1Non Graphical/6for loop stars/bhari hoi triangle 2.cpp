// bhari hoi triangle 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "windows.h"
using namespace std;

int main()
{
	int length, timer = 1000;

	cout << "Please enter the length.";
	cin >> length;

	for (int a = 1; a <= length; a++)
	{
		for (int b = 1; b <= length + 1; b++)
		{
			if (a < b)
			{
				cout << "* ";
			}
			else
			{
				cout << "  ";
			}
			Sleep(timer);
		}
		cout << endl;
	}

	return 0;
}

