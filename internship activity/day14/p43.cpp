Q3.c++ set program for Add elements Access elements Change elements Remove elements through iterators

#include <iostream>
#include <set>
#include <iterator>

using namespace std;

int main() {
    set<int> s;
    int element, position;

    cout << "Enter number of elements to add: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> element;
        s.insert(element); 
    }
    cout << "\nAccess elements\n";
    cout << "The elements in the set are: ";
    for (const int& elem : s) {
        cout << elem << " ";
    }
    cout << endl;

    cout << "\nChange an element in the set\n";
    cout << "Enter the element to remove: ";
    cin >> element;
    auto it = s.find(element);
    if (it != s.end()) {
        s.erase(it); 
        cout << "Enter the new value to insert: ";
        cin >> element;
        s.insert(element); 
        cout << "Element changed to " << element << endl;
    } else {
        cout << "Element not found in the set!\n";
    }

    cout << "\nRemove an element from the set\n";
    cout << "Enter the element to remove: ";
    cin >> element;
    it = s.find(element);
    if (it != s.end()) {
        s.erase(it); 
        cout << "Element " << element << " removed.\n";
    } else {
        cout << "Element not found in the set!\n";
    }

    cout << "\nFinal set elements: ";
    for (const int& elem : s) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}

Output:.

Enter number of elements to add: 3
Enter element 1: 4
Enter element 2: 5
Enter element 3: 6

Access elements
The elements in the set are: 4 5 6

Change an element in the set
Enter the element to remove: 4
Enter the new value to insert: 0
Element changed to 0

Remove an element from the set
Enter the element to remove: 5
Element 5 removed.

Final set elements: 0 6