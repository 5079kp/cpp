#include <iostream>

using namespace std;

int main() 
{
    int p, k = 0;

    cout << "Enter a number: ";
    cin >> p;

    
    if (p == 0) {
        k = 1;
    } else {
    
        while (p != 0) {
            p /= 10; 
            k++;   
        }
    }

    cout << "Total number of digits: " << k << endl;
    return 0;
}

