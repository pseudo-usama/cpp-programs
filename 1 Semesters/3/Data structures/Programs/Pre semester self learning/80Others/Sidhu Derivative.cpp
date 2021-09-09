// Derivative.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "math.h"
#include "string"
#include "queue"
using namespace std;

template <class Type>

class Variable {
public:


	Type Value;
	char Symbol;
};

template <class Type>

class Darivation {
private:


	Type Coefficient;
	Variable<Type> Base;
	Type Power;

public:
	void Derivative(string Fn, Type Variables[]) {



	}

	Darivation() {
		Coefficient = 0;
		Base.Symbol = '\0';
		Base.Value = 0;
		Power = 0;
	}
	Darivation(Type Coe, Type Val, Type Sym, Type Pow) {
		Coefficient(Coe);
		Base.Value(Val);
		Base.Symbol(Sym);
		Power(Pow);
	}
};

void main() {
	int x = 5;

	Darivation<int> Fn[5] = { { 4, x, 4 }, { -3, x, 1 } }
}