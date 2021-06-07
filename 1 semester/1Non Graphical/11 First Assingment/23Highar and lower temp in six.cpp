// 23Highar and lower temp in six.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{

	int first, second, third, forth, fifth, sixth, x, y;

	cout << "Please the first tempature     =   ";
	cin >> first;

	cout << "Please the second tempature    =   ";
	cin >> second;

	cout << "Please the third tempature     =   ";
	cin >> third;

	cout << "Please the forth tempature     =   ";
	cin >> forth;

	cout << "Please the fifth tempature     =   ";
	cin >> fifth;

	cout << "Please the sixth tempature     =   ";
	cin >> sixth;

	cout << endl;

	if (first > second)
	{
		if (second > third)
		{
			x = third;
		}
		else if (third > second)
		{
			x = second;
		}
	}
	else if (second > first)
	{
		if (first > third)
		{
			x = third;
		}
		else if (third > first)
		{
			x = first;
		}
	}

	if (forth > fifth)
	{
		if (fifth > sixth)
		{
			y = sixth;
		}
		else
		{
			y = fifth;
		}
	}
	else if (fifth > forth)
	{
		if (forth > sixth)
		{
			y = sixth;
		}
		else if (sixth > forth)
		{
			y = forth;
		}
	}


	if (x > y)
	{
		cout << "The lower tempature is         =   " << y;
	}
	else
	{
		cout << "The lower tempature is         =   " << x;
	}


	cout << endl << endl;


	if (first < second)
	{
		if (second < third)
		{
			x = third;
		}
		else if (third < second)
		{
			x = second;
		}
	}
	else if (second < first)
	{
		if (first < third)
		{
			x = third;
		}
		else if (third < first)
		{
			x = first;
		}
	}

	if (forth < fifth)
	{
		if (fifth > sixth)
		{
			y = sixth;
		}
		else
		{
			y = fifth;
		}
	}
	else if (fifth < forth)
	{
		if (forth < sixth)
		{
			y = sixth;
		}
		else if (sixth < forth)
		{
			y = forth;
		}
	}


	if (x < y)
	{
		cout << "The higher tempature is        =   " << y;
	}
	else
	{
		cout << "The higher tempature is        =   " << x;
	}

	cout << endl << endl;

	return 0;
}