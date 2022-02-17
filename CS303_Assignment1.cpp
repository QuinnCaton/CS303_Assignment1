#include <iostream>
#include <list>
#include <iterator>
#include "Assignment.h";
using namespace std;

int main()
{
    Assignment newAssignment;
    list<Assignment> myList;
    int choice;

    while (true) {
        cout << "\nMENU:\n\n\t1. Add a New Assignment\n\t2. Remove an Assignment\n\t" <<
            "3. Print a List of Assignments\n\t4. Find the Earliest Due Assignment\n\t" <<
            "5. Quit" << endl;
        cout << "Please enter your choice: ";
        cin >> choice;
        cout << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice) {
        case 1:
            addAssignment(myList);
            break;
        case 2:
            removeAssignment(myList);
            break;
        case 3:
            printAssignments(myList);
            break;
        case 4:
            earliestDue(myList);
            break;
        case 5:
            cout << "Goodbye!" << endl;
            return 0;
        }
    }
}

