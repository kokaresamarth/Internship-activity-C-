/*Internship activity - <Day 10>
  Project: Rapid Vision Measuring System.
  Task: <C++ activity>
  Compiler:Windows 10
  IDE:VS Code
create a c++ program using single inheritance find customer and product details.
*/


#ifndef PRODUCTCUSTOMER_H
#define PRODUCTCUSTOMER_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;
class Product {
protected:
    int productCode;
    string name;
    double cost;
    double tax;

public:
    Product(int code = 0, string productName = "", double productCost = 0.0, double productTax = 0.0);
    void initializeProduct();
    double billing(int quantity);
    void saveProductToLogFile(int quantity);
};
class Customer : public Product {
private:
    int customerId;
    string customerName;
    string gst;
    string contactNumber;
    string cityName;
    double totalAmount;

public:
    Customer(int productCode = 0, string productName = "", double productCost = 0.0, double productTax = 0.0);
    void initializeCustomer();
    void displayCustomer();
    void saveCustomerToLogFile();
    void updateContact();
};
#endif 


Product::Product(int code, string productName, double productCost, double productTax) {
    productCode = code;
    name = productName;
    cost = productCost;
    tax = productTax;
}

void Product::initializeProduct() {
    cout << "Enter Product Code: ";
    cin >> productCode;
    cout << "Enter Product Name: ";
    cin >> name;
    cout << "Enter Product Cost: ";
    cin >> cost;
    cout << "Enter Tax Percentage: ";
    cin >> tax;
}

double Product::billing(int quantity) {
    double totalCost = cost * quantity;
    double totalTax = (tax / 100) * totalCost;
    return totalCost + totalTax;
}

void Product::saveProductToLogFile(int quantity) {
    double totalAmount = billing(quantity);
    ofstream logFile("products.log", ios::app);
    if (logFile.is_open()) {
        logFile << "Product Code: " << productCode << "\n";
        logFile << "Product Name: " << name << "\n";
        logFile << "Quantity: " << quantity << "\n";
        logFile << "Total Amount: " << totalAmount << "\n";
        logFile << "------------------------------\n";
        logFile.close();
        cout << "Product details saved to products.log\n";
    }
    else {
        cout << "Error opening log file.\n";
    }
}
Customer::Customer(int productCode, string productName, double productCost, double productTax)
    : Product(productCode, productName, productCost, productTax), customerId(0), customerName(""),
    gst(""), contactNumber(""), cityName(""), totalAmount(0.0) {}

void Customer::initializeCustomer() {
    cout << "Enter Customer ID: ";
    cin >> customerId;
    cout << "Enter Customer Name: ";
    cin >> customerName;
    cout << "Enter GST: ";
    cin >> gst;
    cout << "Enter Contact Number: ";
    cin >> contactNumber;
    cout << "Enter City Name: ";
    cin >> cityName;
    initializeProduct();

    int quantity;
    cout << "Enter Quantity for the product: ";
    cin >> quantity;
    totalAmount = billing(quantity);
}

void Customer::displayCustomer() {
    cout << "\nCustomer Details:\n";
    cout << "Customer ID: " << customerId << endl;
    cout << "Customer Name: " << customerName << endl;
    cout << "GST: " << gst << endl;
    cout << "Contact Number: " << contactNumber << endl;
    cout << "City Name: " << cityName << endl;

    cout << "\nProduct Details:\n";
    cout << "Product Code: " << productCode << endl;
    cout << "Product Name: " << name << endl;
    cout << "Product Cost: " << cost << endl;
    cout << "Tax Percentage: " << tax << "%" << endl;
    cout << "Total Amount (Including Tax): " << totalAmount << endl;
}

void Customer::saveCustomerToLogFile() {
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
        outFile << "Product Name: " << name << "\n";
        outFile << "Product Cost: " << cost << "\n";
        outFile << "Tax Percentage: " << tax << "%\n";
        outFile << "Total Amount (Including Tax): " << totalAmount << "\n";
        outFile << "Billing Date/Time: " << dt;
        outFile << "------------------------------\n";

        outFile.close();
        cout << "Customer details saved to logfile.txt\n";
    }
    else {
        cout << "Error opening log file.\n";
    }
}

void Customer::updateContact() {
    string input;
    cout << "\nWould you like to update the contact? (Enter Yes or No): ";
    cin >> input;
    if (input == "Yes" || input == "yes") {
        cout << "Enter new Contact Number: ";
        cin >> contactNumber;
    }
    else {
        cout << "No updates made.\n";
    }
}

int main() {
    Customer customer1;
    customer1.initializeCustomer();
    customer1.displayCustomer();
    customer1.updateContact();
    customer1.saveCustomerToLogFile();
    int quantity;
    cout << "Enter quantity for billing: ";
    cin >> quantity;
    customer1.saveProductToLogFile(quantity);
    return 0;
}

OUTPUT:
Enter Customer ID: 101
Enter Customer Name: raja
Enter GST: 435
Enter Contact Number: 6383864839
Enter City Name: chennai
Enter Product Code: 202
Enter Product Name: mobile
Enter Product Cost: 1000
Enter Tax Percentage: 4
Enter Quantity for the product: 3

Customer Details:
Customer ID: 101
Customer Name: raja
GST: 435
Contact Number: 6383864839
City Name: chennai

Product Details:
Product Code: 202
Product Name: mobile
Product Cost: 1000
Tax Percentage: 4%
Total Amount (Including Tax): 3120

Would you like to update the contact? (Enter Yes or No): yes
Enter new Contact Number: 456787654
Customer details saved to logfile.txt
Enter quantity for billing: 3
Product details saved to products.log

products.log

Customer ID: 101
Customer Name: raja
GST Number: 435
Contact Number: 456787654
City Name: chennai
Product Code: 202
Product Name: mobile
Product Cost: 1000
Tax Percentage: 4%
Total Amount (Including Tax): 3120
Billing Date/Time: Wed Dec  4 05:41:02 2024
------------------------------
