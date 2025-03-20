Q5.write a c++ program for perform hybrid inheritance.

#include <iostream>
using namespace std;

class Base {
public:
    void baseMethod() {
        cout << "Base class method called." << endl;
    }
};

class Derived1 : public Base {
public:
    void derived1Method() {
        cout << "Derived1 class method called." << endl;
    }
};

class Derived2 : public Base {
public:
    void derived2Method() {
        cout << "Derived2 class method called." << endl;
    }
};

class Final : public Derived1, public Derived2 {
public:
    void finalMethod() {
        cout << "Final class method called." << endl;
    }
};

int main() {
    Final obj;

    obj.derived1Method();  
    obj.derived2Method();
    obj.finalMethod();     

  
    obj.Derived1::baseMethod(); 
    obj.Derived2::baseMethod(); 

    return 0;
}

Output:

Derived1 class method called.
Derived2 class method called.
Final class method called.
Base class method called.
Base class method called.