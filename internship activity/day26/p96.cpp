Q2.Write a Matrix class that supports basic operations like addition, subtraction, multiplication, and transpose using class ,vector in c++.

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Matrix {
private:
    vector<vector<int>> data;
    size_t rows;
    size_t cols;

public:
    Matrix(size_t r, size_t c) : rows(r), cols(c), data(r, vector<int>(c, 0)) {}

    void inputMatrix() {
        cout << "Enter elements of the matrix (row by row):\n";
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                cin >> data[i][j];
            }
        }
    }

    void displayMatrix() const {
        for (const auto& row : data) {
            for (const auto& elem : row) {
                cout << elem << " ";
            }
            cout << endl;
        }
    }

    Matrix add(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Matrix dimensions must match for addition.");
        }
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix subtract(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Matrix dimensions must match for subtraction.");
        }
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix multiply(const Matrix& other) const {
        if (cols != other.rows) {
            throw invalid_argument("Matrix dimensions do not allow multiplication.");
        }
        Matrix result(rows, other.cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < other.cols; ++j) {
                for (size_t k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    Matrix transpose() const {
        Matrix result(cols, rows);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result.data[j][i] = data[i][j];
            }
        }
        return result;
    }
};

int main() {
    size_t rows1, cols1, rows2, cols2;

    cout << "Enter dimensions of the first matrix (rows and columns): ";
    cin >> rows1 >> cols1;
    Matrix mat1(rows1, cols1);
    mat1.inputMatrix();

    cout << "Enter dimensions of the second matrix (rows and columns): ";
    cin >> rows2 >> cols2;
    Matrix mat2(rows2, cols2);
    mat2.inputMatrix();

    try {
        cout << "Matrix 1:\n";
        mat1.displayMatrix();

        cout << "Matrix 2:\n";
        mat2.displayMatrix();

        if (rows1 == rows2 && cols1 == cols2) {
            cout << "Addition of matrices:\n";
            Matrix sum = mat1.add(mat2);
            sum.displayMatrix();

            cout << "Subtraction of matrices:\n";
            Matrix diff = mat1.subtract(mat2);
            diff.displayMatrix();
        } else {
            cout << "Addition and subtraction not possible due to dimension mismatch.\n";
        }

        if (cols1 == rows2) {
            cout << "Multiplication of matrices:\n";
            Matrix prod = mat1.multiply(mat2);
            prod.displayMatrix();
        } else {
            cout << "Multiplication not possible due to dimension mismatch.\n";
        }

        cout << "Transpose of the first matrix:\n";
        Matrix trans1 = mat1.transpose();
        trans1.displayMatrix();

        cout << "Transpose of the second matrix:\n";
        Matrix trans2 = mat2.transpose();
        trans2.displayMatrix();

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}


Output:

Enter dimensions of the first matrix (rows and columns): 3 2
Enter elements of the matrix (row by row):
1 2
3 4
7 8
Enter dimensions of the second matrix (rows and columns): 2 1
Enter elements of the matrix (row by row):
2
2
Matrix 1:
1 2
3 4
7 8
Matrix 2:
2
2
Addition and subtraction not possible due to dimension mismatch.
Multiplication of matrices:
6
14
30
Transpose of the first matrix:
1 3 7
2 4 8
Transpose of the second matrix:
2 2