// x and y.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;
int main()
{
	int x, y, z ;

	cout << "Enter the value of x=" ;
	cin >> x ;

	cout << "Enter the value of y=" ;
	cin >> y ;

	z = x ;
	x = y ;
	y = z ;


	cout << endl ;

	cout << "By exchanging the values" << endl << endl ;

	cout << "The value of x is " ;
	cout << x << endl ;

	cout << "The value of y is " ;
	cout << y ;

	cout << endl << endl << endl ;
	return 0;
}

