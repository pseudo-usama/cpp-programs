// Stop Watch.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int seconds = 0, CentiSeconds = 0;

	for (;;)										//Infinitive loop we can put condition that after that limit prosscessing will stop
	{
		CentiSeconds = 0;
		for (; CentiSeconds < 100;)
		{
			CentiSeconds = CentiSeconds + 1;

			system("CLS");									//This is due to clear previous cout data

			cout << "The time is " << seconds << "." << CentiSeconds;

			for (int a = 0; a < 2990000; a++)				//This loop is to waste time that's equal to one CENTI SECOND
			{												//this time or condition of loop varies computer to computer
			}												//as different computers have different speed of processing
		}
		seconds = seconds + 1;
	}
	return 0;
}

