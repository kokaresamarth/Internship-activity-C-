/*Internship activity - <Day 9>
  Project: Rapid Vision Measuring System.
  Task: <C++ activity>
  Compiler:Windows 10
  IDE:VS Code
create a c++ program with including class find customer and product details.
*/

#include <iostream>
#include <fstream>
#include <string>
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
    Customer() {
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
    void initialize() {
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
        cin.ignore(); 
        
        taxAmount = productCost * 0.18;
        totalAmount = productCost + taxAmount;
    }

    void display() {
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

    void update() {
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

    void saveToLogFile() {
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
};

int main() {
    Customer customer1;

    customer1.initialize();

    customer1.display();
   
    customer1.update();

    customer1.saveToLogFile();

    return 0;
}

output:
Enter Customer ID: 101
Enter Customer Name: raja
Enter GST: 1209 
Enter Contact Number: 43567890
Enter City Name: kvp
Enter Product Code: p102
Enter Product Name: prodA
Enter Product Cost: 2000

Customer Details:
Customer ID: 101
Customer Name: raja
GST: 1209
Contact Number: 43567890
City Name: kvp
Product Code: p102
Product Name: prodA
Product Cost: 2000
Tax Amount: 360
Total Amount (Including Tax): 2360

Would you like to update the contact? (Enter one of the following: Yes, No): yes
Enter new Contact Number: 5647382949
Customer details saved to logfile.txt


customer logfile:
Customer ID: 101
Customer Name: raja
GST Number: 1209
Contact Number: 5647382949
City Name: kvp
Product Code: p102
Product Name: prodA
Product Cost: 2000
Tax Amount: 360
Total Amount (Including Tax): 2360
Billing Date/Time: Tue Dec  3 07:19:56 2024
------------------------------