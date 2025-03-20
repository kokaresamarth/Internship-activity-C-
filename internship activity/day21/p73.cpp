Q2.write a c++ program for perform the multiple inheritance for car details.

#include <iostream>
#include <string>

using namespace std;

class Vehicle {
public:
    string make;
    string model;
    int year;

    Vehicle(string make, string model, int year) {
        this->make = make;
        this->model = model;
        this->year = year;
    }

    void displayVehicleDetails() {
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }

    void drive() {
        cout << "Driving the " << make << " " << model << "!" << endl;
    }
};

class Engine {
public:
    string engineType;
    int horsepower;

    Engine(string engineType, int horsepower) {
        this->engineType = engineType;
        this->horsepower = horsepower;
    }

    void displayEngineDetails() {
        cout << "Engine Type: " << engineType << endl;
        cout << "Horsepower: " << horsepower << " HP" << endl;
    }

    void startEngine() {
        cout << "Starting the " << engineType << " engine with " << horsepower << " horsepower!" << endl;
    }
};

class Car : public Vehicle, public Engine {
public:
    string color;

    Car(string make, string model, int year, string engineType, int horsepower, string color)
        : Vehicle(make, model, year), Engine(engineType, horsepower) {
        this->color = color;
    }

    void displayCarDetails() {
        displayVehicleDetails();
        displayEngineDetails();
        cout << "Color: " << color << endl;
    }

    void driveCar() {
        drive();
        startEngine();
        cout << "Enjoy the ride in your " << color << " " << make << " " << model << "!" << endl;
    }
};

int main() {
    string make, model, engineType, color;
    int year, horsepower;

    cout << "Enter car make: ";
    getline(cin, make);

    cout << "Enter car model: ";
    getline(cin, model);

    cout << "Enter car year: ";
    cin >> year;
    cin.ignore();  
    cout << "Enter engine type: ";
    getline(cin, engineType);

    cout << "Enter horsepower: ";
    cin >> horsepower;
    cin.ignore();  

    cout << "Enter car color: ";
    getline(cin, color);

    Car car1(make, model, year, engineType, horsepower, color);

    cout << endl;
    car1.displayCarDetails();
    car1.driveCar();

    return 0;
}

Output:

Enter car make: shift
Enter car model: battery
Enter car year: 2027
Enter engine type: 4 strock
Enter horsepower: 20000
Enter car color: white

Make: shift
Model: battery
Year: 2027
Engine Type: 4 strock
Horsepower: 20000 HP
Color: white
Driving the shift battery!
Starting the 4 strock engine with 20000 horsepower!
Enjoy the ride in your white shift battery!