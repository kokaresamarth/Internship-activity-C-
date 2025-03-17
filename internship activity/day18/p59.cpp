Q3.write a c++ program for Call-By-Value,Call-By-Reference with a Pointer Argument,Call-By-Reference with a Reference Argument

#include <iostream>
using namespace std;

int calculateSquareByValue(int num)
{

    cout << "Address of num in calculateSquareByValue(): " << &num << "\n";

    num *= num;
    return num;
}

void calculateSquareByPointer(int* num)
{

    cout << "Address of num in calculateSquareByPointer(): " << num << "\n";

    *num *= *num;
}

void calculateSquareByReference(int& num)
{

    cout << "Address of num in calculateSquareByReference(): " << &num << "\n";

    num *= num;
}

void performCalculations()
{
    int num1;
    cout << "Enter a number for call-by-value: ";
    cin >> num1;
    cout << "Address of num1 in main(): " << &num1 << "\n";
    cout << "Square of num1: " << calculateSquareByValue(num1) << "\n";
    cout << "No change in num1: " << num1 << "\n";

    int num2;
    cout << "\nEnter a number for call-by-reference with pointer: ";
    cin >> num2;
    cout << "Address of num2 in main(): " << &num2 << "\n";
    calculateSquareByPointer(&num2);
    cout << "Square of num2: " << num2 << "\n";
    cout << "Change reflected in num2: " << num2 << "\n";

    int num3;
    cout << "\nEnter a number for call-by-reference with reference: ";
    cin >> num3;
    cout << "Address of num3 in main(): " << &num3 << "\n";
    calculateSquareByReference(num3);
    cout << "Square of num3: " << num3 << "\n";
    cout << "Change reflected in num3: " << num3 << "\n";
}

int main() {
    performCalculations();
    return 0;
}

Output:

Enter a number for call-by-value: 10 10 20
Address of num1 in main(): 0053F6E8
Address of num in calculateSquareByValue(): 0053F5F8
Square of num1: 100
No change in num1: 10

Enter a number for call-by-reference with pointer: Address of num2 in main(): 0053F6DC
Address of num in calculateSquareByPointer(): 0053F6DC
Square of num2: 100
Change reflected in num2: 100

Enter a number for call-by-reference with reference: Address of num3 in main(): 0053F6D0
Address of num in calculateSquareByReference(): 0053F6D0
Square of num3: 400
Change reflected in num3: 400