// Assignemt 3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"
using namespace std;

class Item {
private:
	string BarCode;
	string ItemName;

public:
	void SetBarCode() {
		cout << "Enter Bar Code                = ";
		cin >> BarCode;
	}
	void GetBarCode() {
		cout << "Bar Code is                   = " << BarCode << endl;
	}
	void Scanner() {
		SetBarCode();
		
		cout << "Enter Item Name               = ";
		cin >> ItemName;
	}
	void Printer() {
		GetBarCode();

		cout << "Item Name is                  = " << ItemName << endl;
	}

	Item(string Bar_Code, string Item_Name) :BarCode(Bar_Code), ItemName(Item_Name) {}		//Parameterizwd Constructor
	Item() :BarCode("\0"), ItemName("\0") {}												//Default Constructor
};

class PackedFood :public Item{
private:
	float PricePerPiece;

public:
	void SetPrice() {
		cout << "Enter the Price per Packet    = ";
		cin >> PricePerPiece;
	}
	void GetPrice() {
		cout << "Price per Packet              = " << PricePerPiece << endl;
	}
	void Scanner() {
		SetPrice();
	}
	void Printer() {
		GetPrice();
	}

	PackedFood(float Price_Per_Piece) :PricePerPiece(Price_Per_Piece) {}
	PackedFood() :PricePerPiece(0.0) {}
};

class FreshFood :public Item{
private:
	float Weight;
	float PricePerKG;

public:
	void SetWeight() {
		cout << "Enter Weight in KG            = ";
		cin >> Weight;
	}
	void GetWeight() {
		cout << "Weight in KG                  = " << Weight << endl;
	}
	void Scanner() {
		SetWeight();
		
		cout << "Enter Price per KG            = ";
		cin >> PricePerKG;
	}
	void Printer() {
		GetWeight();

		cout << "Price per KG                  = " << PricePerKG << endl;
	}

	FreshFood(float _Weight, float Price_Per_KG) :Weight(_Weight), PricePerKG(Price_Per_KG) {}
	FreshFood() :Weight(0.0), PricePerKG(0.0) {}
};

void main() {
	cout << "Enter values for Item object (Parameterized)" << endl << endl;
	Item Item_ob("A2fe8", "Meat");												//Parameterized Object
	Item_ob.Scanner();
	cout << endl << "Entered values are:" << endl;
	Item_ob.Printer();

	cout << endl << endl;

	cout << "Enter values for Item object (Non Parameterized)" << endl << endl;
	Item Item_ob1;																//Non parameterized Object
	Item_ob1.Scanner();
	cout << endl << "Entered values are:" << endl;
	Item_ob1.Printer();

	cout << endl << endl << endl;
	
	cout << "Enter values for Packed Item object (Parameterized)" << endl << endl;
	PackedFood PackedFood_Ob(0.0);												//Parameterized Object
	PackedFood_Ob.Scanner();
	cout << endl << "Entered values are:" << endl;
	PackedFood_Ob.Printer();

	cout << endl << endl;
	
	cout << "Enter values for Packed Item object (Non Parameterized)" << endl << endl;
	PackedFood PackedFood_Ob1;													//Non Parameterized Object
	PackedFood_Ob1.Scanner();
	cout << endl << "Entered values are:" << endl;
	PackedFood_Ob1.Printer();

	cout << endl << endl << endl;

	cout << "Enter values for Fresh Item object (Parameterized)" << endl << endl;
	FreshFood FreeshFood_ob(0.0, 0.0);											//Parameterized Object
	FreeshFood_ob.Scanner();
	cout << "Entered values are:" << endl;
	FreeshFood_ob.Printer();

	cout << endl << endl;
	
	cout << "Enter values for Fresh Item object (Non Parameterized)" << endl << endl;
	FreshFood FreeshFood_ob1(0.0, 0.0);											//Non Parameterized Object
	FreeshFood_ob1.Scanner();
	cout << "Entered values are:" << endl;
	FreeshFood_ob1.Printer();
}