// Macros.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

#define pi 3.14

#ifndef NULL
#define NULL 0
#endif

#ifdef DEBUG
cerr << "Variable x = " << x << endl;
#endif

void main() {
	
	cout << pi << endl;

}

