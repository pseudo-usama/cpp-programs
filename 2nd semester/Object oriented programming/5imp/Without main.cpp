// Without main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"iostream"


using namespace std;
#define decode(s,t,u,m,p,e,d) m##s##u##t
#define begin decode(a,n,i,m,a,t,e)
int begin()
{
	cout << "hi" << endl;
}