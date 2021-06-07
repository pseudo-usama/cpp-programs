// Pointer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int a = 1;
	int *b;

	b = &a;
	

	cout << a << endl;

	cout << &b << endl;

	cout << &a << endl;
	cout << b << endl;

	cout << &b << endl;



    return 0;
}

