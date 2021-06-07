// 11)1 over 11 and 31 and 41 series sum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int range;
	float sum = 0.0, a = 1.0;
	do{
		cout << "Enter the range(enter number of 1, 11, 21, 31 type).       =   ";
		cin >> range;
	} while ((range - 1) % 10 != 0 && range != 0);

	cout << endl << "      The sum of the following series" << endl << "          ";

	if (range > 0)
	{

		while (a < range)
		{
			cout << "1/" << a << "+";
			sum = sum + 1 / a;
			a = a + 10.0;
		}
		cout << "1/" << a;
		sum = sum + 1 / a;
	}

		cout << endl << "                        is    =  " << sum;
	
	return 0;
}

