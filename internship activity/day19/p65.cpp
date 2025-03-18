Q3.write a c++ program for Example Input/Output 1:
Input 5
12345
23451
34512
45123
51234
Output: Yes

Example Input/Output 2:
Input 4
1234
2341
3412
4231
Output: No

#include <iostream>

using namespace std;


void calculateSums(int matrix[][100], int N, int rowSum[], int colSum[], int& diagonalSum) {
    
    for (int i = 0; i < N; i++) {
        rowSum[i] = 0;
        colSum[i] = 0;
    }

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            rowSum[row] += matrix[row][col];
            colSum[col] += matrix[row][col];

            if (row == col) {
                diagonalSum += matrix[row][col];
            }
        }
    }
}

void printSums(int rowSum[], int colSum[], int diagonalSum, int N) {
   
    bool isEqual = true;
    for (int i = 0; i < N; i++) {
        if (rowSum[i] != colSum[i]) {
            isEqual = false;
            break;
        }
    }

    if (isEqual) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    int N;
    cout<<"Enter the number: ";
    cin >> N;

    int matrix[100][100];  
    int rowSum[100] = {0}, colSum[100] = {0}; 
    int diagonalSum = 0;

   cout<<"Enter the values of matrix: ";
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cin >> matrix[row][col];
        }
    }
    
    calculateSums(matrix, N, rowSum, colSum, diagonalSum);

    printSums(rowSum, colSum, diagonalSum, N);

    return 0;
}

Output:

Enter the number: 3
Enter the values of matrix:
1 2 3
4 5 6
7 8 9
No

Enter the number: 3
Enter the values of matrix:
10 20 30
20 30 10
30 10 20
Yes