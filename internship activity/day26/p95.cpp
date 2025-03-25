Q1.Implement a custom "template" function in C++ that can perform mathematical operations (addition, subtraction, etc.) on different numeric types (int, float, double) without explicitly specifying the type at runtime.


#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Calculator {
private:
    T num1;
    T num2;

public:
   
    Calculator(const T& a, const T& b) : num1(a), num2(b) {}

    
    T performOperation(const string& operation) {
        if (operation == "add") {
            return num1 + num2;
        }
        else if (operation == "subtract") {
            return num1 - num2;
        } 
        else if (operation == "multiply") {
            return num1 * num2;
        }
        else if (operation == "divide") {
            if (num2 == 0) {
                throw runtime_error("Division by zero is not allowed.");
            }
            return num1 / num2;
        }
        else {
            throw invalid_argument("Unsupported operation: " + operation);
        }
    }
};


int main() {
    cout << "Choose numeric type (int, float, double): ";
    string type;
    cin >> type;

    cout << "Enter first number: ";
    double input1;
    cin >> input1;

    cout << "Enter second number: ";
    double input2;
    cin >> input2;

    cout << "Enter operation (add, subtract, multiply, divide): ";
    string operation;
    cin >> operation;

    try {
        if (type == "int") {
            Calculator<int> calc(static_cast<int>(input1), static_cast<int>(input2));
            int result = calc.performOperation(operation);
            cout << "Result: " << result << endl;
        }
        else if (type == "float") {
            Calculator<float> calc(static_cast<float>(input1), static_cast<float>(input2));
            float result = calc.performOperation(operation);
            cout << "Result: " << result << endl;
        }
        else if (type == "double") {
            Calculator<double> calc(input1, input2);
            double result = calc.performOperation(operation);
            cout << "Result: " << result << endl;
        } 
        else {
            cerr << "Unsupported type." << endl;
        }
    } 
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}

Output:

Choose numeric type (int, float, double): double
Enter first number: 12034
Enter second number: 12034
Enter operation (add, subtract, multiply, divide): add
Result: 24068

Choose numeric type (int, float, double): double
Enter first number: 12034
Enter second number: 12034
Enter operation (add, subtract, multiply, divide): add
Result: 24068

Choose numeric type (int, float, double): float
Enter first number: 124.2
Enter second number: 0
Enter operation (add, subtract, multiply, divide): divide
Error: Division by zero is not allowed.