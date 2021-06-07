// Time(Seconds) using SLEEP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	unsigned int microseconds;
	int seconds = 0; 

	for (;;)
	{
		system("CLS");
		cout << "The time is   = " << seconds << "SECONDS";
		seconds = seconds + 1;
		usleep(microseconds);
	}

	return 0;
}

