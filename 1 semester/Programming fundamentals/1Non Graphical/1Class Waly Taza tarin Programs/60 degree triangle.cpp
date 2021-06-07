// 60 degree triangle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int i, j, k;

	for (i = 1; i <= 4; i++)
	{
		for (j = 1; j <= i - 1; j++)
		{
			cout << "  ";
		}
		for (k = 1; k <= (2*i) - 1; k++)
		{
			cout << "* ";
		}
		cout << endl;
	}

	return 0;
}

