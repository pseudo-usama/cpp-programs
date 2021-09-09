// Enter data in specific INDEX.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

void main() {
	int const L = 10;

	int Array[L];

	int Index, Length = 0, Option;
	
	do{
		cout << endl << endl;
		cout << "To enter Data     : 1" << endl;
		cout << "To Display Array  : 2" << endl;
		cout << "To Exit           : 0" << endl;
		cout << "Enter Option   : ";
		cin >> Option;

		cout << endl << endl;

		if (Option == 1) {
			if (Length != 10) {
				do
				{
					cout << "LENGTH of ARRAY is  " << Length << endl << "Enter Index to set value   : ";
					cin >> Index;
				} while (Index > Length);

				for (int i = Length; i > Index; i--)		//To shift the data to right
					Array[i] = Array[i - 1];

				Length++;

				cout << "Enter Data to Store   : ";
				cin >> Array[Index];							//Input data from user
			}
			else
				cout << "Sorry! Array is full.";
		}
		else if (Option == 2) {
			cout << endl << endl << "The Array is  :";

			for (int i = 0; i < Length; i++)				//Display Array
				cout << Array[i] << ", ";
		}
	} while (Option != 0);
}

