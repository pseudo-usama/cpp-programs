// Year Calender.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "windows.h"
#include "ctime"
using namespace std;

unsigned int Year;

int return_Day();
int Make_Spaces(int Day);
int Make_Month(int Day, int Max_Date);
int Maximum_Date(int Month);

#pragma region These Functions make calender

void Make_Calender(int Day) {
	cout << endl << endl << endl;

	//this function make Month and to make further days and weeks it uses Make_Month Function
	for (int Month = 1; Month < 13; Month++) {
		cout << endl << endl << "\t";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3); //replace the 0 with a number for the color you want
		if (Month == 1)cout << "January";
		else if (Month == 2) cout << "February";
		else if (Month == 3) cout << "March";
		else if (Month == 4) cout << "April";
		else if (Month == 5) cout << "May";
		else if (Month == 6) cout << "June";
		else if (Month == 7) cout << "July";
		else if (Month == 8) cout << "August";
		else if (Month == 9) cout << "September";
		else if (Month == 10) cout << "October";
		else if (Month == 11) cout << "November";
		else if (Month == 12) cout << "December";

		cout << endl << endl << "\t\t";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); //replace the 0 with a number for the color you want
		cout << "Su";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 128); //replace the 0 with a number for the color you want
		cout << "\tMo\tTu\tWe\tTh\t";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); //replace the 0 with a number for the color you want
		cout << "Fr";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 128); //replace the 0 with a number for the color you want
		cout << "\tSa" << endl << endl;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //replace the 0 with a number for the color you want

		Day = Make_Month(Day, Maximum_Date(Month));

		cout << endl << endl;
	}
}

int Make_Month(int Day, int Max_Date) {
	//this function makeweeks and days and dates
	int Days = Make_Spaces(Day);

	for (int week = 1, Date = 1; Date < Max_Date; week++) {
		if (week != 1) Days = 1;
		cout << "\t\t";
		for (; Days < 8 && Date < Max_Date; Days++, Date++) {
			if (Days == 1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); //replace the 0 with a number for the color you want
				cout << Date << "\t";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //replace the 0 with a number for the color you want
			}
			else if (Days == 6) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); //replace the 0 with a number for the color you want
				cout << Date << "\t";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //replace the 0 with a number for the color you want
			}
			else
				cout << Date << "\t";

		}
		cout << endl;
	}

	if (Days > 5)       return(Days - 4);
	else if (Days == 5) return(1);
	else if (Days == 4) return(0);
	else                return(Days + 3);
}

#pragma endregion

void main() {
	Make_Calender(return_Day());
}

#pragma region Helper and Supportive Functions in making of Calender

int return_Day() {
	//return the first day of entered Year
	do
	{
		cout << "Enter Year(Greater then 1799 and Smaller then " << MAXINT << " )   : ";
		cin >> Year;
	} while (Year < 1800 || Year > MAXINT);

	long Days;

	Days = (Year - 1800) * 365;

	Days += (Year - 1800) / 4;

	if (Year % 4 == 0) Days--;

	for (int i = 1900; i < Year; i += 100)
	if (i % 400 != 0)
		Days--;

	return(Days % 7);
}

int Make_Spaces(int Day) {
	//Make spaces before starting a month
	//also return the specific index from where month Dates will start
	switch (Day)
	{
	case 1:			//Thusday
		cout << "\t\t\t\t";
		return(5);
	case 2:			//Friday
		cout << "\t\t\t\t\t";
		return(6);
	case 3:			//Saturday
		cout << "\t\t\t\t\t\t";
		return(7);
	case 4:			//Sunday
		return(1);
	case 5:			//Monday
		cout << "\t";
		return(2);
	case 6:			//Tuesday
		cout << "\t\t";
		return(3);
	default:		//Wednesday
		cout << "\t\t\t";
		return(4);
	}
}

int Maximum_Date(int Month) {
	//return the days in given month
	switch (Month)
	{
	case 1:
		return(32);
	case 2:
		if (::Year % 4 == 0)
		{
			if (::Year % 100 == 0)
			{
				if (::Year % 400 == 0)
					return(30);
				else
					return(29);
			}
			else
				return(30);
		}
		else
			return(29);
	case 3:
		return(32);
	case 4:
		return(31);
	case 5:
		return(32);
	case 6:
		return(31);
	case 7:
		return(32);
	case 8:
		return(32);
	case 9:
		return(31);
	case 10:
		return(32);
	case 11:
		return(31);
	default:
		return(32);
	}
}

#pragma endregion