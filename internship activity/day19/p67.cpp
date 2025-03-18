Q5.write a c++ program for perform the following string operations

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string str1, str2, str3;
    cout << "Enter the first string: ";
    getline(cin, str1);
    
    cout << "Enter the second string: ";
    getline(cin, str2);
    
    cout << "Enter the third string: ";
    getline(cin, str3);
    string str4 = str1 + " " + str2;  
    cout << "Concatenated string (using +): " << str4 << endl;

    str4.append(str3);  
    cout << "Concatenated string (using append): " << str4 << endl;

    int position;
    cout << "Enter the position where you want to insert a substring: ";
    cin >> position;
    cin.ignore(); 
    string insertStr;
    cout << "Enter the substring to insert: ";
    getline(cin, insertStr);
    str4.insert(position, insertStr);
    cout << "String after insert: " << str4 << endl;
    int erasePos, eraseLength;
    cout << "Enter the position and length of substring to erase: ";
    cin >> erasePos >> eraseLength;
    str4.erase(erasePos, eraseLength);
    cout << "String after erase: " << str4 << endl;
   
    int substrPos, substrLen;
    cout << "Enter the position and length to extract a substring: ";
    cin >> substrPos >> substrLen;
    string substr = str4.substr(substrPos, substrLen);  
    cout << "Extracted substring: " << substr << endl;

    string searchStr;
    cout << "Enter the string to find in the main string: ";
    cin.ignore();
    getline(cin, searchStr);

    size_t pos = str4.find(searchStr);
    if (pos != string::npos) {
        cout << "Found '" << searchStr << "' at position: " << pos << endl;
    } else {
        cout << "'" << searchStr << "' not found in the string" << endl;
    }

    reverse(str4.begin(), str4.end());
    cout << "Reversed string: " << str4 << endl;

    string oldStr, newStr;
    cout << "Enter the substring you want to replace: ";
    getline(cin, oldStr);
    cout << "Enter the replacement substring: ";
    getline(cin, newStr);
    
    size_t found = str4.find(oldStr);
    if (found != string::npos) {
        str4.replace(found, oldStr.length(), newStr);
        cout << "String after replace: " << str4 << endl;
    } else {
        cout << "'" << oldStr << "' not found to replace" << endl;
    }

    if (str4.empty()) {
        cout << "The string is empty." << endl;
    } else {
        cout << "The string is not empty." << endl;
    }

    int newSize;
    cout << "Enter the new size to resize the string: ";
    cin >> newSize;
    str4.resize(newSize);
    cout << "Resized string: " << str4 << endl;

    transform(str4.begin(), str4.end(), str4.begin(), ::toupper);
    cout << "Uppercase string: " << str4 << endl;

    transform(str4.begin(), str4.end(), str4.begin(), ::tolower);
    cout << "Lowercase string: " << str4 << endl;


    return 0;
}

Output:

Enter the first string: Hello

Enter the second string: World

Enter the third string: C++ Programming

Concatenated string (using +): Hello World

Concatenated string (using append): Hello World C++ Programming

Enter the position where you want to insert a substring: 5
Enter the substring to insert: amazing

String after insert: Hello amazing World C++ Programming

Enter the position and length of substring to erase: 5 8

String after erase: Hello World C++ Programming

Enter the position and length to extract a substring: 0 5
Extracted substring: Hello

Enter the string to find in the main string: World
Found 'World' at position: 6

Reversed string: gnimmargorP ++C dlroW olleH

Enter the substring you want to replace: C++
Enter the replacement substring: C++ Language

String after replace: gnimmargorP Language dlroW olleH
The string is not empty.

Enter the new size to resize the string: 15
Resized string: gnimmargorP Lan

Uppercase string: GNIMMARGORP LAN

Lowercase string: gnimmargorp lan