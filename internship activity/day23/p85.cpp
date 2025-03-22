Q4.write a c++ program for find the Area of different shapes using function template.

#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Shape {
public:
    virtual bool isGreaterThan(T value) = 0;  
};

template <typename T>
class Circle : public Shape<T> {
private:
    T radius;

public:
    Circle(T r) : radius(r) {}

    bool isGreaterThan(T value) override {
        return radius > value;
    }
};

template <typename T>
class Rectangle : public Shape<T> {
private:
    T length, breadth;

public:
    Rectangle(T l, T b) : length(l), breadth(b) {}

    bool isGreaterThan(T value) override {
        return (length * breadth) > value;
    }
};

int main() {
    double radius, length, breadth, compareValue;
    cout << "Enter the radius of the circle: ";
    cin >> radius;
    Circle<double> circle(radius);

    cout << "Enter the length and breadth of the rectangle: ";
    cin >> length >> breadth;
    Rectangle<double> rectangle(length, breadth);

    cout << "Enter a value to compare with: ";
    cin >> compareValue;

    if (circle.isGreaterThan(compareValue)) {
        cout << "Circle area is greater than the value." << endl;
    } else {
        cout << "Circle area is not greater than the value." << endl;
    }

    if (rectangle.isGreaterThan(compareValue)) {
        cout << "Rectangle area is greater than the value." << endl;
    } else {
        cout << "Rectangle area is not greater than the value." << endl;
    }

    return 0;
}

Output:

Enter the radius of the circle: 10
Enter the length and breadth of the rectangle: 40 20
Enter a value to compare with: 15
Circle area is not greater than the value.
Rectangle area is greater than the value.