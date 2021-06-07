// binary representation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#define B(x) S_to_binary_(#x)

static inline unsigned long long S_to_binary_(const char *s)
{
	unsigned long long i = 0;
	while (*s) {
		i <<= 1;
		i += *s++ - '0';
	}
	return i;
}

void main() {
	int foo = B(1011);

	cout << foo;
}

