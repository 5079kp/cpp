#include <iostream>

using namespace std;
int main() {
    int rows = 5;  

    for (int i = 1; i <= rows; i++) { 
        
        for (int j = 1; j <= rows - i; j++) {
            
        cout << "  "; 
        }

        
        for (int j = i; j <= 5; j++) {
            cout << j << " ";
        }

        
        for (int j = 5 - 1; j >= i; j--) {
            cout << j << " ";
        }

        cout <<endl; 
    }

    return 0;
}

