// 30) Add 2 ARRAY in Fn.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int ArrayAddition(int a[10], int b[10], int  result[10], int length) {

	int i = 0;

	while (i < length) {
		result[i] = a[i] + b[i];

		i++;
	}

	return result[10];
}

int main()
{
	int a[10], b[10], i = 0, c[10] = { 0 }, result[10];

	while (i < 10) {

		cout << "Enter the " << i << "'s value of first ARRAY         = ";
		cin >> a[i];

		i++;
	}

	i = 0;
	cout << endl;

	while (i < 10) {

		cout << "Enter the " << i << "'s value value of Second ARRAY  = ";
		cin >> b[i];

		i++;
	}

	result[10] = ArrayAddition(a, b, c, 10);

	cout << endl << "By ADDITION them the result is" << endl << endl;

	i = 0;

	while (i < 10) {

		cout << "The " << i << "'s index number is   = " << result[i] << endl;

		i++;
	}

	return 0;
}

