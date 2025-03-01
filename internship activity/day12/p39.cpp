
create a c++ program using class find customer and product details using Nested classes in c++ 

Customer.h:

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
using namespace std;

class Customer {
private:
    int customerId;
    string customerName;
    string gst;
    string contactNumber;
    string cityName;

public:
    class Product {
    private:
        string productCode;
        string productName;
        double productCost;
        double taxAmount;
        double totalAmount;

    public:
        Product();  
        void initialize();  
        void display() const;  
        friend class Customer; 
    };
    
    Customer();  
    void initialize();  
    void display() const;  
    void update();  
    void saveToLogFile(Product& product) const;  
};

#endif 


Customer.cpp

#include <iostream>
#include <fstream>    // For ofstream
#include <ctime>      // For time
#include "Customer.h"

using namespace std;

Customer::Product::Product() : productCode(""), productName(""), productCost(0.0), taxAmount(0.0), totalAmount(0.0) {}

void Customer::Product::initialize() {
    cout << "Enter Product Code: ";
    getline(cin, productCode);

    cout << "Enter Product Name: ";
    getline(cin, productName);

    cout << "Enter Product Cost: ";
    cin >> productCost;
    cin.ignore();

    taxAmount = productCost * 0.18;
    totalAmount = productCost + taxAmount;
}

void Customer::Product::display() const {
    cout << "Product Code: " << productCode << endl;
    cout << "Product Name: " << productName << endl;
    cout << "Product Cost: " << productCost << endl;
    cout << "Tax Amount: " << taxAmount << endl;
    cout << "Total Amount (Including Tax): " << totalAmount << endl;
}

Customer::Customer() : customerId(0), customerName(""), gst(""), contactNumber(""), cityName("") {}

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
}

void Customer::display() const {
    cout << "\nCustomer Details:" << endl;
    cout << "Customer ID: " << customerId << endl;
    cout << "Customer Name: " << customerName << endl;
    cout << "GST: " << gst << endl;
    cout << "Contact Number: " << contactNumber << endl;
    cout << "City Name: " << cityName << endl;
}

void Customer::update() {
    string input;
    cout << "\nWould you like to update the contact? (Enter one of the following: Yes, No): ";
    cin >> input;

    if (input == "Yes" || input == "yes") {
        cout << "Enter new Contact Number: ";
        cin >> contactNumber;
    }
    else {
        cout << "No updates made." << endl;
    }
}

void Customer::saveToLogFile(Product& product) const {
    ofstream outFile("logfile.txt", ios::app);
    if (outFile.is_open()) {
        time_t now = time(0);
        char dt[26];  // Buffer for the date/time
        ctime_s(dt, sizeof(dt), &now);  // Safe alternative to ctime

        outFile << "Customer ID: " << customerId << "\n";
        outFile << "Customer Name: " << customerName << "\n";
        outFile << "GST Number: " << gst << "\n";
        outFile << "Contact Number: " << contactNumber << "\n";
        outFile << "City Name: " << cityName << "\n";

        // Manually output each product attribute
        outFile << "Product Code: " << product.productCode << endl;
        outFile << "Product Name: " << product.productName << endl;
        outFile << "Product Cost: " << product.productCost << endl;
        outFile << "Tax Amount: " << product.taxAmount << endl;
        outFile << "Total Amount (Including Tax): " << product.totalAmount << endl;

        outFile << "Billing Date/Time: " << dt;
        outFile << "------------------------------\n";

        outFile.close();
        cout << "Customer details saved to logfile.txt" << endl;
    }
    else {
        cout << "Error opening file!" << endl;
    }
}

main.cpp:

#include "Customer.h"

using namespace std;

int main() {
    Customer customer1;
    Customer::Product product1; 
    customer1.initialize();
    product1.initialize();

    customer1.display();
    product1.display();

    customer1.update();

    customer1.saveToLogFile(product1);

    return 0;
}


Output:

Enter Customer ID: 101
Enter Customer Name: samarth
Enter GST: 20
Enter Contact Number: 7896541230
Enter City Name: vijayapur
Enter Product Code: 20.1
Enter Product Name: laptop
Enter Product Cost: 25000

Customer Details:
Customer ID: 101
Customer Name: samarth
GST: 20
Contact Number: 7896541230
City Name: vijayapur
Product Code: 20.1
Product Name: laptop
Product Cost: 25000
Tax Amount: 4500
Total Amount (Including Tax): 29500

Would you like to update the contact? (Enter one of the following: Yes, No): yes
Enter new Contact Number: 2163478901
Customer details saved to logfile.txt