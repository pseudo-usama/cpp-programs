// Giv No in ary and  revrs it in another.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int a[10], b[10], a1 = 0, b1 = 9;

	while (a1 < 10)
	{
		cout << "Enter the " << a1 + 1 << " value       =  ";
		cin >> a[a1];
		a1++;
	}

	a1 = 0;
	while (b1 >= 0)
	{
		b[b1] = a[a1];
		b1--;
		a1++;
	}

	b1 = 0;
	while (b1 < 10)
	{
		cout << b[b1] << endl;
		b1++;
	}

	return 0;
}

