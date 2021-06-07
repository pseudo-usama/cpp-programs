// 28) Float ARRAY Reverse it.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

float ArrayReverse(float n[10]) {

	int i = 0, j = 9;
	float a[10];

	while (i < 10) {
		a[j] = n[i];

		i++;
		j--;
	}
	return a[10];
}

int main()
{
	float n[10];
	int i = 0;

	while (i < 10) {

		cout << "Enter the " << i + 1 << " number  = ";
		cin >> n[i];

		i++;
	}

	cout << endl << "Bofore reversing the array." << endl;

	i = 0;

	while (i < 10) {
		
		cout << endl << "The " << i + 1 << "'s number is  = " << n[i];
		i++;
	}

	n[10] = ArrayReverse(n);


	cout << endl << endl << "After reversing the Array the result is." << endl;

	i = 0;

	while (i < 10) {
		cout << endl << "The " << i + 1 << "'s number is  = " << n[i];
		i++;
	}

	return 0;
}

