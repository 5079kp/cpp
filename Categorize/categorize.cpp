#include <iostream>
using namespace std;

class Selection {
public:
    int* arr;
    int size;

    Selection() {
        size = 0;
        arr = 0;
    }

    ~Selection() {
        delete[] arr;
    }

    // Function for selection sort 
    void select() {
        cout << "Enter the number of elements in the array: ";
        cin >> size;

        arr = new int[size];
        cout << "Enter the elements of the array: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }

        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (arr[i] > arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    // Function For Merge sort function
    void mergeSort(int arr[], int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

    void merge(int arr[], int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int* L = new int[n1];
        int* R = new int[n2];

        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }

        delete[] L;
        delete[] R;
    }

    // Binary search function
    void binarySearch(int target) {
        int left = 0;
        int right = size - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] == target) {
                cout << "Element found at index: " << mid << endl;
                return;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        cout << "Element not found in the array." << endl;
    }

    // Display array
    void display() {
        cout << "The array is: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Selection obj;
    int choice;

    while (true) {
        cout << "\n********** Logic Menu **********\n";
        cout << "1. Selection Sort\n";
        cout << "2. Merge Sort\n";
        cout << "3. Binary Search\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                obj.select();
                obj.display();
                break;
            case 2:
                if (obj.arr == 0 || obj.size == 0) {
                    cout << "Please input array first using Selection Sort option.\n";
                } else {
                    obj.mergeSort(obj.arr, 0, obj.size - 1);
                    cout << "After Merge Sort: ";
                    obj.display();
                }
                break;
            case 3:
                if (obj.arr == 0 || obj.size == 0) {
                    cout << "Please input array first using Selection Sort option.\n";
                } else {
                    int target;
                    cout << "Enter the element to search: ";
                    cin >> target;
                    obj.binarySearch(target);
                }
                break;
            case 4:
                cout << "Exiting the program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
