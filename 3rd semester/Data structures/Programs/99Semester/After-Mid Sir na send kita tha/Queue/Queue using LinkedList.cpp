#include<iostream>
using namespace std;


//   Creating a Node Structure
struct Node
{
    int data;
    Node *next;
};

// Creating a class Queue
class Queue
{
    Node *front, *rear;
    public:
    
	Queue(){
        front = rear = NULL;
    }
    
    void enQueue(){
    	int value;
    	Node *temp;
    	cout << "\nenQueue Operationn\n";
    	cout << "Enter a number to insert: ";
    	cin >> value;
    	temp = new Node;
    	temp->data = value;
    	temp->next = NULL;
    	if(front == NULL){
    		front = temp;
    		rear = temp;
		}
		else{
			rear->next = temp;
			rear = temp;
		}
    	cout << "\nNew item is inserted to the Queue!!!\n";
	} 
	
    void deQueue(){
    	Node *temp;
    	if(front == NULL){
        	cout<<"\nThe Queue is empty!!!\n";
        	return;
    	}
    	temp = front;
    	front = front->next;
    	cout << "\ndeQueue Operation........\ndeQueued value is " << temp->data << endl;
    	delete temp;
	}
	  
    void show(){
    	Node *temp = front;
    	cout<<"\nThe Queue is\n";
    	while(temp != NULL){
        	cout << temp->data<<" ->";
        	temp = temp->next;
    	}
    	cout<<"NULL\n";
	} 
};

// Main function
int main()
{
    Queue q;
    int choice;
    while(1)
    {
        cout << "\n-----------------------------------------------------------";
        cout << "\n\t\tQueue USING LINKED LIST\n\n";
        cout << "1:enQueue\n2:deQueue\n3:DISPLAY Queue\n4:EXIT";
        cout << "\nEnter your choice(1-4): ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                q.enQueue();
                break;
            case 2:
                q.deQueue();
                break;
            case 3:
                q.show();
                break;
            case 4:
                exit(1);
            default:
                cout << "\nPlease enter correct choice(1-4)!!";
                break;
        }
    }
    return 0;
}
