// char.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	char a, c = 'a';

	cin >> a;

	for (int d = 1; d < 3 && a == 'i'; d++, c++)
	{
		cout << c;
	}

	return 0;
}

