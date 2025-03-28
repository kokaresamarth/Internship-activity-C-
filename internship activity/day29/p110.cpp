Q4.write a c++ program for string operations like palindrome or not,longest common prefix,anagrams or not.

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool isPalindrome(const string& str) 
{
    int start = 0;
    int end = str.length() - 1;
    while (start < end) 
    {
        if (str[start] != str[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

string longestCommonPrefix(vector<string>& strs)
{
    if (strs.empty()) return "";
    sort(strs.begin(), strs.end());
    string first = strs[0];
    string last = strs[strs.size() - 1];
    int i = 0;
    while (i < first.length() && i < last.length() && first[i] == last[i]) 
    {
        i++;
    }
    return first.substr(0, i);
}

bool areAnagrams(const string& str1, const string& str2) 
{
    if (str1.length() != str2.length()) return false;
    unordered_map<char, int> freq;
    for (char ch : str1) freq[ch]++;
    for (char ch : str2) 
    {
        if (freq[ch] == 0) return false;
        freq[ch]--;
    }
    return true;
}

int main()
{
    string str, substr;
    vector<string> strs;
    int choice;
    
    while (true) 
    {
        cout << "\nString Operations Menu:\n";
        cout << "1. Check if palindrome\n";
        cout << "2. Longest common prefix\n";
        cout << "3. Check if two strings are anagrams\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter string: ";
                cin >> str;
                cout << "Is palindrome? " << (isPalindrome(str) ? "Yes" : "No") << endl;
                break;
            case 2:
                cout << "Enter number of strings: ";
                int n;
                cin >> n;
                strs.resize(n);
                cout << "Enter strings:\n";
                for (int i = 0; i < n; i++)
                {
                    cin >> strs[i];
                }
                cout << "Longest common prefix: " << longestCommonPrefix(strs) << endl;
                break;
            case 3:
                cout << "Enter first string: ";
                cin >> str;
                cout << "Enter second string: ";
                cin >> substr;
                cout << "Are anagrams? " << (areAnagrams(str, substr) ? "Yes" : "No") << endl;
                break;
            case 4:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

Output:

String Operations Menu:
1. Check if palindrome
2. Longest common prefix
3. Check if two strings are anagrams
4. Exit
Enter your choice: 1
Enter string: gadag
Is palindrome? Yes

String Operations Menu:
1. Check if palindrome
2. Longest common prefix
3. Check if two strings are anagrams
4. Exit
Enter your choice: 2
Enter number of strings: 3
Enter strings:
hello
hi
health
Longest common prefix: h

String Operations Menu:
1. Check if palindrome
2. Longest common prefix
3. Check if two strings are anagrams
4. Exit
Enter your choice: 3
Enter first string: eat
Enter second string: ate
Are anagrams? Yes

String Operations Menu:
1. Check if palindrome
2. Longest common prefix
3. Check if two strings are anagrams
4. Exit
Enter your choice: 4
Exiting program...