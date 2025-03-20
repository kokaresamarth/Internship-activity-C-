Q3.write a c++ program for perform hierarchical inheritance.

#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "This animal eats food." << endl;
    }
    void sleep() {
        cout << "This animal sleeps." << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "The dog barks: Woof Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void meow() {
        cout << "The cat meows: Meow Meow!" << endl;
    }
};

int main() {
    Dog dog;
    cout << "Dog activities:" << endl;
    dog.eat(); 
    dog.sleep(); 
    dog.bark(); 

    Cat cat;
    cout << "\nCat activities:" << endl;
    cat.eat();  
    cat.sleep(); 
    cat.meow(); 

    return 0;
}

Output:

Dog activities:
This animal eats food.
This animal sleeps.
The dog barks: Woof Woof!

Cat activities:
This animal eats food.
This animal sleeps.
The cat meows: Meow Meow!