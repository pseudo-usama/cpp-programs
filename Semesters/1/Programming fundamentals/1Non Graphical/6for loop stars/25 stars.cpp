// 25 stars.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{

	for (int a = 1; a <= 36; ++a)
	{
		cout << "*" ;

		if (a == 6 | a == 12 | a == 18 | a == 24 | a == 30 | a == 36)
		{
			cout << endl ;
		}
	}
	return 0;
}

