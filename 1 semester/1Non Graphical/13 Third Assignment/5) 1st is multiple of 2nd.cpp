// 5) 1st is multiple of 2nd.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

bool multiple(int n1, int n2) {

	if (n1 % n2 == 0) { return 1; }
	else { return 0; }
}

int main()
{
	int n1, n2;

	cout << "Enter the First number  = ";
	cin >> n1;

	cout << "Enter the Second number = ";
	cin >> n2;

	cout << endl;

	if (multiple(n1, n2)) { cout << "Yes, the First number is multiple of Second"; }
	else                  { cout << "No, the First number is multiple of Second"; }

	cout << endl;

	return 0;
}

