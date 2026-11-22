/* 12. Divide and conquer: Implementation of Strassen’s algorithm for matrix
multiplication. Also analyze how this approach is advantage when compared to
normal multiplication */

// Algorithm
// 1. Start.
// 2. Read two square matrices of equal size.
// 3. Divide both matrices into four equal submatrices.
// 4. Calculate the seven intermediate products using Strassen's formulas.
// 5. Combine the seven products to obtain four result submatrices.
// 6. Repeat recursively for larger matrices.
// 7. Display the resultant matrix.
// 8. Stop.

// T.C : O(N ^ 2.807)

#include <iostream>
#include <vector>
using namespace std;

class Matrix
{
    vector<vector<int>> mat;
    int n;

    // add or subtract the matrix elements
    // 1 --> add ; -1 --> subtract
    Matrix op(const Matrix &B, int sign)
    {
        Matrix result(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                result.mat[i][j] = mat[i][j] + sign * B.mat[i][j];
        }
        return result;
    }

public:
    Matrix(int size)
    {
        n = size;
        mat.resize(n, vector<int>(n, 0));
    }

    void addValue(int i, int j, int val)
    {
        mat[i][j] = val;
    }

    Matrix straseenMulitply(const Matrix &B)
    {
        // Base Case
        if (n == 1)
        {
            Matrix result(1);
            result.mat[0][0] = mat[0][0] * B.mat[0][0];
            return result;
        }

        // step-1 : Divide the matrix into n/2 parts
        int k = n / 2;
        Matrix a(k), b(k), c(k), d(k);
        Matrix e(k), f(k), g(k), h(k);

        // step-2 : Store the elements in the divided matrices
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                a.mat[i][j] = mat[i][j];
                b.mat[i][j] = mat[i][j + k];
                c.mat[i][j] = mat[i + k][j];
                d.mat[i][j] = mat[i + k][j + k];

                e.mat[i][j] = B.mat[i][j];
                f.mat[i][j] = B.mat[i][j + k];
                g.mat[i][j] = B.mat[i + k][j];
                h.mat[i][j] = B.mat[i + k][j + k];
            }
        }

        // step-3 : Store the results of 7 straseen's products formulas
        Matrix M1 = (a.op(d, 1)).straseenMulitply((e.op(h, 1)));
        Matrix M2 = (c.op(d, 1)).straseenMulitply(e);
        Matrix M3 = a.straseenMulitply(f.op(h, -1));
        Matrix M4 = d.straseenMulitply(g.op(e, -1));
        Matrix M5 = (a.op(b, 1)).straseenMulitply(h);
        Matrix M6 = (c.op(a, -1)).straseenMulitply((e.op(f, 1)));
        Matrix M7 = (b.op(d, -1)).straseenMulitply(g.op(h, 1));

        // step-4 : Combine and store them in the results
        Matrix C(n);

        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                C.mat[i][j] = M1.mat[i][j] + M4.mat[i][j] - M5.mat[i][j] + M7.mat[i][j];
                C.mat[i][j + k] = M3.mat[i][j] + M5.mat[i][j];
                C.mat[i + k][j] = M2.mat[i][j] + M4.mat[i][j];
                C.mat[i + k][j + k] = M1.mat[i][j] - M2.mat[i][j] + M3.mat[i][j] + M6.mat[i][j];
            }
        }

        return C; // Return the Final Matrix
    }

    void print()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << mat[i][j] << " ";
            cout << endl;
        }
    }
};

int main()
{
    int n;

    cout << "Enter the required dimensions of the matrix (only power of 2) : ";
    cin >> n;

    Matrix A(n), B(n);

    int val;

    // insert the values in A and B

    cout << "\nEnter the elments of Matrix-A row-by-row : \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Enter the element at " << i << " row  and " << j << " column : ";
            cin >> val;
            A.addValue(i, j, val);
        }
    }

    cout << endl;

    cout << "\nEnter the elments of Matrix-B row-by-row : \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Enter the element at " << i << " row  and " << j << "column : ";
            cin >> val;
            B.addValue(i, j, val);
        }
    }

    Matrix C = A.straseenMulitply(B);

    cout << "\nResult of Multiplying matrix A with B : \n";
    C.print();

    return 0;
}