// ak number ki tajzii.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int input, divider = 2, NextNumber;

	cin >> input;

	NextNumber = input;

	for (; divider <= input; divider++)
	{
		if (NextNumber % divider == 0)
		{
			cout << divider << ", ";
			NextNumber = NextNumber / divider;
		}
	}
	cout << NextNumber;
	return 0;
}

