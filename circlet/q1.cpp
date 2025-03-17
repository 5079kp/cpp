#include <iostream>
using namespace std;
int main()
{
	int k = 5;
	
	for(int i = 0; i < k; i++)
	{
		for( int j = 41; j <=41 + i; j++)
		{
			cout<<j <<" ";
		}
		 cout<<endl;
	}
	return 0;
}
