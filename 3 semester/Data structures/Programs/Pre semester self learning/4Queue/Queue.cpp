// Queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int Queue[10], Front = 0;

bool Is_Full() {
	if (Front == 10) { return(true);  }
	else             { return(false); }
}

bool Is_Empty() {
	if (Front == 0) { return(true);  }
	else            { return(false); }
}

void Enqueue(int Data) {
	if (Is_Full()) {
		cout << "Error.! Queue is Full." << endl;
	}
	else {
		Queue[Front] = Data;

		Front++;
	}
}

void Dequeue() {
	if (Is_Empty()) {
		cout << "Error.! Queue is Empty." << endl;
	}
	else {
		cout << "The Data is   = " << Queue[0] << endl;	

		Front--;

		for (int i = 0; i < Front; i++) {
			Queue[i] = Queue[i + 1];
		}
	}
}

void main() {
	do{
		int Selector;

		cout << "Enque ---------> 1" << endl;
		cout << "Deque ---------> 2" << endl;
		cout << "Exit  ---------> 0" << endl;

		cout << "Enter here    = ";
		cin >> Selector;

		if(Selector == 1) { 
			int Data;
			cout << "Enter Data to Enqueue   = ";
			cin >> Data;

			Enqueue(Data);
		}
		else if (Selector == 2) { Dequeue(); }
		else if (Selector == 0) { exit(0);   }
	} while (true);
}

