Q4.c++ map program for Add elements Access elements Change elements Remove elements through iterators


#include <iostream>
#include <map>
#include <iterator>

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

    cout << "\nAccess elements\n";
    cout << "The elements in the map are: \n";
    for (const auto& pair : m) {
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }
    cout << "\nChange a value in the map\n";
    cout << "Enter the key to change its value: ";
    cin >> key;
    auto it = m.find(key);
    if (it != m.end()) {
        cout << "Enter the new value for key " << key << ": ";
        cin >> value;
        it->second = value; 
        cout << "Value for key " << key << " changed to " << value << endl;
    } else {
        cout << "Key not found in the map!\n";
    }
    cout << "\nRemove an element from the map\n";
    cout << "Enter the key to remove: ";
    cin >> key;
    it = m.find(key);
    if (it != m.end()) {
        m.erase(it); 
        cout << "Element with key " << key << " removed.\n";
    } else {
        cout << "Key not found in the map!\n";
    }

    cout << "\nFinal map elements: \n";
    for (const auto& pair : m) {
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }

    return 0;
}

Output:

Enter number of elements to add: 3
Enter key and value for element 1: 1 2
Enter key and value for element 2: 2 3
Enter key and value for element 3: 3 4

Access elements
The elements in the map are:
Key: 1, Value: 2
Key: 2, Value: 3
Key: 3, Value: 4

Change a value in the map
Enter the key to change its value: 2
Enter the new value for key 2: 8
Value for key 2 changed to 8

Remove an element from the map
Enter the key to remove: 1
Element with key 1 removed.

Final map elements:
Key: 2, Value: 8
Key: 3, Value: 4