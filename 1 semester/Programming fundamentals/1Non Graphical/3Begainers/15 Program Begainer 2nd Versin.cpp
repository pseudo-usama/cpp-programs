// 15 Program Begainer 2nd Versin.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int largest(int n[5]) {

	int i = 0, smallest;

	while (i < 5) {
		if (!i) { smallest = n[i]; }
		else if (n[i] < smallest) { smallest = n[i]; }

		i++;
	}
	return smallest;
}

struct CITY {

	char name[15];
	double population;
};

void cities(CITY city1, CITY city2) {

	if (city1.population < city2.population) { cout << "First city '" << city1.name << "' has less POPULATION of " << city1.population; }
	else if (city1.population > city2.population) { cout << "Second city '" << city2.name << "' has less POPULATION of " << city2.population; }
	else { cout << "Both cities have same POPULATION of " << city1.population; }
}

float ArrayReverse(float n[10]) {

	int i = 0, j = 9;
	float a[10];

	while (i < 10) {
		a[j] = n[i];

		i++;
		j--;
	}
	return a[10];
}

int ArrayAddition(int a[10], int b[10], int  result[10], int length) {

	int i = 0;

	while (i < length) {
		result[i] = a[i] + b[i];

		i++;
	}

	return result[10];
}

void Display(int n[5][5]) {

	int i = 0, j;

	while (i < 5) {
		j = 0;
		while (j < 5) {

			cout << n[i][j] << " ";
			j++;
		}
		cout << endl;
		i++;
	}
}

void ArrayDouble(int n[5][5]) {

	int i = 0, j;

	while (i < 5) {
		j = 0;
		while (j < 5) {
			n[i][j] *= 2;

			j++;
		}
		i++;
	}
	Display(n);
}



int main()
{
	int PriOpraSelector = 2, SecOpraSelector = 20;

	do{
		if (SecOpraSelector == 20)
		{
			cout << "                      List of Programs" << endl;
			cout << "To exit whole program enter    '0'." << endl;
			cout << "Or enter any number to rum that program" << endl;
			cout << "1) Largest number in ARRAY  2) Population of two cities        3) Count Zeros Even Odd in Number" << endl;
			cout << "4) Reverses Float ARRAY     5) Two ARRAYS                      6) Double the 2D ARRAY" << endl;
	
		}

		if (SecOpraSelector != 1)
		{
			cout << endl << endl;

			cout << "    Enter here the number     =  ";
			cin >> PriOpraSelector;

			while (PriOpraSelector < 0 || PriOpraSelector > 6)
			{
				cout << "Enter a number from '0' to '6'" << endl;
				cout << "    Enter here the number     =  ";
				cin >> PriOpraSelector;
			}
		}

		if (PriOpraSelector == 1)
		{
			int n[5], i = 0, answer;

			while (i < 5) {
				cout << "Enter the " << i + 1 << "'s number   = ";
				cin >> n[i];

				i++;
			}

			answer = largest(n);

			cout << endl << "The Largest number is  = " << answer;

		}
		else if (PriOpraSelector == 2)
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


		}
		else if (PriOpraSelector == 3)
		{
			float n[10];
			int i = 0;

			while (i < 10) {

				cout << "Enter the " << i + 1 << " number  = ";
				cin >> n[i];

				i++;
			}

			cout << endl << "Bofore reversing the array." << endl;

			i = 0;

			while (i < 10) {

				cout << endl << "The " << i + 1 << "'s number is  = " << n[i];
				i++;
			}

			n[10] = ArrayReverse(n);


			cout << endl << endl << "After reversing the Array the result is." << endl;

			i = 0;

			while (i < 10) {
				cout << endl << "The " << i + 1 << "'s number is  = " << n[i];
				i++;
			}

		}
		else if (PriOpraSelector == 4)
		{
			int a[10], b[10], i = 0, c[10] = { 0 }, result[10];

			while (i < 10) {

				cout << "Enter the " << i << "'s value of first ARRAY         = ";
				cin >> a[i];

				i++;
			}

			i = 0;
			cout << endl;

			while (i < 10) {

				cout << "Enter the " << i << "'s value value of Second ARRAY  = ";
				cin >> b[i];

				i++;
			}

			result[10] = ArrayAddition(a, b, c, 10);

			cout << endl << "By ADDITION them the result is" << endl << endl;

			i = 0;

			while (i < 10) {

				cout << "The " << i << "'s index number is   = " << result[i] << endl;

				i++;
			}


		}
		else if (PriOpraSelector == 5)
		{
			
			int a[10], b[10], i = 0, c[10] = { 0 }, result[10];

			while (i < 10) {

				cout << "Enter the " << i << "'s value of first ARRAY         = ";
				cin >> a[i];

				i++;
			}

			i = 0;
			cout << endl;

			while (i < 10) {

				cout << "Enter the " << i << "'s value value of Second ARRAY  = ";
				cin >> b[i];

				i++;
			}

			result[10] = ArrayAddition(a, b, c, 10);

			cout << endl << "By ADDITION them the result is" << endl << endl;

			i = 0;

			while (i < 10) {

				cout << "The " << i << "'s index number is   = " << result[i] << endl;

				i++;
			}


		}
		else if (PriOpraSelector == 6)
		{
			
			int n[5][5], i = 0, j;

			while (i < 5) {
				j = 0;
				while (j < 5) {

					cout << "Enter the " << i << "*" << j << "'s index number  = ";
					cin >> n[i][j];
					j++;
				}
				i++;
			}

			cout << endl << "The values before DOUBLING." << endl << endl;
			Display(n);

			cout << endl << "The values after DOUBLING." << endl << endl;
			ArrayDouble(n);


		}

	} while (PriOpraSelector != 0 && SecOpraSelector != 0);

	cout << endl;

	return 0;
}

