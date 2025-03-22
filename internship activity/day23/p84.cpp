Q3.write a c++ program for find the details of different vehicles using function overriding.

#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string brand;
    int speed;

public:
    
    Vehicle(string b, int s) : brand(b), speed(s) {}

    virtual void displayInfo() {
        cout << "Brand: " << brand << endl;
        cout << "Speed: " << speed << " km/h" << endl;
    }

    virtual ~Vehicle() {}
};

class Car : public Vehicle {
private:
    int numDoors;

public:

    Car(string b, int s, int doors) : Vehicle(b, s), numDoors(doors) {}

    void displayInfo() override {
        cout << "Car Details:" << endl;
        cout << "Brand: " << brand << endl;
        cout << "Speed: " << speed << " km/h" << endl;
        cout << "Number of Doors: " << numDoors << endl;
    }
};

class Bike : public Vehicle {
private:
    string type;

public:
    Bike(string b, int s, string t) : Vehicle(b, s), type(t) {}

    void displayInfo() override {
        cout << "Bike Details:" << endl;
        cout << "Brand: " << brand << endl;
        cout << "Speed: " << speed << " km/h" << endl;
        cout << "Type: " << type << endl;
    }
};

int main() {
    Vehicle* vehicle;

    int choice;
    cout << "Select a vehicle type:\n1. Car\n2. Bike\nEnter your choice: ";
    cin >> choice;

    if (choice == 1) {
        string brand;
        int speed, doors;
        cout << "Enter car brand: ";
        cin >> brand;
        cout << "Enter car speed: ";
        cin >> speed;
        cout << "Enter number of doors: ";
        cin >> doors;

        vehicle = new Car(brand, speed, doors);
    } else if (choice == 2) {
        string brand, type;
        int speed;
        cout << "Enter bike brand: ";
        cin >> brand;
        cout << "Enter bike speed: ";
        cin >> speed;
        cout << "Enter bike type (e.g., Sports, Cruiser): ";
        cin >> type;

        vehicle = new Bike(brand, speed, type);
    } else {
        cout << "Invalid choice." << endl;
        return 1;
    }

    vehicle->displayInfo();

    delete vehicle;

    return 0;
}

Output:

Select a vehicle type:
1. Car
2. Bike
Enter your choice: 1
Enter car brand: RR
Enter car speed: 180
Enter number of doors: 4
Car Details:
Brand: RR
Speed: 180 km/h
Number of Doors: 4