// 5) Fibonaci Series from1 to n.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

void fibonnaci(int n) {

	int a = 0, b = 1, holder;

	cout << endl << "          "  << a;

	while (b <= n) {
		cout << ", " << b;
		holder = a;
		a = b;
		b = holder + b;
	}
}

int main()
{
	int n;

	cout << "Enter the maximum range of FIBONACCI series   = ";
	cin >> n;

	while (n < 0) {
		cout << "Enter a +ve number   = ";
		cin >> n;
	}

	cout << "The required series is";

	fibonnaci(n);

	return 0;
}

