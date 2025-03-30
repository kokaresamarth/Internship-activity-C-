Q4.write a c++ program for perform multilevel inheritance using class, vector and exception handling techniques.

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

class Person 
{
protected:
    string name;
    int age;

public:
    Person(string name = "", int age = 0) 
    {
        if (age < 0) 
        {
            throw invalid_argument("Age cannot be negative.");
        }
        this->name = name;
        this->age = age;
    }

    void displayPersonInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Employee : public Person
{
protected:
    string company;
    double salary;

public:
    Employee(string name = "", int age = 0, string company = "", double salary = 0.0)
        : Person(name, age)
        {
        if (salary < 0) 
        {
            throw invalid_argument("Salary cannot be negative.");
        }
        this->company = company;
        this->salary = salary;
    }

    void displayEmployeeInfo() 
    {
        displayPersonInfo();
        cout << "Company: " << company << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Manager : public Employee 
{
private:
    int teamSize;
    vector<string> teamMembers;

public:
    Manager(string name = "", int age = 0, string company = "", double salary = 0.0, int teamSize = 0)
        : Employee(name, age, company, salary)
        {
        if (teamSize < 0) 
        {
            throw invalid_argument("Team size cannot be negative.");
        }
        this->teamSize = teamSize;
    }

    void addTeamMember(string memberName) 
    {
        if (teamMembers.size() >= teamSize) 
        {
            throw overflow_error("Cannot add more team members than the team size.");
        }
        teamMembers.push_back(memberName);
    }

    void displayManagerInfo() 
    {
        displayEmployeeInfo();
        cout << "Team Size: " << teamSize << endl;
        cout << "Team Members: ";
        for (const auto &member : teamMembers)
        {
            cout << member << " ";
        }
        cout << endl;
    }
};

int main() 
{
    try 
    {
        cout << "Creating a valid manager object..." << endl;
        Manager manager1("John Doe", 35, "TechCorp", 85000, 3);
        manager1.addTeamMember("Alice");
        manager1.addTeamMember("Bob");
        manager1.addTeamMember("Charlie");
        manager1.displayManagerInfo();

        cout << "\nAttempting to add an extra team member..." << endl;
        manager1.addTeamMember("Diana");
    } catch (const invalid_argument &e) {
        cerr << "Error: " << e.what() << endl;
    } catch (const overflow_error &e) {
        cerr << "Error: " << e.what() << endl;
    }

    try {
        cout << "\nAttempting to create an invalid employee object..." << endl;
        
        Employee employee2("Jane Smith", 28, "InnoTech", -50000);
    } catch (const invalid_argument &e) {
        cerr << "Error: " << e.what() << endl;
    }

    try {
        cout << "\nAttempting to create an invalid manager object..." << endl;
        Manager manager2("Alice Brown", 40, "WebSolutions", 92000, -5);
    } catch (const invalid_argument &e) {
        cerr << "Error: " << e.what() << endl;
    }

    try {
        cout << "\nCreating another manager object and testing team management..." << endl;
        Manager manager3("Eve White", 45, "DataWorks", 95000, 2);
        manager3.addTeamMember("George");
        manager3.addTeamMember("Hannah");
        manager3.displayManagerInfo();

        cout << "\nAttempting to add one more team member than allowed..." << endl;
        manager3.addTeamMember("Isaac");
    } catch (const invalid_argument &e) {
        cerr << "Error: " << e.what() << endl;
    } catch (const overflow_error &e) {
        cerr << "Error: " << e.what() << endl;
    }

    cout << "\nEnd of program." << endl;
    return 0;
}

Output:

Creating a valid manager object...
Name: John Doe
Age: 35
Company: TechCorp
Salary: 85000
Team Size: 3
Team Members: Alice Bob Charlie 

Attempting to add an extra team member...
ERROR!
Error: Cannot add more team members than the team size.

Attempting to create an invalid employee object...
Error: Salary cannot be negative.

Attempting to create an invalid manager object...
Error: Team size cannot be negative.

Creating another manager object and testing team management...
Name: Eve White
Age: 45
Company: DataWorks
Salary: 95000
Team Size: 2
Team Members: George Hannah 

Attempting to add one more team member than allowed...
Error: Cannot add more team members than the team size.

End of program.