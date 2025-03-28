Q1.write a c++ program for constructor and destructor concepts for book details using class .

#include <iostream>
#include <string>
using namespace std;

class Book
{
    
private:

    string title;
    string author;
    int publicationYear;

public:
    
    Book()
    {
        title = "Unknown";
        author = "Unknown";
        publicationYear = 0;
        cout << "Default constructor called" << endl;
    }

    Book(string t, string a, int y) {
        title = t;
        author = a;
        publicationYear = y;
        cout << "Parameterized constructor called" << endl;
    }

    Book(const Book &b)
    {
        title = b.title;
        author = b.author;
        publicationYear = b.publicationYear;
        cout << "Copy constructor called" << endl;
    }

    ~Book() 
    {
        cout << "Destructor called for book: " << title << endl;
    }

    void display()
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publication Year: " << publicationYear << endl;
    }


    void setDetails(string t, string a, int y) 
    {
        title = t;
        author = a;
        publicationYear = y;
    }
    
};


int main() 
{
    
    string title, author;
    int year;

    cout << "Enter the title of the book: ";
    getline(cin, title);

    cout << "Enter the author of the book: ";
    getline(cin, author);

    cout << "Enter the publication year of the book: ";
    cin >> year;

    Book book1(title, author, year);

    cout << "\nBook details using parameterized constructor:" << endl;
    book1.display();


    Book book2;
    
    cout << "\nBook details using default constructor:" << endl;
    book2.display();

    book2.setDetails("1984", "George Orwell", 1949);
    
    cout << "\nBook details after setting values:" << endl;
    book2.display();


    Book book3 = book1;
    
    cout << "\nBook details using copy constructor:" << endl;
    book3.display();

    return 0;
}

Output:

Enter the title of the book: toxic
Enter the author of the book: geetu
Enter the publication year of the book: 2025
Parameterized constructor called

Book details using parameterized constructor:
Title: toxic
Author: geetu
Publication Year: 2025
Default constructor called

Book details using default constructor:
Title: Unknown
Author: Unknown
Publication Year: 0

Book details after setting values:
Title: 1984
Author: George Orwell
Publication Year: 1949
Copy constructor called

Book details using copy constructor:
Title: toxic
Author: geetu
Publication Year: 2025
Destructor called for book: toxic
Destructor called for book: 1984
Destructor called for book: toxic