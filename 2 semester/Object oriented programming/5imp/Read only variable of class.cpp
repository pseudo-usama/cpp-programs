	
// Read only variable of class.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;




class CLASS{
private:
	int variable;

public:
	int *var = &variable;
};

void main() {
	CLASS z;

	cout<<z.var;
	//z.var=2;
}



/*
#include "unknwn.h" 
//Microsoft example

int _tmain(int argc, _TCHAR* argv[])
{
	// cpp_attr_ref_readonly.cpp  
	// compile with: /LD  
	[idl_quote("midl_pragma warning(disable:2461)")];
 
	[module(name = "ATLFIRELib")];

	[dispinterface, uuid(11111111 - 1111 - 1111 - 1111 - 111111111111)]
	__interface IFireTabCtrl
	{
		[readonly, id(1)] int i();
	};

	return 0;
}

*/