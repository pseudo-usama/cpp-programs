#include<iostream>
using namespace std;
int main(){
	int arr1[5];
	cout << "Enter 5 elements of array: " << endl;
	
	for(int i=0 ; i<5 ; i++){
		cin >> arr1[i];
	}
	
	for(int i =0 ; i<5 ; i++){
		cout << arr1[i] << endl;
	}
	
	return 0;
}

//Do it by getting the size of array from user as input
