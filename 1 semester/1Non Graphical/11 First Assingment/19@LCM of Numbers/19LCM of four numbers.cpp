// 19LCM of four numbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int a, b, c, d, minimum, minimum1, LCM = 1;

	cout << "Enter the first number.           =     ";
	cin >> a;
	if (a < 0)
	{
		a = a * -1;
	}

	cout << "Enter the second number.          =     ";
	cin >> b;
	if (b < 0)
	{
		b = b * -1;
	}

	cout << "Enter the third number.           =     ";
	cin >> c;
	if (c < 0)
	{
		c = c * -1;
	}

	cout << "Enter the fourth number.          =     ";
	cin >> d;
	if (d < 0)
	{
		d = d * -1;
	}

	if (a < b)
	{
		minimum = a;
	}
	else
	{
		minimum = b;
	}

	if (c < d)
	{
		minimum1 = c;
	}
	else
	{
		minimum1 = d;
	}

	if (minimum < minimum1)
	{
		minimum = minimum;
	}
	else
	{
		minimum = minimum1;
	}

	cout << minimum;

	for (int divider = 1; divider < minimum; divider++)
	{
		if (a % divider == 0 && b % divider == 0 && c % divider == 0 && d % divider == 0)
		{
			if (a % divider == 0)
			{
				a = a / divider;
			}
			if (b % divider == 0)
			{
				b = b / divider;
			}		
			if (c % divider == 0)
			{
				c = c / divider;
			}			
			if (d % divider == 0)
			{
				d = d / divider;
			}
			LCM = LCM * divider;
			divider--;
		}
	}

	return '0';
}