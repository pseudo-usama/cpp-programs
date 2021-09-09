// 12Teen series in one series.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int range, a = 1, n1 = 8, n2 = 9, n3 = 10;

	do{
		cout << "Enter the range of the series.          =  ";
		cin >> range;
		if (range < 0)
		{
			cout << "Enter a positive number" << endl;
		}
	} while (range < 0);

	cout << endl << "      The series is" << endl << "          ";

	while (a < range)
	{
		if (n1 <= range)
		{
			cout << n1 << " ";
		}
		if (n2 <= range)
		{
			cout << n2 << " ";
		}
		if (n3 <= range)
		{
			cout << n3 << " ";
		}
		n1 = n1 + 8;
		n2 = n2 + 9;
		n3 = n3 + 10;
		a =  a + 11;
	}

	return 0;
}

