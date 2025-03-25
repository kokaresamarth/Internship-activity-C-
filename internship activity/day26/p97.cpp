Q3)implement functions to perform union, intersection, and difference operations using set container in c++.

#include <iostream>
#include <set>
using namespace std;

class SetOperations {
private:
    set<int> set1;
    set<int> set2;

public:

    void inputSets() {
        int n1, n2, element;
        
        cout << "Enter the number of elements in the first set: ";
        cin >> n1;
        cout << "Enter the elements of the first set:\n";
        for (int i = 0; i < n1; ++i) {
            cin >> element;
            set1.insert(element);
        }

        cout << "Enter the number of elements in the second set: ";
        cin >> n2;
        cout << "Enter the elements of the second set:\n";
        for (int i = 0; i < n2; ++i) {
            cin >> element;
            set2.insert(element);
        }
    }


    void displaySet(const set<int>& s, const string& name) {
        cout << name << ": ";
        for (const int& elem : s) {
            cout << elem << " ";
        }
        cout << endl;
    }


    set<int> unionSets() {
        set<int> result = set1;
        result.insert(set2.begin(), set2.end());
        return result;
    }


    set<int> intersectionSets() {
        set<int> result;
        for (const int& elem : set1) {
            if (set2.find(elem) != set2.end()) {
                result.insert(elem);
            }
        }
        return result;
    }


    set<int> differenceSets() {
        set<int> result;
        for (const int& elem : set1) {
            if (set2.find(elem) == set2.end()) {
                result.insert(elem);
            }
        }
        return result;
    }


    set<int> symmetricDifferenceSets() {
        set<int> result = unionSets();
        set<int> intersection = intersectionSets();
        for (const int& elem : intersection) {
            result.erase(elem);
        }
        return result;
    }
};


int main() {
    SetOperations operations;

    operations.inputSets();

    set<int> unionResult = operations.unionSets();
    set<int> intersectionResult = operations.intersectionSets();
    set<int> differenceResult = operations.differenceSets();
    set<int> symmetricDifferenceResult = operations.symmetricDifferenceSets();


    cout << "\nResults:\n";
    operations.displaySet(unionResult, "Union");
    operations.displaySet(intersectionResult, "Intersection");
    operations.displaySet(differenceResult, "Difference (Set1 - Set2)");
    operations.displaySet(symmetricDifferenceResult, "Symmetric Difference");

    return 0;
}

Output:

Enter the number of elements in the first set: 10
Enter the elements of the first set:
1 2 3 4 5 6 7 8 9 10
Enter the number of elements in the second set: 10
Enter the elements of the second set:
10 20 30 40 50 60 70 80 90 100

Results:
Union: 1 2 3 4 5 6 7 8 9 10 20 30 40 50 60 70 80 90 100
Intersection: 10
Difference (Set1 - Set2): 1 2 3 4 5 6 7 8 9
Symmetric Difference: 1 2 3 4 5 6 7 8 9 20 30 40 50 60 70 80 90 100