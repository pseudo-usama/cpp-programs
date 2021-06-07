// 21) Largest in 5 in ARREY.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int largest(int n[5]) {

	int i = 0, smallest;

	while (i < 5) {
		if (!i)                   { smallest = n[i]; }
		else if (n[i] < smallest) { smallest = n[i]; }

		i++;
	}
	return smallest;
}

int main()
{
	int n[5], i = 0, answer;

	while (i < 5){
		cout << "Enter the " << i + 1 << "'s number   = ";
		cin >> n[i];

		i++;
	}

	answer = largest(n);

	cout << endl << "The Largest number is  = " << answer;

	return 0;
}

