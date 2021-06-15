// Queue (Circular ARRAY).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

#define MAX 10

int Queue[MAX];
int Front = -1, Rear = -1;

bool Is_Empty() {
	if (Front == -1) { return(true ); }
	else             { return(false); }
}

bool Is_Full() {
	if ((Rear + 1) % MAX == Front) { return(true ); }
	else                           { return(false); }
}

void Enqueue(int Data) {
	if      (Is_Full() ) { cout << "Error! Queue is Full." << endl; }
	else if (Is_Empty()) { Front = Rear = 0;                        }
	else                 { Rear = (Rear + 1) % MAX;                 }

	Queue[Rear] = Data;
}

void Dequeue() {
	if      (Is_Empty()   ) { cout << "Error! Queue is Empty" << endl; }
	else if (Front == Rear) { Front = Rear = -1;                       }
	else                    { Front = (Front + 1) % MAX; }
}

void front()
{
	if (Front == -1) {
		cout << "Error: cannot return front from empty queue\n";
	}
	else {
		cout << "Data is  : " << Queue[Front] << endl;
	}
}
/*
Printing the elements in queue from front to rear.
This function is only to test the code.
This is not a standard function for Queue implementation.
*/
void Print()
{
	// Finding number of elements in queue  
	int count = (Rear + MAX - Front) % MAX + 1;
	cout << "Queue       : ";
	for (int i = 0; i <count; i++) {
		int index = (Front + i) % MAX; // Index of element while travesing circularly from front
		cout << Queue[index] << " ";
	}
	cout << "\n\n";
}

void main() {
	Dequeue();		Print();		//Queue     :			(Error)

	Enqueue(2);		Print();		//Queue     :2 
	Enqueue(3);		Print();		//Queue     :2 3 
	Enqueue(4);		Print();		//Queue     :2 3 4 

	front();		Print();		//Queue     :2 3 4 

	Dequeue();		Print();		//Queue     :2 3 
	Dequeue();		Print();		//Queue     :2 
	Dequeue();		Print();		//Queue     :
	Dequeue();		Print();		//Queue     :			(Error)

}

