Q1.create a structure product with productCode, Name, Cost, Tax as attributes

*/

#include <iostream>
using namespace std;

struct product{
    string productcode;
    string productname;
    float cost,tax;
};
int main()
{
    product  p1;

    cout << "Enter product code: ";
    cin >> p1.productcode;
    cout <<  "Enter product name: ";
    cin >> p1.productname;
    cout << "Enter product cost: ";
    cin >> p1.cost;
    cout << "Enter tax: ";
    cin >> p1.tax;

    cout << "\nDisplaying Information." << endl;
    cout << "product code:" << p1.productcode<< endl;
    cout << "product name: "<< p1.productname<< endl;
    cout << "product cost: "<< p1.cost << endl;
    cout << "tax: " << p1.tax;

    return 0;
}

Output:

Enter product code: p101
Enter product name: productA
Enter product cost: 10000
Enter tax: 200

Displaying Information.
product code:p101
product name: productA
product cost: 10000
tax: 200