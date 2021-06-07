#include<iostream> 
  
using namespace std; 
  
#define MAX 1000 
  
class Stack 
{ 
    int top; 
public: 
    int a[MAX];    //Maximum size of Stack 
  
    Stack()
	{
		top = -1; 
	} 
    
	void push(int x)
	{ 
    	if (top >= (MAX-1)) 
    	{	 
        	cout << "Stack Overflow";  
    	} 
    	else
    	{ 
        	a[++top] = x; 
        	cout<<x <<" Pushed into Stack\n";  
    	} 
} 
    void pop()
	{ 
    	if (top < 0) 
    	{ 
        	cout << "Stack Underflow";  
    	} 
    	else
    	{ 
        	int x = a[top--]; 
        	cout << x << " Popped from Stack\n"; 
    	} 
	}  
    
	bool isEmpty()
	{ 
    	if(top < 0)
			return true;
		else
			return false; 
	} 
}; 
    
// Driver program to test above functions 
int main() 
{ 
    Stack s; 
    s.push(10); 
    s.push(20); 
    s.push(30); 
    s.pop(); 
  
    return 0; 
} 
