// sum of serios in devesion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int input;
	float sum = 1;

	cout << "Enter the range         =   ";
	cin >> input;

	cout << "The sum of series is" << endl;

	for (float a = 1; a <= input; a++)
	{
		cout << "1/" << a << "+";
		sum = 1 / a + sum;
	}

	cout << " = " << sum;

	return 0;
}

