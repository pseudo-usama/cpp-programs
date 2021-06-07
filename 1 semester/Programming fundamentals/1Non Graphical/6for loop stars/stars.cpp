// stars.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{

	int row, coloum ;

	cout << "Enter the number of rows.          =     " ;
	cin >> row ;

	cout << "Enter the number of coloums.       =     " ;
	cin >> coloum ;

	for (int a = 1; a <= row; a++)
	{
		for (int b = 1; b <= coloum; b++)
		{
			cout << " *" ;
		}

		cout << endl ;

	}

	cout << endl << endl ;

	return 0;
}

