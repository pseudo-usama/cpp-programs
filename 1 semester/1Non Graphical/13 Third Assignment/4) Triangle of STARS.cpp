// 4) Triangle of STARS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

void star(int length) {

	int liner;

	liner = length + 1;

	for (int a = 1; a <= length; a++) {

		for (int b = 1; b <= length; b++) {

			if (a + b >= liner) { cout << " *"; }
			else { cout << "  "; }
		}
		cout << endl;
	}
}

int main()
{
	int length;

	cout << "Please enter the length.   = ";
	cin >> length;

	star(length);

	return 0;
}

