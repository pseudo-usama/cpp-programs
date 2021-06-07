// Dacimal Search.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int x, low = 0, high = 9, m, decider, n[10] = { 1, 3, 5, 8, 9, 20, 21, 22, 23, 40 };

	cin >> x;

	for (int a = 0; a < 10; a++)
	{
		if (x > n[m])
		{
			high = m - 1;
			m = (low + high) / 2;
		}
		else if (x < n[m])
		{
			low = m + 1;
			m = (low + high) / 2;
		}
		else
		{
			decider = 1;
			break;
		}
	}

	return 0;
}

