#include <iostream>
using namespace std;


int add(int a, int b);
int sub(int a, int b);
int mult(int a, int b);
float div(int a, int b);
int mod(int a, int b);

int main() {
    int kp, i, j;

    do {
        cout << endl;
        cout << "Press 1 for +" << endl;
        cout << "Press 2 for -" << endl;
        cout << "Press 3 for *" << endl;
        cout << "Press 4 for /" << endl;
        cout << "Press 5 for %" << endl;
        cout << "Press 0 to exit" << endl;
        cout << "Enter your choice: ";
        cin >> kp;

        if (kp == 0) break;

        if (kp < 1 || kp > 5) {
            cout << "Wrong choice, please try again." << endl;
            continue;
        }

        cout << "Enter the first number: ";
        cin >> i;
        cout << "Enter the second number: ";
        cin >> j;

        switch (kp) {
            case 1:
                cout << "Addition of " << i << " and " << j << " is " << add(i, j) << endl;
                break;
            case 2:
                cout << "Subtraction of " << i << " and " << j << " is " << sub(i, j) << endl;
                break;
            case 3:
                cout << "Multiplication of " << i << " and " << j << " is " << mult(i, j) << endl;
                break;
            case 4:
                if (j != 0) {
                    cout << "Division of " << i << " and " << j << " is " << div(i, j) << endl;
                } else {
                    cout << "Division by zero is not allowed." << endl;
                }
                break;
            case 5:
                if (j != 0) {
                    cout << "Modulus of " << i << " and " << j << " is " << mod(i, j) << endl;
                } else {
                    cout << "Modulus by zero is not allowed." << endl;
                }
                break;
        }
    } while (true);

    cout << "Calculation ended." << endl;
    return 0;
}


int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mult(int a, int b) {
    return a * b;
}

float div(int a, int b) {
    return static_cast<float>(a) / b; 
}

int mod(int a, int b) {
    return a % b;
}
