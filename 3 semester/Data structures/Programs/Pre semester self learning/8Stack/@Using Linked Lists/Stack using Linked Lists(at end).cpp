// Stack using Linked Lists(at end).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

class Stack {		//My method
private:
	int Data;
	Stack *Prev;

	Stack *top;

public:
	Stack() {
		top = NULL;
	}

	void Push(int _Data) {
		Stack *NewNode = new Stack;

		NewNode->Data = _Data;
		NewNode->Prev = top;
		top = NewNode;
	}

	void Pop() {
		if (top == NULL) {
			cout << "Error! Stack is Empty." << endl;
		}
		else {
			Stack *Temp = top;

			top = top->Prev;

			delete Temp;
		}
	}

	int Top() {
		return(top->Data);
	}

	void Print() {		//This Print Functin is not neccesry in implementation of Stack its just for to see Stack
		Stack *Temp = top;

		cout << "Stack is  : ";

		while (Temp != NULL) {
			cout << Temp->Data;
			Temp = Temp->Prev;
		}
		cout << endl;
	}
};

void main() {
	Stack Ob;

	Ob.Pop();		Ob.Print();		//Stack is  :		(Error)

	Ob.Push(1);		Ob.Print();		//Stact is  : 1 
	Ob.Push(2);		Ob.Print();		//Stact is  : 2 1 
	Ob.Push(3);		Ob.Print();		//Stact is  : 3 2 1 

	Ob.Pop();		Ob.Print();		//Stact is  : 2 1 

	Ob.Top();		Ob.Print();		//Stact is  : 2 1 
	Ob.Top();		Ob.Print();		//Stact is  : 2 1 

	Ob.Pop();		Ob.Print();		//Stact is  : 1 
	Ob.Pop();		Ob.Print();		//Stact is  : 
	Ob.Pop();		Ob.Print();		//Stact is  :		(Error)  


	Ob.Push(-1);	Ob.Print();		//Stact is  : -1
}



