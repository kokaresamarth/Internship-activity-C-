Q3.write a c++ program for perform list operations in a class using templates.

#include <iostream>
#include <list>
#include <string>
using namespace std;

template <typename T>
class ProductManager {
    list<pair<T, double>> products;

public:
    void initialize(const list<pair<T, double>>& initialProducts) {
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
        products.emplace_back(product, price);
        cout << "Product added: " << product << " - " << price << endl;
    }

    void removeProduct(int index) {
        if (index <= 0 || index > products.size()) {
            cout << "Error: Invalid index!" << endl;
            return;
        }
        auto it = products.begin();
        advance(it, index - 1);
        cout << "Removing product: " << it->first << endl;
        products.erase(it);
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
    list<pair<string, double>> initialProducts = {{"Laptop", 999.99}, {"Smartphone", 499.99}, {"Tablet", 299.99}};
    manager.initialize(initialProducts);
    manager.display();
    manager.addProduct("Headphones", 89.99);
    manager.display();
    manager.removeProduct(2);
    manager.display();
    cout << "Total value of products: " << manager.calculateTotalValue() << endl;
    return 0;
}

Output:

1. Laptop - 999.99
2. Smartphone - 499.99
3. Tablet - 299.99
Product added: Headphones - 89.99
1. Laptop - 999.99
2. Smartphone - 499.99
3. Tablet - 299.99
4. Headphones - 89.99
Removing product: Smartphone
1. Laptop - 999.99
2. Tablet - 299.99
3. Headphones - 89.99
Total value of products: 1389.97