// 10) Prime or not in fn.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

bool prime(int n) {

	int a = 2;

	while (a < n / 2 + 1) {
		if (n % a == 0) { return 1; }
	}
	return 0;
}

int main()
{
	int number;

	cout << "Enter a number to check weather it is prime or not   = ";
	cin >> number;

	while (number < 0) {
		cout << "Enter number greater then zero.   = ";
		cin >> number;
	}

	cout << endl;

	if (prime(number)) { cout << "No, the number is not prime."; }
	else                { cout << "Yes, the number is prime."; }

	return 0;
}

