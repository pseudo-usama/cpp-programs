// Infix to Postfix (Stack).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "stack"
using namespace std;

bool Oprator_Prefrance(char First, char Second);

string To_Postfix(string Expression);

void main() {
	string Expression;
	string Postfix;

	cout << "Enter an Infix Expression  : ";
	cin >> Expression;

	if (Expression == "\0") {
		cout << "Error! Enter an Expression." << endl;
		exit(0);
	}

	for (int i = 0; Expression[i] != '\0'; i++) {
		if      (Expression[i] == '{' || Expression[i] == '[') { Expression[i] = '('; }
		else if (Expression[i] == '}' || Expression[i] == ']') { Expression[i] = ')'; }
	}
	
	Postfix = To_Postfix(Expression);

	cout << endl << "The Equation you entered in Postfix is  : ";

	for (int i = 0; Postfix[i] != '\0'; i++) {
		cout << Postfix[i] << " ";
	}
	cout << endl << endl;
}

bool Oprator_Prefrance(char First, char Second) {
	if (First == '+') {
		if      (Second == '+' || Second == '-') { return(true);  }
		else if (Second == '/' || Second == '*') { return(false); }
		
	}
	else if (First == '-') {
		if      (Second == '+' || Second == '-') { return(true);  }
		else if (Second == '*' || Second == '/') { return(false); }
	}
	else if (First == '*')                       { return(true);  }
	else if (First == '/')                       { return(true);  }

	return(false);
}

string To_Postfix(string Expression) {
	stack<char> Ob;
	string Postfix;

	for (int i = 0; Expression[i] != '\0'; i++) {
		if (Expression[i] == '+' || Expression[i] == '-' || Expression[i] == '*' || Expression[i] == '/' || Expression[i] == '(' || Expression[i] == ')') {
			if (Expression[i] == '(') {
				Ob.push(Expression[i]);
			}
			else if (Expression[i] == ')') {
				while (Ob.top() != '(') {
					Postfix += Ob.top();

					Ob.pop();
				}
				Ob.pop();
			}
			else {
				while (!Ob.empty() && Oprator_Prefrance(Ob.top(), Expression[i])) {
					Postfix += Ob.top();

					Ob.pop();
				}
				Ob.push(Expression[i]);
			}
		}
		else if ((Expression[i] >= 'a' && Expression[i] <= 'z') || (Expression[i] >= 'A' && Expression[i] <= 'Z') || (Expression[i] >= '0' && Expression[i] <= '9')) {
			Postfix += Expression[i];
		}

		else {
			cout << endl << "Error! Enter an valid Expression." << endl;
			cout << "Use Alphabets, Numbers, +, -, *, / and spaces only." << endl << endl;
			exit(0);
		}
	}

	while (!Ob.empty()) {
		Postfix += Ob.top();
		Ob.pop();
	}
	return(Postfix);
}