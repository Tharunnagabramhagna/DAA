#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int chainMatrixMul(vector<int>& arr) {
    int n = arr.size();

    // Edge Case (less than or equal to 2 dimensions)
    if(n <= 2)
        return 0;
    
    // Initiaize the dp vector (caculates from 2 to n dimensions multiplications values)
    vector<vector<int>>dp(n, vector<int>(n, 0));

    for(int len = 2; len < n; len++) { // len => E.g. M1 X M2, M1 X M2 X M3 
        for(int i = 1; i <= n-len; i++) {
            int j = i + len - 1;
            // re-intialize so that we can get the min value of multiplication
            dp[i][j] = INT_MAX;

            for(int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + (arr[i-1] * arr[k] * arr[j]);
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    
    return dp[1][n-1]; // Final Min Valid of the Matrix
}

int main() {
    vector<int> arr = {2,1,3,4};

    cout << "Minimal Number of Multiplications for arr : " << chainMatrixMul(arr) << endl;

    return 0;
}