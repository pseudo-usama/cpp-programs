// 7) Power in fn.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int powar(int a, int b) {
	return pow(b, a);
}

int main()
{
	int a, b, answer;

	cout << "Enter the First number   = ";
	cin >> a;

	cout << "Enter the Second number  = ";
	cin >> b;

	answer = powar(a, b);

	cout << endl << "The POWER is  = " << answer;

	return 0;
}

