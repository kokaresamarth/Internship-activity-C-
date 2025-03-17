Q4.write a c++ program for 
arithmetic operations on pointers in C++. These arithmetic operations are:
Increment Operator (++),Decrement Operator (--),Addition (+),Subtraction (-)

#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the number of elements you want to input: ";
    cin >> size;

    int* arr = new int[size]; 
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < size; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }
    
    int* ptr = arr;

    
    cout << "\nUsing increment operator (++) on pointer:\n";
    cout << "Initial pointer points to value: " << *ptr << " (address: " << ptr << ")\n";
    ptr++;  
    cout << "After incrementing, pointer points to value: " << *ptr << " (address: " << ptr << ")\n";

    cout << "\nUsing decrement operator (--) on pointer:\n";
    ptr--;  
    cout << "After decrementing, pointer points to value: " << *ptr << " (address: " << ptr << ")\n";

    cout << "\nUsing addition (+) with pointer:\n";
    ptr = arr;  
    ptr = ptr + 2; 
    cout << "After adding 2, pointer points to value: " << *ptr << " (address: " << ptr << ")\n";

  
    cout << "\nUsing subtraction (-) with pointer:\n";
    ptr = ptr - 1; 
    cout << "After subtracting 1, pointer points to value: " << *ptr << " (address: " << ptr << ")\n";

   
    delete[] arr;

    return 0;
}

Output:

Enter the number of elements you want to input: 6
Enter the elements of the array:
Element 1: 10
Element 2: 20
Element 3: 30
Element 4: 40
Element 5: 50
Element 6: 60

Using increment operator (++) on pointer:
Initial pointer points to value: 10 (address: 01624340)
After incrementing, pointer points to value: 20 (address: 01624344)

Using decrement operator (--) on pointer:
After decrementing, pointer points to value: 10 (address: 01624340)

Using addition (+) with pointer:
After adding 2, pointer points to value: 30 (address: 01624348)

Using subtraction (-) with pointer:
After subtracting 1, pointer points to value: 20 (address: 01624344)