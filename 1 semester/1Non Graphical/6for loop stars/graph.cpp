// graph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int x, y, A, B, a, b;

	cout << "Please enter the x-intercept      =    ";
	cin >> x;

	cout << "Please enter the y-intercept      =    ";
	cin >> y;

	for (int a = 1; a <= 11; a++)
	{
		for (int b = 1; b <= 11; b++)
		{
			
				A = a;
				B = b;

				B = b - 1;

				if (A == 1)
				{
					A = 10;
				}
				else if (A == 2)
				{
					A = 9;
				}
				else if (A == 3)
				{
					A = 7;
				}
				else if (A == 4)
				{
					A = 7;
				}
				else if (A == 5)
				{
					A = 6;
				}
				else if (A == 6)
				{
					A = 5;
				}
				else if (A == 7)
				{
					A = 4;
				}
				else if (A == 8)
				{
					A = 3;
				}
				else if (A == 9)
				{
					A = 2;
				}
				else if (A == 10)
				{
					A = 1;
				}
				else if (A == 11)
				{
					A = 0;
				}

				if (x == B && y == A)
				{
					cout << "*";
				}
			

			if (a == 11 && b == 1)
			{
				cout << " 0";
			}
			else if (((a == 11 && b == 2) || (a == 11 && b == 4) || (a == 11 && b == 6) || (a == 11 && b == 8)) ||
				(b == 1 && a == 11) || (b == 1 && a == 9) || (b == 1 && a == 7) || (b == 1 && a == 5) || (b == 1 && a == 3) || (b == 1 && a == 1))
			{
				cout << " ";
			}
			else if ((a == 11 && b == 3) || (b == 1 && a == 10))
			{
				cout << " 2";
			}
			else if ((a == 11 && b == 5) || (b == 1 && a == 8))
			{
				cout << " 4";
			}
			else if ((a == 11 && b == 7) || (b == 1 && a == 6))
			{
				cout << " 6";
			}
			else if ((a == 11 && b == 9) || (b == 1 && a == 4))
			{
				cout << " 8";
			}
			else if ((a == 11 && b == 11) || (b == 1 && a == 2))
			{
				cout << " 10";
			}

		}
		cout << endl;
	}
	return 0;
}


	

