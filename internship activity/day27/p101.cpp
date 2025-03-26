 Q3.write a c++ program for overloading the input and output "<<" and ">>" operators.

#include <iostream>

using namespace std;

class SimpleNumber {
private:
    int value;

public:
   
    SimpleNumber(int val = 0) : value(val) {}

    int getValue() const {
        return value;
    }

    void setValue(int val) {
        value = val;
    }

    SimpleNumber operator+(const SimpleNumber& other)
    {
        return SimpleNumber(value + other.value);
    }

    SimpleNumber operator-(const SimpleNumber& other) 
    {
        return SimpleNumber(value - other.value);
    }

    SimpleNumber operator*(const SimpleNumber& other)
    {
        return SimpleNumber(value * other.value);
    }

    SimpleNumber operator/(const SimpleNumber& other) 
    {
        if (other.value == 0) {
            cout << "Error: Division by zero!" << endl;
            return SimpleNumber(0); 
        }
        return SimpleNumber(value / other.value);
    }

    friend ostream& operator<<(ostream& out, const SimpleNumber& num);

    friend istream& operator>>(istream& in, SimpleNumber& num);
};

ostream& operator<<(ostream& out, const SimpleNumber& num)
{
    out << num.value;
    return out;
}

istream& operator>>(istream& in, SimpleNumber& num)
{
    cout << "Enter a value: ";
    in >> num.value;
    return in;
}

int main() {
    SimpleNumber num1, num2, result;

    cout << "Enter the first number:" << endl;
    cin >> num1;

    cout << "Enter the second number:" << endl;
    cin >> num2;

    result = num1 + num2;
    cout << "Addition result: " << result << endl;

    result = num1 - num2;
    cout << "Subtraction result: " << result << endl;

    result = num1 * num2;
    cout << "Multiplication result: " << result << endl;

    result = num1 / num2;
    cout << "Division result: " << result << endl;

    return 0;
}

Output:

Enter the first number:
Enter a value: 10
Enter the second number:
Enter a value: 20
Addition result: 30
Subtraction result: -10
Multiplication result: 200
Division result: 0