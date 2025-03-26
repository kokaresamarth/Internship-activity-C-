Q2.write a c++ program for price details of Divices using smart pointers and new and delete operators.

#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

class Device {
protected:
    string name;
    double price;

public:
    Device(const std::string& name, double price) : name(name), price(price) {}
    virtual ~Device() {}

    virtual void displayDetails() const {
        cout << "Device Name: " << name << "\nPrice: $" << price << std::endl;
    }
};

class Mobile : public Device {
private:
    int storage;

public:
    Mobile(const string& name, double price, int storage)
        : Device(name, price), storage(storage) {}

    void displayDetails() const override {
        Device::displayDetails();
        cout << "Storage: " << storage << "GB" << std::endl;
    }
};

class Laptop : public Device {
private:
    int ram;

public:
    Laptop(const std::string& name, double price, int ram)
        : Device(name, price), ram(ram) {}

    void displayDetails() const override {
        Device::displayDetails();
        cout << "RAM: " << ram << "GB" << std::endl;
    }
};

int main() {
    vector<<shared_ptr<Device>> inventory;

    int choice;
    while (true) {
        cout << "\nInventory Management System\n";
        cout << "1. Add Mobile\n";
        cout << "2. Add Laptop\n";
        cout << "3. Display Inventory\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 4) break;

        string name;
        double price;
        switch (choice) {
            case 1: {
                int storage;
                std::cout << "Enter mobile name: ";
                std::cin >> name;
                std::cout << "Enter price: ";
                std::cin >> price;
                std::cout << "Enter storage (GB): ";
                std::cin >> storage;

                std::shared_ptr<Device> mobile = std::make_shared<Mobile>(name, price, storage);
                inventory.push_back(mobile);
                break;
            }
            case 2: {
                int ram;
                cout << "Enter laptop name: ";
                cin >> name;
                cout << "Enter price: ";
                cin >> price;
                cout << "Enter RAM (GB): ";
                cin >> ram;

                unique_ptr<Device> laptop(new Laptop(name, price, ram));
                inventory.push_back(move(laptop));
                break;
            }
            case 3: {
                if (inventory.empty()) {
                    cout << "Inventory is empty!" <<endl;
                } else {
                    for (const auto& device : inventory) {
                        device->displayDetails();
                        cout << "-------------------\n";
                    }
                }
                break;
            }
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    Device* manualDevice = new Mobile("ManualMobile", 299.99, 128);
    cout << "\nManually allocated device:\n";
    manualDevice->displayDetails();
    delete manualDevice;

    cout << "\nProgram terminated.\n";
    return 0;
}

Output:

Inventory Management System
1. Add Mobile
2. Add Laptop
3. Display Inventory
4. Exit
Enter your choice: 1
Enter mobile name: mi
Enter price: 10000
Enter storage (GB): 128

Inventory Management System
1. Add Mobile
2. Add Laptop
3. Display Inventory
4. Exit
Enter your choice: 2
Enter laptop name: dell
Enter price: 60000
Enter RAM (GB): 8

Inventory Management System
1. Add Mobile
2. Add Laptop
3. Display Inventory
4. Exit
Enter your choice: 3
Device Name: mi
Price: $10000
Storage: 128GB
-------------------
Device Name: dell
Price: $60000
RAM: 8GB
-------------------

Inventory Management System
1. Add Mobile
2. Add Laptop
3. Display Inventory
4. Exit
Enter your choice: 4

Manually allocated device:
Device Name: ManualMobile
Price: $299.99
Storage: 128GB

Program terminated.