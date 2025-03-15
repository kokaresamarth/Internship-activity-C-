Q3.c++ set program for Add elements Access elements Change elements Remove elements through iterators using exception handling try,catch,throw.

#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> s;
    int element;

    cout << "Enter number of elements to add: ";
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> element;
        s.insert(element); 
    }

    try {
        cout << "\nAccess elements in the set\n";
        cout << "Enter the index to access an element: ";
        int position;
        cin >> position;
        
        if (position < 0 || position >= s.size()) {
            throw out_of_range("Invalid index for access.");
        }

        set<int>::iterator it = s.begin();
        for (int i = 0; i < position; ++i) {
            ++it; 
        }
        cout << "Element at index " << position << " is: " << *it << endl;

        cout << "\nModify an element in the set\n";
        cout << "Enter the index of the element to modify: ";
        cin >> position;
        if (position < 0 || position >= s.size()) {
            throw out_of_range("Invalid index for modification.");
        }

        set<int>::iterator it2 = s.begin();
        for (int i = 0; i < position; ++i) {
            ++it2; 
        }
        cout << "Enter the new value: ";
        cin >> element;
        s.erase(it2);
       
        s.insert(element);
        cout << "Element modified to: " << element << endl;
        
        cout << "\nRemove an element from the set\n";
        cout << "Enter the index of the element to remove: ";
        cin >> position;
        if (position < 0 || position >= s.size()) {
            throw out_of_range("Invalid index for removal.");
        }

        set<int>::iterator it3 = s.begin();
        for (int i = 0; i < position; ++i) {
            ++it3;
        }
        s.erase(it3);
        cout << "Element removed from the set.\n";

        cout << "\nFinal set elements: ";
        for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
            cout << *it << " "; 
        }
        cout << endl;

    } catch (const out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    } catch (...) {
        cout << "An unexpected error occurred." << endl;
    }

    return 0;
}

Output:

Enter number of elements to add: 10
Enter element 1: 2
Enter element 2: 4
Enter element 3: 6
Enter element 4: 8
Enter element 5: 10
Enter element 6: 12
Enter element 7: 14
Enter element 8: 16
Enter element 9: 18
Enter element 10: 20

Access elements in the set
Enter the index to access an element: 6
Element at index 6 is: 14

Modify an element in the set
Enter the index of the element to modify: 3
Enter the new value: 250
Element modified to: 250

Remove an element from the set
Enter the index of the element to remove: 8
Element removed from the set.

Final set elements: 2 4 6 10 12 14 16 18 250