// Check Alternative Bits.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

int main() {
	unsigned int n;

	cout << "Enter an number   ";
	cin >> n;

	n = n ^ (n >> 1);

	if ((n & (n + 1)) == 0)
		cout << "The number have alternative bits.\n";
	else
		cout << "The number does not have alternative bits.\n";

}
