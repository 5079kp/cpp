#include<iostream>
using namespace std;
int main()

{ 
  int p = 6;
  
  for(int i = 0; i < p; i++)
  {
  	for(int j = 1; j <= 0; j++){
  		cout<<"  ";
	  }
	  for(int j = 1; j < p - i; j++){
	  cout<<(j % 2) <<" ";	
	  }
	cout<<endl;  
  }
	
	return 0;
}
