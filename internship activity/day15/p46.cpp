Q2.c++ multimap program for Add elements Access elements Change elements Remove elements through iterators

#include <iostream>
#include <map>
#include <iterator>

using namespace std;

int main() {
    multimap<int, int> mmap;
    int key, value, numElements;

    cout << "How many key-value pairs would you like to add to the multimap? ";
    cin >> numElements;

    for (int i = 0; i < numElements; ++i) {
        cout << "Enter key for element " << i + 1 << ": ";
        cin >> key;
        cout << "Enter value for key " << key << ": ";
        cin >> value;
        mmap.insert({key, value});
    }
    cout << numElements << " key-value pair(s) added to multimap.\n";

    cout << "\nMultimap elements (key-value pairs): \n";
    for (auto it = mmap.begin(); it != mmap.end(); ++it) {
        cout << "Key: " << it->first << ", Value: " << it->second << "\n";
    }

    cout << "\nEnter key whose value you want to change: ";
    cin >> key;

    auto range = mmap.equal_range(key);
    if (range.first != range.second) {
        cout << "Enter new value for key " << key << ": ";
        cin >> value;
     
        mmap.erase(key);
        mmap.insert({key, value});
        cout << "Value for key " << key << " changed to " << value << ".\n";
    } else {
        cout << "Key " << key << " not found in multimap.\n";
    }

    cout << "\nUpdated multimap elements (key-value pairs): \n";
    for (auto it = mmap.begin(); it != mmap.end(); ++it) {
        cout << "Key: " << it->first << ", Value: " << it->second << "\n";
    }

    cout << "\nEnter key to remove from multimap: ";
    cin >> key;

    if (mmap.count(key) > 0) {
        mmap.erase(key);
        cout << "All entries with key " << key << " removed from multimap.\n";
    } else {
        cout << "Key " << key << " not found in multimap.\n";
    }

    cout << "\nFinal multimap elements (key-value pairs): \n";
    for (auto it = mmap.begin(); it != mmap.end(); ++it) {
        cout << "Key: " << it->first << ", Value: " << it->second << "\n";
    }

    return 0;
}


Output:

How many key-value pairs would you like to add to the multimap? 3
Enter key for element 1: 2 2
Enter value for key 2: Enter key for element 2: 5 4
Enter value for key 5: Enter key for element 3: 7 8
Enter value for key 7: 3 key-value pair(s) added to multimap.

Multimap elements (key-value pairs):
Key: 2, Value: 2
Key: 5, Value: 4
Key: 7, Value: 8

Enter key whose value you want to change: 5
Enter new value for key 5: 6
Value for key 5 changed to 6.

Updated multimap elements (key-value pairs):
Key: 2, Value: 2
Key: 5, Value: 6
Key: 7, Value: 8

Enter key to remove from multimap: 7
All entries with key 7 removed from multimap.

Final multimap elements (key-value pairs):
Key: 2, Value: 2
Key: 5, Value: 6