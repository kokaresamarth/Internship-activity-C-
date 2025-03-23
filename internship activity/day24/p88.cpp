Q2.write a c++ program for perform product details operations using Exception handling Techniques.

#include <iostream>
#include <string>
using namespace std;

struct Product {
    int id;
    string name;
    double price;
    int quantity;
};

class InvalidInputException {
public:
    string message;
    InvalidInputException(string msg) : message(msg) {}
};

void displayMenu() {
    cout << "\nInventory Management System\n";
    cout << "1. Add Product\n";
    cout << "2. View Products\n";
    cout << "3. Search Product by ID\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int getValidatedIntInput(const string &prompt) {
    int value;
    cout << prompt;
    cin >> value;
    if (cin.fail() || value <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw InvalidInputException("Invalid input. Enter a positive integer.");
    }
    return value;
}

double getValidatedDoubleInput(const string &prompt) {
    double value;
    cout << prompt;
    cin >> value;
    if (cin.fail() || value <= 0.0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw InvalidInputException("Invalid input. Enter a positive number.");
    }
    return value;
}

void addProduct(Product inventory[], int &count, const int maxProducts) {
    if (count >= maxProducts) {
        throw InvalidInputException("Inventory full. Cannot add more products.");
    }
    try {
        Product newProduct;
        newProduct.id = getValidatedIntInput("Enter Product ID: ");
        cin.ignore();
        cout << "Enter Product Name: ";
        getline(cin, newProduct.name);
        newProduct.price = getValidatedDoubleInput("Enter Product Price: ");
        newProduct.quantity = getValidatedIntInput("Enter Product Quantity: ");
        inventory[count++] = newProduct;
        cout << "Product added successfully!\n";
    } catch (InvalidInputException &e) {
        cout << "Error: " << e.message << "\n";
    }
}

void viewProducts(Product inventory[], int count) {
    if (count == 0) {
        cout << "No products available.\n";
        return;
    }
    cout << "\nProduct List:\n";
    for (int i = 0; i < count; ++i) {
        cout << "ID: " << inventory[i].id
             << ", Name: " << inventory[i].name
             << ", Price: $" << inventory[i].price
             << ", Quantity: " << inventory[i].quantity << "\n";
    }
}

void searchProduct(Product inventory[], int count) {
    try {
        int id = getValidatedIntInput("Enter Product ID to search: ");
        for (int i = 0; i < count; ++i) {
            if (inventory[i].id == id) {
                cout << "Product Found:\n";
                cout << "ID: " << inventory[i].id
                     << ", Name: " << inventory[i].name
                     << ", Price: $" << inventory[i].price
                     << ", Quantity: " << inventory[i].quantity << "\n";
                return;
            }
        }
        throw InvalidInputException("Product not found.");
    } catch (InvalidInputException &e) {
        cout << "Error: " << e.message << "\n";
    }
}

int main() {
    const int maxProducts = 50;
    Product inventory[maxProducts];
    int count = 0;
    int choice;

    do {
        displayMenu();
        try {
            choice = getValidatedIntInput("");
            switch (choice) {
            case 1:
                addProduct(inventory, count, maxProducts);
                break;
            case 2:
                viewProducts(inventory, count);
                break;
            case 3:
                searchProduct(inventory, count);
                break;
            case 4:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice!\n";
            }
        } catch (InvalidInputException &e) {
            cout << "Error: " << e.message << "\n";
        }
    } while (choice != 4);

    return 0;
}

Output:

Inventory Management System
1. Add Product
2. View Products
3. Search Product by ID
4. Exit
Enter your choice: 1
Enter Product ID: 150
Enter Product Name: laptop
Enter Product Price: 20000
Enter Product Quantity: 10
Product added successfully!

Inventory Management System
1. Add Product
2. View Products
3. Search Product by ID
4. Exit
Enter your choice: 2

Product List:
ID: 150, Name: laptop, Price: $20000, Quantity: 10

Inventory Management System
1. Add Product
2. View Products
3. Search Product by ID
4. Exit
Enter your choice: 3
Enter Product ID to search: 150
Product Found:
ID: 150, Name: laptop, Price: $20000, Quantity: 10

Inventory Management System
1. Add Product
2. View Products
3. Search Product by ID
4. Exit
Enter your choice: 4
Exiting the program.