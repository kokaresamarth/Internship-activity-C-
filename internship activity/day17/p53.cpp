Q1.write a c++ program for Given coordinates of four points in a plane, find if the four points form a square or not. 

#include <iostream>
using namespace std;

struct Point {
    int x, y;
};

int distSq(Point p, Point q)
{
    return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
}
bool isSquare(Point p1, Point p2, Point p3, Point p4)
{
    int d2 = distSq(p1, p2); 
    int d3 = distSq(p1, p3); 
    int d4 = distSq(p1, p4); 

    if (d2 == 0 || d3 == 0 || d4 == 0) 
        return false;
    if (d2 == d3 && 2 * d2 == d4
        && 2 * distSq(p2, p4) == distSq(p2, p3))
    {
        return true;
    }
    if (d3 == d4 && 2 * d3 == d2
        && 2 * distSq(p3, p2) == distSq(p3, p4)) 
    {
        return true;
    }
    if (d2 == d4 && 2 * d2 == d3
        && 2 * distSq(p2, p3) == distSq(p2, p4)) 
    {
        return true;
    }

    return false;
}

int main()
{
    Point p1, p2, p3, p4;

    cout << "Enter the coordinates of the first point (x1 y1): ";
    cin >> p1.x >> p1.y;

    cout << "Enter the coordinates of the second point (x2 y2): ";
    cin >> p2.x >> p2.y;

    cout << "Enter the coordinates of the third point (x3 y3): ";
    cin >> p3.x >> p3.y;

    cout << "Enter the coordinates of the fourth point (x4 y4): ";
    cin >> p4.x >> p4.y;

    isSquare(p1, p2, p3, p4) ? cout << "Yes" : cout << "No";

    return 0;
}

Output:

Enter the coordinates of the first point (x1 y1): 10 20
Enter the coordinates of the second point (x2 y2): 20 10
Enter the coordinates of the third point (x3 y3): 10 10
Enter the coordinates of the fourth point (x4 y4): 20 20
Yes

Enter the coordinates of the first point (x1 y1): 10 20
Enter the coordinates of the second point (x2 y2): 30 40
Enter the coordinates of the third point (x3 y3): 30 30
Enter the coordinates of the fourth point (x4 y4): 40 40
No