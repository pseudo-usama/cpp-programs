// Time (SECONDS).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int seconds = 0;

	for (;;)										//Infinitive loop we can put condition that after that limit prosscessing will stop
	{
		seconds = seconds + 1;

		system("ClS");

		cout << "The time is    =  " << seconds << " SECONDS";
		for(int a = 0; a < 299000000; a++)				//This loop is to waste time that's equal to one SECOND
		{												//this time or condition of loop varies computer to computer
		}												//as different computers have different speed of processing
	}
	return 0;
}

