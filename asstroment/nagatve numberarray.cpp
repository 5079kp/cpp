#include<iostream>
using namespace std;
int main()
{
	int size;
	
	cout<<"Enter the array size:";
	cin>>size;
	
	int arr[size];
	
	cout<<"enter the array element:";
	
	
	for(int i = 0; i < size; i++)
	
	{
		cin>> arr[i];
	}
	
	cout<<"Nagative elements array:";
	
	for(int i = 0; i < size; i++)
	{
		if(arr[i] < 0){
			
			cout<<arr[i] <<" ";
		}
	}
	
	
	return 0;
	
	
	}

