// 19. Implement 0/1 Knapsack problem using Dynamic Programming

// Algorithm 
// 1. Start.
// 2. Read the number of items and knapsack capacity.
// 3. Read the profit and weight of each item.
// 4. Create a DP table.
// 5. Initialize the first row and first column with zero.
// 6. For each item, check whether its weight fits in the current capacity.
// 7. If it fits, choose the maximum of including or excluding the item.
// 8. Otherwise, exclude the item.
// 9. Display the maximum profit.
// 10. Stop.

// T.C : O(nW) ; S.C : O(nW)

#include <iostream>
#include <vector>
using namespace std;

int knapSack0by1(vector<vector<int>>& items, int W) {
    int n = items.size();

    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= W; j++) {
            int val = items[i-1][0];
            int wt = items[i-1][1];

            if(wt <= j) // wt <= W
                dp[i][j] = max(val + dp[i-1][j-wt], dp[i-1][j]);
            else // wt > j --> wt > W
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][W]; // Final Result
}

int main() {
    vector<vector<int>> items = {
        {10, 5},
        {40, 4},
        {30, 6},
        {50, 3}
    }; // {val, wt}

    int c;

    cout << "Enter the required capacity : ";
    cin >> c;

    cout << "\nMaximum Profit of the items (0/1 knapSack DP) : \n";
    cout << knapSack0by1(items, c) << endl;

    return 0;
}