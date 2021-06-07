// My age.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int Count_Remaining_days_of_Birth_Year(int Month, int Day) {
	//This function will return the remaining days in birth year
	//Note this will not check for Leap Year

	if (Month == 1)
		return(334 + 31 - Day);
	else if (Month == 2)
		return(304 + 28 - Day);
	else if (Month == 3)
		return(273 + 31 - Day);
	else if (Month == 4)
		return(243 + 30 - Day);
	else if (Month == 5)
		return(212 + 31 - Day);
	else if (Month == 6)
		return(181 + 30 - Day);
	else if (Month == 7)
		return(151 + 31 - Day);
	else if (Month == 8)
		return(120 + 31 - Day);
	else if (Month == 9)
		return(90 + 30 - Day);
	else if (Month == 10)
		return(59 + 31 - Day);
	else if (Month == 11)
		return(31 + 30 - Day);
	else if (Month == 12)
		return(0 + 31 - Day);
}

int Count_Passed_Days_of_Current_Year(int Month) {
	//Will return the passed days of Current Year 
	//Note: It will not clear the passed days of current Month

	if (Month == 1)
		return(0);
	else if (Month == 2)
		return(31);
	else if (Month == 3)
		return(59);
	else if (Month == 4)
		return(90);
	else if (Month == 5)
		return(120);
	else if (Month == 6)
		return(151);
	else if (Month == 7)
		return(181);
	else if (Month == 8)
		return(212);
	else if (Month == 9)
		return(243);
	else if (Month == 10)
		return(273);
	else if (Month == 11)
		return(304);
	else if (Month == 12)
		return(334);
}

int Return_Days_of_Month(int Month, int Day) {
	//This function will return the remaining days of month in birth year
	Day -= 31;

	if (Month == 2) return(Day - 3);
	else if (Month == 4 || Month == 6 || Month == 9 || Month == 11) return(Day - 1);
}

int Remaining_Month(int &Days) {
	//this function will return the remaining month and set the day as final days

	if (Days < 31)
		return(0);
	else if (Days < 59)
	{
		Days -= 31;
		return(1);
	}
	else if (Days < 90)
	{
		Days -= 59;
		return(2);
	}
	else if (Days < 120)
	{
		Days -= 90;
		return(3);
	}
	else if (Days < 151)
	{
		Days -= 120;
		return(4);
	}
	else if (Days < 181)
	{
		Days -= 151;
		return(5);
	}
	else if (Days < 212)
	{
		Days -= 181;
		return(6);
	}
	else if (Days < 243)
	{
		Days -= 212;
		return(7);
	}
	else if (Days < 273)
	{
		Days -= 243;
		return(8);
	}
	else if (Days < 304)
	{
		Days -= 273;
		return(9);
	}
	else if (Days < 334)
	{
		Days -= 304;
		return(10);
	}
	else if (Days < 365)
	{
		Days -= 334;
		return(11);
	}
}

void main() {
	int CurrentYear = 2018, CurrentMonth = 9, CurrentDay = 13;
	int BirthYear = 1999, BirthMonth = 2, BirthDay = 23;

	int Days;	//Temporary use

	cout << "Enter the dates like 23 01 2018 : DD MM YYYY" << endl << endl;

	cout << "Enter your Date of Birth   : ";
	cin >> BirthDay >> BirthMonth >> BirthYear;

	cout << "Enter Current Date         : ";
	cin >> CurrentDay >> CurrentMonth >> CurrentYear;

	Days = (CurrentYear - BirthYear - 1) * 365;		//It will count the days of all Years except birth Year

	Days += Count_Remaining_days_of_Birth_Year(BirthMonth, BirthDay);	//It will count the days in Birth Year
	
	Days += Count_Passed_Days_of_Current_Year(CurrentMonth);	//It will count the passed Days in Current Year

	Days += CurrentDay;	//It will count the passed days in Current Month

	Days += (CurrentYear - BirthYear) / 4;	//This will count the Leap Year except Birth Year
		
	Days++;	//This is because if the Birth Year is Leap so we must add 1 to Days and other reason is that the above formula to count the number of Leap Year Has an Drawback that if the Birth Year the not Leap then it will count Leap Years - 1 so in both cases we must add 1 to Days
		

	cout << endl << Days << endl << endl;

	cout << "Your age is:" << endl << endl;
	

	cout << "Years			:	" << Days / 365 << endl;

	Days = Days % 365;	//Acctually now this is not days this is now remaining months and days

	cout << "Months			:	" << Remaining_Month(Days) << endl;

	cout << "Days			:	" << Days << endl;
}

