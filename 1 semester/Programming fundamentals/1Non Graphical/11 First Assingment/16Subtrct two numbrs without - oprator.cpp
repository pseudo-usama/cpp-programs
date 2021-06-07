// 16Subtrct two numbrs without - oprator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{

	int a, b, less, greater, difference = 0;

	cout << "Enter the first number.         =    ";
	cin >> a;

	cout << "Enter the second number.        =    ";
	cin >> b;

	if (a > b)
	{
		less = b;
		greater = a;
	}
	else
	{
		less = a;
		greater = b;
	}

	cout << endl << endl;

	for (; less < greater; less++)
	{
		difference = difference + 1;
	}

	cout << "According to this proceder."		 << endl;
	cout << endl;
	cout << "	if (a > b)  where a = First Number"		  << endl;
	cout << "	{                 b = Second Number"	  << endl;
	cout << "	less = b"								  << endl;
	cout << "	greater = a"							  << endl;
	cout << "	}"	 									  << endl;
	cout << "	else"									  << endl;
	cout << "	{"									 	  << endl;
	cout << "	less = a"								  << endl;
	cout << "	greater = b"							  << endl;
	cout << "	}"										  << endl;
	cout << endl;
	cout << "	for (; less < greater; less++)"			  << endl;
	cout << "	{" << endl;
	cout << "	difference = difference + 1;"			  << endl;
	cout << "	}" << endl << endl;

	cout << "The difference of " << a << " and " << b << " is " << difference << ".";

	return 0;
}

