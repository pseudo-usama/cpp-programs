// 1 2 3 4 5 Tarteeb waar ulta Dimond.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	for (int j = 1; j <= 9; j++)
	{
		for (int spacer = 1; spacer <= j - 1; spacer++)
		{
			cout << " ";
		}
		for (int star = 1; star <= 9 - j; star++)
		{
			cout << "* ";
		}
		cout << endl;
	}

	return 0;
}

