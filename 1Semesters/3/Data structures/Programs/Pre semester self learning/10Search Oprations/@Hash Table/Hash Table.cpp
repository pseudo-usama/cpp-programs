// Hash Table.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"
using namespace std;

class Hash {
private:
	static const int TableSize = 10;

	struct Item {
		string Name;
		string Drink;

		Item *Next;
	};

	Item *HashTable[TableSize];

private:
	int Get_Index(string Key);

public:
	void Add_Item(string _Name, string _Drink);
	int Length_of_Index(int Index);
	void Print_Table();
	void Search(string _Name);
	void Delete(string _Name);

	Hash();
};

void main() {
	Hash Ob;

	//Ob.Add_Item("Usama", "Milk");
	cout << Ob.Length_of_Index(5);
	Ob.Print_Table();
}

int Hash::Get_Index(string Key) {
	int Hash = 0;
	int L = Key.length();

	for (int i = 0; i < L; i++) {
		Hash += (int)Key[i];
	}
	return(Hash % TableSize);
}

void Hash::Add_Item(string _Name, string _Drink) {
	int Index = Get_Index(_Name);

	Item *NewNode = new Item;

	NewNode->Name = _Name;
	NewNode->Drink = _Drink;
	NewNode->Next = NULL;

	Item *Temp = HashTable[Index];

	if (Temp == NULL) {
		cout << Temp->Next<<endl;
	}
	else {
		while (Temp->Next != NULL) {
			Temp = Temp->Next;
		}
		Temp->Next = NewNode;
	}
}

int Hash::Length_of_Index(int Index) {
	if (HashTable[Index] == NULL) { return(0); }

	int Length = 0;

	Item *Temp = HashTable[Index];

	while (Temp->Next != NULL) {
		Temp = Temp->Next;

		Length++;
	}
	return(Length);
}

void Hash::Print_Table() {
	Item *Temp;

	for (int i = 0; i < TableSize; i++) {
		Temp = HashTable[i];

		cout << "Index no. : " << i << endl;

		while (Temp != NULL) {
			cout << "-----------------------------" << endl;
			cout << "Drink  : " << Temp->Drink << endl;
			cout << "Name  : " << Temp->Name << endl;

			Temp = Temp->Next;
		}
		cout << "=============================" << endl;
		cout << "=============================" << endl;
	}
}

void Hash::Search(string _Name) {
	int Index = Get_Index(_Name);

	Item *Temp = HashTable[Index];

	while (Temp != NULL) {
		if (_Name == Temp->Name) {
			cout << _Name << "'s drink is " << Temp->Drink << endl;

			return;
		}
		Temp = Temp->Next;
	}
	cout << "Sorry! " << _Name << "'s drink not found." << endl;
}

void Hash::Delete(string _Name) {
	int Index = Get_Index(_Name);

	if (HashTable[Index] == NULL) { cout << "Error! " << _Name << " not found." << endl; return; }
	
	if (HashTable[Index]->Next == NULL) {
		if (HashTable[Index]->Name == _Name) {
			delete(HashTable[Index]);
			HashTable[Index] = NULL;
		}
		else {
			cout << "Error! " << _Name << " not found." << endl;
		}
		return;
	}
	else if (HashTable[Index]->Name == _Name) {
		Item *Temp = HashTable[Index];

		HashTable[Index]->Next = HashTable[Index]->Next->Next;

		delete(Temp);
	}
	else {
		Item *Temp1 = HashTable[Index];
		Item *Temp2;

		while (true) {
			if (Temp1->Next != NULL) {
				Temp2 = Temp1;
				Temp1 = Temp1->Next;

				if (Temp1->Name == _Name) {
					Temp2->Next = Temp1->Next;

					delete(Temp1);
				}
			}
			else { break; }
		}
		cout << "Error! " << _Name << " not found." << endl;
	}
}

Hash::Hash() {
	for (int i = 0; i < TableSize; i++) {
		HashTable[i] = NULL;
	}
}