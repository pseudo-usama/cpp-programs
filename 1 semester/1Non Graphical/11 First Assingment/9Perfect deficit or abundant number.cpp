// 9Perfect deficit or abundant number.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
		
	int b = 0, a = 1;
	long input;

	cout << "Enter a number.";
	cin >> input;

	for (; a <= input; a++)
	{
		if (input % a == 0)
			{
				b = a + b;
			}
	}
	if (input == b / 2)
		{
			cout << "Yes the number is PERFECT.";
		}
	else if(input < (b - a))
	{
		cout << "The number is ABUNDANT.";
	}
	else if (input > (b - a))
	{
		cout << "The number is DEFICIENT.";
	}

	return 0;
}

