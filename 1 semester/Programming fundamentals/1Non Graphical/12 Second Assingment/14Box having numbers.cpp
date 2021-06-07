// 14Box having numbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int number, length, width, a = 1, b, MidPoint;

	do{
		cout << "Enter the length(enter a odd number)         =   ";
		cin >> length;
	} while (length % 2 == 0);

	cout << "Enter the width                              =   ";
	cin >> width;

	MidPoint = length / 2 + 1;

	while (a <= width)
	{
		b = 1;
		number = a * 10 - 10;
		while (b <= length)
		{
			if (b / MidPoint != 0 && b % MidPoint != 0)
			{
				number = number - 10;
			}
			else
			{
				number = number + 10;
			}
			cout << number << " ";
			b++;
		}
		cout << endl;
		a++;
	}
	return 0;
}

