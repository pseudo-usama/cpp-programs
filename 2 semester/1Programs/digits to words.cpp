// digits to words.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"
using namespace std;

void Fn(string n) {
	int length;
	length = n.length();

	for (int i = 0; i <= n[i]!='\0'; i++) {
		if		(n[i] == '0') { cout << "zero "; }
		else if (n[i] == '1') { cout << "one "; }
		else if (n[i] == '2') { cout << "two "; }
		else if (n[i] == '3') { cout << "three "; }
		else if (n[i] == '4') { cout << "four "; }
		else if (n[i] == '5') { cout << "five "; }
		else if (n[i] == '6') { cout << "six "; }
		else if (n[i] == '7') { cout << "seven "; }
		else if (n[i] == '8') { cout << "eight "; }
		else if (n[i] == '9') { cout << "nine "; }


	}
}

int main()
{
	string n;

	cout << "Enter a number     = ";
	cin >> n;

	Fn(n);

	return 0;
}

