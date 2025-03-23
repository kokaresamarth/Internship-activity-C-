Q3.write a c++ program for perform Area of shapes details operations using class ,pure virtual functions.

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Shape {
public:
    virtual void inputDimensions() = 0; 
    virtual double calculateArea() const = 0; 
    virtual void display() const = 0; 
    virtual ~Shape() {}
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    void inputDimensions() override {
        cout << "Enter the length of the rectangle: ";
        cin >> length;
        cout << "Enter the width of the rectangle: ";
        cin >> width;
    }

    double calculateArea() const override {
        return length * width;
    }

    void display() const override {
        cout << "Rectangle - Length: " << length << ", Width: " << width
             << ", Area: " << calculateArea() << "\n";
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    void inputDimensions() override {
        cout << "Enter the radius of the circle: ";
        cin >> radius;
    }

    double calculateArea() const override {
        return M_PI * radius * radius;
    }

    void display() const override {
        cout << "Circle - Radius: " << radius << ", Area: " << calculateArea() << "\n";
    }
};

void displayMenu() {
    cout << "\nShape Area Calculator\n";
    cout << "1. Rectangle\n";
    cout << "2. Circle\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Shape* shape = nullptr;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            shape = new Rectangle();
            break;
        case 2:
            shape = new Circle();
            break;
        case 3:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            continue;
        }

        if (choice == 1 || choice == 2) {
            shape->inputDimensions();
            shape->display();
            delete shape;
            shape = nullptr;
        }

    } while (choice != 3);

    return 0;
}

Output:

Shape Area Calculator
1. Rectangle
2. Circle
3. Exit
Enter your choice: 1
Enter the length of the rectangle: 40
Enter the width of the rectangle: 20
Rectangle - Length: 40, Width: 20, Area: 800

Shape Area Calculator
1. Rectangle
2. Circle
3. Exit
Enter your choice: 2
Enter the radius of the circle: 10
Circle - Radius: 10, Area: 314.159

Shape Area Calculator
1. Rectangle
2. Circle
3. Exit
Enter your choice: 3
Exiting the program.