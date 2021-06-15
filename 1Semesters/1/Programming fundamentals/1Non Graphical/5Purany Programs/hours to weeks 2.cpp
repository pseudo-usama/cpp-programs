// hours to weeks 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	long hours, days, weeks ;

	cout << "Please enter the time in hours." ;
	cin >> hours ;
	
	weeks = hours / 168 ;

	if (weeks == 0)
	{
		days = hours / 24 ;
	}
	else if (weeks > 0)
	{
		days = weeks % 168 ;
		days = hours / 24  ;
	}
	if (days == 0)
	{

	}



	return 0;
}

