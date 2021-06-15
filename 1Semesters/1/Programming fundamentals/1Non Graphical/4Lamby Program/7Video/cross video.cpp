// cross video.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	for (;;)
	{
		for (int repeater = 0; repeater < 5; repeater++)
		{

			for (int a = 1; a < 11; a++)
			{
				for (int b = 1; b <= 11; b++)
				{
					if (a == b)
					{
						cout << "* ";
					}
					else
					{
						cout << "  ";
					}
				}
				cout << endl;
			}
			system("CLS");
		}
		for (int repeater = 0; repeater < 5; repeater++)
		{

			for (int a = 1; a < 11; a++)
			{
				for (int b = 1; b < 11; b++)
				{
					if (b == 5)
					{
						cout << "* ";
					}
					else
					{
						cout << "  ";
					}
				}
				cout << endl;
			}
			system("CLS");
		}
		for (int repeater = 0; repeater < 5; repeater++)
		{

			for (int a = 1; a < 21; a++)
			{
				for (int b = 1; b < 11; b++)
				{
					if (a + b == 10)
					{
						cout << "* ";
					}
					else
					{
						cout << "  ";
					}
				}
				cout << endl;
			}
			system("CLS");
		}
		for (int repeater = 0; repeater < 5; repeater++)
		{

			for (int a = 1; a < 11; a++)
			{
				for (int b = 1; b < 11; b++)
				{
					if (a == 5)
					{
						cout << "* ";
					}
					else
					{
						cout << "  ";
					}
				}
				cout << endl;
			}
			system("CLS");
		}
	}

	return 0;
}

