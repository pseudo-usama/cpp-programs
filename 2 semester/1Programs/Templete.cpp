// Templete.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"
using namespace std;
/*
template <class T>	//class and typename both can use in braces
T Max(T a, T b){
	return(a < b ? b : a);
}

void main() {
	int a = 1, b = 2;
	cout << Max(a, b)<<endl;

	cout << Max(1.1, 2.4) << endl;

	cout << Max("Hello", "World") << endl;

}

*/

template <class T>

class Calculator{
private:
	T a, b;

public:
	Calculator(T x, T y) {
		a = x;
		b = y;
	}

	void _OprateAndDisplay() {
		cout << "Numbers are    :  " << a << " and " << b << "." << endl << endl;

		cout << "Sum is              = " << a + b << endl;
		cout << "Difference is       = " << a - b << endl;
		cout << "Multiplication is   = " << a*b << endl;
		cout << "Division is         = " << a / b << endl;
	}
};

void main() {
	Calculator<int> Ob(1, 2);
	Calculator<float> Ob2(1.1, 2);

	Ob._OprateAndDisplay();
	Ob2._OprateAndDisplay();
}