// 1 to 10 using aray desnding asending.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int n[10], primer = 0, sum = 0;

	for (int a = 0; a < 10; a++)
	{
		cout << "Enter the " << a + 1 << " value       =   ";
		cin >> n[a];
	}

	for (int a = 0; a < 10; a++)
	{
		cout << "The " << a + 1 << " number is " << n[a] << endl;
	}
	for (int a = 1; a > -1 && a < 11;)
	{
		cout << "Enter the index where you store the number." << endl;
		cout << "Or enter any number excipt 1 to 10 to exit." << endl;
		cout << "           Enter here      =  ";
		cin >> a;
		a = a - 1;
		if (a > -1 && a < 11)
		{
			cout << endl;
			cout << "Enter an value to store in " << a + 1 << "'s value.       =   ";
			cin >> n[a];
		}
	}

	for (int a = 0; a < 10; a++)
	{
		if (n[a] % 2 == 0)
		{
			cout << "The number " << n[a] << " is EVEN.";
		}
		else
		{
			cout << "The number " << n[a] << " is ODD.";
			for (int b = 2; b <= n[a]; b++)
			{
				if (n[a] % b == 0)
				{
					sum = sum + 1;
				}
			}
			if (sum == 1)
			{
				cout << "And also an prime number.";
			}
		}
		sum = 0;
		cout << endl;
	}

	for (int a = 0; a < 10; a++)
	{
		sum = sum + n[a];
	}
	cout << "The average of the inputs are      =  " << sum / 10;

	return 0;
}

