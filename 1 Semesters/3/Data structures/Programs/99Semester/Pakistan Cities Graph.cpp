// Pakistan Cities Graph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "stack"
using namespace std;


class CitiesNetwork {
private:
	class Link {
	public:
		string CityName;
		int Distance;
		Link *Next;
	};

	class City {
	public:
		string Name;
		Link *Connections;
	};

public:

	string Country;
	City *Capital;

	void CitiesNetwork::NewCity();		//Creates new city
	void CitiesNetwork::DisplayAll();	//Diplay all Cities

	//Constructor
	CitiesNetwork::CitiesNetwork();
};

void main() {
	CitiesNetwork Ob;

	Ob.DisplayAll();
}

void CitiesNetwork::NewCity() {

}

void CitiesNetwork::DisplayAll() {
	Link *temp;
	stack<Link*> stck;

	cout << "Name   : " << Capital->Name << endl;

	if (this->Capital->Connections != NULL) {
		stck.push(Capital->Connections);

		while (!stck.empty()) {
			temp = stck.top;
			stck.pop();
			cout << "Name   : " << temp->CityName << endl;

			if (temp->Next != NULL)
				stck.push(temp->Next);
		}
	}
}

CitiesNetwork::CitiesNetwork() {	//Constructor
	cout << "Enter Country Name   : ";
	cin >> this->Country;

	Capital = new City;

	cout << "Enter Capital Name   : ";
	cin >> this->Capital->Name;

	this->Capital->Connections = NULL;
}