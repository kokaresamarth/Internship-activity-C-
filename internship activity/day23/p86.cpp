Q5.write a c++ program for perform multiset operations using class templates.

#include <iostream>
#include <set>
#include <string>
using namespace std;

template <typename T>
class ProductManager {
    multiset<pair<T, double>> products;

public:
    void initialize(const multiset<pair<T, double>>& initialProducts) {
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
        products.emplace(product, price);
        cout << "Product added: " << product << " - " << price << endl;
    }

    void removeProduct(const T& product) {
        auto it = products.begin();
        while (it != products.end()) {
            if (it->first == product) {
                cout << "Removing product: " << product << " - " << it->second << endl;
                products.erase(it);
                return;
            }
            ++it;
        }
        cout << "Product not found: " << product << endl;
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
    multiset<pair<string, double>> initialProducts = {{"Laptop", 999.99}, {"Smartphone", 499.99}, {"Tablet", 299.99}};
    manager.initialize(initialProducts);
    
    cout << "Initial Products: " << endl;
    manager.display();
    
    manager.addProduct("Headphones", 89.99);
    manager.addProduct("Smartphone", 499.99);  
    cout << "\nAfter adding products: " << endl;
    manager.display();
    
    
    manager.removeProduct("Smartphone");
    cout << "\nAfter removing product: " << endl;
    manager.display();
    
    cout << "\nTotal value of products: " << manager.calculateTotalValue() << endl;
    
    return 0;
}

Output:

Initial Products:
1. Laptop - 999.99
2. Smartphone - 499.99
3. Tablet - 299.99
Product added: Headphones - 89.99
Product added: Smartphone - 499.99

After adding products:
1. Headphones - 89.99
2. Laptop - 999.99
3. Smartphone - 499.99
4. Smartphone - 499.99
5. Tablet - 299.99
Removing product: Smartphone - 499.99

After removing product:
1. Headphones - 89.99
2. Laptop - 999.99
3. Smartphone - 499.99
4. Tablet - 299.99

Total value of products: 1889.96