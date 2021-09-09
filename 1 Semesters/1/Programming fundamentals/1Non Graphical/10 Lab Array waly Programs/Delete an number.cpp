// Delete an number.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;
int main()
{
	int n[10], selector;

	for (int a = 0; a < 10; a++)
	{
		cout << "Enter the " << a + 1 << " value   = ";
		cin >> n[a];
	}

	cout << "Enter the number of variable to delete its value.";
	cin >> selector;

	selector = selector - 1;

	for (; selector < 10; selector++)
	{
		n[selector] = n[selector + 1];
	}

	for (int a = 0; a < 10; a++)
	{
		cout << n[a] << ",";
	}

	return 0;
}

