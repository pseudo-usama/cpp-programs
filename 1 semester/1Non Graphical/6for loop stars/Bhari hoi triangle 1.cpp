// Bhari hoi triangle 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "windows.h"
using namespace std;

int main()
{
	int length = 5, decider = 0, a = 1, b, timer = 100;

	cout << "Please enter the length.   = ";
	cin >> length;
	for (;a <= length;)
	{
		if (decider) { cout << "Please enter the length.   = " << length << endl; }
		decider = 1;

		for (a = 1; a <= length; a++)
		{
			for (b = 1; b <= length + 1 && b == a && b <= decider || b < a && b <= length + 1; b++)
			{
				if (a + b <= length + 1)
				{
					cout << "* ";
				}
				else
				{
					cout << "  ";
				}
				decider = decider + 1;
			}
			cout << endl;
		 break; 
		}

	Sleep(timer);

	if (decider != length) { cout << system("CLS"); }

	decider = 1;
	}

	return 0;
}

