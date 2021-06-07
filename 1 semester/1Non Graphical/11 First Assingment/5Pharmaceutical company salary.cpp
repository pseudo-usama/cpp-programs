// 5Pharmaceutical company salary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int salary, HouseRent, DailyAllowance;

	cout << "Enter the basic salary.                       =     ";
	cin >> salary;

	for (; salary < 0;)
	{
		cout << "ERROR. Salary cannot be -ve." << endl;
		cout << "Enter the basic salary.                       =      ";
		cin >> salary;
	}

	if (salary < 1500)
	{
		HouseRent = salary * 0.1;
		DailyAllowance = salary * 0.9;
		salary = salary + HouseRent + DailyAllowance;

		cout << "The total salary of employ according to " << endl;
		cout << "10% HOUSE RENT and 90% DAILY ALLOWANCE is     =     " << salary;
	}
	else
	{
		HouseRent = salary * 0.2;
		DailyAllowance = salary * 0.95;
		salary = salary + HouseRent + DailyAllowance;

		cout << "The total salary of employ according to " << endl;
		cout << "20% HOUSE RENT and 95% DAILY ALLOWANCE is     =     " << salary;
	}

	return 0;
}

