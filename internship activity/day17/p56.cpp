Q4.write a c++ program for find wheather the given lines are parallel or perpendicular.

#include <iostream>
using namespace std;

bool areLinesParallel(float A1, float B1, float A2, float B2)
{
    return (A1 * B2 == A2 * B1);
}
bool areLinesPerpendicular(float A1, float B1, float A2, float B2)
{   
    return (A1 * A2 + B1 * B2 == 0);
}
int main()
{
    float A1, B1, C1, A2, B2, C2; 
    cout << "Enter coefficients for the first line A1 B1 C1: ";
    cin >> A1 >> B1 >> C1;

    cout << "Enter coefficients for the second line A2 B2 C2: ";
    cin >> A2 >> B2 >> C2;

    if (areLinesParallel(A1, B1, A2, B2))
    {
        cout << "The lines are parallel." << endl;
    }
    else
    {
        cout << "The lines are not parallel." << endl;
    }

    if (areLinesPerpendicular(A1, B1, A2, B2))
    {
        cout << "The lines are perpendicular." << endl;
    }
    else
    {
        cout << "The lines are not perpendicular." << endl;
    }

    return 0;
}

Output:

Enter coefficients for the first line A1 B1 C1: 10 20 30
Enter coefficients for the second line A2 B2 C2: 20 40 50
The lines are parallel.
The lines are not perpendicular.

Enter coefficients for the first line A1 B1 C1: 10 20 30
Enter coefficients for the second line A2 B2 C2: -20 10 30
The lines are not parallel.
The lines are perpendicular.