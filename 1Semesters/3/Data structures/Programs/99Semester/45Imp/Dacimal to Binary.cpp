#include "stdafx.h"
#include <iostream>
using namespace std;


int main() {
	int dec, bin = 0;

	cout << "Enter a decimal number    : ";
	cin >> dec;

	for (int i = 31; i > -1; i--)
		bin = bin * 10 + (1 & (dec >> i));

	cout << "Binary conversion is  : " << bin << endl;

	return(0);
}

