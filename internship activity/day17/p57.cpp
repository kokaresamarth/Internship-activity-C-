Q5.write a c++ program for find the volume and area of the shapes circle,sphere,sylinder,cone,ellipse.

#include <iostream>
#include <string>
#define PI 3.1415926

using namespace std;

double circleRadius;
double sphereRadius;
double cylinderRadius, cylinderHeight;
double coneRadius, coneHeight;
double major, minor;

void circle(double r) 
{
    cout << "Circle: " << endl;
    cout << "Perimeter = " << PI * 2 * r << endl;
    cout << "Area = " << PI * r * r << endl << endl;
}

void sphere(double r) 
{
    cout << "Sphere: " << endl;
    cout << "Surface Area = " << 4 * PI * r * r << endl;
    cout << "Volume = " << (4.0 / 3.0) * PI * r * r * r << endl << endl;
}

void cylinder(double r, double h) 
{
    cout << "Cylinder: " << endl;
    cout << "Surface Area = " << (2 * PI * r * h) + 2 * PI * r * r << endl;
    cout << "Volume = " << PI * r * r * h << endl << endl;
}

void cone(double r, double h)
{
    cout << "Cone: " << endl;
    cout << "Surface Area = " << (PI * r * h) + (PI * r * r) << endl;
    cout << "Volume = " << (1.0 / 3.0) * PI * r * r * h << endl << endl;
}

void ellipse(double m, double n) 
{
    cout << "Ellipse: " << endl;
    cout << "Area = " << PI * m * n << endl << endl;
}

int main() 
{
    cout << "Enter the radius of the circle: ";
    cin >> circleRadius;
    circle(circleRadius);
   
    cout << "Enter the radius of the sphere: ";
    cin >> sphereRadius;
    sphere(sphereRadius);
  
    cout << "Enter the radius and height of the cylinder: ";
    cin >> cylinderRadius >> cylinderHeight;
    cylinder(cylinderRadius, cylinderHeight);

    cout << "Enter the radius and height of the cone: ";
    cin >> coneRadius >> coneHeight;
    cone(coneRadius, coneHeight);

    cout << "Enter the major and minor axes of the ellipse: ";
    cin >> major >> minor;
    ellipse(major, minor);

    return 0;
}

Output:

Enter the radius of the circle: 20
Circle:
Perimeter = 125.664
Area = 1256.64

Enter the radius of the sphere: 30
Sphere:
Surface Area = 11309.7
Volume = 113097

Enter the radius and height of the cylinder: 30 80
Cylinder:
Surface Area = 20734.5
Volume = 226195

Enter the radius and height of the cone: 20 60
Cone:
Surface Area = 5026.55
Volume = 25132.7

Enter the major and minor axes of the ellipse: 2 4
Ellipse:
Area = 25.1327