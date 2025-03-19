Q1.write a c++ program for perform the function over loading task for Integer and float Add,sub,mul,div.

#include <iostream>
#include <limits>

using namespace std;

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

double divide(int a, int b) {
    if (b == 0) {
        cout << "Error! Division by zero." << endl;
        return std::numeric_limits<double>::infinity();
    } else {
        return static_cast<double>(a) / b;
    }
}

float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}
float divide(float a, float b) {
    if (b == 0) {
        cout << "Error! Division by zero." << endl;
        return std::numeric_limits<float>::infinity();
    } else {
        return a / b;
    }
}

int getValidInteger() {
    int num;
    while (true) {
        cout << "Enter a number: ";
        cin >> num;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid input! Please enter a valid integer." << endl;
        } else {
            return num;
        }
    }
}
float getValidFloat() {
    float num;
    while (true) {
        cout << "Enter a number: ";
        cin >> num;

        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid input! Please enter a valid float." << endl;
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
    int num1, num2;
    float fnum1, fnum2;
    double result;

    switch (choice) {
        case 1:
            num1 = getValidInteger();
            num2 = getValidInteger();
            result = add(num1, num2);
            cout << "Result (int): " << result << endl;
            break;

        case 2:
            num1 = getValidInteger();
            num2 = getValidInteger();
            result = subtract(num1, num2);
            cout << "Result (int): " << result << endl;
            break;

        case 3:
            num1 = getValidInteger();
            num2 = getValidInteger();
            result = multiply(num1, num2);
            cout << "Result (int): " << result << endl;
            break;

        case 4:
            num1 = getValidInteger();
            num2 = getValidInteger();
            result = divide(num1, num2);
            if (num2 != 0) {
                cout << "Result (int): " << result << endl;
            }
            break;

        case 5:
            fnum1 = getValidFloat();
            fnum2 = getValidFloat();
            result = add(fnum1, fnum2);
            cout << "Result (float): " << result << endl;
            break;

        case 6:
            fnum1 = getValidFloat();
            fnum2 = getValidFloat();
            result = subtract(fnum1, fnum2);
            cout << "Result (float): " << result << endl;
            break;

        case 7:
            fnum1 = getValidFloat();
            fnum2 = getValidFloat();
            result = multiply(fnum1, fnum2);
            cout << "Result (float): " << result << endl;
            break;

        case 8:
            fnum1 = getValidFloat();
            fnum2 = getValidFloat();
            result = divide(fnum1, fnum2);
            if (fnum2 != 0) {
                cout << "Result (float): " << result << endl;
            }
            break;

        case 9:
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
        cout << "Enter your choice (1-9): ";
        cin >> choice;

        if (choice == 9) {
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
Enter your choice (1-9): 1
Enter a number: 10
Enter a number: 20
Result (int): 30

Select an operation:
1. Add
2. Subtract
3. Multiply
4. Divide
5. Exit
Enter your choice (1-9): 2
Enter a number: 10
Enter a number: 20
Result (int): -10

Select an operation:
1. Add
2. Subtract
3. Multiply
4. Divide
5. Exit
Enter your choice (1-9): 3
Enter a number: 10
Enter a number: 20
Result (int): 200

Select an operation:
1. Add
2. Subtract
3. Multiply
4. Divide
5. Exit
Enter your choice (1-9): 4
Enter a number: 40
Enter a number: 4
Result (int): 10