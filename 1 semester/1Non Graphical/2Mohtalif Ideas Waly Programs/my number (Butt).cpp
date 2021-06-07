// my number (Butt).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

struct NUMBER { int a, b, c; };

NUMBER number;

int fn(int &d, int e) {

	if (e == 0) { return 0; }
	else { --e; fn(d, e); d++; }
}

int main()
{
	number.a = 10;
	number.b = 20;
	number.c = 5;

	number.a = --number.a + ++number.b - --number.c/number.c++;

	number.b = fn(number.c, number.a);

	number.a = number.a + number.b + number.c;

	number.a = ++number.a / --number.a;

	cout << "My number is  = " << number.a++;

    return 0;
}

