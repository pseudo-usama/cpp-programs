// 33) Inline fn to find circle area.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

inline float Area(int radius) {

	return 3.14 * radius * radius;
}

int main()
{
	int radius;
	float area;

	cout << "Enter the radius of circle  = ";
	cin >> radius;

	area = Area(radius);

	cout << endl << "The Area of circle is  = " << area;

	return 0;
}

