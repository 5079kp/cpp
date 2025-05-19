#include<iostream>
#include<vector>
#include<string>
using namespace std;
template<class  T>
class MemoryCalculator {

    vector<T> id;
    vector<T> name;
    public:
    MemoryCalculator() {
        
        cout << "MemoryCalculator constructor called" << endl;


    }
    void add(T id, T name) {
        T newId = id;
        string  newName = name;

        cout<<"\n enter the id: "<<newId<<endl;
        cin>>newId;
        cout<<"\n enter the name: "<<newName<<endl;
        cin>>newName;
        id.push_back(newId);
        name.push_back(newName);
    }
    void display() {
        cout << "student list:" << endl;

        if(id.empty()) {
            cout << "No students found." << endl;
        } else {
            for (int i = 0; i < id.size(); i++) {
                cout << "ID: " << id[i] << ", Name: " << name[i] << endl;
            }
        }
    }
    void remove(T searchid) {
        for(int i = 0; i < id.size(); i++) {
            if (id[i] == searchid) {
                id.erase(id.begin() + i);
                name.erase(name.begin() + i);
                cout << "Student with ID " << searchid << " removed." << endl;
                return;
            }
        }
        cout << "Student with ID " << searchid << " not found." << endl;
    }
        void search(T searchid) {
            for (int i = 0; i < id.size(); i++) {
                if (id[i] == searchid) {
                    cout << "Student found: ID: " << id[i] << ", Name: " << name[i] << endl;
                    return;
                }
            }
            cout << "Student with ID " << searchid << " not found." << endl;
        }
        
      int main() {
        MemoryCalculator<int> mc;
        int choice;
        do {
            cout << "\n1. Add Student\n2. Display Students\n3. Remove Student\n4. Search Student\n5. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    int id;
                    string name;
                    mc.add(id, name);
                    break;
                }
                case 2:
                    mc.display();
                    break;
                case 3: {
                    int searchid;
                    cout << "Enter ID to remove: ";
                    cin >> searchid;
                    mc.remove(searchid);
                    break;
                }
                case 4: {
                    int searchid;
                    cout << "Enter ID to search: ";
                    cin >> searchid;
                    mc.search(searchid);
                    break;
                }
                case 5:
                    cout << "Exiting..." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice != 5);

        return 0;
    }

};