// factorial with loop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int _tmain()
{
	int a, b = 1;

	cout << "Please enter the number.";
	cin >> a;
	
	for (; a > 0; a--)

	{
		b = b * a;
	}

	cout << b;

	return 0;
}

