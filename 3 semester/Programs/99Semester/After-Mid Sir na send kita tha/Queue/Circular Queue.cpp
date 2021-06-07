#include <iostream>
#define SIZE 10
using namespace std;

class CircularQueue{
	int cQueue[SIZE];
	int front, rear;
	
	public:
		
	CircularQueue(){
		front = rear = -1;
	}
	
	void enQueue(int val) {
   		if ((front == 0 && rear == SIZE-1) || (front == rear+1)) {
      		cout<<"Queue Overflow \n\n";
      		return;
   		}
   		if (front == -1) {
      		front = 0;
      		rear = 0;
   		} 
		else {
      		if (rear == SIZE-1)
      			rear = 0;
      		else
      			rear++;
   		}
   		cQueue[rear] = val;
   		cout << "Value enQueued\n\n";
	}
	
	void deQueue() {
   		if (front == -1) {
      		cout<<"Queue Underflow\n\n";
      		return ;
   		}
   		cout<<"Element deleted from queue is : "<<cQueue[front]<<endl<<endl;
   
   		if (front == rear) {
      		front = -1;
      		rear = -1;
   		} 
		else {
      		if (front == SIZE-1)
      			front = 0;
      		else
      			front++;
   		}
	}
	
	void displayCQ() {
   		int f = front, r = rear;
   		if (front == -1) {
      		cout<<"Queue is empty"<<endl<<endl;
      		return;
   		}
   		cout<<"Queue elements are :\n";
   		if (f <= r) {
      		while (f <= r){
         		cout<<cQueue[f]<<" ";
         		f++;
      		}
   		} 
		else {
      		while (f <= SIZE - 1) {
         		cout<<cQueue[f]<<" ";
         		f++;
      		}
      		f = 0;
      		while (f <= r) {
         		cout<<cQueue[f]<<" ";
         		f++;
      		}
   		}
   		cout<<endl<<endl;
	}
};

int main() {
   
	int ch, val;
	CircularQueue obj;
	
   	do {
   		cout << "1)enQueue\n";
		cout << "2)deQueue\n";
		cout << "3)Display\n";
		cout << "4)Exit\n";
		cout<<"Enter choice : "<<endl;
   	cin>>ch;
   	switch(ch) {
      	
		case 1: 
         	cout<<"Input for insertion: "<<endl;
         	cin>>val;
         	obj.enQueue(val);
         	break;
         
      	case 2: 
         	obj.deQueue();
         	break;
         
      	case 3: 
         	obj.displayCQ();
         	break;
         
      	case 4: 
         	cout<<"Exit\n";
         	break;
        
		default: 
			cout<<"Incorrect!\n";
   		}
	} while(ch != 4);
   return 0;
}
