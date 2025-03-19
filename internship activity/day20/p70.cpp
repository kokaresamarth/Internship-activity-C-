Q3.write a c++ program for perform the Assignment operator over loading task.

#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    int inches;
public:
    Distance() {
        feet = 0;
        inches = 0;
    }
    Distance(int f, int i) {
        feet = f;
        inches = i;
    }
    void operator=(const Distance &D) {
        feet = D.feet;
        inches = D.inches;
    }
    void displayDistance() const {
        cout << "F: " << feet << " I: " << inches << endl;
    }

    void inputDistance() {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }
};

int main() {
    Distance D1, D2;

    cout << "Enter the first distance:" << endl;
    D1.inputDistance();
    
    cout << "Enter the second distance:" << endl;
    D2.inputDistance();

    cout << "First Distance: ";
    D1.displayDistance();
    cout << "Second Distance: ";
    D2.displayDistance();

    D1 = D2;

    cout << "First Distance after assignment: ";
    D1.displayDistance();

    return 0;
}

Output:

Enter the first distance:
Enter feet:
20
Enter inches: 10
Enter the second distance:
Enter feet: 40
Enter inches: 20
First Distance: F: 20 I: 10
Second Distance: F: 40 I: 20
First Distance after assignment: F: 40 I: 20
