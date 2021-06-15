// MaxiAnd miniAsanTarika.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int n[15], maxi, mini;

	for (int a = 0; a <= 14; a++)
	{
		cout << "Enter the " << a + 1 << " value.     =  ";
		cin >> n[a];
		if (a == 0)
		{
			mini = n[a];
			maxi = n[a];
		}
		else
		{
			if (n[a] < mini) { mini = n[a]; }
			if (n[a] > maxi) { maxi = n[a]; }
		}
	}
	cout << endl << "The minimum number is.       =  " << mini << endl;
	cout << "The maximum number is        =  " << maxi << endl;

	return 0;
}

