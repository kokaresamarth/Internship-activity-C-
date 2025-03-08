Q1.c++ program to find the customer and product details using class,objec,constructors
also use exception handling try,catch,throw.

Customer.h

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

class InvalidInputException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid input provided!";
    }
};

class Customer {
private:
    int customerId;
    string customerName;
    string gst;
    string contactNumber;
    string cityName;
    string productCode;
    string productName;
    double productCost;
    double taxAmount;
    double totalAmount;

public:
    Customer();
    void initialize();
    void display();
    void update();
    void saveToLogFile();
};

#endif 

Customer.cpp

#include "Customer.h"

Customer::Customer() {
    customerId = 0;
    customerName = "";
    gst = "";
    contactNumber = "";
    cityName = "";
    productCode = "";
    productName = "";
    productCost = 0.0;
    taxAmount = 0.0;
    totalAmount = 0.0;
}

void Customer::initialize() {
    try {
        cout << "Enter Customer ID: ";
        cin >> customerId;
        if (cin.fail()) {
            throw InvalidInputException();
        }
        cin.ignore();  
        cout << "Enter Customer Name: ";
        getline(cin, customerName);

        cout << "Enter GST: ";
        getline(cin, gst);

        cout << "Enter Contact Number: ";
        getline(cin, contactNumber);

        cout << "Enter City Name: ";
        getline(cin, cityName);

        cout << "Enter Product Code: ";
        getline(cin, productCode);

        cout << "Enter Product Name: ";
        getline(cin, productName);

        cout << "Enter Product Cost: ";
        cin >> productCost;
        if (cin.fail()) {
            throw InvalidInputException();
        }
        cin.ignore();  
        taxAmount = productCost * 0.18;
        totalAmount = productCost + taxAmount;
    }
    catch (const InvalidInputException& e) {
        cerr << e.what() << endl;
        exit(1);  
    }
}

void Customer::display() {
    cout << "\nCustomer Details:" << endl;
    cout << "Customer ID: " << customerId << endl;
    cout << "Customer Name: " << customerName << endl;
    cout << "GST: " << gst << endl;
    cout << "Contact Number: " << contactNumber << endl;
    cout << "City Name: " << cityName << endl;

    cout << "Product Code: " << productCode << endl;
    cout << "Product Name: " << productName << endl;
    cout << "Product Cost: " << productCost << endl;
    cout << "Tax Amount: " << taxAmount << endl;
    cout << "Total Amount (Including Tax): " << totalAmount << endl;
}

void Customer::update() {
    string input;

    cout << "\nWould you like to update the contact? (Enter one of the following: Yes, No): ";
    cin >> input;

    if (input == "Yes" || input == "yes") {
        cout << "Enter new Contact Number: ";
        cin >> contactNumber;
    } else {
        cout << "No updates made." << endl;
    }
}

void Customer::saveToLogFile() {
    try {
        ofstream outFile("logfile.txt", ios::app);
        if (!outFile.is_open()) {
            throw runtime_error("Error opening file!");
        }

        time_t now = time(0);
        char* dt = ctime(&now);

        outFile << "Customer ID: " << customerId << "\n";
        outFile << "Customer Name: " << customerName << "\n";
        outFile << "GST Number: " << gst << "\n";
        outFile << "Contact Number: " << contactNumber << "\n";
        outFile << "City Name: " << cityName << "\n";
        outFile << "Product Code: " << productCode << "\n";
        outFile << "Product Name: " << productName << "\n";
        outFile << "Product Cost: " << productCost << "\n";
        outFile << "Tax Amount: " << taxAmount << "\n";
        outFile << "Total Amount (Including Tax): " << totalAmount << "\n";
        outFile << "Billing Date/Time: " << dt;
        outFile << "------------------------------\n";

        outFile.close();
        cout << "Customer details saved to logfile.txt" << endl;
    }
    catch (const runtime_error& e) {
        cerr << e.what() << endl;
        exit(1);  
    }
}

main.cpp

#include <iostream>
#include "Customer.h"  // Include the Customer header file
#include <exception>    // Include exception for error handling

int main() {
    try {
        Customer customer1;  // Create a Customer object

        customer1.initialize();  // Initialize customer and product details

        customer1.display();  // Display the details

        customer1.update();  // Allow user to update contact information

        customer1.saveToLogFile();  // Save customer and product details to log file
    }
    catch (const std::exception& e) {  // Catch any standard exceptions
        std::cerr << "An error occurred: " << e.what() << std::endl;  // Print the error message
        return 1;  // Exit with failure status
    }

    return 0;  // Exit with success status
}

Output:

Enter Customer ID: 101
Enter Customer Name: samarth
Enter GST: 20.2
Enter Contact Number: 12365478925
Enter City Name: bdn
Enter Product Code: .300vvds
Enter Product Name: kbgliegr kaer
Enter Product Cost: 20000

Customer Details:
Customer ID: 101
Customer Name: samarth
GST: 20.2
Contact Number: 12365478925
City Name: bdn
Product Code: .300vvds
Product Name: kbgliegr kaer
Product Cost: 20000
Tax Amount: 3600
Total Amount (Including Tax): 23600

Would you like to update the contact? (Enter one of the following: Yes, No): no
No updates made.
Customer details saved to logfile.txt
