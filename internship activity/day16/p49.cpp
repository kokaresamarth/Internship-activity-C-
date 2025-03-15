Q1.c++ vector program for Add elements Access elements Change elements Remove elements through iterators using exception handling try,catch,throw.

#include <iostream>
#include <vector>

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

    try {
        cout << "\nAccess elements by index\n";
        cout << "Enter the index to access an element: ";
        cin >> position;
        if (position < 0 || position >= vec.size()) {
            throw out_of_range("Invalid index for access.");
        }
        cout << "Element at index " << position << " is: " << vec[position] << endl;

        cout << "\nChange an element in the vector\n";
        cout << "Enter the index of the element to change: ";
        cin >> position;
        if (position < 0 || position >= vec.size()) {
            throw out_of_range("Invalid index for modification.");
        }
        cout << "Enter the new value: ";
        cin >> element;
        vec[position] = element;
        cout << "Element changed at index " << position << " to " << vec[position] << endl;

        cout << "\nRemove an element from the vector\n";
        cout << "Enter the index of the element to remove: ";
        cin >> position;
        if (position < 0 || position >= vec.size()) {
            throw out_of_range("Invalid index for removal.");
        }
        vec.erase(vec.begin() + position);
        cout << "Element at index " << position << " removed.\n";

        cout << "\nFinal vector elements: ";
        for (auto it = vec.begin(); it != vec.end(); ++it) {
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

Enter number of elements to add: 4
Enter element 1: 2
Enter element 2: 4
Enter element 3: 6
Enter element 4: 8

Access elements by index
Enter the index to access an element: 3
Element at index 3 is: 8

Change an element in the vector
Enter the index of the element to change: 0
Enter the new value: 1
Element changed at index 0 to 1

Remove an element from the vector
Enter the index of the element to remove: 2
Element at index 2 removed.

Final vector elements: 1 4 8