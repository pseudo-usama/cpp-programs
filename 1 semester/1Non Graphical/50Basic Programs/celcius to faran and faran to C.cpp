// celcius to faran and faran to C.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std ;
;
int main()
{
	float a, b ;

	cout << "Please enter the temprature(In CELCIUS)   =           " ;
	cin >> a ;

	cout << "The temp in fahrenheit is                 =           " ;
	cout << a * (9.0 / 5.0) + 32.0 << endl << endl ;

	cout << "Enter temp in celcius                     =           " ;
	cin >> b ;

	cout << "The temp in calcius is                    =           " << (b - 32) * 5 / 9 << endl ;

	cout << endl << endl ;

	getchar();
	return 0;
}

