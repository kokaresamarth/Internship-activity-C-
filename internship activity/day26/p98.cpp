Q4.Define an abstract class Vehicle with pure virtual methods startEngine() and stopEngine(). Implement derived classes Car and Bike with appropriate functionality.

#include <iostream>
#include <string>

using namespace std;


class Vehicle {
public:
    virtual void startEngine() const = 0;
    virtual void stopEngine() const = 0;
    virtual void displayInfo() const = 0;
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
private:
    string brand;
    int horsepower;

public:
    Car(const string& brand, int horsepower) : brand(brand), horsepower(horsepower) {}

    void startEngine() const override {
        cout << "The engine of the car (" << brand << ", " << horsepower << " HP) is started." << endl;
    }

    void stopEngine() const override {
        cout << "The engine of the car (" << brand << ", " << horsepower << " HP) is stopped." << endl;
    }

    void displayInfo() const override {
        cout << "Car Info:\nBrand: " << brand << "\nHorsepower: " << horsepower << " HP\n";
    }
};


class Bike : public Vehicle {
private:
    string model;

public:
    Bike(const string& model) : model(model) {}

    void startEngine() const override {
        cout << "The engine of the bike (" << model << ") is started." << endl;
    }

    void stopEngine() const override {
        cout << "The engine of the bike (" << model << ") is stopped." << endl;
    }

    void displayInfo() const override {
        cout << "Bike Info:\nModel: " << model << "\n";
    }
};

int main() {
    int choice;
    string name;
    Vehicle* vehicle = nullptr;

    cout << "Select a vehicle to test:\n";
    cout << "1. Car\n";
    cout << "2. Bike\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) 
    {
        int horsepower;
        cout << "Enter the brand of the car: ";
        cin >> name;
        cout << "Enter the horsepower of the car: ";
        cin >> horsepower;
        vehicle = new Car(name, horsepower);
    } 
    else if (choice == 2) 
    {
        cout << "Enter the model of the bike: ";
        cin >> name;
        vehicle = new Bike(name);
    }
    else 
    {
        cout << "Invalid choice!" << endl;
        return 1;
    }


    vehicle->displayInfo();
    vehicle->startEngine();
    vehicle->stopEngine();


    delete vehicle;

    return 0;
}

Output:

Select a vehicle to test:
1. Car
2. Bike
Enter your choice (1 or 2): 1
Enter the brand of the car: shift
Enter the horsepower of the car: 6
Car Info:
Brand: shift
Horsepower: 6 HP
The engine of the car (shift, 6 HP) is started.
The engine of the car (shift, 6 HP) is stopped.

Select a vehicle to test:
1. Car
2. Bike
Enter your choice (1 or 2): 2
Enter the model of the bike: spinder +
Bike Info:
Model: spinder
The engine of the bike (spinder) is started.
The engine of the bike (spinder) is stopped.