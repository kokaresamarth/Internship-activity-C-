Q1.write a c++ program for perform vector operations in a class using templates.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
class ProductManager {
    vector<T> products; 
    vector<double> prices; 

public:
    
    void initialize(const vector<T>& initialProducts, const vector<double>& initialPrices) {
        if (initialProducts.size() != initialPrices.size()) {
            cout << "Error: Products and prices must have the same size." << endl;
            return;
        }
        products = initialProducts;
        prices = initialPrices;
    }

    
    void display() const {
        if (products.empty()) {
            cout << "No products available!" << endl;
            return;
        }
        cout << "Product List:" << endl;
        for (size_t i = 0; i < products.size(); ++i) {
            cout << i + 1 << ". " << products[i] << " - " << prices[i] << endl;
        }
    }

    void addProduct(const T& product, double price) {
        products.push_back(product);
        prices.push_back(price);
        cout << "Product added: " << product << " - " << price << endl;
    }

    void removeProduct(size_t index) {
        if (index >= products.size()) {
            cout << "Error: Invalid index!" << endl;
            return;
        }
        cout << "Removing product: " << products[index] << endl;
        products.erase(products.begin() + index);
        prices.erase(prices.begin() + index);
    }

    double calculateTotalValue() const {
        double total = 0.0;
        for (const auto& price : prices) {
            total += price;
        }
        return total;
    }
};

int main() {
    ProductManager<string> manager;

    vector<string> initialProducts = {"Laptop", "Smartphone", "Tablet"};
    vector<double> initialPrices = {999.99, 499.99, 299.99};
    manager.initialize(initialProducts, initialPrices);

    manager.display();

    manager.addProduct("Headphones", 89.99);

    manager.display();

    manager.removeProduct(1);

    manager.display();

    double totalValue = manager.calculateTotalValue();
    cout << "Total value of products: " << totalValue << endl;

    return 0;
}

Output:

Product List:
1. Laptop - 999.99
2. Smartphone - 499.99
3. Tablet - 299.99
Product added: Headphones - 89.99
Product List:
1. Laptop - 999.99
2. Smartphone - 499.99
3. Tablet - 299.99
4. Headphones - 89.99
Removing product: Smartphone
Product List:
1. Laptop - 999.99
2. Tablet - 299.99
3. Headphones - 89.99
Total value of products: 1389.97