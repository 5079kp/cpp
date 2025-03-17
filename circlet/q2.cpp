#include<iostream>
using namespace std;
int main()
{
	int k = 4, p = 11;
	
	for(int i = 0; i <= k; i++)
	{
		for( int j = 1; j <= i;  j++)
		{
			cout<<p <<" ";
			p++;
		}
		 cout<<endl;
	}
	return 0;
}
