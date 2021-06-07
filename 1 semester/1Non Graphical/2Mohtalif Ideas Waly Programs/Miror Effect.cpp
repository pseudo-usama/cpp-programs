// Miror Effect.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int decider = 0, mirror = 6;

	for (; mirror != 0;)
	{

		for (int y = 5; y >= -5; y--)
		{
			for (int x = -5; x <= 5; x++)
			{
				if (decider == 1)
				 {
					cout << endl;
					cout << "To apply HORIZONTLY mirror enter     '1'       =  " << endl;
					cout << "To apply VERTICALY mirror enter      '2'       =  " << endl;
					cout << "Or to close program enter            '0'       =  " << endl;
					cout << "          Enter here       =     ";
					cin >> mirror;

					decider = 0;
				}

				if (mirror == 1)
				{
					y = -y;
				}
				else if (mirror == 2)
				{
					x = -x;
				}

				if (mirror != 0)
				{

					if (x < y)
					{
						cout << "* ";
					}
					else
					{
						cout << "  ";
					}

					if (mirror == 1)
					{
						y = -y;
					}
					else if (mirror == 2)
					{
						x = -x;
					}
				}
				if (mirror == 0)
				{
					break;
				}
			}
			if (mirror == 0)
			{
				break;
			}
			cout << endl;
		}
		decider = 1;
	}

	return 0;
}

