// Sidhu k dost ki Assignment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "conio.h"
using namespace std;

class BST {
private:
	struct Node {
	public:
		int ID;
		string Name;
		float Salary;
		Node* Right;
		Node* Left;

		//Constructor
		Node(int id, string name, float salary) : ID(id), Name(name), Salary(salary), Right(NULL), Left(NULL)
		{};
	};

	Node* Root;

	Node* Insert(int Id, string name, float salary, Node* Parent) {
		if (Parent == NULL) {
			Parent = new Node(Id, name, salary);
			cout << "Record successfully added.\n";
		}
		else if (Id < Parent->ID)
			Parent->Left = this->Insert(Id, name, salary, Parent->Left);
		else if (Id > Parent->ID)
			Parent->Right = this->Insert(Id, name, salary, Parent->Right);
		else
			cout << "Data already exist.\n";
		return(Parent);
	}
	void PostOrderTraversal(Node* Parent) {
		if (Parent != NULL) {
			this->PostOrderTraversal(Parent->Left);
			this->PostOrderTraversal(Parent->Right);

			cout << Parent->ID << "\t" << Parent->Name << "\t" << Parent->Salary << endl;
		}
	}
	void InOrderTraversal(Node* Parent) {
		if (Parent != NULL) {
			this->InOrderTraversal(Parent->Left);

			cout << Parent->ID << "\t" << Parent->Name << "\t" << Parent->Salary << endl;

			this->InOrderTraversal(Parent->Right);
		}
	}

public:
	void BuildBST() {
		int Id;
		string name;
		float salary;

	Again:

		cout << "\nEnter Employ ID      : ";
		cin >> Id;
		
		cout << "Enter Employ Salary  : ";
		cin >> salary;

		cout << "Enter Employ Name    : ";
		cin >> name;

		this->Root = this->Insert(Id, name, salary, Root);

		cout << "\nDo you want to enter another record! Press Y to continue\n";
		char selector = _getche();
		if (selector == 'y' || selector == 'Y')
			goto Again;
	}

	void PostOrder() {
		cout << "\n\n\n postOrder Traversal form:\n\nEmp Id\tName\tEmpSalary\n";

		this->PostOrderTraversal(this->Root);
	}

	void asscendingOrder() {
		cout << "\n\n\nSorted form of the data after traversing BST:\n\nEmp Id\tName\tEmpSalary\n";

		this->InOrderTraversal(this->Root);
	}

	BST() {	//Constructor
		//Defaut Data
		this->Root = this->Insert(32, "Raza", 3000, Root);
		this->Root = this->Insert(56, "Sajjad", 25000, Root);
		this->Root = this->Insert(93, "Rabia", 19230, Root);
		this->Root = this->Insert(5, "Sehar", 24000, Root);
		this->Root = this->Insert(10, "Ali", 22200, Root);
		system("cls");
	}
};

void main() {
	BST Ob;
	char selector;

	do {
		cout << "Press 1 to Enter Data.\n"
			<< "Press 2 to see the records in ascending Order.\n"
			<< "Press 3 to see the records in Post Order.\n"
			<< "Press 4 to exit\n";

		switch (_getche()) {
		case '1':
			Ob.BuildBST();
			break;
		case '2':
			Ob.asscendingOrder();
			break;
		case '3':
			Ob.PostOrder();
			break;
		case '4':
			exit(0);
			break;
		}

		cout << "\n\nDo you wnt to continue, Press Y to continue!!!";

		selector = _getche();
		cout << endl;
	} while (selector == 'y' || selector == 'Y');
}

