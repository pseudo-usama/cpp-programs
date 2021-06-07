// 4Rigth triangle find hyp and area.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "math.h"
using namespace std;

int main()
{

	int a, b;
	float area, hypotenuse;

	cout << "Enter the length of base(meters).            =   ";
	cin >> a;

	cout << "Enter the length of perpendicular(meters).   =   ";
	cin >> b;

	for (; a < 0 || b < 0;)
	{
		cout << "Length cannot be -ve." << endl;

		cout << "Enter the length of base(meters).            =   ";
		cin >> a;

		cout << "Enter the length of perpendicular(meters).   =   ";
		cin >> b;
	}

	cout << endl;

	hypotenuse = a*a + b*b;
	cout << "The hypotenuse of the triangle is             =   " << sqrt(hypotenuse) << endl << endl;                    // hypotenuse;

	cout << "The area of triangle is                       =   " << (a * b) / 2;

	return 0;
}

