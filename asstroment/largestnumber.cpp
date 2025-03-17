 #include<iostream>
using namespace std;
int main()
{
	int rows, cols;
	
	cout<<"enter the arry raw size:";
	cin>>rows;
	cout<<"enter the array colum size:";
	cin>>cols;
	
	int arr[rows][cols];
	
	cout<<"enter the aaray  elements:"<<endl;
	for(int i = 0; i< rows; i++)
	 {
	 	for(int j = 0; j < cols; j++)
	 	{
	 		cin>>arr[i][j];
		 }
		 
	  } 
	  int largest = arr[0][0];
	  
	  for(int i = 0; i < rows; i++)
	  {
	  	for(int j = 0; j < cols; j++)
	  	
	  	{
	  		if(arr[i][j] > largest){
	  			largest = arr[i][j];
			  }
		  }
	  }
	  
	   cout<<"the largest elements in array is:"<<largest <<endl;
	  
	  return 0;
}

