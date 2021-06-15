// 13) Even Odd of 5 numbrs Tru Fals.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

bool even(int a) {

	if (a % 2 == 0) { return true; }
	return false;
}

int main()
{
	int n[5];

	for (int i = 0; i < 5; i++) {
		cout << "Enter the " << i + 1 << "'s number   = ";
		cin >> n[i];
	}

	cout << endl;

	for (int i = 0; i < 5; i++) {
		if (even(n[i])) { cout << "The number " << n[i] << " is EVEN."; }
		else            { cout << "The number " << n[i] << " is ODD."; }
		cout << endl;
	}

	return 0;
}

