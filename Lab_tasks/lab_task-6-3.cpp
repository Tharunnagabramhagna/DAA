/* 3Q) Divide and conquer: Implementation of Strassen’s algorithm for matrix multiplication.
Also analyze how this approach is advantage when compared to normal multiplication */

// Ans)

#include <iostream>
#include <vector>
using namespace std;

class Matrix {
private:
    vector<vector<int>> mat;
    int n;

    // Add two matrices
    Matrix add(const Matrix &B) {
        Matrix result(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                result.mat[i][j] = mat[i][j] + B.mat[i][j];
        return result;
    }

    // Subtract two matrices
    Matrix subtract(const Matrix &B) {
        Matrix result(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                result.mat[i][j] = mat[i][j] - B.mat[i][j];
        return result;
    }

public:
    Matrix(int size) {
        n = size;
        mat.resize(n, vector<int>(n, 0));
    }

    void setValue(int i, int j, int val) {
        mat[i][j] = val;
    }

    int getValue(int i, int j) const {
        return mat[i][j];
    }

    int size() const { return n; }

    // Strassen’s recursive multiplication
    Matrix multiplyStrassen(const Matrix &B) {
        if (n == 1) {
            Matrix result(1);
            result.mat[0][0] = mat[0][0] * B.mat[0][0];
            return result;
        }

        int k = n / 2;
        Matrix A11(k), A12(k), A21(k), A22(k);
        Matrix B11(k), B12(k), B21(k), B22(k);

        // Divide matrices into quadrants
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                A11.mat[i][j] = mat[i][j];
                A12.mat[i][j] = mat[i][j + k];
                A21.mat[i][j] = mat[i + k][j];
                A22.mat[i][j] = mat[i + k][j + k];

                B11.mat[i][j] = B.mat[i][j];
                B12.mat[i][j] = B.mat[i][j + k];
                B21.mat[i][j] = B.mat[i + k][j];
                B22.mat[i][j] = B.mat[i + k][j + k];
            }
        }

        // Strassen’s 7 products
        Matrix M1 = (A11.add(A22)).multiplyStrassen(B11.add(B22));
        Matrix M2 = (A21.add(A22)).multiplyStrassen(B11);
        Matrix M3 = A11.multiplyStrassen(B12.subtract(B22));
        Matrix M4 = A22.multiplyStrassen(B21.subtract(B11));
        Matrix M5 = (A11.add(A12)).multiplyStrassen(B22);
        Matrix M6 = (A21.subtract(A11)).multiplyStrassen(B11.add(B12));
        Matrix M7 = (A12.subtract(A22)).multiplyStrassen(B21.add(B22));

        // Combine results
        Matrix C(n);
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                C.mat[i][j] = M1.mat[i][j] + M4.mat[i][j] - M5.mat[i][j] + M7.mat[i][j];       // C11
                C.mat[i][j + k] = M3.mat[i][j] + M5.mat[i][j];                                // C12
                C.mat[i + k][j] = M2.mat[i][j] + M4.mat[i][j];                                // C21
                C.mat[i + k][j + k] = M1.mat[i][j] - M2.mat[i][j] + M3.mat[i][j] + M6.mat[i][j]; // C22
            }
        }
        return C;
    }

    void print() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << mat[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    int n = 2; // must be power of 2
    Matrix A(n), B(n);

    // Example input
    A.setValue(0, 0, 1); A.setValue(0, 1, 2);
    A.setValue(1, 0, 3); A.setValue(1, 1, 4);

    B.setValue(0, 0, 5); B.setValue(0, 1, 6);
    B.setValue(1, 0, 7); B.setValue(1, 1, 8);

    Matrix C = A.multiplyStrassen(B);

    cout << "Result of Strassens Multiplication:" << endl;
    C.print();

    return 0;
}
