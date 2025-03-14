Q1.c++ multiset program for Add elements Access elements Change elements Remove elements through iterators

#include <iostream>
#include <set>
#include <iterator>

using namespace std;

int main() {
    multiset<int> mset;
    int element;
    int numElements;

    cout << "How many elements would you like to add to the multiset ";
    cin >> numElements;

    for (int i = 0; i < numElements; ++i) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> element;
        mset.insert(element);
    }
    cout << numElements << " element(s) added to multiset.\n";

    cout << "\nMultiset elements: ";
    for (auto it = mset.begin(); it != mset.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";

    cout << "Enter element to change: ";
    cin >> element;
   
    if (mset.count(element) > 0) {
        mset.erase(element);
        cout << "Element " << element << " removed. Now, enter new element: ";
        cin >> element;
        mset.insert(element);
        cout << "Element " << element << " added to multiset.\n";
    } else {
        cout << "Element " << element << " not found in multiset.\n";
    }

    cout << "\nUpdated multiset elements: ";
    for (auto it = mset.begin(); it != mset.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";

    cout << "Enter element to remove: ";
    cin >> element;

    if (mset.count(element) > 0) {
        mset.erase(element);
        cout << "Element " << element << " removed from multiset.\n";
    } else {
        cout << "Element " << element << " not found in multiset.\n";
    }

    cout << "\nFinal multiset elements: ";
    for (auto it = mset.begin(); it != mset.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";

    return 0;
}

Output:

How many elements would you like to add to the multiset 4
Enter element 1: 2
Enter element 2: 5
Enter element 3: 8
Enter element 4: 6
4 element(s) added to multiset.

Multiset elements: 2 5 6 8
Enter element to change: 6
Element 6 removed. Now, enter new element: 10
Element 10 added to multiset.

Updated multiset elements: 2 5 8 10
Enter element to remove: 2
Element 2 removed from multiset.

Final multiset elements: 5 8 10