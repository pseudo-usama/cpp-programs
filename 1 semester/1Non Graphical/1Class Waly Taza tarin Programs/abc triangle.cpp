// abc triangle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	char c =  'a';

	for (int a = 0; a < 4; a++)
	{
		for (int b = 0; b < a; c++, b++)
		{
			cout << c;
		}
		cout << endl;
	}
	
	return 0;
}

