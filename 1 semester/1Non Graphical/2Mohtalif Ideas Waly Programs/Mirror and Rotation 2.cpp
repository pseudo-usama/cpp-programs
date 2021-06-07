// Mirror and Rotation 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

void rotational(int &a, int &b, int rotater)										//Ya Image ko rotate karta ha
{
	int holder;
	for (int i= 1; i <= sqrt(rotater * rotater); i++)
	{
		holder = a;
		a = b;
		b = holder;
		if (rotater < 0) { b = -b; }
		else{ a = -a; }
	}
}

int main()
{
	int decider = 0, selector = 6, rotater = 0, Xmirror = 1, Ymirror = 1;

	for (; selector; )
	{
		for (int y = 5; y >= 0; y--)
		{
			for (int x = -5; x <= 5; x++)
			{
				if (decider)
				{
					cout << endl;
					cout << "To close program enter                                 '0'" << endl;
					cout << "To apply VERTICALY  mirror enter                       '1'" << endl;
					cout << "To apply HORIZONTLY mirror enter                       '2'" << endl;
					cout << "To rotate image in RIGHT side at 90 Degree enter       '3'" << endl;
					cout << "To rotate image in RIGHT side at 90 Degree enter       '4'" << endl;
					cout << "          Enter here       =     ";
					cin >> selector; 

					cout << endl;

					for (; selector < 0 || selector > 4;)
					{
						cout << "Enter a number from 0 to 4." << endl;
						cout << "          Enter here       =     ";
						cin >> selector;
					}

					if (selector == 1) { Ymirror = Ymirror + 1; }
					else if (selector == 2) { Xmirror = Xmirror + 1; }
					else if (selector == 3) { rotater = rotater + 1; }
					else { rotater = rotater - 1; }

					if (rotater == 5) { rotater = 1; }
					else if (rotater == -5) { rotater = -1; }

					if (selector) { system("CLS"); }
					decider = 0;
				}

				if (selector)
				{
					if (selector == 1 || selector == 2)
					{
						if (Ymirror % 2 == 0) { y = -y; }
						if (Xmirror % 2 == 0) { x = -x; }
					}
					
					rotational(x, y, rotater);

					if (y == 0) { cout << "* "; }									//This is defining the accutial picture
					else if (x + y == 0 && x > 0 && y < 0) { cout << "# "; }		//This is defining the accutial picture
					else if (x + y == 0 && x < 0 && y > 0) { cout << "@ "; }		//This is defining the accutial picture
					else { cout << "  "; }											//This is defining the accutial picture

					if (selector == 1 || selector == 2)
					{
						if (Ymirror % 2 == 0) { y = -y; }
						if (Xmirror % 2 == 0) { x = -x; }
					}

					rotational(y, x, rotater);

				}
				if (!selector) { break; }
			}
			if (!selector) { break; }
			cout << endl;
		}
		decider = 1;
	}

	return 0;
}


