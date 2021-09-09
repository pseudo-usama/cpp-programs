// Car Viechal Motorcycle in structure.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;


int main()
{
	struct MOTERCYCLE {

		char company[10];
		char colour[10];
		char model[5];
		float petrol;
		float speed;
	};

	struct CAR {

		int seats;
		char number[10];
		bool autogaer;
		char name[10];
		int CC;
	};

	struct VIECHAL {

		MOTERCYCLE motercycle ;
		CAR car;

		int price;
		bool AC;
		char PetrolOrGas[6];
		bool condition;
		bool engine;
	};

	VIECHAL viechal;
	
	cout << "Enter the company of viechal                  ";
	cin >> viechal.motercycle.company;

	cout << "Enter the colour of viechal                   ";
	cin >> viechal.motercycle.colour;
	 
	cout << "Enter the model of viechal                    ";
	cin >> viechal.motercycle.model;

	cout << "Maximum capacity of petrol tank or gas tank   ";
	cin >> viechal.motercycle.petrol;

	cout << "Enter the maximum speed of viechal            ";
	cin >> viechal.motercycle.speed;

	cout << "Enter the seats in viechal                    ";
	cin >> viechal.car.seats;

	cout << "Enter the name of viechal owner               ";
	cin >> viechal.car.name;

	cout << "Enter the number of viechal owner             ";
	cin >> viechal.car.number;

	cout << "Enter the CC of the viechal                   ";
	cin >> viechal.car.CC;

	cout << "Is viechal is AUTOGAER or not(Enter 1 or 0)   ";
	cin >> viechal.car.autogaer;

	cout << "Enter the price of viechal                    ";
	cin >> viechal.price;

	cout << "Is AC presente or not (Enter 1 or 0)          ";
	cin >> viechal.AC;

	cout << "Is viechal is on gas or petrol                ";
	cin >> viechal.PetrolOrGas;

	cout << "Enter the condition of viechal(Enter 1 or 0)  ";
	cin >> viechal.condition;

	cout << "Enter the condition of engine(Enter 1 or 0)   ";
	cin >> viechal.engine;


	cout << endl << endl << endl << endl;


	cout << "Company of viechal                            " << viechal.motercycle.company << endl;

	cout << "Colour of viechal                             " << viechal.motercycle.colour << endl;

	cout << "Model of viechal                              " << viechal.motercycle.model << endl;

	cout << "Maximum capacity of petrol tank or gas tank   " << viechal.motercycle.petrol << endl;

	cout << "Maximum speed of viechal                      " << viechal.motercycle.speed << endl;

	cout << "Seats in viechal                              " << viechal.car.seats << endl;

	cout << "Name of viechal owner                         " << viechal.car.name << endl;

	cout << "Number of viechal owner                       " << viechal.car.number << endl;

	cout << "CC of the viechal                             " << viechal.car.CC << endl;

	cout << "Viechal is AUTOGAER or not(In 1 or 0)         " << viechal.car.autogaer << endl;

	cout << "Price of viechal                              " << viechal.price << endl;

	cout << "AC presente or not (In 1 or 0)                " << viechal.AC << endl;

	cout << "Viechal is on gas or petrol                   " << viechal.PetrolOrGas << endl;

	cout << "Condition of viechal(Enter 1 or 0)            " << viechal.condition << endl;

	cout << "Condition of engine(Enter 1 or 0)             " << viechal.engine << endl;

	return 0;
}

