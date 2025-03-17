Q2.write a c++ program for find the volume of the boxes using classes and this pointer.

#include <iostream>
using namespace std;

class Box {
private:
    double length, width, height;

public:
    
    Box(double length, double width, double height) {
        this->length = length;
        this->width = width;
        this->height = height;
    }

    double getVolume() {
        return this->length * this->width * this->height;
    }

  
    void displayDimensions() {
        cout << "Length: " << this->length << endl;
        cout << "Width: " << this->width << endl;
        cout << "Height: " << this->height << endl;
    }

   
    static void compareBoxes(Box &box1, Box &box2) {
        if (box1.getVolume() > box2.getVolume()) {
            cout << "Box 1 is larger in volume." << endl;
        } else if (box1.getVolume() < box2.getVolume()) {
            cout << "Box 2 is larger in volume." << endl;
        } else {
            cout << "Both boxes have the same volume." << endl;
        }
    }
};

int main() {
    double length1, width1, height1;
    double length2, width2, height2;

    
    cout << "Enter dimensions for Box 1 (length width height): ";
    cin >> length1 >> width1 >> height1;

    cout << "Enter dimensions for Box 2 (length width height): ";
    cin >> length2 >> width2 >> height2;


    Box box1(length1, width1, height1);
    Box box2(length2, width2, height2);

    cout << "\nBox 1 Dimensions:" << endl;
    box1.displayDimensions();

    cout << "\nBox 2 Dimensions:" << endl;
    box2.displayDimensions();

    cout << "\nBox 1 Volume: " << box1.getVolume() << endl;
    cout << "Box 2 Volume: " << box2.getVolume() << endl;


    cout << "\nComparing the two boxes by volume:" << endl;
    Box::compareBoxes(box1, box2);

    return 0;
}

Output:

Enter dimensions for Box 1 (length width height): 10 20  30
Enter dimensions for Box 2 (length width height): 40 50 60

Box 1 Dimensions:
Length: 10
Width: 20
Height: 30

Box 2 Dimensions:
Length: 40
Width: 50
Height: 60

Box 1 Volume: 6000
Box 2 Volume: 120000

Comparing the two boxes by volume:
Box 2 is larger in volume.