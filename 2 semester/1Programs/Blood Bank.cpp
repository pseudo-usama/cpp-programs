// Blood Bank.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "conio.h"
#include "stdio.h"
#include "fstream"
using namespace std;

char MainFn();
char ViewerFn();
char SearchFn();
char EnterDataFn();

class BloodBank{
private:
	string Name;
	string Age; 
	string IdCard;
	string Number;
	string Addrees;
	string Email;

public:
	void Put();
	void ShowAllData();
	void Search();
	void Edit();

	BloodBank(){
		Name = '\0';
		Age = '\0';
		Number = '\0';
		Addrees = '\0';
		Email = '\0';
	}
	~BloodBank(){
		Name = '\0';
		Age = '\0';
		Number = '\0';
		Addrees = '\0';
		Email = '\0';
	}
};

void main(){
	char selector = 'm';

	for (;;){
		if      (selector == 'm') { selector = MainFn(); }
		else if (selector == 'e') { selector = EnterDataFn(); }
		else if (selector == 'v') { selector = ViewerFn(); }
		else if (selector == 's') { selector = SearchFn(); }
	}
}

char MainFn(){
	system("CLS");

	char selector;
	
	cout << "Select Option" << endl;
	cout << "1) View Whole Data" << endl;
	cout << "2) Enter new Data" << endl;
	cout << "3) Search any Person" << endl;

	AGAIN:
	selector = _getche();
	if (selector != '1'&&selector != '2'&&selector!='3') { goto AGAIN; }
	
	if      (selector == '1') { selector = 'v'; }
	else if (selector == '2') { selector = 'e'; }
	else if (selector == '3') { selector = 's'; }

	return selector;
}

char ViewerFn(){
	char selector;

	BloodBank ob;

	ob.ShowAllData();
	
	cout << endl << endl << "1) Main Manu" << endl;

	AGAIN:
	selector = _getche();
	if (selector != '1') { goto AGAIN; }

	if (selector == '1') { selector = 'm'; }

	return selector;
}

char EnterDataFn(){
	system("CLS");

	BloodBank ob;
	ob.Put();

	return 'm';
}

char SearchFn(){
	char selector;

	system("CLS");

	BloodBank ob;
	ob.Search();

	cout << endl << endl << "1) Main Manu" << endl;

	AGAIN:
	selector = _getche();
	if (selector != '1') { goto AGAIN; }

	if (selector == '1') { selector = 'm'; }

	return selector;
}

void BloodBank::Put(){
	char selector;
	string Group;

	cout << "Enter your Name            = ";
	cin >> Name;

	cout << "Enter your Age             = ";
	cin >> Age;

	cout << "Enter your Id Card number  = ";
	cin >> IdCard;

	cout << "Enter your Number          = ";
	cin >> Number;

	cout << "Enter your Address         = ";
	cin >> Addrees;

	cout << "Enter your Email           = ";
	cin >> Email;

	cout << "Select your Blood Groud" << endl;
	cout << "1) A+    2) A-    3) B+    4) B-" << endl;
	cout << "5) AB+   6) AB-   7) O+    8) O-" << endl;

	AGAIN:
	selector = _getche();
	if (selector<'1' || selector >'8') { goto AGAIN; }

	if      (selector == '1') { Group = "A+.txt" ; }
	else if (selector == '2') { Group = "A-.txt" ; }
	else if (selector == '3') { Group = "B+.txt" ; }
	else if (selector == '4') { Group = "B-.txt" ; }
	else if (selector == '5') { Group = "AB+.txt"; }
	else if (selector == '6') { Group = "AB-.txt"; }
	else if (selector == '7') { Group = "O+.txt" ; }
	else if (selector == '8') { Group = "O-.txt" ; }

	ofstream ob;
	ob.open(Group, ios::app);

	ob << Name << endl;
	ob << Age << endl;
	ob << IdCard << endl;
	ob << Number << endl;
	ob << Addrees << endl;
	ob << Email << endl;
	ob << '.' << endl;

	ob.close();
	}

void BloodBank::ShowAllData(){
	char selector;
	string Group;

	system("CLS");
	

	
	cout << "Select Blood Groud" << endl;
	cout << "1) A+    2) A-    3) B+    4) B-" << endl;
	cout << "5) AB+   6) AB-   7) O+    8) O-" << endl;

	AGAIN:
	selector = _getche();
	if (selector<'1' || selector >'8') { goto AGAIN; }

	if (selector == '1') { Group = "A+.txt"; }
	else if (selector == '2') { Group = "A-.txt"; }
	else if (selector == '3') { Group = "B+.txt"; }
	else if (selector == '4') { Group = "B-.txt"; }
	else if (selector == '5') { Group = "AB+.txt"; }
	else if (selector == '6') { Group = "AB-.txt"; }
	else if (selector == '7') { Group = "O+.txt"; }
	else if (selector == '8') { Group = "O-.txt"; }
		
	system("CLS");

	cout << "Peoples having " << Group << " are" << endl << endl;

	ifstream ob;
	ob.open(Group, ios::in);
	while (!ob.eof()){
		ob >> Name;
		ob >> Age;
		ob >> IdCard;
		ob >> Number;
		ob >> Addrees;
		ob >> Email;
		ob >> selector;

		cout << "Name                       = " << Name << endl;			
		cout << "Age                        = " << Age << endl;
		cout << "Id Card number             = " << IdCard << endl;
		cout << "Number                     = " << Number << endl;
		cout << "Address                    = " << Addrees << endl;
		cout << "Email                      = " << Email << endl;
							
		ob.close();

		cout << endl;
	}
}

void BloodBank::Search(){
	
	string Group, Searcher, selector;
	int decider = 0;

	system("CLS");

	cout << "Enter Id Card Number       = ";
	cin >> Searcher;

	system("CLS");

	ifstream ob;

	for (int i = 1; i<9; i++){
		if (i == 1)      { Group = "A+.txt"; }
		else if (i == 2) { Group = "A-.txt"; }
		else if (i == 3) { Group = "B+.txt"; }
		else if (i == 4) { Group = "B-.txt"; }
		else if (i == 5) { Group = "AB+.txt"; }
		else if (i == 6) { Group = "AB-.txt"; }
		else if (i == 7) { Group = "O+.txt"; }
		else if (i == 8) { Group = "O-.txt"; }
				
		ob.open(Group, ios::in);
		
		while (!ob.eof()){
			ob >> Name;
			ob >> Age;
			ob >> IdCard;
			ob >> Number;
			ob >> Addrees;
			ob >> Email;
			ob >> selector;

		if (Searcher == IdCard){
				cout << "Name                       = " << Name << endl;
				cout << "Age                        = " << Age << endl;
				cout << "Id Card number             = " << IdCard << endl;
				cout << "Number                     = " << Number << endl;
				cout << "Address                    = " << Addrees << endl;
				cout << "Email                      = " << Email << endl;
				
				decider = 1;
				break;
			}
		}
		ob.close();

		if (decider) { break; }
	}
}

void BloodBank::Edit(){
	char selector;
	string Group, Searcher;
	int decider = 0;

	system("CLS");

	cout << "Enter Id Card Number       = ";
	cin >> Searcher;

	system("CLS");

	ifstream ob;

	for (int i = 1; i<9; i++){
		if (i == 1)      { Group = "A+.txt"; }
		else if (i == 2) { Group = "A-.txt"; }
		else if (i == 3) { Group = "B+.txt"; }
		else if (i == 4) { Group = "B-.txt"; }
		else if (i == 5) { Group = "AB+.txt"; }
		else if (i == 6) { Group = "AB-.txt"; }
		else if (i == 7) { Group = "O+.txt"; }
		else if (i == 8) { Group = "O-.txt"; }


		ob.open(Group, ios::in);

		while (!ob.eof()){
			ob >> Name;
			ob >> Age;
			ob >> IdCard;
			ob >> Number;
			ob >> Addrees;
			ob >> Email;
			ob >> selector;

			if (Searcher == IdCard){
				cout << "Name                       = " << Name << endl;
				cout << "Age                        = " << Age << endl;
				cout << "Id Card number             = " << IdCard << endl;
				cout << "Number                     = " << Number << endl;
				cout << "Address                    = " << Addrees << endl;
				cout << "Email                      = " << Email << endl;

				decider = 1;
				break;
			}
			cout << "asd" << endl;
		}
		ob.close();

		cout << "for" << endl;

		if (decider) { break; }
	}
}