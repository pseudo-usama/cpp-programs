// 15) Greatest common Diviser.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int GreatestCommonDivisor(int a, int b) {

	int i = 1;

	if (a < b) { i = a; }
	else       { i = b; }

	while (i > 0) { if (a % i == 0 && b % i == 0) { break; } i--; }

	return i;
}

int main()
{
	int a, b, answer;

	cout << "Enter the First number  = ";
	cin >> a;

	cout << "Enter the Second number = ";
	cin >> b;

	answer = GreatestCommonDivisor(a, b);

	cout << endl << "The greatest common diviser is of " << a << " and " << b << " is  = " << answer;

	return 0;
}

