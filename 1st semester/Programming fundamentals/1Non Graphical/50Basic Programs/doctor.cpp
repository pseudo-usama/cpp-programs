// doctor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;
int main()
{
	cout << "Enter the temprature of your body(In CELCIUS)." << endl;
	int a;
	cin >> a;
	if (a == 37)
	{
		cout << "Your body temprature is normal." << endl;
	}
	else if (a == 38)
	{
		cout << "You have a minor fever. Its better visit your phisit." << endl;
	}
	else if (a == 39)
	{
		cout << "You have very high fever. Immediately visit your phisit." << endl;
	}
	else if (a == 36)
	{
		cout << "You have very low blood pressure. Must visit your physit." << endl;
	}
	else
	{
		cout << "It is not possible. Check again or check your thermometer." << endl;
	}
	return 0;
}

