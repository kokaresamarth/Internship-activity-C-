
Q5.write a c++ program for file handling open, write, read, append, check error, close the file.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
   
    fstream file;

    file.open("example.txt", ios::out); 
    if (!file) {
        cerr << "Error opening file for writing!" << endl;
        return 1; 
    }
    file << "Hello, this is a test file for file handling in C++.\n";
    file << "We are writing this text to the file.\n";
    file.close(); 
    cout << "File written successfully." << endl;

    
    file.open("example.txt", ios::in);
    if (!file) {
        cerr << "Error opening file for reading!" << endl;
        return 1; 
    }
    string line;
    cout << "Reading from the file:\n";
    while (getline(file, line)) { 
        cout << line << endl;
    }
    file.close(); 
    cout << "File read successfully." << endl;

    file.open("example.txt", ios::app); 
    if (!file) {
        cerr << "Error opening file for appending!" << endl;
        return 1; 
    }
    file << "This is the appended text.\n";
    file.close(); 
    cout << "Text appended to the file successfully." << endl;

    
    file.open("example.txt", ios::in);
    if (!file) {
        cerr << "Error opening the file!" << endl;
        return 1; 
    } else {
        cout << "File opened successfully for error checking!" << endl;
    }
    file.close(); 

    return 0;
}

Output:

File written successfully.
Reading from the file:
Hello, this is a test file for file handling in C++.
We are writing this text to the file.
File read successfully.
Text appended to the file successfully.
File opened successfully for error checking!

Hello, this is a test file for file handling in C++.
We are writing this text to the file.
This is the appended text.