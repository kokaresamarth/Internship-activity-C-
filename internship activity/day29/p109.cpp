Q3.write a c++ program for Nested Containers set,map Design a program that uses  to manage groups of students. Implement functions to:

Add a student to a group.
Remove a student from a group.
Get all students in a specific group.
Print all groups and their students.

#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

using GroupMap = map<int, set<string>>;

void addStudentToGroup(GroupMap& groups, int groupID, const string& studentName) 
{
    groups[groupID].insert(studentName);
    cout << "Added " << studentName << " to group " << groupID << ".\n";
}

void removeStudentFromGroup(GroupMap& groups, int groupID, const string& studentName) 
{
    auto group = groups.find(groupID);
    if (group != groups.end() && group->second.erase(studentName)) 
    {
        cout << "Removed " << studentName << " from group " << groupID << ".\n";
        if (group->second.empty())
        {
            groups.erase(groupID);
            cout << "Group " << groupID << " is now empty and has been removed.\n";
        }
    }
    else
    {
        cout << "Student " << studentName << " not found in group " << groupID << ".\n";
    }
}

void getStudentsInGroup(const GroupMap& groups, int groupID) 
{
    auto group = groups.find(groupID);
    if (group != groups.end()) {
        cout << "Students in group " << groupID << ":\n";
        for (const auto& student : group->second) 
        {
            cout << "- " << student << '\n';
        }
    } 
    else
    {
        cout << "Group " << groupID << " does not exist.\n";
    }
}

void printAllGroups(const GroupMap& groups)
{
    if (groups.empty())
    {
        cout << "No groups to display.\n";
        return;
    }
    cout << "All groups and their students:\n";
    for (const auto& group : groups) 
    {
        cout << "Group " << group.first << ":\n";
        for (const auto& student : group.second) 
        {
            cout << "- " << student << '\n';
        }
    }
}

int main()
{
    GroupMap groups;

    addStudentToGroup(groups, 1, "Alice");
    addStudentToGroup(groups, 1, "Bob");
    addStudentToGroup(groups, 2, "Charlie");
    addStudentToGroup(groups, 2, "David");
    addStudentToGroup(groups, 3, "Eve");

    printAllGroups(groups);
    cout << '\n';

    removeStudentFromGroup(groups, 2, "Charlie");
    cout << '\n';

    printAllGroups(groups);
    cout << '\n';

    getStudentsInGroup(groups, 1);
    cout << '\n';

    removeStudentFromGroup(groups, 2, "Frank");
    cout << '\n';

    printAllGroups(groups);

    return 0;
}

Output:

Added Alice to group 1.
Added Bob to group 1.
Added Charlie to group 2.
Added David to group 2.
Added Eve to group 3.
All groups and their students:
Group 1:
- Alice
- Bob
Group 2:
- Charlie
- David
Group 3:
- Eve

Removed Charlie from group 2.

All groups and their students:
Group 1:
- Alice
- Bob
Group 2:
- David
Group 3:
- Eve

Students in group 1:
- Alice
- Bob

Student Frank not found in group 2.

All groups and their students:
Group 1:
- Alice
- Bob
Group 2:
- David
Group 3:
- Eve