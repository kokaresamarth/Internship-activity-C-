Q2.c++ list program for Add elements Access elements Change elements Remove elements through iterators

#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main() {
    list<int> lst;
    int element, position;

    cout << "Enter number of elements to add: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> element;
        lst.push_back(element);
    }

    cout << "\nAccess elements by index\n";
    cout << "Enter the index to access an element: ";
    cin >> position;
    
    if (position >= 0 && position < lst.size()) {
        list<int>::iterator it = lst.begin();
        cout << "Element at index " << position << " is: " << *it << endl;
    } else {
        cout << "Invalid index!\n";
    }
    cout << "\nChange an element in the list\n";
    cout << "Enter the index of the element to change: ";
    cin >> position;

    if (position >= 0 && position < lst.size()) {
        cout << "Enter the new value: ";
        cin >> element;
        list<int>::iterator it = lst.begin();
        *it = element;
        cout << "Element changed at index " << position << " to " << *it << endl;
    } else {
        cout << "Invalid index!\n";
    }

    cout << "\nRemove an element from the list\n";
    cout << "Enter the index of the element to remove: ";
    cin >> position;

    if (position >= 0 && position < lst.size()) {
        list<int>::iterator it = lst.begin();
        lst.erase(it);
        cout << "Element at index " << position << " removed.\n";
    } else {
        cout << "Invalid index!\n";
    }
    cout << "\nFinal list elements: ";
    list<int>::iterator it;
    for (it = lst.begin(); it != lst.end(); ++it) {
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
Element at index 2 is: 4

Change an element in the list
Enter the index of the element to change: 1
Enter the new value: 0
Element changed at index 1 to 0

Remove an element from the list
Enter the index of the element to remove: 0
Element at index 0 removed.

Final list elements: 5 6