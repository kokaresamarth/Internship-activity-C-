Q5.write a c++ program for Insert,update,delete user details and save in to the text file.


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Student {
    int id;
    string name;
    int age;
};

int main() {
    string choice;
    cout << "File Handling Menu\n";
    cout << "Insert Record\n";
    cout << "Display Records\n";
    cout << "Update Record\n";
    cout << "Delete Record\n";
    cout << "Exit\n";
    cout << "Enter your choice (Insert/Display/Update/Delete/Exit): ";
    cin >> choice;

    if (choice == "Insert") {
        ofstream outFile("students.txt", ios::app);
        if (!outFile) { cout << "Error opening file!\n"; return 1; }

        Student student;
        cout << "Enter Student ID, Name, Age: ";
        cin >> student.id;
        cin.ignore();
        getline(cin, student.name);
        cin >> student.age;

        outFile << student.id << " " << student.name << " " << student.age << endl;
        outFile.close();
        cout << "Record inserted successfully!\n";
    }
    else if (choice == "Display") {
        ifstream inFile("students.txt");
        if (!inFile) { cout << "Error opening file!\n"; return 1; }

        Student student;
        while (inFile >> student.id >> student.name >> student.age) {
            cout << "ID: " << student.id << ", Name: " << student.name << ", Age: " << student.age << endl;
        }
        inFile.close();
    }
    else if (choice == "Update") {
        int searchId;
        cout << "Enter Student ID to update: ";
        cin >> searchId;

        ifstream inFile("students.txt");
        if (!inFile) { cout << "Error opening file!\n"; return 1; }

        vector<Student> students;
        Student student;
        bool found = false;
        while (inFile >> student.id >> student.name >> student.age) {
            if (student.id == searchId) {
                found = true;
                cout << "Record found! Enter new Name, Age: ";
                cin.ignore();
                getline(cin, student.name);
                cin >> student.age;
            }
            students.push_back(student);
        }
        inFile.close();

        if (!found) { cout << "No record found!\n"; return 1; }

        ofstream outFile("students.txt");
        if (!outFile) { cout << "Error opening file!\n"; return 1; }

        for (auto& s : students) {
            outFile << s.id << " " << s.name << " " << s.age << endl;
        }
        outFile.close();
        cout << "Record updated successfully!\n";
    }
    else if (choice == "Delete") {
        int deleteId;
        cout << "Enter Student ID to delete: ";
        cin >> deleteId;

        ifstream inFile("students.txt");
        if (!inFile) { cout << "Error opening file!\n"; return 1; }

        vector<Student> students;
        Student student;
        bool found = false;
        while (inFile >> student.id >> student.name >> student.age) {
            if (student.id != deleteId) {
                students.push_back(student);
            }
            else {
                found = true;
            }
        }
        inFile.close();

        if (!found) { cout << "No record found!\n"; return 1; }

        ofstream outFile("students.txt");
        if (!outFile) { cout << "Error opening file!\n"; return 1; }

        for (auto& s : students) {
            outFile << s.id << " " << s.name << " " << s.age << endl;
        }
        outFile.close();
        cout << "Record deleted successfully!\n";
    }
    else if (choice == "Exit") {
        cout << "Exiting...\n";
    }
    else {
        cout << "Invalid choice! Exiting...\n";
    }
    return 0;
}

Output:

File Handling Menu
Insert Record
Display Records
Update Record
Delete Record
Exit
Enter your choice (Insert/Display/Update/Delete/Exit): Insert
Enter Student ID, Name, Age:
123
Samarth
23
Record inserted successfully!