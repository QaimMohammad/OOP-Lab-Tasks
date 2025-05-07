#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class DimensionMismatchException : public exception {
public:
    const char* what() const noexcept override {
        return "Matrix dimension mismatch!";
    }
};

template <typename T>
class Matrix {
    vector<vector<T>> mat;
    int rows, cols;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        mat.resize(r, vector<T>(c));
    }

    T& at(int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            throw out_of_range("Index out of bounds!");
        return mat[r][c];
    }

    Matrix operator+(const Matrix& other) {
        if (rows != other.rows || cols != other.cols)
            throw DimensionMismatchException();
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.mat[i][j] = mat[i][j] + other.mat[i][j];
        return result;
    }

    Matrix operator*(const Matrix& other) {
        if (cols != other.rows)
            throw DimensionMismatchException();
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < other.cols; ++j)
                for (int k = 0; k < cols; ++k)
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];
        return result;
    }

    void display() {
        for (const auto& row : mat) {
            for (T val : row)
                cout << val << " ";
            cout << "\n";
        }
    }
};

int main() {
    Matrix<int> m1(2, 2), m2(2, 2);
    m1.at(0, 0) = 1; m1.at(0, 1) = 2;
    m1.at(1, 0) = 3; m1.at(1, 1) = 4;

    m2.at(0, 0) = 5; m2.at(0, 1) = 6;
    m2.at(1, 0) = 7; m2.at(1, 1) = 8;

    try {
        Matrix<int> sum = m1 + m2;
        sum.display();
    } catch (const exception& e) {
        cout << "Error: " << e.what() << "\n";
    }

    return 0;
}

