#include<iostream>
using namespace std;

//Linked List Node

struct Node {
    int data;
    Node* next;
};
//linked list oprestions
class LinkedList {
    private:
        Node* head;
    public:
        LinkedList() : head(nullptr) {}

        void insert(int value) {
            Node*newNode = new Node{value, nullptr};
            if(!head) {
                head = newNode;
            
            }
            else {
                Node* temp = head;
                while (temp -> next) temp = temp -> next;
                temp -> next = newNode;

        }
    }
     void deleteValue(int value) {
            if (!head) return; // List is empty
            if (head->data == value) { // If the head is the value to delete
                Node* temp = head;
                head = head->next; // Move head to the next node
                delete temp; // Delete the old head
                return;
            }
            Node* current = head;
            while(current -> next && current->next->data != value) {
                current = current->next; // Traverse the list

                if(current->next) {
                    Node* temp = current->next; // Node to delete
                    current->next = current->next->next; // Bypass the node
                    delete temp; // Delete the node
                }
            }
                void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
        

    


// Merge Sort Functions
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Quick Sort Functions
int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = (low - 1);
    for (int j = low; j < high; j++)
        if (arr[j] < pivot)
            swap(arr[++i], arr[j]);
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Binary Search
int binarySearch(int arr[], int size, int key) {
    int l = 0, r = size - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

// Menu
int main() {
    LinkedList list;
    const int MAX = 100;
    int arr[MAX], n = 0;
    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Insert into Linked List\n";
        cout << "2. Delete from Linked List\n";
        cout << "3. Display Linked List\n";
        cout << "4. Input Array\n";
        cout << "5. Merge Sort Array\n";
        cout << "6. Quick Sort Array\n";
        cout << "7. Binary Search in Sorted Array\n";
        cout << "8. Display Array\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int val;
            cout << "Enter value to insert: ";
            cin >> val;
            list.insert(val);
            break;
        }
        case 2: {
            int val;
            cout << "Enter value to delete: ";
            cin >> val;
            list.deleteValue(val);
            break;
        }
        case 3:
            list.display();
            break;
        case 4:
            cout << "Enter size of array (max " << MAX << "): ";
            cin >> n;
            cout << "Enter elements:\n";
            for (int i = 0; i < n; i++) cin >> arr[i];
            break;
        case 5:
            mergeSort(arr, 0, n - 1);
            cout << "Array sorted using Merge Sort.\n";
            break;
        case 6:
            quickSort(arr, 0, n - 1);
            cout << "Array sorted using Quick Sort.\n";
            break;
        case 7: {
            int key;
            cout << "Enter value to search: ";
            cin >> key;
            int idx = binarySearch(arr, n, key);
            if (idx != -1)
                cout << "Value found at index " << idx << "\n";
            else
                cout << "Value not found.\n";
            break;
        }
        case 8:
            cout << "Array: ";
            for (int i = 0; i < n; i++) cout << arr[i] << " ";
            cout << "\n";
            break;
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
	}

