#include<iostream>
using namespace std;

int main() 
{
    int num, firstDigit, lastDigit, sum;

    cout << "Enter a number: ";
    cin >> num;

    lastDigit = num % 10;  

    firstDigit = num;
    
    while (firstDigit >= 10) 
	{
        firstDigit /= 10; 
    }

    sum = firstDigit + lastDigit;

    cout << "Sum of first and last digit: " << sum << endl;

    return 0;
}

