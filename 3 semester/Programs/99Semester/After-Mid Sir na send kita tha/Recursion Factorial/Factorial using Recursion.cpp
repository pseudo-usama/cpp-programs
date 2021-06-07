#include<iostream>
#include<conio.h>
using namespace std;
int factorial(int num);
int main(){
	int i,j;
	cout<<"Enter no : ";
	cin>>i;
		cout<<i<<"! = "<<factorial(i);
	
	return 0;
}
int factorial(int num){
	if(num<=1)
		return 1;
	else
		return (num*factorial(num-1));
}
	
