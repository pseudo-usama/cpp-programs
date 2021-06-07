// 20Perimeter of circle ractangl triangl.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{

	int OprationSelector = 1;

	for (;OprationSelector != 0;)
	{

		cout << "                           Calculate Perimeter of" << endl;
		cout << "                   1) Circle   2) Ractangle   3) Triangle   0) Exit" << endl << endl;
		cout << "     Enter here      =    ";
		cin >> OprationSelector;


		if (OprationSelector < 0 || OprationSelector > 3)
		{
			for (;;)
			{
				cout << "ERROR.Enter 1 , 2 , 3 or 0" << endl;
				cout << "     Enter here      =    ";
				cin >> OprationSelector;
			}
		}

		cout << endl;

		switch (OprationSelector)
		{

		case 1:
		{
				  int radius;
				  float pi = 3.14;

				  cout << "Enter the Radius.       =     ";
				  cin >> radius;

				  cout << "The perimeter is " << 2 * pi * radius;
				  break;
		}

		case 2:
		{
				  int a, b;
				  cout << "Enter the length        =      ";
				  cin >> a;

				  cout << "Enter the width         =      ";
				  cin >> b;

				  cout << "The perimeter is        =      " << 2 * a + 2 * b;
				  break;
		}
		case 3:
		{
			int a, b, c;

			cout << "Enter the length of first side       =    ";
			cin >> a;

			cout << "Enter the length of second side      =    ";
			cin >> b;

			cout << "Enter the length of third side       =    ";
			cin >> c;

			cout << "The perimeter is                     =    " << a + b + c;
			break;
		}
		}

		cout << endl << endl;

		if (OprationSelector != 0)
		{
			cout << "Enter the value to run that calculation" << endl;
			cout << "Or enter '0' to close this program." << endl;
		}
	}

	return 0;
}

