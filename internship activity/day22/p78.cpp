Q2.write a c++ program for perform array operations in a class using templates.

#include <iostream>
#include <string>
using namespace std;

const int MAX_PRODUCTS = 100; 
template <typename T>
class ProductManager {
    T products[MAX_PRODUCTS]; 
    double prices[MAX_PRODUCTS]; 
    int productCount;

public:
    
    ProductManager() : productCount(0) {}

    void initialize(const T initialProducts[], const double initialPrices[], int count) {
        if (count > MAX_PRODUCTS) {
            cout << "Error: Too many products to initialize!" << endl;
            return;
        }
        for (int i = 0; i < count; ++i) {
            products[i] = initialProducts[i];
            prices[i] = initialPrices[i];
        }
        productCount = count;
    }

    void display() const {
        if (productCount == 0) {
            cout << "No products available!" << endl;
            return;
        }
        cout << "Product List:" << endl;
        for (int i = 0; i < productCount; ++i) {
            cout << i + 1 << ". " << products[i] << " - " << prices[i] << endl;
        }
    }

    void addProduct(const T& product, double price) {
        if (productCount >= MAX_PRODUCTS) {
            cout << "Error: Product list is full!" << endl;
            return;
        }
        products[productCount] = product;
        prices[productCount] = price;
        ++productCount;
        cout << "Product added: " << product << " - " << price << endl;
    }

    void removeProduct(int index) {
        if (index < 0 || index >= productCount) {
            cout << "Error: Invalid index!" << endl;
            return;
        }
        cout << "Removing product: " << products[index] << endl;
        for (int i = index; i < productCount - 1; ++i) {
            products[i] = products[i + 1];
            prices[i] = prices[i + 1];
        }
        --productCount;
    }

    double calculateTotalValue() const {
        double total = 0.0;
        for (int i = 0; i < productCount; ++i) {
            total += prices[i];
        }
        return total;
    }
};

int main() {
  
    ProductManager<string> manager;

    string initialProducts[] = {"Laptop", "Smartphone", "Tablet"};
    double initialPrices[] = {999.99, 499.99, 299.99};
    manager.initialize(initialProducts, initialPrices, 3);

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