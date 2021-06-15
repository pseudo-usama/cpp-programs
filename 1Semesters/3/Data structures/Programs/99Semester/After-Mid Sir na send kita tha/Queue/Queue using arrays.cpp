#include<iostream> 
  
using namespace std; 
  
#define MAX 1000 
  
class Queue 
{ 
    int front, rear; 
public: 
    int a[MAX];    //Maximum size of Queue 
  
    Queue()
	{
		front = 0;
		rear = -1; 
	} 
    
	void enQueue(int x)
	{ 
    	if (isFull()) 
    	{	 
        	cout << "Queue is Full";  
    	} 
    	else
    	{ 
        	rear++;
			a[rear] = x; 
        	cout << x << " enQueued into Queue\n";  
    	} 
} 
    void deQueue()
	{ 
    	if (isEmpty()) 
    	{ 
        	cout << "Queue is Empty";  
    	} 
    	else
    	{ 
        	int x = a[front];
			front++; 
        	cout << x << " deQueued from Queue\n"; 
    	} 
	}  
    
	bool isEmpty()
	{ 
    	if(rear < 0)
			return true;
		else
			return false; 
	}
	
	bool isFull(){
		if(rear == MAX-1)
			return true;
		else
			return false;
	} 
}; 
    
// Driver program to test above functions 
int main() 
{ 
    Queue s; 
    s.enQueue(10); 
    s.enQueue(20); 
    s.enQueue(30); 
    s.deQueue(); 
  
    return 0; 
} 
