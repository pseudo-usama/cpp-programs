// 2D Graph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

class Graph_2D {
private:
	bool Data;

	Graph_2D *Right;
	Graph_2D *Up;

	Graph_2D *Origin = NULL;

public:
	virtual void Add(bool _Data, int x, int y)   {
		Graph_2D *NewNode = new Graph_2D;
		NewNode->Data = _Data;

		if (Origin == NULL) {
			Origin = NewNode;
		}
		else {
			Graph_2D *Temp = Origin;

			for (int i = 1, bool Decider; i < x; i++) {
				if (Temp->Right != NULL) {
					Temp = Temp->Right;
				}
				else {

				}
			}
			for (int j = 1; j < y; j++) {
				Temp = Temp->Up;
			}
		}
	}
};





void main() {
	
}

