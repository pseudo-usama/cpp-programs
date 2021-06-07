// Saanp wali Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "windows.h"
using namespace std;

int main()
{
	int saanp = 1, saanp2 = 0, saanp3 = 0, saanp4 = 4, timer = 1;

	for (;;)
	{
		saanp3 += 1;
		saanp4 += 1;
		saanp = saanp3 + 1;

		if (saanp4 >= 80) { saanp2 += 1; }
		if (saanp3 >= 80) { saanp3 = 1; saanp4 = saanp2; saanp2 = 0; }

		cout << system("CLS");

		for (int a = 1; a < 20; a++)
		{
			for (int b = 1; b < 80; b++)
			{
				if (a == 5 && ((b <= saanp4 && b >= saanp3) || (b <= saanp2))) { cout << "*"; }
				else { cout << " "; }

				if (saanp < saanp4) { saanp += 1; }
			}
			cout << endl;
		}
	//	Sleep(timer);
	}

	return 0;
}

