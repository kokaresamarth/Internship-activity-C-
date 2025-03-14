Q4.c++ unordered map program for Add elements Access elements Change elements Remove elements through iterators

#include <iostream>
#include <unordered_map>
#include <iterator>

using namespace std;

int main() {
    unordered_map<int, int> myMap;  
    int key, value, newValue;

    cout << "Enter the number of key-value pairs to add: ";
    int numElements;
    cin >> numElements;

    for (int i = 0; i < numElements; ++i) {
        cout << "Enter key and value to add: ";
        cin >> key >> value;
        myMap[key] = value;  
    }

    cout << "\nElements in the map (key -> value): ";
    if (myMap.empty()) {
        cout << "The map is empty.\n";
    } else {
        for (auto it = myMap.begin(); it != myMap.end(); ++it) {
            cout << it->first << " -> " << it->second << " | ";
        }
        cout << endl;
    }

    cout << "\nEnter the key of the element you want to change: ";
    cin >> key;

    if (myMap.find(key) != myMap.end()) {
        cout << "Enter the new value for key " << key << ": ";
        cin >> newValue;
        myMap[key] = newValue;  
        cout << "Key " << key << " value changed to " << newValue << ".\n";
    } else {
        cout << "Key " << key << " not found.\n";
    }

    cout << "\nEnter the key you want to remove: ";
    cin >> key;

    if (myMap.find(key) != myMap.end()) {
        myMap.erase(key); 
        cout << "Key " << key << " removed.\n";
    } else {
        cout << "Key " << key << " not found.\n";
    }

    cout << "\nFinal elements in the map (key -> value): ";
    if (myMap.empty()) {
        cout << "The map is empty.\n";
    } else {
        for (auto it = myMap.begin(); it != myMap.end(); ++it) {
            cout << it->first << " -> " << it->second << " | ";
        }
        cout << endl;
    }

    return 0;
}

Output:

Enter the number of key-value pairs to add: 4
Enter key and value to add: 2 4
Enter key and value to add: 3 9
Enter key and value to add: 4 16
Enter key and value to add: 5 25

Elements in the map (key -> value): 2 -> 4 | 3 -> 9 | 4 -> 16 | 5 -> 25 |

Enter the key of the element you want to change: 2
Enter the new value for key 2: 8
Key 2 value changed to 8.

Enter the key you want to remove: 4
Key 4 removed.

Final elements in the map (key -> value): 2 -> 8 | 3 -> 9 | 5 -> 25 |