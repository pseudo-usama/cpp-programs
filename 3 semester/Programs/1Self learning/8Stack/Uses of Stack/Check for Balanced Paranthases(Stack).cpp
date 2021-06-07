// Check for Balanced Paranthases(Stack).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "stack"
using namespace std;

void main() {
	char Array[50];
	stack<char> Ob;

	cout << "Enter an equation for Checking that is Balanced or not  : ";
	cin >> Array;

	for (int i = 0; Array[i] != '\0'; i++) {
		if(Array[i] == '(' || Array[i] == '{' || Array[i] == '[') {
			Ob.push(Array[i]);
		}
		else if (Array[i] == ')' || Array[i] == '}' || Array[i] == ']') {
			if      (Array[i] == ')' && !Ob.empty() && Ob.top() == '(') { Ob.pop();                                        }
			else if (Array[i] == '}' && !Ob.empty() && Ob.top() == '{') { Ob.pop();                                        }
			else if (Array[i] == ']' && !Ob.empty() && Ob.top() == '[') { Ob.pop();                                        }
			else                                                        { cout << "Equation not balanced!" << endl;        }
		}
	}
	if (!Ob.empty()) {
		cout << "Equation is not balanced." << endl;
	}
	else {
		cout << "Equation is balanced." << endl;
	}	
}

