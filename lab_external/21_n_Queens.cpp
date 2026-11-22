// 21. Implementation of N-Queen problem using Backtracking

// Algorithm
// 1. Start.
// 2. Read the number of queens N.
// 3. Create an N×N chessboard and initialize all positions as empty.
// 4. Place a queen in a safe position in the current row.
// 5. Check whether the position is safe from other queens in the same column and diagonals.
// 6. If safe, move to the next row.
// 7. If no safe position exists, backtrack and change the previous queen's position.
// 8. Repeat until all N queens are placed.
// 9. Display the chessboard.
// 10. Stop.

// T.C : O(n!) ; S.C : O(n ^ 2)

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &board, int row, int col, int n)
{
    // check all the columns
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
            return false;
    }

    // check both the diagonals
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Unsafe cheking condition
            // |row - i| == |col - j| --> checks for any diagonal queen condition
            // board[i][j] --> checks if diagonal queen alreay exists
            if (board[i][j] == 1 && abs(row - i) == abs(col - j))
                return false;
        }
    }

    return true; // Safe Position to place
}

bool solve(vector<vector<int>> &board, int row, int n)
{
    // All queens are placed
    if (row == n)
        return true;

    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col, n))
        {
            board[row][col] = 1;

            if (solve(board, row + 1, n))
                return true;

            board[row][col] = 0; // backtracking
        }
    }

    return false; // solution don't exist case
}

int main()
{
    int n;

    cout << "Enter the required number of queens : "; // input no. of queens
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0)); // NXN chessboard

    if (solve(board, 0, n))
    {

        cout << "Solution : \n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
    }
    else
        cout << "No Solution Exists!\n";

    return 0;
}