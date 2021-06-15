// Hotel Managment(Ousaf).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "fstream"
#include "windows.h"
#include "conio.h"
using namespace std;

string FileDirectory = "D://";	//Path where Files will save data

string FirstName;
string LastName;
string Age;
string Gender;
string BloodGroup;
string Number;
string Addrees;
string RoomNo;
string ID;

void Insert();			//Insert Data in File
void ShowAllData();		//Print all the Data
void Delete();			//Delete Specific Data
void Search();			//Search data with ID
void Update();			//Edit the data of any Person

void main() {
	do {
		system("cls");
		cout << "Press an Option number\n"
			<< "1. Insert Data\n"
			<< "2. Show all Data\n"
			<< "3. Search Data\n"
			<< "4. Update Data\n"
			<< "5. Delete Data\n"
			<< "6. Exit\n";

		switch (_getch()) {
		case '1':
			Insert();
			break;
		case '2':
			ShowAllData();
			break;
		case '3':
			Search();
			break;
		case '4':
			Update();
			break;
		case '5':
			Delete();
			break;
		case '6':
			exit(0);
			break;
		}
	} while (true);
}

void Insert() {
	system("cls");

	//First we Input Data from USER
	cout << "Enter First Name        : ";
	getline(cin, FirstName);

	cout << "Enter Last Name         : ";
	getline(cin, LastName);

	cout << "Enter your Age          : ";
	getline(cin, Age);

	cout << "Enter your Gender       : ";
	getline(cin, Gender);

	cout << "Enter your Blood Group  : ";
	getline(cin, BloodGroup);

	cout << "Enter your Number       : ";
	getline(cin, Number);

	cout << "Enter yout Addrees      : ";
	getline(cin, Addrees);

	//Now we will Generate User Uniqe ID and its Room No

	//Creating and saving Room No
	int RoomNotemp = 0;
	ifstream Read;
	Read.open(FileDirectory + "Room.txt", ios::in);
	Read >> RoomNotemp;
	Read.close();

	RoomNotemp++;
	RoomNo = to_string(RoomNotemp);

	int temp = 0;
	Read.open(FileDirectory + "ID.txt", ios::in);
	Read >> temp;
	Read.close();

	temp++;

	ID = "Carena" + to_string(temp);

	system("cls");
	cout << "Your Room No is         : " << RoomNo << endl;
	cout << "Your unique ID is       : " << ID << endl;
	system("pause");

	//Now we Save Data into File
	ofstream Write;
	Write.open(FileDirectory + "Recordes.txt", ios::app);

	Write << endl << endl << FirstName << endl << LastName << endl << Age << endl << Gender << endl << BloodGroup << endl << Number << endl << Addrees << endl << RoomNo << endl << ID;
	Write.close();

	Write.open(FileDirectory + "Room.txt");
	Write << RoomNo;
	Write.close();

	Write.open(FileDirectory + "ID.txt");
	Write << temp;
	Write.close();
}

void ShowAllData() {
	system("cls");

	ifstream Read;
	Read.open(FileDirectory + "Recordes.txt");
	string temp;

	getline(Read, temp);

	while (!Read.eof()) {
		//First we read data from file
		getline(Read, temp);
		getline(Read, FirstName);
		getline(Read, LastName);
		getline(Read, Age);
		getline(Read, Gender);
		getline(Read, BloodGroup);
		getline(Read, Number);
		getline(Read, Addrees);
		getline(Read, RoomNo);
		getline(Read, ID);

		cout << "First Name              : " << FirstName << endl;
		cout << "Last Name               : " << LastName << endl;
		cout << "Age                     : " << Age << endl;
		cout << "Gender                  : " << Gender << endl;
		cout << "Blood Group             : " << BloodGroup << endl;
		cout << "Number                  : " << Number << endl;
		cout << "Addrees                 : " << Addrees << endl;
		cout << "Room No                 : " << RoomNo << endl;
		cout << "ID                      : " << ID << endl << endl;
	}

	cout << endl;
	system("pause");
}

void Search() {
	system("cls");

	string id, temp;

	cout << "Enter ID to search      : ";
	getline(cin, id);

	ifstream Read;
	Read.open(FileDirectory + "Recordes.txt", ios::in);

	getline(Read, temp);

	while (!Read.eof()) {
		getline(Read, temp);
		getline(Read, FirstName);
		getline(Read, LastName);
		getline(Read, Age);
		getline(Read, Gender);
		getline(Read, BloodGroup);
		getline(Read, Number);
		getline(Read, Addrees);
		getline(Read, RoomNo);
		getline(Read, ID);

		if (id == ID) {
			cout << endl << "First Name              : " << FirstName << endl;
			cout << "Last Name               : " << LastName << endl;
			cout << "Age                     : " << Age << endl;
			cout << "Gender                  : " << Gender << endl;
			cout << "Blood Group             : " << BloodGroup << endl;
			cout << "Number                  : " << Number << endl;
			cout << "Addrees                 : " << Addrees << endl;
			cout << "Room No                 : " << RoomNo << endl;
			cout << "ID                      : " << ID << endl << endl;

			system("pause");
			return;
		}
	}
	cout << "Sorry data not found.\n";
	system("pause");
}

void Delete() {
	system("cls");

	string id, temp;
	bool Data_Not_Found = true;

	cout << "Enter ID to delete      : ";
	getline(cin, id);

	ifstream Read;
	Read.open(FileDirectory + "Recordes.txt", ios::in);
	ofstream Write;
	Write.open(FileDirectory + "temp.txt");

	getline(Read, temp);

	while (!Read.eof()) {
		getline(Read, temp);
		getline(Read, FirstName);
		getline(Read, LastName);
		getline(Read, Age);
		getline(Read, Gender);
		getline(Read, BloodGroup);
		getline(Read, Number);
		getline(Read, Addrees);
		getline(Read, RoomNo);
		getline(Read, ID);

		if (id != ID) {
			Write << endl << endl;
			Write << FirstName << endl;
			Write << LastName << endl;
			Write << Age << endl;
			Write << Gender << endl;
			Write << BloodGroup << endl;
			Write << Number << endl;
			Write << Addrees << endl;
			Write << RoomNo << endl;
			Write << ID;
		}
		else
			Data_Not_Found = false;
	}

	Read.close();
	Write.close();

	if (Data_Not_Found) {
		cout << "Sorry! Data not Found.\n";
		system("pause");
		return;
	}

	Read.open(FileDirectory + "temp.txt", ios::in);
	Write.open(FileDirectory + "Recordes.txt", ios::out);

	getline(Read, temp);

	while (!Read.eof()) {
		getline(Read, temp);
		getline(Read, FirstName);
		getline(Read, LastName);
		getline(Read, Age);
		getline(Read, Gender);
		getline(Read, BloodGroup);
		getline(Read, Number);
		getline(Read, Addrees);
		getline(Read, RoomNo);
		getline(Read, ID);

		Write << endl << endl;
		Write << FirstName << endl;
		Write << LastName << endl;
		Write << Age << endl;
		Write << Gender << endl;
		Write << BloodGroup << endl;
		Write << Number << endl;
		Write << Addrees << endl;
		Write << RoomNo << endl;
		Write << ID;
	}
	Read.close();
	Write.close();

	cout << "Data updated sacssesfully.\n";
	system("pause");
}

void Update() {
	system("cls");

	string id, temp;
	bool Data_Not_Found = true;

	cout << "Enter ID to Update      : ";
	getline(cin, id);

	ifstream Read;
	Read.open(FileDirectory + "Recordes.txt", ios::in);
	ofstream Write;
	Write.open(FileDirectory + "temp.txt");

	getline(Read, temp);

	while (!Read.eof()) {
		getline(Read, temp);
		getline(Read, FirstName);
		getline(Read, LastName);
		getline(Read, Age);
		getline(Read, Gender);
		getline(Read, BloodGroup);
		getline(Read, Number);
		getline(Read, Addrees);
		getline(Read, RoomNo);
		getline(Read, ID);

		if (id == ID) {
			cout << "Enter First Name        : ";
			getline(cin, FirstName);

			cout << "Enter Last Name         : ";
			getline(cin, LastName);

			cout << "Enter your Age          : ";
			getline(cin, Age);

			cout << "Enter your Gender       : ";
			getline(cin, Gender);

			cout << "Enter your Blood Group  : ";
			getline(cin, BloodGroup);

			cout << "Enter your Number       : ";
			getline(cin, Number);

			cout << "Enter your Addrees      : ";
			getline(cin, Addrees);

			Data_Not_Found = false;
		}

		Write << endl << endl;
		Write << FirstName << endl;
		Write << LastName << endl;
		Write << Age << endl;
		Write << Gender << endl;
		Write << BloodGroup << endl;
		Write << Number << endl;
		Write << Addrees << endl;
		Write << RoomNo << endl;
		Write << ID;
	}

	Read.close();
	Write.close();

	if (Data_Not_Found) {
		cout << "Sorry! Data not Found.\n";
		system("pause");
		return;
	}

	Read.open(FileDirectory + "temp.txt", ios::in);
	Write.open(FileDirectory + "Recordes.txt", ios::out);

	getline(Read, temp);

	while (!Read.eof()) {
		getline(Read, temp);
		getline(Read, FirstName);
		getline(Read, LastName);
		getline(Read, Age);
		getline(Read, Gender);
		getline(Read, BloodGroup);
		getline(Read, Number);
		getline(Read, Addrees);
		getline(Read, RoomNo);
		getline(Read, ID);

		Write << endl << endl;
		Write << FirstName << endl;
		Write << LastName << endl;
		Write << Age << endl;
		Write << Gender << endl;
		Write << BloodGroup << endl;
		Write << Number << endl;
		Write << Addrees << endl;
		Write << RoomNo << endl;
		Write << ID;
	}
	Read.close();
	Write.close();

	cout << "Data updated sacssesfully.\n";
	system("pause");
}