// 15) Tax on salary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int tex(int a) {

	int tax = 0;

	if (a > 3000) { tax = (3 * (a - 3000)) / 100; }
	if (a > 2000) { tax = tax + (4 * 1000) / 100; }
	if (a > 1000) { tax = tax + (5 * 1000) / 100; }

	return tax;
}

int main()
{
	int salary, tax;

	cout << "Enter your salary  = ";
	cin >> salary;

	tax = tex(salary);

	cout << "The tax is  = " << tax;

	return 0;
}

