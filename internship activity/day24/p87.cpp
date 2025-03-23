Q1.write a c++ program for perform library management operations using struct,vector.

#include <iostream>
#include <vector>
#include <string> 
using namespace std;

struct Book {
    int id;
    string title;
    string author;
    bool isBorrowed;
};

void displayMenu() {
    cout << "\nLibrary Management System\n";
    cout << "1. Add a Book\n";
    cout << "2. View Books\n";
    cout << "3. Search Book by Title\n";
    cout << "4. Borrow a Book\n";
    cout << "5. Return a Book\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

void addBook(vector<Book> &library) {
    Book newBook;
    cout << "\nEnter Book ID: ";
    cin >> newBook.id;
    cin.ignore(); 
    cout << "Enter Book Title: ";
    getline(cin, newBook.title);
    cout << "Enter Author: ";
    getline(cin, newBook.author);
    newBook.isBorrowed = false;
    library.push_back(newBook);
    cout << "Book added successfully!\n";
}

void viewBooks(const vector<Book> &library) {
    cout << "\nAvailable Books:\n";
    for (const auto &book : library) {
        cout << "ID: " << book.id
             << ", Title: " << book.title
             << ", Author: " << book.author
             << ", Borrowed: " << (book.isBorrowed ? "Yes" : "No") << "\n";
    }
}

void searchBook(const vector<Book> &library) {
    string title;
    cout << "\nEnter the title to search: ";
    cin.ignore();
    getline(cin, title);
    bool found = false;
    for (const auto &book : library) {
        if (book.title == title) {
            cout << "Book Found:\n";
            cout << "ID: " << book.id
                 << ", Title: " << book.title
                 << ", Author: " << book.author
                 << ", Borrowed: " << (book.isBorrowed ? "Yes" : "No") << "\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book not found.\n";
    }
}

void borrowBook(vector<Book> &library) {
    int id;
    cout << "\nEnter the ID of the book to borrow: ";
    cin >> id;
    for (auto &book : library) {
        if (book.id == id) {
            if (book.isBorrowed) {
                cout << "Book is already borrowed.\n";
            } else {
                book.isBorrowed = true;
                cout << "Book borrowed successfully!\n";
            }
            return;
        }
    }
    cout << "Book with ID " << id << " not found.\n";
}

void returnBook(vector<Book> &library) {
    int id;
    cout << "\nEnter the ID of the book to return: ";
    cin >> id;
    for (auto &book : library) {
        if (book.id == id) {
            if (!book.isBorrowed) {
                cout << "Book was not borrowed.\n";
            } else {
                book.isBorrowed = false;
                cout << "Book returned successfully!\n";
            }
            return;
        }
    }
    cout << "Book with ID " << id << " not found.\n";
}

int main() {
    vector<Book> library;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            addBook(library);
            break;
        case 2:
            viewBooks(library);
            break;
        case 3:
            searchBook(library);
            break;
        case 4:
            borrowBook(library);
            break;
        case 5:
            returnBook(library);
            break;
        case 6:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

Output:

Library Management System
1. Add a Book
2. View Books
3. Search Book by Title
4. Borrow a Book
5. Return a Book
6. Exit
Enter your choice: 1

Enter Book ID: 101
Enter Book Title: titanic
Enter Author: samarth
Book added successfully!

Library Management System
1. Add a Book
2. View Books
3. Search Book by Title
4. Borrow a Book
5. Return a Book
6. Exit
Enter your choice: 2

Available Books:
ID: 101, Title: titanic, Author: samarth, Borrowed: No

Library Management System
1. Add a Book
2. View Books
3. Search Book by Title
4. Borrow a Book
5. Return a Book
6. Exit
Enter your choice: 3

Enter the title to search: titanic
Book Found:
ID: 101, Title: titanic, Author: samarth, Borrowed: No

Library Management System
1. Add a Book
2. View Books
3. Search Book by Title
4. Borrow a Book
5. Return a Book
6. Exit
Enter your choice: 4

Enter the ID of the book to borrow: 101
Book borrowed successfully!

Library Management System
1. Add a Book
2. View Books
3. Search Book by Title
4. Borrow a Book
5. Return a Book
6. Exit
Enter your choice: 5

Enter the ID of the book to return: 101
Book returned successfully!

Library Management System
1. Add a Book
2. View Books
3. Search Book by Title
4. Borrow a Book
5. Return a Book
6. Exit
Enter your choice: 6
Exiting the program.