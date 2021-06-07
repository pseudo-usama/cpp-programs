// 27) Population of two Cities.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

struct CITY {

	char name[15];
	double population;
};

void cities(CITY city1, CITY city2) {

	if (city1.population < city2.population) { cout << "First city '"  << city1.name << "' has less POPULATION of " << city1.population; }
	else if (city1.population > city2.population){ cout << "Second city '" << city2.name << "' has less POPULATION of " << city2.population; }
	else { cout << "Both cities have same POPULATION of " << city1.population; }
}

int main()
{
	CITY city1, city2;

	cout << "Enter the NAME of First city     = ";
	cin >> city1.name;

	cout << "Enter the First city POPULATION  = ";
	cin >> city1.population;

	cout << endl;

	cout << "Enter the Second city NAME       = ";
	cin >> city2.name;

	cout << "Enter the Second city POPULATION = ";
	cin >> city2.population;

	cities(city1, city2);

	return 0;
}

