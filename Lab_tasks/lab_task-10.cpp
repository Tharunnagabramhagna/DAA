#include <iostream>
#include <vector>
using namespace std;

int knapSack01_DP(vector<vector<int>>& items, int W) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= W; j++) {
            // val and wt of prev row
            int val = items[i-1][0];
            int wt = items[i-1][1];
            
            // Case-1
            if(wt <= j)
                dp[i][j] = max(val + dp[i-1][j-wt] , dp[i-1][j]);
            else // wt > j (Case-2)
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][W];
}

int main() {
    vector<vector<int>> items = {
        {10, 5},
        {40, 4},
        {30, 6},
        {50, 3}
    }; // {val, wt}

    int W = 10;

    cout << "Maximum Profit of items : ";
    cout << knapSack01_DP(items, W);

    return 0;
}