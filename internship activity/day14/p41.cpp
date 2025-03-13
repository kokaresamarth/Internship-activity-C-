Q1.c++ vector program for Add elements Access elements Change elements Remove elements through iterators

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main() {
    vector<int> vec;
    int element, position;

    cout << "Enter number of elements to add: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> element;
        vec.push_back(element);
    }

    cout << "\nAccess elements by index\n";
    cout << "Enter the index to access an element: ";
    cin >> position;
    if (position >= 0 && position < vec.size()) {
        vector<int>::iterator it = vec.begin() + position;
        cout << "Element at index " << position << " is: " << *it << endl;
    } else {
        cout << "Invalid index!\n";
    }

    cout << "\nChange an element in the vector\n";
    cout << "Enter the index of the element to change: ";
    cin >> position;
    if (position >= 0 && position < vec.size()) {
        cout << "Enter the new value: ";
        cin >> element;
        vector<int>::iterator it = vec.begin() + position;
        *it = element;
        cout << "Element changed at index " << position << " to " << *it << endl;
    } else {
        cout << "Invalid index!\n";
    }

    cout << "\nRemove an element from the vector\n";
    cout << "Enter the index of the element to remove: ";
    cin >> position;
    if (position >= 0 && position < vec.size()) {
        vector<int>::iterator it = vec.begin() + position;
        vec.erase(it);
        cout << "Element at index " << position << " removed.\n";
    } else {
        cout << "Invalid index!\n";
    }

    cout << "\nFinal vector elements: ";
    vector<int>::iterator it;
    for (it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}

Output:

Enter number of elements to add: 3
Enter element 1: 4
Enter element 2: 5
Enter element 3: 6

Access elements by index
Enter the index to access an element: 2
Element at index 2 is: 6

Change an element in the vector
Enter the index of the element to change: 1
Enter the new value: 0
Element changed at index 1 to 0

Remove an element from the vector
Enter the index of the element to remove: 0
Element at index 0 removed.

Final vector elements: 0 6