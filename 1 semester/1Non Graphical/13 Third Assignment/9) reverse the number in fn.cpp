// 9) reverse the number in fn.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int reverse(int a) {

	int z = 0;

	for (; a != 0;) {
		z = z * 10 + a % 10;
		a = a / 10;
	}
	return z;
}

int main()
{
	int number, ans;

	cout << "Enter a number to reverse it   = ";
	cin >> number;

	ans = reverse(number);

	cout << endl << "The reverse of this number is   = " << ans;

	return 0;
}

