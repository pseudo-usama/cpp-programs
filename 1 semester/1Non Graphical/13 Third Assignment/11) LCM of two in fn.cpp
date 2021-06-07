// 11) LCM of two in fn.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int LCM(int a, int b) {

	int greater, n = 2, ans = 1, decider;

	if (a > b) { greater = a; }
	else       { greater = b; }

	while (n <= a || n <= b) {
		decider = 1;
		if (a % n == 0 || b % n == 0) {
			if (a % n == 0) { a = a / n; }
			if (b % n == 0) { b = b / n; }
			ans = ans * n;
			decider = 0;
		}
		if (decider) { n++; }
	}
	return ans;
}

int main()
{
	int n1, n2, ans;

	cout << "Enter the first number  = ";
	cin >> n1;

	while (n1 < 0) {
		cout << "Enter a +ve number  = ";
		cin >> n1;
	}

	cout << "Enter the second number = ";
	cin >> n2;

	while (n2 < 0) {
		cout << "Enter a +ve number  = ";
		cin >> n2;
	}

	ans = LCM(n1, n2);

	cout << endl << "The LCM of " << n1 << " and " << n2 << " is  = " << ans;

	return 0;
}

