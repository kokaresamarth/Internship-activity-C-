Q3.write a c++ program for perform the multi level inheritance for employee details.

#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    string name;
    int age;

    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }

    void displayPersonDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << " years" << endl;
    }
};

class Employee : public Person {
public:
    double salary;

    Employee(string name, int age, double salary)
        : Person(name, age) {
        this->salary = salary;
    }

    void displayEmployeeDetails() {
        displayPersonDetails();
        cout << "Salary: " << salary << endl;
    }
};

class Manager : public Employee {
public:
    string department;

    Manager(string name, int age, double salary, string department)
        : Employee(name, age, salary) {
        this->department = department;
    }

    void displayManagerDetails() {
        displayEmployeeDetails();
        cout << "Department: " << department << endl;
    }
};

int main() {
    string name, department;
    int age;
    double salary;

    cout << "Enter Manager's Name: ";
    getline(cin, name);

    cout << "Enter Manager's Age: ";
    cin >> age;

    cout << "Enter Manager's Salary: ";
    cin >> salary;
    cin.ignore();  

    cout << "Enter Manager's Department: ";
    getline(cin, department);

    Manager manager1(name, age, salary, department);

    cout << endl;
    manager1.displayManagerDetails();

    return 0;
}

Output:

Enter Manager's Name: sam kuran
Enter Manager's Age: 50
Enter Manager's Salary: 100000
Enter Manager's Department: game

Name: sam kuran
Age: 50 years
Salary: 100000
Department: game