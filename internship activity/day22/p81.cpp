Q5.write a c++ program for perform map operations in a class using templates.

#include <iostream>
#include <map>
#include <string>
using namespace std;

template <typename T>
class ProductManager {
    map<T, double> products;

public:
    void initialize(const map<T, double>& initialProducts) {
        products = initialProducts;
    }

    void display() const {
        if (products.empty()) {
            cout << "No products available!" << endl;
            return;
        }
        int index = 1;
        for (const auto& product : products) {
            cout << index++ << ". " << product.first << " - " << product.second << endl;
        }
    }

    void addProduct(const T& product, double price) {
        auto result = products.emplace(product, price);
        if (result.second) {
            cout << "Product added: " << product << " - " << price << endl;
        } else {
            cout << "Product already exists: " << product << " with price " << products[product] << endl;
        }
    }

    void removeProduct(const T& product) {
        if (products.erase(product)) {
            cout << "Product removed: " << product << endl;
        } else {
            cout << "Product not found: " << product << endl;
        }
    }

    double calculateTotalValue() const {
        double total = 0.0;
        for (const auto& product : products) {
            total += product.second;
        }
        return total;
    }
};

int main() {
    ProductManager<string> manager;
    map<string, double> initialProducts = {{"Laptop", 999.99}, {"Smartphone", 499.99}, {"Tablet", 299.99}};
    manager.initialize(initialProducts);
    manager.display();
    manager.addProduct("Headphones", 89.99);
    manager.display();
    manager.removeProduct("Smartphone");
    manager.display();
    cout << "Total value of products: " << manager.calculateTotalValue() << endl;
    return 0;
}

Output:

1. Laptop - 999.99
2. Smartphone - 499.99
3. Tablet - 299.99
Product added: Headphones - 89.99

1. Headphones - 89.99
2. Laptop - 999.99
3. Smartphone - 499.99
4. Tablet - 299.99
Product removed: Smartphone

1. Headphones - 89.99
2. Laptop - 999.99
3. Tablet - 299.99
Total value of products: 1389.97