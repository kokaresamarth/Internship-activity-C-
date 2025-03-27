Q1.write a c++ program for create vehicle details perform activities using struct,union,enum.

#include <iostream>
#include <string>
using namespace std;

enum VehicleType
{
    CAR,
    MOTORCYCLE,
    TRUCK
};

struct CarInfo
{
    int numDoors;
    bool hasSunroof;
};

struct MotorcycleInfo 
{
    bool hasSidecar;
};

struct TruckInfo 
{
    double loadCapacity;
    int numAxles;
};

union VehicleDetails 
{
    CarInfo car;
    MotorcycleInfo motorcycle;
    TruckInfo truck;
};

struct Vehicle 
{
    string make;
    string model;
    int year;
    VehicleType type;
    VehicleDetails details;
};

void displayCarDetails(const CarInfo& car) 
{
    cout << "Number of doors: " << car.numDoors << endl;
    cout << "Sunroof: " << (car.hasSunroof ? "Yes" : "No") << endl;
}

void displayMotorcycleDetails(const MotorcycleInfo& motorcycle) 
{
    cout << "Sidecar: " << (motorcycle.hasSidecar ? "Yes" : "No") << endl;
}

void displayTruckDetails(const TruckInfo& truck)
{
    cout << "Load capacity (tons): " << truck.loadCapacity << endl;
    cout << "Number of axles: " << truck.numAxles << endl;
}

void displayVehicle(const Vehicle& vehicle) 
{
    cout << "\nVehicle Information:" << endl;
    cout << "Make: " << vehicle.make << endl;
    cout << "Model: " << vehicle.model << endl;
    cout << "Year: " << vehicle.year << endl;

    switch (vehicle.type)
    {
        case CAR:
            cout << "Type: Car" << endl;
            displayCarDetails(vehicle.details.car);
            break;
        case MOTORCYCLE:
            cout << "Type: Motorcycle" << endl;
            displayMotorcycleDetails(vehicle.details.motorcycle);
            break;
        case TRUCK:
            cout << "Type: Truck" << endl;
            displayTruckDetails(vehicle.details.truck);
            break;
        default:
            cout << "Type: Unknown" << endl;
    }
}

int main()
{
    Vehicle car;
    car.make = "Toyota";
    car.model = "Camry";
    car.year = 2021;
    car.type = CAR;
    car.details.car.numDoors = 4;
    car.details.car.hasSunroof = true;

    Vehicle motorcycle;
    motorcycle.make = "Harley-Davidson";
    motorcycle.model = "Sportster";
    motorcycle.year = 2020;
    motorcycle.type = MOTORCYCLE;
    motorcycle.details.motorcycle.hasSidecar = false;

    Vehicle truck;
    truck.make = "Ford";
    truck.model = "F-150";
    truck.year = 2019;
    truck.type = TRUCK;
    truck.details.truck.loadCapacity = 3.5;
    truck.details.truck.numAxles = 2;

    displayVehicle(car);
    displayVehicle(motorcycle);
    displayVehicle(truck);

    return 0;
}

Output:


Vehicle Information:
Make: Toyota
Model: Camry
Year: 2021
Type: Car
Number of doors: 4
Sunroof: Yes

Vehicle Information:
Make: Harley-Davidson
Model: Sportster
Year: 2020
Type: Motorcycle
Sidecar: No

Vehicle Information:
Make: Ford
Model: F-150
Year: 2019
Type: Truck
Load capacity (tons): 3.5
Number of axles: 2