Q1.write a c++ program for perform the operator over loading task for Integer and float Add,sub,mul,div.

#include <iostream>
#include <limits>
using namespace std;

class Calculator {
private:
    double value;

public:

    Calculator(double v = 0.0) : value(v) {}

    Calculator operator+(const Calculator& other) {
        return Calculator(value + other.value);  
    }

    Calculator operator-(const Calculator& other) {
        return Calculator(value - other.value);  
    }

    Calculator operator*(const Calculator& other) {
        return Calculator(value * other.value);  
    }

    Calculator operator/(const Calculator& other) {
        if (other.value == 0) {
            cout << "Error! Division by zero." << endl;
            return Calculator(numeric_limits<double>::infinity());
        }
        return Calculator(value / other.value); 
    }

    void display() const {
        cout << value << endl;
    }

    void setValue(double v) {
        value = v;
    }

    double getValue() const {
        return value;
    }
};

double getValidDouble() {
    double num;
    while (true) {
        cout << "Enter a number: ";
        cin >> num;

        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a valid number." << endl;
        } else {
            return num;
        }
    }
}

void displayMenu() {
    cout << "\nSelect an operation:" << endl;
    cout << "1. Add" << endl;
    cout << "2. Subtract" << endl;
    cout << "3. Multiply" << endl;
    cout << "4. Divide" << endl;
    cout << "5. Exit" << endl;
}

void performOperation(int choice) {
    double num1, num2;
    Calculator calc1, calc2, result;

    switch (choice) {
        case 1:
            num1 = getValidDouble();
            num2 = getValidDouble();
            calc1.setValue(num1);
            calc2.setValue(num2);
            result = calc1 + calc2; 
            cout << "Result: ";
            result.display();
            break;

        case 2:
            num1 = getValidDouble();
            num2 = getValidDouble();
            calc1.setValue(num1);
            calc2.setValue(num2);
            result = calc1 - calc2;
            cout << "Result: ";
            result.display();
            break;

        case 3:
            num1 = getValidDouble();
            num2 = getValidDouble();
            calc1.setValue(num1);
            calc2.setValue(num2);
            result = calc1 * calc2; 
            cout << "Result: ";
            result.display();
            break;

        case 4:
            num1 = getValidDouble();
            num2 = getValidDouble();
            calc1.setValue(num1);
            calc2.setValue(num2);
            result = calc1 / calc2;
            cout << "Result: ";
            result.display();
            break;

        case 5:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
    }
}

int main() {
    int choice;

    while (true) {
        displayMenu();
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        if (choice == 5) {
            break;
        }

        performOperation(choice);
    }

    return 0;
}

Output:

Select an operation:
1. Add
2. Subtract
3. Multiply
4. Divide
5. Exit
Enter your choice (1-5): 1
Enter a number: 10
Enter a number: 20
Result: 30

Select an operation:
1. Add
2. Subtract
3. Multiply
4. Divide
5. Exit
Enter your choice (1-5): 2
Enter a number: 20
Enter a number: 10
Result: 10

Select an operation:
1. Add
2. Subtract
3. Multiply
4. Divide
5. Exit
Enter your choice (1-5): 3
Enter a number: 20
Enter a number: 10
Result: 200

Select an operation:
1. Add
2. Subtract
3. Multiply
4. Divide
5. Exit
Enter your choice (1-5): 4
Enter a number: 20
Enter a number: 10
Result: 2

Select an operation:
1. Add
2. Subtract
3. Multiply
4. Divide
5. Exit
Enter your choice (1-5): 5