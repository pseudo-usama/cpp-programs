// Linked List Full (Asnmnt 2).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "windows.h"
#include "conio.h"
using namespace std;

class LinkedList {
private:
	class Node {
	public:
		int Data;
		Node *Next;

		Node(int _Data) {
			this->Data = _Data;
			this->Next = NULL;
		}
	};

	Node *Head;

public:
	//Insert Functions
	void LinkedList::Insert_atStart(int _Data);
	void LinkedList::Insert_atEnd(int _Data);
	void LinkedList::Insert_at_nth(int _Data, int n);
	//Delete Functions
	void LinkedList::Delete_atStart();
	void LinkedList::Delete_atEnd();
	void LinkedList::Delete_at_nth(int n);

	void LinkedList::Display();

	int LinkedList::Size();

	LinkedList::LinkedList();
};

void main() {
	char Option;
	int a, l;
	LinkedList List;

	do {
		system("cls");
		cout << "Select an Option.\n"
			<< "1. Insert at Start.\n"
			<< "2. Insert at End.\n"
			<< "3. Insert at Specific Location.\n"
			<< "4. Delete at Start.\n"
			<< "5. Delete at End.\n"
			<< "6. Delete at Specific Location.\n"
			<< "7. Display Linked List.\n"
			<< "8. Size of Linked List.\n"
			<< "9. Exit.\n";

		Option = _getch();
		system("cls");

		switch (Option)
		{
		case '1':	//Insert at Start
			cout << "Insertion at Start\n"
				<< "Enter a number to Insert   : ";
			cin >> a;

			List.Insert_atStart(a);
			break;
		case '2':	//Insert at End
			cout << "Insertion at End\n"
				<< "Enter a number to Insert    : ";
			cin >> a;

			List.Insert_atEnd(a);
			break;
		case '3':	//Insert at Specific Location
			cout << "Insertion at Specific Location\n"
				<< "Enter a number to Insert    : ";
			cin >> a;

			cout << "Enter the Location         : ";
			cin >> l;

			List.Insert_at_nth(a, l);
			break;
		case '4':	//Delete at Start
			List.Delete_atStart();
			break;
		case '5':	//Delete at End
			List.Delete_atEnd();
			break;
		case '6':
			cout << "Deletion at Specific Location.\n"
				<< "Enter a Location to Delete :";
			cin >> l;

			List.Delete_at_nth(l);
			break;
		case '7':
			List.Display();
			system("pause");
			break;
		case '8':
			cout << "Size of Linked List is  : " << List.Size() << endl;
			system("pause");
			break;
		}

		if (Option > '0' && Option < '7')
			Sleep(1500);

	} while (Option != '9');
}

void LinkedList::Insert_atStart(int _Data) {
	Node *NewNode = new Node(_Data);

	NewNode->Next = Head;
	Head = NewNode;

	system("cls");
	cout << "Node inserted successfully.\n";
}

void LinkedList::Insert_atEnd(int _Data) {
	Node *NewNode = new Node(_Data);

	if (Head == NULL) {
		NewNode->Next = Head;
		Head = NewNode;
	}
	else {
		Node *temp = Head;
		while (temp->Next != NULL)
			temp = temp->Next;
		temp->Next = NewNode;
	}
	system("cls");
	cout << "Node inserted successfully.\n";
}

void LinkedList::Insert_at_nth(int _Data, int n) {
	if (n < 1)
		cout << "Error! Location can't less then one.\n";
	else if (n > this->Size() + 1)
		cout << "Error! Location does not exist.\n";
	else if (n == 1)
		this->Insert_atStart(_Data);
	else if (n == this->Size() + 1)
		this->Insert_atEnd(_Data);
	else {
		Node *NewNode = new Node(_Data);
		Node *temp = Head;

		for (int i = 2; i < n; i++)
			temp = temp->Next;

		NewNode->Next = temp->Next;
		temp->Next = NewNode;

		system("cls");
		cout << "Node inserted successfully.\n";
	}
}

void LinkedList::Delete_atStart() {
	if (Head != NULL) {
		Node *To_beDeleted = Head;

		Head = Head->Next;

		delete(To_beDeleted);

		system("cls");
		cout << "Node deleted successfully.\n";
	}
	else
		cout << "Error! Linked List is empty.\n";
}

void LinkedList::Delete_atEnd() {
	if (Head != NULL) {
		if (Head->Next == NULL) {
			delete(Head);
			Head = NULL;
		}
		else {
			Node *temp = Head;

			while (temp->Next->Next != NULL)
				temp = temp->Next;

			delete(temp->Next);
			temp->Next = NULL;
		}
		system("cls");
		cout << "Node deleted successfully.\n";
	}
	else
		cout << "Error! Linked List is empty.\n";
}

void LinkedList::Delete_at_nth(int n) {
	if (Head == NULL)
		cout << "Error! Linked List is empty.\n";
	else if (n < 1)
		cout << "Error! Location can't less then one.\n";
	else if (n > this->Size())
		cout << "Error! Location does not exist.\n";
	else if (n == 1)
		this->Delete_atStart();
	else if (n == this->Size())
		this->Delete_atEnd();
	else {
		Node *temp = Head;

		for (int i = 2; i < n; i++)
			temp = temp->Next;

		Node *To_beDeleted = temp->Next;

		temp->Next = temp->Next->Next;

		delete(To_beDeleted);

		system("cls");
		cout << "Node deleted successfully.\n";
	}
}

void LinkedList::Display() {
	Node *temp = Head;

	cout << "Linked List is   : ";

	while (temp != NULL) {
		cout << temp->Data << ", ";
		temp = temp->Next;
	}
	cout << endl;
}

int LinkedList::Size() {
	int Size = 0;
	Node *temp = Head;

	while (temp != NULL) {
		Size++;
		temp = temp->Next;
	}
	return(Size);
}

LinkedList::LinkedList() {
	Head = NULL;
}