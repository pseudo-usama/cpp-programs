// Sort Asceding order in ARRAY.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int n[10], min[10], maxi[10], max, max2;

	for (int a = 0; a < 10; a++)
	{
		cout << "Enter the " << a + 1 << " number.   = ";
		cin >> n[a];
	}

	for (int a = 0; a < 10; a++)
	{
		for (int b = 0; b < 10; b++)
		{
			if (!b) { max = n[0]; max2 = n[0]; }
			else if (n[b] > max ) { max = n[b]; }
		}
		maxi[a] = max;

	}

	for (int a = 0; a < 10; a++)
	{
		cout << maxi[a] << endl;
	}

	return 0;
}

