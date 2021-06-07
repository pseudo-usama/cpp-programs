// Merror and Rotation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int decider = 0, selector = 6, holder;

	for (; selector != 0;)
	{

		for (int y = 5; y >= -5; y--)
		{
			for (int x = -5; x <= 5; x++)
			{
				if (decider == 1)
				{
					cout << endl;
					cout << "To apply VERTICALY  mirror enter     '1'" << endl;
					cout << "To apply HORIZONTLY mirror enter     '2'" << endl;
					cout << "To apply rotate RIGHT enter          '3'" << endl;
					cout << "To apply rotate LEFT enter           '4'" << endl;
					cout << "Or to close program enter            '0'" << endl;
					cout << "          Enter here       =     ";
					cin >> selector;

					cout << endl;

					for (; selector < 0 || selector > 4; )
					{
						cout << "Enter a number from 0 to 4." << endl;
						cout << "          Enter here       =     ";
						cin >> selector;
					}

					decider = 0;
				}

				if (selector == 1)													//For VERTICAL
				{
					y = -y;
				}
				else if (selector == 2)												//For HORIZONTYL
				{
					x = -x;
				}
				else if (selector == 3)												//for RIGHT rotation
				{
					holder = y;
					y = x;
					x = -holder;
				}
				else if (selector == 4)												//for LEFT rotation
				{
					holder = x;
					x = y;
					y = -holder;
				}

				if (selector != 0)
				{

					if (y == 0)														//This is defining the accutial picture
					{
						cout << "* ";
					}
					else if (x + y == 0 && x > 0 && y < 0)
					{
						cout << "# ";
					}
					else															//This is defining the accutial picture
					{
						cout << "  ";
					}

					if (selector == 1)												//For VERTICAL
					{
						y = -y;
					}
					else if (selector == 2)											//For HORIZONTYL
					{
						x = -x;
					}
					else if (selector == 3)											//for RIGHT rotation
					{
						holder = -x;
						x = y;
						y = holder;
					}
					else if (selector == 4)											//for LEFT rotation
					{
						holder = x;
						x = -y;
						y = holder;
					}
				}
				if (selector == 0)
				{
					break;
				}
			}
			if (selector == 0)
			{
				break;
			}
			cout << endl;
		}
		decider = 1;
	}

	return 0;
}

