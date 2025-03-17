 #include<iostream>
using namespace std;
int main()
  {
  	
  	int rows, cols;
  	
  	cout<<"eneter the number of rows:";
	  cin>>rows; 
  	
  	cout<<"eneter the number of cols:";
	  cin>>cols;
	   
	   int matrix[rows][cols], transpose[cols][rows];
	   
	   cout<<"enter the elements of the matrix:"<<endl;
	   
	   for(int i = 0; i < rows; i++)
	   {
	   	 for( int j = 0; j < cols; j++)
	   	 
	   	 {
	   	 	cin>>matrix[i][j];
			}
	   }
	   
	   for(int i = 0; i < rows; i++)
	   {
	   	for(int j = 0; j< cols; j++)
	   	{
	   		transpose[j][i] = matrix[i][j];
	   		
		   }
	   }
  	
  	
  	cout<<"transpose of the matrix:"<<endl;
  	
  	for(int i = 0; i < rows; i++){
	  
	   for(int j = 0; j< cols; j++){
	   	
	   	cout<<transpose[i][j] <<"  ";
	   }
	   
	   cout<<endl;
	     
	  }
	  
return 0;	  

}
	  
  	
  	
  	
  	
  	
  	

	


	
