// Evalution of Prefix (Stack).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "stack"
#include "string"
using namespace std;

void main() {
	string Expression;
	stack<int> Ob;
	int Length;

	cout << "Enter an Postfix expression(using Spaces) : ";
	getline(cin, Expression);

	Length = Expression.length() - 1;

	if (Length == 0) {
		cout << endl << endl << "Error! Enter an expression that having only numbers, +, -, *, /(oprators) and spaces." << endl << endl << endl;
		exit(0);
	}
	
	for (int i = Length; i > -1; i--) {
		if (Expression[i] >= '0' && Expression[i] <= '9') {
			Ob.push(Expression[i] - '0');
		}
		else if (Expression[i] == '+' || Expression[i] == '-' || Expression[i] == '*' || Expression[i] == '/') {
			int a, b;

			if (!Ob.empty()) {
				a = Ob.top();
				Ob.pop();

				if (!Ob.empty()) {
					b = Ob.top();
					Ob.pop();

					if      (Expression[i] == '+') { Ob.push(a + b); }
					else if (Expression[i] == '-') { Ob.push(a - b); }
					else if (Expression[i] == '*') { Ob.push(a * b); }
					else if (Expression[i] == '/') { Ob.push(a / b); }
				}
				else { cout << "Error! Please write an valid equation." << endl; exit(0); }
			}
			else { cout << "Error! Please write an valid equation." << endl; exit(0); }
		}
		else if (Expression[i] != ' ') {
			cout << endl << endl << "Error! Enter an expression that having only numbers, +, -, *, /(oprators) and spaces." << endl << endl << endl;
			exit(0);
		}
	}
	cout << "The result is  : " << Ob.top() << endl;
	Ob.pop();
}

