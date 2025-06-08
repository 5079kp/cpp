#include <iostream>
using namespace std;

// Base class: Stack
class Stack {
protected:
    int *arr;
    int topindex;
    int capacity;

public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        topindex = -1;
    }

    virtual void push(int value) {
        if (isFull()) {
            cout << "Stack is full. Cannot push." << endl;
        } else {
            arr[++topindex] = value;
            cout << "Pushed " << value << " onto stack." << endl;
        }
    }

    virtual void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
        } else {
            cout << "Popped " << arr[topindex--] << " from stack." << endl;
        }
    }

    virtual int top() {
        if (isEmpty()) {
            cout << "Stack is empty. No top element." << endl;
            return -1;
        } else {
            cout << "Top element is: " << arr[topindex] << endl;
            return arr[topindex];
        }
    }

    bool isEmpty() {
        return topindex == -1;
    }

    bool isFull() {
        return topindex == capacity - 1;
    }

    virtual ~Stack() {
        delete[] arr;
    }
};

// Derived class: CustomStack
class CustomStack : public Stack {
public:
    CustomStack(int size) : Stack(size) {}

    void push(int value) override {
        cout << "Using CustomStack's push: ";
        Stack::push(value);
    }

    void pop() override {
        cout << "Using CustomStack's pop: ";
        Stack::pop();
    }

    int top() override {
        cout << "Using CustomStack's top: ";
        return Stack::top();
    }
};

// Main function
int main() {
    int size;
    cout << "Enter stack size: ";
    cin >> size;

    CustomStack myStack(size); // Object of derived class

    int choice, value;
    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Top\n4. Check Empty\n5. Check Full\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            myStack.push(value);
            break;
        case 2:
            myStack.pop();
            break;
        case 3:
            myStack.top();
            break;
        case 4:
            cout << (myStack.isEmpty() ? "Stack is Empty." : "Stack is not Empty.") << endl;
            break;
        case 5:
            cout << (myStack.isFull() ? "Stack is Full." : "Stack is not Full.") << endl;
            break;
        case 6:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 6);

    return 0;
}
