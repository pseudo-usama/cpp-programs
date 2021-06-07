// Prime numbers from5 to user.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int n;

	cout << "Enter a number    = ";
	cin >> n;

	cout << endl << "The prime numbers less than " << n << " and greater then 5 is" << endl;

	for (int a = 6; a < n; a++)
	{
		for (int b = 2; b < a; b++)
		{
			if (a % b == 0) { break; }
			else if (b == a - 1){ cout << a << endl; }
		}
	}

    return 0;
}

