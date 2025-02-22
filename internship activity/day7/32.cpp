Q2.create a three methods
initialize() To initialize the product attributes
billing) To calculate the total amount based on product ame and Quantity
update()- update the hilling details to log file (products.log)

*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Product {
    int productCode;
    string name;
    double cost;
    double tax;
    double totalAmount;

    void initialize(int code, string productName, double productCost, double productTax) {
        productCode = code;
        name = productName;
        cost = productCost;
        tax = productTax;
        totalAmount = 0.0;
    }


    void billing(int quantity) {
        double taxAmount = cost * (tax / 100);
        double totalCost = cost + taxAmount;
        totalAmount = totalCost * quantity;
    }

    void update() {
        ofstream logFile;
        logFile.open("products.log", ios::app); 
        if (logFile.is_open()) {
            logFile << "Product Code: " << productCode << "\n";
            logFile << "Product Name: " << name << "\n";
            logFile << "product Cost: " << cost << "\n";
            logFile << "product Tax: " << tax << "\n";
            logFile << "Total Amount: " << totalAmount << "\n\n";
            logFile.close();
        } else {
            cout << "Unable to open log file.\n";
        }
    }
};

int main() {
    Product p;

    int code, quantity;
    string name;
    double cost, tax;

    cout << "Enter product code: ";
    cin >> code;
    cout << "Enter product name: ";
    cin>>name;
    cout << "Enter product cost: ";
    cin >> cost;
    cout << "Enter tax percentage: ";
    cin >> tax;
    cout << "Enter quantity: ";
    cin >> quantity;
    
    p.initialize(code, name, cost, tax);
    p.billing(quantity);
    p.update();
    
    cout << "\nTotal Billing Amount: " << p.totalAmount << endl;
    
    return 0;
}

Output:
Enter product code: 101
Enter product name: productA
Enter product cost: 10000
Enter tax percentage: 2
Enter quantity: 5

Total Billing Amount: 51000

products.log file:

Product Code: 101
Product Name: prodA
product Cost: 10000
product Tax: 4
Total Amount: 31200

Product Code: 101
Product Name: productA
product Cost: 10000
product Tax: 2
Total Amount: 51000