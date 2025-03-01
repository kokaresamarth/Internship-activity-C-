   create a c++ program using class find customer and product details using friend functions in c++ 


Customer.h

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

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
    void display() const;
    void update();
    void saveToLogFile() const;

    friend void updateContactNumber(Customer& customer);
    friend void saveCustomerDetailsToFile(const Customer& customer);
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
    cout << "Enter Customer ID: ";
    cin >> customerId;
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

    taxAmount = productCost * 0.18;
    totalAmount = productCost + taxAmount;
}

void Customer::display() const {
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

void Customer::saveToLogFile() const {
    ofstream outFile("logfile.txt", ios::app);
    if (outFile.is_open()) {
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
    } else {
        cout << "Error opening file!" << endl;
    }
}

// Friend function to update contact number
void updateContactNumber(Customer& customer) {
    string input;
    cout << "\nWould you like to update the contact? (Enter one of the following: Yes, No): ";
    cin >> input;

    if (input == "Yes" || input == "yes") {
        cout << "Enter new Contact Number: ";
        cin >> customer.contactNumber;
    } else {
        cout << "No updates made." << endl;
    }
}

// Friend function to save customer details to file
void saveCustomerDetailsToFile(const Customer& customer) {
    ofstream outFile("logfile.txt", ios::app);
    if (outFile.is_open()) {
        time_t now = time(0);
        char* dt = ctime(&now);

        outFile << "Customer ID: " << customer.customerId << "\n";
        outFile << "Customer Name: " << customer.customerName << "\n";
        outFile << "GST Number: " << customer.gst << "\n";
        outFile << "Contact Number: " << customer.contactNumber << "\n";
        outFile << "City Name: " << customer.cityName << "\n";

        outFile << "Product Code: " << customer.productCode << "\n";
        outFile << "Product Name: " << customer.productName << "\n";
        outFile << "Product Cost: " << customer.productCost << "\n";
        outFile << "Tax Amount: " << customer.taxAmount << "\n";
        outFile << "Total Amount (Including Tax): " << customer.totalAmount << "\n";
        outFile << "Billing Date/Time: " << dt;
        outFile << "------------------------------\n";

        outFile.close();
        cout << "Customer details saved to logfile.txt" << endl;
    } else {
        cout << "Error opening file!" << endl;
    }
}

main.cpp

#include <iostream>
#include "Customer.h"

using namespace std;

int main() {
    Customer customer1;

    customer1.initialize();

    customer1.display();

    updateContactNumber(customer1);

    saveCustomerDetailsToFile(customer1);

    return 0;
}

Output:

Enter Customer ID: 101
Enter Customer Name: samarth
Enter GST: 3
Enter Contact Number: 7349712503
Enter City Name: Bengalore
Enter Product Code: 101.2
Enter Product Name: CPU
Enter Product Cost: 2500

Customer Details:
Customer ID: 101
Customer Name: samarth
GST: 3
Contact Number: 7349712503
City Name: Bengalore
Product Code: 101.2
Product Name: CPU
Product Cost: 2500
Tax Amount: 450
Total Amount (Including Tax): 2950

Would you like to update the contact? (Enter one of the following: Yes, No): yes
Enter new Contact Number: 8055462450
Customer details saved to logfile.txt

Customer ID: 101
Customer Name: samarth
GST Number: 3
Contact Number: 8055462450
City Name: Bengalore
Product Code: 101.2
Product Name: CPU
Product Cost: 2500
Tax Amount: 450
Total Amount (Including Tax): 2950
Billing Date/Time: Thu Feb 27 11:02:26 2025
------------------------------