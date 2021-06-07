// a b c greater4545.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{

	int first, second, third, max = 0;

	cout << "Enter he first number        =   ";
	cin >> first;

	cout << "Enter the second number      =   ";
	cin >> second;

	cout << "Enter the third number       =   ";
	cin >> third;

	cout << endl;

	if (first > second)
	{
		max = first;
	}

	else
	{
		max = second;
	}

	if (max > third)
	{
		cout << "The greater number is " << max;
	}
	else
	{
		cout << "The greater number is " << third;
	}

	cout << endl << endl;

	return 0;
}