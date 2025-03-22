Q1.write a c++ program for find the Area of different shapes using function overloading.

#include <iostream>
#include <cmath>
using namespace std;

class Shape {
protected:
    string name;

public:
    Shape(string n) : name(n) {}

    virtual void calculateArea() {
        cout << "Undefined shape." << endl;
    }

    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : Shape("Circle"), radius(r) {}

    void calculateArea() override {
        double area = M_PI * radius * radius;
        cout << "The area of the circle is: " << area << endl;
    }

    ~Circle() {}
};

class Rectangle : public Shape {
private:
    double length;
    double breadth;

public:
    Rectangle(double l, double b) : Shape("Rectangle"), length(l), breadth(b) {}

    Rectangle(double side) : Shape("Square"), length(side), breadth(side) {}

    void calculateArea() override {
        double area = length * breadth;
        cout << "The area is: " << area << endl;
    }

    ~Rectangle() {}
};

int main() {
    Shape* shape;
    int choice;
    cout << "Select a shape:\n1. Circle\n2. Rectangle\n3. Square\nEnter your choice: ";
    cin >> choice;

    if (choice == 1) {
        double radius;
        cout << "Enter the radius: ";
        cin >> radius;
        shape = new Circle(radius);
    } else if (choice == 2) {
        double length, breadth;
        cout << "Enter the length and breadth: ";
        cin >> length >> breadth;
        shape = new Rectangle(length, breadth);
    } else if (choice == 3) {
        double side;
        cout << "Enter the side of the square: ";
        cin >> side;
        shape = new Rectangle(side);
    } else {
        cout << "Invalid choice." << endl;
        return 1;
    }

    shape->calculateArea();
    delete shape;

    return 0;
}

Output:

Select a shape:
1. Circle
2. Rectangle
3. Square
Enter your choice: 3
Enter the side of the square: 30
The area is: 900