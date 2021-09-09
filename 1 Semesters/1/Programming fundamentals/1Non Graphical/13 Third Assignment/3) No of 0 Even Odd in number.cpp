// 3) No of 0 Even Odd in number.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int zero = 0, even = 0, odd = 0;
	long n;

	cout << "Enter a number    =  ";
	cin >> n;

	while (n > 0) {
		if (n % 10 == 0) { zero++; }
		else if ((n % 10) % 2 == 0) { even++; }
		else { odd++; }

		n = n / 10;
	}

	cout << "Number of ZEROS          = " << zero << endl;
	cout << "Number of EVEN numbers   = " << even << endl;
	cout << "Number of ODD numbers    = " << odd;

	return 0;
}

