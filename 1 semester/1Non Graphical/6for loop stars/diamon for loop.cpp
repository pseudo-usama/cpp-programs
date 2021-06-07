// diamon for loop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int length;

	cout << "Enter the length";
	cin >> length;

	for (int j = 1; j <= length; j++)
	{
		for (int i = 1; i <= length; i++)
		{
			if (i + j <=  length)
			{
				cout << "* ";
			}
			else
			{
				cout << "\n";
			}
		}
		cout << endl;
	}

	return 0;
}

