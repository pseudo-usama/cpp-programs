#include<iostream>
using namespace std;


//   Creating a Node Structure
struct Node
{
    int data;
    Node *next;
};

// Creating a class STACK
class stack
{
    Node *top;
    public:
    
	stack(){
        top = NULL;
    }
    
    void push(){
    	int value;
    	Node *temp;
    	cout << "\nPUSH Operationn\n";
    	cout << "Enter a number to insert: ";
    	cin >> value;
    	temp = new Node;
    	temp->data = value;
    	temp->next = NULL;
    	if(top != NULL){
    		temp->next = top;
		}
    	top = temp;
    	cout << "\nNew item is inserted to the stack!!!\n";
	} 
	
    void pop(){
    	Node *temp;
    	if(top == NULL){
        	cout<<"\nThe stack is empty!!!\n";
        	return;
    	}
    	temp = top;
    	top = top->next;
    	cout << "\nPOP Operation........\nPoped value is " << temp->data << endl;
    	delete temp;
	}
	  
    void show(){
    	Node *temp = top;
    	cout<<"\nThe stack is\n";
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
    stack s;
    int choice;
    while(1)
    {
        cout<<"\n-----------------------------------------------------------";
        cout<<"\n\t\tSTACK USING LINKED LIST\n\n";
        cout<<"1:PUSH\n2:POP\n3:DISPLAY STACK\n4:EXIT";
        cout<<"\nEnter your choice(1-4): ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                s.push();
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.show();
                break;
            case 4:
                exit(1);
            default:
                cout<<"\nPlease enter correct choice(1-4)!!";
                break;
        }
    }
    return 0;
}
