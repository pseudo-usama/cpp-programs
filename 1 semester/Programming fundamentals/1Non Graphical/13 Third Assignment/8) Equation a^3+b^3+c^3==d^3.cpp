// 8) Equation a^3+b^3+c^3==d^3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int Equation(int a, int b, int c, int d) {
	if (a*a*a + b*b*b + c*c*c == d*d*d) { return 0; }
	else { return -1; }
}

int main()
{
	int a, b, c, d;
	 
	cout << "Enter four numbers to check weather the" << endl << endl;
	cout << "              a*a*a + b*b*b + c*c*c = d*d*d" << endl;
	cout << "                          is satisfied or not" << endl << endl;

	cout << "Enter First number       = ";
	cin >> a;

	cout << "Enter the Second number  = ";
	cin >> b;

	cout << "Enter the Third number   = ";
	cin >> c;

	cout << "Enter the Forth number   = ";
	cin >> d;

	if (!Equation(a, b, c, d)) { cout << "Yes, the equation is satisfied."; }
	else                       { cout << "No, the equation is not satisfied."; }

	return 0;
}

