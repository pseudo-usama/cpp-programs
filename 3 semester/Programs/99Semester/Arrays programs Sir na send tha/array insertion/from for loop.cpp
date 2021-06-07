#include<iostream>
using namespace std;
int main()
{
	int arr[5];

	for(int i=0 ; i<5 ; i++){
		arr[i] = i*i*i;
	}
	
	for(int i=0 ; i<5 ; i++){
		cout << "arr[" << i << "] = " << arr[i] << endl;
	}

	return 0;
}

//Do the same using while and do while loop
