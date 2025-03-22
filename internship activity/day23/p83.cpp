Q2.write a c++ program for find the Area of different shapes using operator overloading.

#include <iostream>
#include <cmath>
using namespace std;

class Shape {
protected:
    string name;

public:
    Shape(string n) : name(n) {}

    virtual double getArea() = 0;

    Shape& operator+(Shape& other) {
        double combinedArea = this->getArea() + other.getArea();
        cout << "The combined area of " << this->name << " and " << other.name 
             << " is: " << combinedArea << endl;
        return *this;
    }

    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : Shape("Circle"), radius(r) {}

    double getArea() override {
        return M_PI * radius * radius;
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

    double getArea() override {
        return length * breadth;
    }

    ~Rectangle() {}
};

int main() {
    int choice1, choice2;
    Shape* shape1;
    Shape* shape2;

    cout << "Select the first shape:\n1. Circle\n2. Rectangle\n3. Square\nEnter your choice: ";
    cin >> choice1;

    if (choice1 == 1) {
        double radius;
        cout << "Enter the radius of the first circle: ";
        cin >> radius;
        shape1 = new Circle(radius);
    } else if (choice1 == 2) {
        double length, breadth;
        cout << "Enter the length and breadth of the first rectangle: ";
        cin >> length >> breadth;
        shape1 = new Rectangle(length, breadth);
    } else if (choice1 == 3) {
        double side;
        cout << "Enter the side of the first square: ";
        cin >> side;
        shape1 = new Rectangle(side);
    } else {
        cout << "Invalid choice." << endl;
        return 1;
    }

    cout << "\nSelect the second shape:\n1. Circle\n2. Rectangle\n3. Square\nEnter your choice: ";
    cin >> choice2;

    if (choice2 == 1) {
        double radius;
        cout << "Enter the radius of the second circle: ";
        cin >> radius;
        shape2 = new Circle(radius);
    } else if (choice2 == 2) {
        double length, breadth;
        cout << "Enter the length and breadth of the second rectangle: ";
        cin >> length >> breadth;
        shape2 = new Rectangle(length, breadth);
    } else if (choice2 == 3) {
        double side;
        cout << "Enter the side of the second square: ";
        cin >> side;
        shape2 = new Rectangle(side);
    } else {
        cout << "Invalid choice." << endl;
        delete shape1;
        return 1;
    }

    *shape1 + *shape2;

    delete shape1;
    delete shape2;

    return 0;
}

Output:

Select the second shape:
1. Circle
2. Rectangle
3. Square
Enter your choice: 2
Enter the length and breadth of the second rectangle: 20 10
The combined area of Rectangle and Rectangle is: 400