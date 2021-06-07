// Salary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std ;

int main()
{
	int a, b ;

	cout << "please enter the salery                     =   " ;
	cin >> a ;

	cout << "According to 15% bounas. Your salary is     =   " ;
	cout << a + 15 * a / 100 << endl <<endl <<endl ;

	getchar();
	return 0;
}