// 3 dimention.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{

	for (int a = 1; a <= 2; a++)
	{
		for (int b = 1; b <= 2; b++)
		{
			for (int c = 1; c <= 2; c++)
			{
				cout << "* ";
			}
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}