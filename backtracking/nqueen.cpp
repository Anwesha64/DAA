//  Time complexity : O(n)

#include <iostream>
using namespace std;
#define N 4 // Change N to the desired size of the board
int board[N][N] = {0};

void printBoard(int board[N][N]) {
    static int k = 1;
    cout << "Solution #" << k++ << ":\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int board[N][N], int row, int col) {
    // Check this row on the left side
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;
 
    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on the left side
    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

void solveNQueensUtil(int board[N][N], int col) {
    // If all queens are placed
    if (col >= N) {
        printBoard(board);
        return;
    }

    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < N; i++) {
        // Check if the queen can be placed on board[i][col]
        if (isSafe(board, i, col)) {
            // Place this queen in board[i][col]
            board[i][col] = 1;

            // Recur to place the rest of the queens
            solveNQueensUtil(board, col + 1);

            // If placing queen in board[i][col] doesn't lead to a solution,
            // then remove the queen from board[i][col]
            board[i][col] = 0; // BACKTRACK
        }
    }
}


// int board[N][N] = {0};
int main() {
    solveNQueensUtil(board,0);
    return 0;
}
