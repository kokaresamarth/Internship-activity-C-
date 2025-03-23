Q4.write a c++ program for perform Area of shapes details operations using friend class ,friend functions.

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Circle;

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle() : length(0), width(0) {}

    void inputDimensions() {
        cout << "Enter the length of the rectangle: ";
        cin >> length;
        cout << "Enter the width of the rectangle: ";
        cin >> width;
    }

    double calculateArea() const {
        return length * width;
    }

    void display() const {
        cout << "Rectangle - Length: " << length << ", Width: " << width
             << ", Area: " << calculateArea() << "\n";
    }

    friend double compareAreas(const Rectangle&, const Circle&);
};

class Circle {
private:
    double radius;

public:
    Circle() : radius(0) {}

    void inputDimensions() {
        cout << "Enter the radius of the circle: ";
        cin >> radius;
    }

    double calculateArea() const {
        return M_PI * radius * radius;
    }

    void display() const {
        cout << "Circle - Radius: " << radius << ", Area: " << calculateArea() << "\n";
    }

    friend double compareAreas(const Rectangle&, const Circle&);
};

double compareAreas(const Rectangle& rect, const Circle& circ) {
    double rectArea = rect.calculateArea();
    double circArea = circ.calculateArea();
    cout << "Rectangle Area: " << rectArea << ", Circle Area: " << circArea << "\n";
    if (rectArea > circArea) {
        cout << "The rectangle has a larger area.\n";
    } else if (rectArea < circArea) {
        cout << "The circle has a larger area.\n";
    } else {
        cout << "Both have equal areas.\n";
    }
    return rectArea - circArea;
}
void displayMenu() {
    cout << "\nShape Area Comparison\n";
    cout << "1. Input Rectangle and Circle Dimensions\n";
    cout << "2. Compare Areas\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Rectangle rectangle;
    Circle circle;
    int choice;
    bool dimensionsEntered = false;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            rectangle.inputDimensions();
            circle.inputDimensions();
            dimensionsEntered = true;
            break;
        case 2:
            if (!dimensionsEntered) {
                cout << "Please enter dimensions first (Option 1).\n";
            } else {
                compareAreas(rectangle, circle);
            }
            break;
        case 3:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}

Output:

Shape Area Comparison
1. Input Rectangle and Circle Dimensions
2. Compare Areas
3. Exit
Enter your choice: 1
Enter the length of the rectangle: 40
Enter the width of the rectangle: 20
Enter the radius of the circle: 10

Shape Area Comparison
1. Input Rectangle and Circle Dimensions
2. Compare Areas
3. Exit
Enter your choice: 2
Rectangle Area: 800, Circle Area: 314.159
The rectangle has a larger area.

Shape Area Comparison
1. Input Rectangle and Circle Dimensions
2. Compare Areas
3. Exit
Enter your choice: 3
Exiting the program.