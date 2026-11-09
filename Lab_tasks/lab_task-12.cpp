// Implementation of N-Queen Problem using Backtracking

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<string> &board, int n, int row, int col)
{
    // Column check
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 'Q')
            return false;
    }

    // Left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    // Right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    return true;
}

void nQueens(vector<string> &board,
             int n,
             int row,
             vector<vector<string>> &ans)
{
    // Base Case
    if (row == n)
    {
        ans.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, n, row, col))
        {
            board[row][col] = 'Q';
            // Recursive Case
            nQueens(board, n, row + 1, ans);
            board[row][col] = '.'; // BackTracking
        }
    }
}

vector<vector<string>> solveQueens(int n)
{
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;

    nQueens(board, n, 0, ans);

    return ans;
}

int main()
{
    int n;

    cout << "Enter number of queens: ";
    cin >> n;

    vector<vector<string>> ans = solveQueens(n);

    cout << "\nTotal Solutions: " << ans.size() << "\n\n";

    for (int k = 0; k < ans.size(); k++)
    {
        cout << "Solution " << k + 1 << ":\n";

        for (string row : ans[k])
            cout << row << endl;

        cout << endl;
    }

    return 0;
}