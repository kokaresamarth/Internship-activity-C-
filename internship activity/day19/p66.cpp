Q4.write a c++ program for perform the following string operations

Function	Description
copy()	Copies characters from a string into a char array.
capacity()	Returns the total capacity of the string.
replace()	Replaces part of the string with another string.
empty()	Checks if the string is empty.

#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    
    cout << "Enter a string: ";
    getline(cin, str);
    int length = str.length();
    char charArray[length + 1]; 
    str.copy(charArray, length);
    charArray[length] = '\0';  
    cout << "Copied string to char array: " << charArray << endl;
    
    cout << "The capacity of the string is: " << str.capacity() << endl;

    string toReplace, replacement;
    cout << "Enter a substring to replace: ";
    getline(cin, toReplace);
    cout << "Enter the replacement string: ";
    getline(cin, replacement);
    
    size_t pos = str.find(toReplace);
    if (pos != string::npos) {
        str.replace(pos, toReplace.length(), replacement);
        cout << "Updated string after replacement: " << str << endl;
    } else {
        cout << "Substring to replace not found!" << endl;
    }

    if (str.empty()) {
        cout << "The string is empty." << endl;
    } else {
        cout << "The string is not empty." << endl;
    }

    return 0;
}

Output:

Enter a string: Samarth Kokare
Copied string to char array: Samarth Kokare
The capacity of the string is: 15
Enter a substring to replace: Kokare
Enter the replacement string: Its my Name
Updated string after replacement: Samarth Its my Name
The string is not empty.