/*Internship activity - <Day 8>
  Project: Rapid Vision Measuring System.
  Task: <C++ activity>
  Compiler:Windows 10
  IDE:VS Code

*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Product {
private:
    int productCode;
    string name;
    double cost;
    double tax;

public:
    Product(int code = 0, string productName = "", double productCost = 0.0, double productTax = 0.0) {
        productCode = code;
        name = productName;
        cost = productCost;
        tax = productTax;
    }

    void initialize() {
        cout << "Enter Product Code: ";
        cin >> productCode;
        cin.ignore(); 
        cout << "Enter Product Name: ";
        getline(cin, name);
        cout << "Enter Product Cost: ";
        cin >> cost;
        cout << "Enter Tax Percentage: ";
        cin >> tax;
    }

    double billing(int quantity) {
        double totalCost = cost * quantity;
        double totalTax = (tax / 100) * totalCost;
        double totalAmount = totalCost + totalTax;
        return totalAmount;
    }

    void update(int quantity) {
        double totalAmount = billing(quantity);
        ofstream logFile("products.log", ios::app); 
        if (logFile.is_open()) {
            logFile << "Product Code: " << productCode <<"\n"<<" Name: " << name
                    <<"\n"<<"Quantity: " << quantity<<"\n"<< "Total Amount: " << totalAmount << endl;
            logFile.close();
            cout << "Billing details updated to 'products.log'.\n";
        } else {
            cout << "Unable to open the log file.\n";
        }
    }
};

int main() {
  
    Product product1;

    product1.initialize();

    int quantity;
    cout << "Enter the quantity for the product: ";
    cin >> quantity;

    cout << "Total amount for " << quantity << " units of " << product1.billing(quantity) << endl;
    product1.update(quantity);

    return 0;
}

Output:

Enter Product Code: 101
Enter Product Name: laptop
Enter Product Cost: 1000
Enter Tax Percentage: 2
Enter the quantity for the product: 4
Total amount for 4 units of 4080
Billing details updated to 'products.log'.

products.log

Product Code: 101
Name: laptop
Quantity: 4
Total Amount: 4080
