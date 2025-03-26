Q1.write a c++ program for calculating Areas of shapes using dynamic binding using class in c++

#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:

    virtual void inputDimensions() = 0;
    virtual void calculateArea() = 0;
    virtual void displayArea() = 0;


    virtual ~Shape() {}
};

class Rectangle : public Shape {
private:
    double length;
    double width;
    double area;

public:
    Rectangle() : length(0), width(0), area(0) {}

    void inputDimensions() override {
        cout << "\nEnter length of the rectangle: ";
        cin >> length;
        cout << "Enter width of the rectangle: ";
        cin >> width;
    }

    void calculateArea() override {
        area = length * width;
    }

    void displayArea() const override {
        cout << "The area of the rectangle is: " << area << endl;
    }
};

class Circle : public Shape {
private:
    double radius;
    double area;

public:
    Circle() : radius(0), area(0) {}

    void inputDimensions() override {
        cout << "\nEnter radius of the circle: ";
        cin >> radius;
    }

    void calculateArea() override {
        area = M_PI * radius * radius;
    }

    void displayArea() const override {
        cout << "The area of the circle is: " << area << endl;
    }
};

int main() {
    const int MAX_SHAPES = 100;
    Shape* shapes[MAX_SHAPES];
    int shapeCount = 0;
    int choice;

    cout << "Dynamic Polymorphism Example: Shapes Area Calculator" << endl;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Add a Rectangle" << endl;
        cout << "2. Add a Circle" << endl;
        cout << "3. Calculate and Display Areas" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if (shapeCount < MAX_SHAPES) {
                    Shape* rect = new Rectangle();
                    rect->inputDimensions();
                    shapes[shapeCount++] = rect;
                } else {
                    cout << "\nShape array is full! Cannot add more shapes." << endl;
                }
                break;
            }
            case 2: {
                if (shapeCount < MAX_SHAPES) {
                    Shape* circ = new Circle();
                    circ->inputDimensions();
                    shapes[shapeCount++] = circ;
                } else {
                    cout << "\nShape array is full! Cannot add more shapes." << endl;
                }
                break;
            }
            case 3: {
                cout << "\nCalculating and displaying areas of all shapes..." << endl;
                for (int i = 0; i < shapeCount; i++) {
                    shapes[i]->calculateArea();
                    shapes[i]->displayArea();
                }
                break;
            }
            case 4:
                cout << "\nExiting program. Cleaning up resources..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 4);

    for (int i = 0; i < shapeCount; i++) {
        delete shapes[i];
    }

    cout << "Program terminated successfully." << endl;
    return 0;
}

Output:

Dynamic Polymorphism Example: Shapes Area Calculator

Menu:
1. Add a Rectangle
2. Add a Circle
3. Calculate and Display Areas
4. Exit
Enter your choice: 1

Enter length of the rectangle: 20
Enter width of the rectangle: 10

Menu:
1. Add a Rectangle
2. Add a Circle
3. Calculate and Display Areas
4. Exit
Enter your choice: 2

Enter radius of the circle: 10

Menu:
1. Add a Rectangle
2. Add a Circle
3. Calculate and Display Areas
4. Exit
Enter your choice: 3

Calculating and displaying areas of all shapes...
The area of the rectangle is: 200
The area of the circle is: 314.159

Menu:
1. Add a Rectangle
2. Add a Circle
3. Calculate and Display Areas
4. Exit
Enter your choice: 4

Exiting program. Cleaning up resources...
Program terminated successfully.