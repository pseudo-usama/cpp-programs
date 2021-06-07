// ginti checker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

int main()
{
	int a;
	for (a = 0; a>=0 ; a = a+100000)
	{
		cout << a;
		cout << endl;
	}
	cout << a;

	return 0;
}

