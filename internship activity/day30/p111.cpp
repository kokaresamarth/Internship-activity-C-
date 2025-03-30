Q1.write a c++ program for perform operations like find feet and inches using operator overloading.

#include <iostream> 
#include <cmath>
using namespace std;

typedef struct
{
    double feet; 
    double inch; 
} Length;


class inchFeet 
{
private:
    Length length; 

public:
    
    inchFeet() 
    {
        length.feet = 0;
        length.inch = 0;
    }

    
    inchFeet(double feet, double inch)
    {
        length.feet = feet;
        length.inch = inch;
    }
    inchFeet(const inchFeet &var)
    {
        length.feet = var.length.feet;
        length.inch = var.length.inch;
    }

    void input() {
        cout << "Enter feet: ";
        cin >> length.feet;
        cout << "Enter inches: ";
        cin >> length.inch;

        if (length.inch >= 12) 
        {
            length.feet += static_cast<int>(length.inch) / 12;
            length.inch = fmod(length.inch, 12);
        }
    }

    void print() const 
    {
        cout << length.feet << " feet and " << length.inch << " inches" << endl;
    }

    double getFeet() const { return length.feet; }
    double getInch() const { return length.inch; }


    inchFeet operator+(const inchFeet &obj)
    {
        inchFeet result;
        result.length.feet = length.feet + obj.length.feet;
        result.length.inch = length.inch + obj.length.inch;

        if (result.length.inch >= 12.0)
        {
            result.length.feet += static_cast<int>(result.length.inch) / 12;
            result.length.inch = fmod(result.length.inch, 12);
        }

        return result;
    }

    inchFeet operator-(const inchFeet &obj) 
    {
        inchFeet result;
        Length temp = length;

        if (temp.feet >= obj.length.feet) 
        {
            if (temp.inch < obj.length.inch)
            {
                temp.feet--;
                temp.inch += 12;
            }

            result.length.feet = temp.feet - obj.length.feet;
            result.length.inch = temp.inch - obj.length.inch;
        } 
        else 
        {
            cout << "Error: Negative length is not possible!" << endl;
            result.length.feet = 0;
            result.length.inch = 0;
        }

        return result;
    }
};

int main()
{
    inchFeet length1, length2, result;

    cout << "Enter the first length:\n";
    length1.input();

    cout << "Enter the second length:\n";
    length2.input();

    cout << "\nThe first length is: ";
    length1.print();

    cout << "The second length is: ";
    length2.print();

    result = length1 + length2;
    cout << "\nAfter addition: ";
    result.print();

    result = length1 - length2;
    cout << "\nAfter subtraction: ";
    result.print();

    return 0;
}

Output:

Enter the first length:
Enter feet: 40
Enter inches: 20
Enter the second length:
Enter feet: 80
Enter inches: 40

The first length is: 41 feet and 8 inches
The second length is: 83 feet and 4 inches

After addition: 125 feet and 0 inches
Error: Negative length is not possible!

After subtraction: 0 feet and 0 inches