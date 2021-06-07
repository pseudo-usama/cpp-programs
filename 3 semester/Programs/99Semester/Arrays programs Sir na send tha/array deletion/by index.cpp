#include<iostream>
using namespace std;
int main()
{
	int arr[50], size, index;
	cout<<"Enter array size : ";
	cin>>size;
	cout<<"Enter array elements : ";
	for(int i=0; i<size; i++)
	{
		cin>>arr[i];
	}
	cout<<"Enter index to be delete : ";
	cin>>index;
	if(index<size){
		for(int i=index; i<size-1; i++)
		{
			arr[i]=arr[i+1];
		}	
		cout<<"Element deleted successfully..!!\n";
		cout<<"Now the new array is :\n";
		for(int i=0; i<(size-1); i++)
		{
			cout<<arr[i]<<" ";
		}
	
		
	}
	
	else
	{
		cout<<"Element not found..!!";
	}
		
	return 0;
}
