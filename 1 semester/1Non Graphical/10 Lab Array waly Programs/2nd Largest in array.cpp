// 2nd Largest in array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int n[10], maxi, maxi2, abc, a = 0;

	for (int a = 0; a < 10; a++)
	{
		cout << "Enter the " << a + 1 << " number  = ";
		cin >> n[a];
		if (a == 0)
		{
			abc = n[0];
			maxi = n[0];
			maxi2 = n[0];
		}
		else
		{
			if (n[a] > maxi) { maxi2 = maxi; }
		}
	}

	while (a < 10)
	{
		if (a == 0) {}
		a++;
	}

	cout << endl << "The 2nd largest number is " << maxi2 << endl;

	return 0;
}