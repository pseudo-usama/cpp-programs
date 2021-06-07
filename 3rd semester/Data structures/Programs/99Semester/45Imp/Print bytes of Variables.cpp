#include "stdafx.h"
#include <iostream>
using namespace std;


void main() {
	int a = 1234567890;

	for (int n = 0; n < 4; n++)
		cout << n + 1 << " byte is  : " << ((a >> (8 * n)) & 0xff) << endl;
}