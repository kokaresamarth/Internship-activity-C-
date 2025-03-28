Q2.write a c++ program for check whether the given matrix is  upper triangular or lower triangular.

#include <iostream>
using namespace std;


void inputMatrix(int matrix[100][100], int rows, int cols)
{
    cout << "Enter the elements of the matrix (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }
}


bool isUpperTriangular(int matrix[100][100], int rows, int cols) 
{
    for (int i = 1; i < rows; i++) 
    { 
        for (int j = 0; j < i; j++) 
        {  
            if (matrix[i][j] != 0) 
            {  
                return false;
            }
        }
    }
    return true;
}


bool isLowerTriangular(int matrix[100][100], int rows, int cols)
{
    for (int i = 0; i < rows - 1; i++) 
    {
        for (int j = i + 1; j < cols; j++)
        { 
            if (matrix[i][j] != 0)
            {  
                return false;
            }
        }
    }
    return true;
}

void printMatrix(int matrix[100][100], int rows, int cols)
{
    cout << "The matrix is:\n";
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


bool isSquareMatrix(int rows, int cols) 
{
    return rows == cols;
}


int main() 
{
    int rows, cols;
    int matrix[100][100]; 

    cout << "Enter the number of rows and columns of the matrix: ";
    cin >> rows >> cols;

    if (!isSquareMatrix(rows, cols))
    {
        cout << "Matrix must be square to check for upper or lower triangular.\n";
        return 0;
    }

    inputMatrix(matrix, rows, cols);

    printMatrix(matrix, rows, cols);

    if (isUpperTriangular(matrix, rows, cols))
    {
        cout << "The matrix is upper triangular.\n";
    }
    
    else if (isLowerTriangular(matrix, rows, cols)) 
    {
        cout << "The matrix is lower triangular.\n";
    }
    
    else
    {
        cout << "The matrix is neither upper triangular nor lower triangular.\n";
    }

    return 0;
}

Output:

Enter the number of rows and columns of the matrix: 3 3
Enter the elements of the matrix (3x3):
1 2 3
0 4 5
0 0 6
The matrix is:
1 2 3 
0 4 5 
0 0 6 
The matrix is upper triangular.

Enter the number of rows and columns of the matrix: 3 3
Enter the elements of the matrix (3x3):
1 2 3 6 5 8 4 9 2
The matrix is:
1 2 3 
6 5 8 
4 9 2 
The matrix is neither upper triangular nor lower triangular