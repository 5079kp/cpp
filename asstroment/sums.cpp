#include<iostream>
using namespace std;
int main()
{
	int rows, cols;
	
	cout<<"enter the number rows:";
	cin>>rows;
	cout<<"enter the number cols:";
	cin>>cols;
	
	int arr[rows][cols];
	
	cout<<"enter the elements of the 2d array:\n";
	
	for(int i = 0; i < rows; i++)
	{
		for (int j = 0; j< cols; j++){
			cin>>arr[i][j];
		}
	}
	
	    cout << "\nThe 2D array is:\n";
	    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    int rowNum, colNum;

       if (rowNum >= rows || colNum >= cols || rowNum < 0 || colNum < 0) {
        cout << "Invalid row or column index!\n";
        return 1;
    }

    int rowSum = 0, colSum = 0;
    
    for (int j = 0; j < cols; j++) {
        rowSum += arr[rowNum][j];
    }

    
    for (int i = 0; i < rows; i++) {
        colSum += arr[i][colNum];
    }

    
    cout << "\nSum of elements in row " << rowNum << " = " << rowSum << endl;
    cout << "Sum of elements in column " << colNum << " = " << colSum << endl;

    return 0;
}
	
	



