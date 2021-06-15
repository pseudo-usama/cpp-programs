// 3 N1 N2 which greter and greter then 0.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{

	int n1, n2, modulas, greater, smaller;

	cout << "Enter the first number.           =   ";
	cin >> n1;

	cout << "Enter the second number.          =   ";
	cin >> n2;

	if (n1 > n2)
	{
		smaller = n2;
		greater = n1;
	}
	else if (n1 < n2)
	{
		smaller = n1;
		greater = n2;
	}

	cout << endl << endl;
	if (n1 == n2)
	{
		cout << "Both the numbers are equal. So both can divide each other.";
	}
	else if (smaller == 0)
	{
		cout << "Cannot be duivide by zero.";
		cout << "The greater number is " << greater << "." << endl;
	}
	else
	{
		modulas = greater % smaller;

		cout << "The greater number is " << greater << "." << endl;

		cout << endl;

		if (modulas == 0)
		{
			cout << "Yes the greater number " << greater << " is multiple of" << endl;
			cout << "(or can be full divided) on smaller number." << smaller;
		}
		else if (modulas != 0)
		{
			cout << "No the greater number " << greater << " is not multiple of" << endl;
			cout << "(or cannot be full divide) on smaller number." << smaller;
		}
	}

	cout << endl;

	if (n1 > 0)
	{
		cout << "First number is greater than zero." << endl;
	}
	else
	{
		cout << "First number is not greater than zero." << endl;
	}

	if(n2 > 0)
	{
		cout << "Second number is greater than zero." << endl;
	}
	else
	{
		cout << "Second number is not greater than zero." << endl;
	}
	return 0;
}

