#include <iostream>
using namespace std;
int size = 5;
class Node
{
public:
    int data;
    Node *next;

    Node(int value)

    {
        data = value;
        next = NULL;
    }
};
class linked_list
{
    Node *Head;
    Node *tail;

public:
    linked_list()
    {
        Head = NULL;
        tail = NULL;
    }
    void insert_front(int value)
    {
        Node *newNode = new Node(value);
        if (Head == NULL)
        {
            Head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = Head;
            Head = newNode;
        }
    }
    void delete_front()
    {
        if (Head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = Head;
        Head = Head->next;
        delete temp;
    }
void search(int value)
    {
        Node *current = Head;
        while (current != NULL)
        {
            if (current->data == value)
            {
                cout << "Value found: " << value << endl;
                return;
            }
            current = current->next;
        }
        cout << "Value not found: " << value << endl;
    }
    void reverse()
    {
        Node *prev = NULL;
        Node *current = Head;
        Node *next = NULL;
        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        Head = prev;
    }
void display()
    {
        Node *current = Head;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
int main ()
{
    linked_list obj;
int ch, num;



while(1)
{
    cout<<"\n\n*******Linked List******\n";
    cout<<"\n select your choice:-";
    cout << "1. Insert at front" << endl;
    cout << "2. Delete at front" << endl;
    cout << "3. Search" << endl;
    cout << "4. Reverse" << endl;
    cout << "5. Display" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> ch;

    switch (ch)
    {
    case 1:
        cout << "Enter number to insert: ";
        cin >> num;
        obj.insert_front(num);
        break;
    case 2:
        obj.delete_front();
        break;
    case 3:
        cout << "Enter number to search: ";
        cin >> num;
        obj.search(num);
        break;
    case 4:
        obj.reverse();
        break;
    case 5:
        obj.display();
        break;
    case 6:
        exit(0);
    default:
        cout << "Invalid choice" << endl;

        return 0;
    }
}
}