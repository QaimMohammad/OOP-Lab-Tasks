#include <iostream>
#include <vector>
using namespace std;

class Matrix {
private:
    int rows, cols;
    vector<vector<int>> elements;

public:
    // Constructor
    Matrix(int r, int c) : rows(r), cols(c) {
        elements.resize(rows, vector<int>(cols, 0)); // Initialize matrix with zeros
    }

    // Get the number of rows
    int getRows() {
        return rows;
    }

    // Get the number of columns
    int getCols() {
        return cols;
    }

    // Set elements at a given position
    void setElement(int i, int j, int value) {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            elements[i][j] = value;
        } else {
            cout << "Invalid index" << endl;
        }
    }

    // Adding two matrices
    Matrix add(Matrix& other) {
        if (this->rows != other.getRows() || this->cols != other.getCols()) {
            cout << "Matrices cannot be added" << endl;
            return Matrix(0, 0);  // Return an empty matrix if they can't be added
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.setElement(i, j, elements[i][j] + other.elements[i][j]);
            }
        }
        return result;
    }

    // Multiplying two matrices
    Matrix multiply(Matrix& other) {
        if (this->cols != other.getRows()) {
            cout << "Matrices cannot be multiplied" << endl;
            return Matrix(0, 0);  // Return an empty matrix if they can't be multiplied
        }
        Matrix result(rows, other.getCols());
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.getCols(); j++) {
                for (int k = 0; k < cols; k++) {
                    result.elements[i][j] += elements[i][k] * other.elements[k][j];
                }
            }
        }
        return result;
    }

    // Display the matrix
    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << elements[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Create two 2x2 matrices
    Matrix matrix1(2, 2);
    Matrix matrix2(2, 2);

    // Set values for the first matrix
    matrix1.setElement(0, 0, 1);
    matrix1.setElement(0, 1, 2);
    matrix1.setElement(1, 0, 3);
    matrix1.setElement(1, 1, 4);

    // Set values for the second matrix
    matrix2.setElement(0, 0, 5);
    matrix2.setElement(0, 1, 6);
    matrix2.setElement(1, 0, 7);
    matrix2.setElement(1, 1, 8);

    cout << "Matrix 1:" << endl;
    matrix1.display();

    cout << "Matrix 2:" << endl;
    matrix2.display();

    // Add matrices
    Matrix resultAdd = matrix1.add(matrix2);
    cout << "Matrix 1 + Matrix 2:" << endl;
    resultAdd.display();

    // Multiply matrices
    Matrix resultMul = matrix1.multiply(matrix2);
    cout << "Matrix 1 * Matrix 2:" << endl;
    resultMul.display();

    return 0;
}

