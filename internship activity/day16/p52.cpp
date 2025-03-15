Q4.c++ map program for Add elements Access elements Change elements Remove elements through iterators using exception handling try,catch,throw.

#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, int> m; 
    int key, value;

    cout << "Enter number of elements to add: ";
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Enter key and value for element " << i + 1 << ": ";
        cin >> key >> value;
        m[key] = value; 
    }

    try {
        cout << "\nAccess elements in the map\n";
        cout << "Enter the index to access an element: ";
        int position;
        cin >> position;

        if (position < 0 || position >= m.size()) {
            throw out_of_range("Invalid index for access.");
        }

        map<int, int>::iterator it = m.begin();
        for (int i = 0; i < position; ++i) {
            ++it; 
        }
        cout << "Element at index " << position << " (key-value pair) is: " << it->first << " - " << it->second << endl;

        cout << "\nModify an element in the map\n";
        cout << "Enter the index of the element to modify: ";
        cin >> position;
        if (position < 0 || position >= m.size()) {
            throw out_of_range("Invalid index for modification.");
        }

        map<int, int>::iterator it2 = m.begin();
        for (int i = 0; i < position; ++i) {
            ++it2;
        }

        cout << "Enter the new value: ";
        cin >> value;
        it2->second = value;
        cout << "Element at index " << position << " (key-value pair) modified to: " << it2->first << " - " << it2->second << endl;

        cout << "\nRemove an element from the map\n";
        cout << "Enter the index of the element to remove: ";
        cin >> position;
        if (position < 0 || position >= m.size()) {
            throw out_of_range("Invalid index for removal.");
        }

        map<int, int>::iterator it3 = m.begin();
        for (int i = 0; i < position; ++i) {
            ++it3; 
        }
        m.erase(it3); 
        cout << "Element removed from the map.\n";

        cout << "\nFinal map elements (key-value pairs): ";
        for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
            cout << "(" << it->first << ", " << it->second << ") ";
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

Enter number of elements to add: 6
Enter key and value for element 1: 2 3
Enter key and value for element 2: 4 6
Enter key and value for element 3: 6 9
Enter key and value for element 4: 8 12
Enter key and value for element 5: 10 15
Enter key and value for element 6: 12 18

Access elements in the map
Enter the index to access an element: 3
Element at index 3 (key-value pair) is: 8 - 12

Modify an element in the map
Enter the index of the element to modify: 0
Enter the new value: 55
Element at index 0 (key-value pair) modified to: 2 - 55

Remove an element from the map
Enter the index of the element to remove: 2
Element removed from the map.

Final map elements (key-value pairs): (2, 55) (4, 6) (8, 12) (10, 15) (12, 18)