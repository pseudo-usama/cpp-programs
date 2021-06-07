// Even or Odd.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int a, b;
	cin >> a;
	b = a % 2;
	if ( b == 1 )
	{
		cout << "your digit is ODD";
	}
	else
	{
		cout << "your digit is EVEN";
	}
	cout << endl;
	return 0;
}

