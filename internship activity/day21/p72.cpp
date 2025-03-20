Q1.write a c++ program for perform the single inheritance for Student details.

#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    string name;
    int age;
    string course;

    Student(string name, int age, string course) {
        this->name = name;
        this->age = age;
        this->course = course;
    }

    void displayDetails() {
        cout << "Student Name: " << name << endl;
        cout << "Student Age: " << age << " years" << endl;
        cout << "Course: " << course << endl;
    }

    void study() {
        cout << name << " is studying!" << endl;
    }
};

class GraduateStudent : public Student {
public:
    string thesisTitle;

    GraduateStudent(string name, int age, string course, string thesisTitle)
        : Student(name, age, course) {
        this->thesisTitle = thesisTitle;
    }

    void displayGraduateDetails() {
        displayDetails();
        cout << "Thesis Title: " << thesisTitle << endl;
    }

    void presentThesis() {
        cout << name << " is presenting the thesis: " << thesisTitle << endl;
    }
};

int main() {
    string name, course, thesisTitle;
    int age;

    cout << "Enter Student's Name: ";
    getline(cin, name);

    cout << "Enter Student's Age: ";
    cin >> age;
    cin.ignore();

    cout << "Enter Student's Course: ";
    getline(cin, course);

    cout << "Enter Thesis Title: ";
    getline(cin, thesisTitle);

    GraduateStudent gradStudent1(name, age, course, thesisTitle);

    cout << endl;
    gradStudent1.displayGraduateDetails();
    gradStudent1.presentThesis();
    gradStudent1.study();

    return 0;
}

Output:

Enter Student's Name: samarth
Enter Student's Age: 22
Enter Student's Course: cs123
Enter Thesis Title: CD

Student Name: samarth
Student Age: 22 years
Course: cs123
Thesis Title: CD
samarth is presenting the thesis: CD
samarth is studying!