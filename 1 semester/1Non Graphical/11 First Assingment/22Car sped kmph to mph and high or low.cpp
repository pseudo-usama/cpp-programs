// 22Car sped kmph to mph and high or low.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{

	int kmph, mph;

	cout << "Enter the speed(kmph).           =     ";
	cin >> kmph;

	cout << endl;
	cout << "The speed in mph is              =     ";
	mph = kmph * 1000;
	cout << mph << endl;

	if (mph > 150)
	{
		cout << "The speed is over 150 mph. You should lower the speed.";
	}
	else if (mph > 100)
	{
		cout << "The speed is over 100 mph. And the speed is eligible for motor way.";
	}
	else if (mph > 80)
	{
		cout << "The speed is over 80 mph.";
	}
	else if (mph < 80)
	{
		cout << "The speed is less than 80 mph.";
	}


	return 0;
}

