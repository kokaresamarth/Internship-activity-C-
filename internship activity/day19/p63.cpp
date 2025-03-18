Q1.write a c++ program for Matrix diagonal printing.

#include <iostream>

using namespace std;

void printDiagonalOrder(int matrix[100][100], int rows, int cols) {
   
    for (int startRow = rows - 1; startRow >= 0; --startRow) {
        int row = startRow;
        int col = 0;
       
        while (row < rows && col < cols) {
            cout << matrix[row][col] << " ";
            row++;
            col++;
        }
        cout << endl;
    }

    for (int startCol = 1; startCol < cols; ++startCol) {
        int row = 0;
        int col = startCol;

        while (row < rows && col < cols) {
            cout << matrix[row][col] << " ";
            row++;
            col++;
        }
        cout << endl;
    }
}

int main() {
    int rows, cols;
    int matrix[100][100]; 
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    
    cout << "The diagonal order output is:" << endl;
    printDiagonalOrder(matrix, rows, cols);

    return 0;
}

Output:

Enter number of rows: 6 4
Enter number of columns: Enter the elements of the matrix:

10 20 30 40
50 60 70 80
90 100 110 120
130 140 150 160
170 180 190 200
210 220 230 240

The diagonal order output is:

210
170 220
130 180 230
90 140 190 240
50 100 150 200
10 60 110 160
20 70 120
30 80
40