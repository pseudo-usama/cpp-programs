// factorial with nested if.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int a = 0, a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0, a7 = 0;

	cout << "Please enter the number.";
	cin >> a;

	if (a <= 8)
	{
		if (a >= 0)
		{
			if (a != 0)
			{
				a1 = a - 1;
				cout << a * a1;
				cout << endl;
				if (a1 != 0)
				{
					a2 = a1 - 1;
					cout << a * a1 * a2;
					cout << endl;
					if (a2 != 0)
					{
						a3 = a2 - 1;
						cout << a * a1 * a2 * a3;
						cout << endl;
						if (a3 != 0)
						{
							a4 = a3 - 1;
							cout << a * a1 * a2 * a3 * a4;
							cout << endl;
							if (a4 != 0)
							{
								a5 = a4 - 1;
								cout << a * a1 * a2 * a3 * a4 * a5;
								cout << endl;
								if (a5 != 0)
								{
									a6 = a5 - 1;
									cout << a * a1 * a2 * a3 * a4 * a5 * a6;
									cout << endl;
									if (a6 != 0)
									{
										a7 = a6 - 1;
										cout << a * a1 * a2 * a3 * a4 * a5 * a6 * a7;
										cout << endl;
									}
								}
							}
						}
					}
				}
			}
		}
	}

	return 0;
}
