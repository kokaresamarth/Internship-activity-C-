Q2.write a c++ program for find the Volume and Surface area of Frustum of Cone

#include <iostream>
using namespace std;

float pi = 3.14159;
float volume(float r, float R, float h)
{
    return (float(1) / float(3)) * pi * h * (r * r + R * R + r * R);
}
float curved_surface_area(float r, float R, float l)
{
    return pi * l * (R + r);
}
float total_surface_area(float r, float R, float l, float h)
{
    return pi * l * (R + r) + pi * (r * r + R * R);
}
int main()
{
    float small_radius, big_radius, slant_height, height;

    cout << "Enter the radius of the smaller base (r): ";
    cin >> small_radius;

    cout << "Enter the radius of the larger base (R): ";
    cin >> big_radius;

    cout << "Enter the slant height (l): ";
    cin >> slant_height;

    cout << "Enter the height of the frustum (h): ";
    cin >> height;

    cout << "Volume of Frustum of Cone: "
         << volume(small_radius, big_radius, height) << endl;

    cout << "Curved Surface Area of Frustum of Cone: "
         << curved_surface_area(small_radius, big_radius, slant_height) << endl;

    cout << "Total Surface Area of Frustum of Cone: "
         << total_surface_area(small_radius, big_radius, slant_height, height) << endl;

    return 0;
}

Output:

Enter the radius of the smaller base (r): 10
Enter the radius of the larger base (R): 20
Enter the slant height (l): 40
Enter the height of the frustum (h): 30
Volume of Frustum of Cone: 21991.1
Curved Surface Area of Frustum of Cone: 3769.91
Total Surface Area of Frustum of Cone: 5340.7