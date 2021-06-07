// 8date to day.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	long days = 0, year;
	int date, month, DayDecieder = 8, leapDecieder;

	cout << "Enter the date.               =     ";
	cin >> date;

	cout << "Enter the month.              =     ";
	cin >> month;

	cout << "Enter the  year.              =     ";
	cin >> year;

	if (month == 1)
	{
		days = 0;
	}
	else if (month == 2)
	{
		days = 31;
	}
	else if (month == 3)
	{
		days = 59;
	}
	else if (month == 4)
	{
		days = 90;
	}
	else if (month == 5)
	{
		days = 120;
	}
	else if (month == 6)
	{
		days = 151;
	}
	else if (month == 7)
	{
		days = 181;
	}
	else if (month == 8)
	{
		days = 212;
	}
	else if (month == 9)
	{
		days = 243;
	}
	else if (month == 10)
	{
		days = 273;
	}
	else if (month == 11)
	{
		days = 304;
	}
	else if (month == 12)
	{
		days = 334;
	}
    
	days = days + date;
	
	if (0 == year % 4 && month != 1 && month != 2)
	{
		days = days + 1;
	}
	
	year = year - 1990;
	
	days = year * 365 + days; 
    
	leapDecieder = year / 4;
	
	days = leapDecieder + days;
	
	
	
		DayDecieder = days % 7;
		if (days <= 7)
		{

			cout << "The day is ";
			cout << DayDecieder << endl;           

			if (DayDecieder == 0)
			{
				cout << "SUNDAY.";
			}
			else if (DayDecieder == 1)
			{
				cout << "MONDAY.";
			}
			else if (DayDecieder == 2)
			{
				cout << "TUESDAY.";
			}
			else if (DayDecieder == 3)
			{
				cout << "WEDNESDAY.";
			}
			else if (DayDecieder == 4)
			{
				cout << "THUSDAY.";
			}
			else if (DayDecieder == 5)
			{
				cout << "FRIDAY.";
			}
			else if (DayDecieder == 6)
			{
				cout << "SATURDAY.";
			}

		}
		else
		{
			if (DayDecieder == 6)
			{
				cout << "SUNDAY.";
			}
			else if (DayDecieder == 0)
			{
				cout << "MONDAY.";
			}
			else if (DayDecieder == 1)
			{
				cout << "TUESDAY.";
			}
			else if (DayDecieder == 2)
			{
				cout << "WEDNESDAY.";
			}
			else if (DayDecieder == 3)
			{
				cout << "THUSDAY.";
			}
			else if (DayDecieder == 4)
			{
				cout << "FRIDAY.";
			}
			else if (DayDecieder == 5)
			{
				cout << "SATURDAY.";
			}
		}
	return 0;
}

