// gharalo ahragat.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "iostream"
using namespace std ;

int main()
{
	int reloader = 2;

	do{
		if (reloader == 2)
		{
			cout << "                         Monthly Ahragat Calculation" << endl << endl;
		}

		int income, bills, childern, handi, OtherCharges;
		char ReValue, ya = 'y', na = 'n';

		cout << "                          Inputs" << endl << endl;


		cout << "Enter your monthly income                     ";
		cin >> income;
		if (income < 0)
		{
			cout << endl;
			cout << "Impossible...!!! Enter positive number." << endl;
			cout << "To remove negative sign enter 'y'" << endl;
			cout << "or enter 'n' and enter income again" << endl;
			cout << "                Enter here       =     ";
			cin >> ReValue;

			if (ReValue == ya)
			{
				income = income * -1;
			}
			else
			{
				cout << "Enter your monthly income                     ";
				cin >> income;
			}

			system("CLS") ;

			cout << "                         Monthly Ahragat Calculation" << endl << endl ;
			cout << "Enter your monthly income                     " << income << endl ;

		}

		cout << "Now what is your utality bills                " ;
		cin >> bills;
		if (bills < 0)
		{
			cout << endl;
			cout << "Impossible...!!! Enter positive number." << endl;
			cout << "To remove negative sign enter 'y'" << endl;
			cout << "or enter 'n' and enter bills again" << endl;
			cout << "                Enter here       =     ";
			cin >> ReValue;

			if (ReValue == ya)
			{
				bills = bills * -1;
			}
			else
			{
				cout << "Enter your monthly income                     ";
				cin >> bills ;
			}

			system("CLS");

			cout << "                         Monthly Ahragat Calculation" << endl << endl;
			cout << "Enter your monthly income                     " << income << endl;
			cout << "Now what is your utality bills                " << bills << endl ;

		}

		cout << "What is your children ahrajat                 ";
		cin >> childern;
		if (childern < 0)
		{
			cout << endl;
			cout << "Impossible...!!! Enter positive number." << endl;
			cout << "To remove negative sign enter 'y'" << endl;
			cout << "or enter 'n' and enter childern ahrajat again" << endl;
			cout << "                Enter here       =     ";
			cin >> ReValue;

			if (ReValue == ya)
			{
				childern = childern * -1;
			}
			else
			{
				cout << "Enter your childern ahrajat                     " ;
				cin >> childern ;
			}

			system("CLS");

			cout << "                         Monthly Ahragat Calculation" << endl << endl;
			cout << "Enter your monthly income                     " << income << endl;
			cout << "Now what is your utality bills                " << bills << endl;
			cout << "What is your children ahrajat                 " << childern << endl ;
			
		}

		cout << "Please enter your handi roti k ahrajat        ";
		cin >> handi;
		if (handi < 0)
		{
			cout << endl;
			cout << "Impossible...!!! Enter positive number." << endl;
			cout << "To remove negative sign enter 'y'" << endl;
			cout << "or enter 'n' and enter handi roti k ahrajat again" << endl;
			cout << "                Enter here       =     ";
			cin >> ReValue;

			if (ReValue == ya)
			{
				handi = handi * -1;
			}
			else
			{
				cout << "Enter your childern ahrajat                     ";
				cin >> handi;
			}

			system("CLS");

			cout << "                         Monthly Ahragat Calculation" << endl << endl;
			cout << "Enter your monthly income                     " << income << endl;
			cout << "Now what is your utality bills                " << bills << endl;
			cout << "What is your children ahrajat                 " << childern << endl;
			cout << "Please enter your handi roti k ahrajat        " << handi << endl ;

		}

		cout << "If you have some other charges please entre   ";
		cin >> OtherCharges;
		if (OtherCharges < 0)
		{
			cout << endl;
			cout << "Impossible...!!! Enter positive number." << endl;
			cout << "To remove negative sign enter 'y'" << endl;
			cout << "or enter 'n' and enter handi other charges again" << endl;
			cout << "                Enter here       =     ";
			cin >> ReValue;

			if (ReValue == ya)
			{
				OtherCharges = OtherCharges * -1;
			}
			else
			{
				cout << "Enter your childern ahrajat                     ";
				cin >> OtherCharges;
			}

			system("CLS");

			cout << "                         Monthly Ahragat Calculation" << endl << endl;
			cout << "Enter your monthly income                     " << income << endl;
			cout << "Now what is your utality bills                " << bills << endl;
			cout << "What is your children ahrajat                 " << childern << endl;
			cout << "Please enter your handi roti k ahrajat        " << handi << endl;
			cout << "If you have some other charges please entre   " << OtherCharges << endl ;

		}

		int ahragat = bills + childern + handi + OtherCharges;

		cout << endl << endl;

		cout << "  Results(outputs)" << endl << endl;

		cout << "Your total ahrajat is                         " << ahragat;
		if (income == 0)
		{
			cout << "0(0%)";
		}
		else if (ahragat == income)
		{
			cout << "(100%)";
		}
		else if (income > ahragat)
		{
			cout << "(" << ((ahragat * 100) / income) << "%)";
		}
		else if (ahragat == 0)
		{
			cout << "0(0%)";
		}

		cout << endl;

		if (income == ahragat)
		{
			cout << "Your saving is                                0(0%)";
		}

		else if (income > ahragat)
		{
			cout << "Your saving is                                " << income - ahragat << "(" << ((income - ahragat) * 100) / income << "%)";
		}

		else
		{
			cout << "Unfortunately your income is less than your " << endl;
			cout << "ahrajat.So you have to make lone of           " << ahragat - income;
		}

		cout << endl << endl;

		cout << "To claculate again enter '1'. " << endl;
		cout << "To reloade program enter '2'." << endl;
		cout << "To close program enter any digity." << endl << endl;

		cout << "            Enter here     =    ";
		cin >> reloader;

		if (reloader == 2)
		{
			system("CLS");
		}
		else
		{
			cout << endl << endl;
		}

	} while (reloader == 1 | reloader == 2);


	cout << "Thanks for using our program" << endl;
	cout << "If you enjoy this please hit like and share it with your friends." << endl << endl;

	return 0;
}


