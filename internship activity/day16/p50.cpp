Q2.c++ list program for Add elements Access elements Change elements Remove elements through iterators using exception handling try,catch,throw.

#include <iostream>
#include <list>


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

    try {
        cout << "\nAccess elements by index\n";
        cout << "Enter the index to access an element: ";
        cin >> position;
        if (position < 0 || position >= n) {
            throw out_of_range("Invalid index for access.");
        }
        
        list<int>::iterator it = lst.begin();
        for (int i = 0; i < position; ++i) {
            ++it; 
        }
        cout << "Element at index " << position << " is: " << *it << endl;

       
        cout << "\nChange an element in the list\n";
        cout << "Enter the index of the element to change: ";
        cin >> position;
        if (position < 0 || position >= n) {
            throw out_of_range("Invalid index for modification.");
        }

        list<int>::iterator it2 = lst.begin();
        for (int i = 0; i < position; ++i) {
            ++it2; 
        }
        cout << "Enter the new value: ";
        cin >> element;
        *it2 = element; 
        cout << "Element changed at index " << position << " to " << *it2 << endl;

        cout << "\nRemove an element from the list\n";
        cout << "Enter the index of the element to remove: ";
        cin >> position;
        if (position < 0 || position >= n) {
            throw out_of_range("Invalid index for removal.");
        }

        list<int>::iterator it3 = lst.begin();
        for (int i = 0; i < position; ++i) {
            ++it3; 
        }
        lst.erase(it3); 
        cout << "Element at index " << position << " removed.\n";

        cout << "\nFinal list elements: ";
        for (list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
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

Enter number of elements to add: 3
Enter element 1: 2
Enter element 2: 4
Enter element 3: 6

Access elements by index
Enter the index to access an element: 2
Element at index 2 is: 6

Change an element in the list
Enter the index of the element to change: 2
Enter the new value: 8
Element changed at index 2 to 8

Remove an element from the list
Enter the index of the element to remove: 0
Element at index 0 removed.

Final list elements: 4 8