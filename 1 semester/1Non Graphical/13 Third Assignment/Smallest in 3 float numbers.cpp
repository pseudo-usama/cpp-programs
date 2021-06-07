// Smallest in 3 float numbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

float smallest(float a, float b, float c) {

	float smalest;

	if (a < b) { smalest = a; }
	else       { smalest = b; }

	if (c < smalest) { smalest = c; }
	return smalest;
}

int main()
{
	float a, b, c, ans;

	cout << "Enter First FLOAT number   = ";
	cin >> a;

	cout << "Enter Second FLOAT number  = ";
	cin >> b;

	cout << "Enter Third FLOAT number   = ";
	cin >> c;

	ans = smallest(a, b, c);

	cout << endl << "The smallest number is   = " << ans;
	return 0;
}

