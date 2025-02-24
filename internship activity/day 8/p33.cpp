/*Internship activity - <Day 8>
  Project: Rapid Vision Measuring System.
  Task: <C++ activity>
  Compiler:Windows 10
  IDE:VS Code 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <ctime> 
using namespace std;

struct Customer {
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

    void initialize() {
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
        
        cout << "Enter Product Code: ";
        cin >> productCode;

        cout << "Enter Product Name: ";
        cin >> productName;

        cout << "Enter Product Cost: ";
        cin >> productCost;

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

OUTPUT:

Enter Customer ID: 101
Enter Customer Name: hp
Enter GST: 293847
Enter Contact Number: 7834988739
Enter City Name: bengaluru
Enter Product Code: p101
Enter Product Name: prodA
Enter Product Cost: 1000

Customer Details:
Customer ID: 101
Customer Name: hp
GST: 293847
Contact Number: 7834988739
City Name: bengaluru
Product Code: p101
Product Name: prodA
Product Cost: 1000
Tax Amount: 180
Total Amount (Including Tax): 1180

Would you like to update the contact? (Enter one of the following: Yes, No): yes
Enter new Contact Number: 6383792281
Customer details saved to logfile.txt

logfile.txt:

Customer ID: 101
Customer Name: hp
GST Number: 293847
Contact Number: 6383792281
City Name: bengaluru
Product Code: p101
Product Name: prodA
Product Cost: 1000
Tax Amount: 180
Total Amount (Including Tax): 1180
Billing Date/Time: Mon Dec  2 07:22:38 2024
------------------------------

