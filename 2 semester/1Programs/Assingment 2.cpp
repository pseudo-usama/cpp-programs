// Assingment 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"
using namespace std;

class Student{
private:
	string Name;
	string Email;
	string Id;
	
public:
	void Show(){
		cout << Name << endl;
		cout << Email << endl;
		cout << Id << endl;
	}

	Student(){													//Constructur with no ARRGUMENT
		 Name = "Ibrahim";
		 Email = "ibrahim@gmail.com";
		 Id = "17114119-046";
	}
	Student(string name, string email, string id){		//Costructur with three ARRGUMENTS
		Name = name;
		Email = email;
		Id = id;
	}
	Student(const Student &a){									//Copy Constructer
		Name = a.Name;
		Email = a.Email;
		Id =  a.Id;
	}
	~Student(){
		cout << "Destructur Called" << endl;
	}
};

int main()
{
	Student a;															//Object with no parameter
	a.Show();

	cout << endl;

	Student b("Usama", "buttusamaiftikhar@gmail.com", "17114119-005");	//Object with having parameter 
	b.Show();

	cout << endl;

	Student c = a;
	c.Show();

	cout << endl << endl;

	return 0;
}

