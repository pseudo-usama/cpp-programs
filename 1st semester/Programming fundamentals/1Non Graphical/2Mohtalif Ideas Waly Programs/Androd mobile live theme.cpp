// Androd mobile live theme.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "windows.h"
using namespace std;

int main()
{
	int abc = 1, abc2 = 0, abc3 = 0, abc4 = 4, def = -6, def2 = 0, def3 = -4, def4 = 0, timer = 1;

	for (;;)
	{
		abc3 += 1;
		abc4 += 1;
		abc = abc3 + 1;

		if (abc4 >= 80) { abc2 += 1; }
		if (abc3 >= 80) { abc3 = 1; abc4 = abc2; abc2 = 0; }

		def3 += 1;
		def4 += 1;
		def = def3 + 1;

		if (def4 >= 80) { def2 += 1; }
		if (def3 >= 80) { def3 = 1; def4 = def2; def2 = 0; }

		cout << system("CLS");

		for (int a = 1; a < 24; a++)
		{
			for (int b = 1; b < 80; b++)
			{
				if ( (a == 2 || a == 7 || a == 12 || a == 17) && ( (b <= abc4 && b >= abc3) || b <= abc2)) { cout << "*"; }
				else if ((b <= abc4 && b >= abc3) || b <= abc2) { }
				else { cout << " "; }

				if (abc < abc4) { abc += 1; }
				if (def < def4) { def += 1; }
			}
			cout << endl;
		}
		Sleep(timer);
	}

	return 0;
}

