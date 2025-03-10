#include <iostream>
using namespace std;
int main() {
    int marks;
    char grade;

    
    cout << "Enter your score (out of 100): ";
    cin >>marks;
    

    grade = (marks >= 90) ? 'A' :
            (marks >= 80) ? 'B' :
            (marks >= 70) ? 'C' :
            (marks >= 55) ? 'D' :
            (marks >= 45) ? 'E' : 'F';
          cout<< "Your grade is: " << grade <<endl;
		  
		    
             switch (grade) {
        case 'A':
        case 'a':
            cout << "Excellent work!" << endl;
            break;
        case 'B':
        case 'b':
            cout << "Well done!" << endl;
            break;
        case 'C':
        case 'c':
            cout << "Good job!" << endl;
            break;
        case 'D':
        case 'd':
            cout << "You passed, but you could do better." << endl;
            break;
        case 'F':
        case 'f':
            cout << "Sorry, you failed." << endl;
            break;
        default:
            cout << "Invalid grade entered." << endl;
    }
    
     if (grade == 'A' || grade == 'a' || grade == 'B' || grade == 'b' ||
        grade == 'C' || grade == 'c' || grade == 'D' || grade == 'd')
		 {
        cout << "Congratulations! You are eligible for the next level." << endl;
    } else if (grade == 'F' || grade == 'f') 
	
	{
        cout << "Please try again next time." << endl;
    }
     

    return 0;
}
