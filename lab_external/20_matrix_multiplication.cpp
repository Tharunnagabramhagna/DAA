// 20. Implementation of matrix chain multiplication using Dynamic Programming

// Algorithm
// 1. Start.
// 2. Read the number of matrices and their dimensions.
// 3. Create a DP table to store minimum multiplication costs.
// 4. Initialize the cost of multiplying a single matrix as zero.
// 5. Consider chains of increasing lengths.
// 6. Try every possible position to split the matrix chain.
// 7. Calculate the multiplication cost for each split.
// 8. Store the minimum cost in the DP table.
// 9. Display the minimum number of scalar multiplications.
// 10. Stop.

// T.C : O(n ^ 3) ; S.C : O(n ^ 2)

// Test Case : arr = [2,1,3,4] --> output : 20

#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int DPMatrixMul(int arr[], int n) {
    // Edge Case
    if(n <= 2)
        return 0;
    
    // step-1 : Initialize a dp vector with 0's
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // step-2 : Calculate the minimum product cost
    // len --> chain length of total number of matrices (E.g --> for M1 X M2 , len is 2)
    // i --> Represent First matrix in the product (E.g. M1)
    // j --> Represent Second matrix in the product (E.g. M2)
    for(int len = 2; len < n; len++) {
        for(int i = 0; i <= n - len; i++) {
            int j = i+len - 1;

            dp[i][j] = INT_MAX; // modify the matrix dist to get a min value

            for(int k = i; k < j; k++) {
                //  The Product (Mi,..,Mj) is Divided into two parts :
                // 1) Mi,....,Mk
                // product cost for 1st half is arr[i-1] * arr[k]
                // 2) M k+1,....,Mj
                // product cost for 2nd half is arr[k] * arr[j]
                int cost = dp[i][k] + dp[k+1][j] + (arr[i-1] * arr[k] * arr[j]);
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[1][n-1]; // Final Result (from M1,...., Mn-1)
}

int main() {
    int n;

    cout << "Enter the size of array : ";
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cout << "Enter the Element at index " << i << " : ";
        cin >> arr[i];
    }

    cout << "\nMinimum Cost Of Matrix Multiplication : " << DPMatrixMul(arr, n) << endl;

    return 0;
}