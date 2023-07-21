#include <iostream>
using namespace std;

const int N_MAX = 100; // Maximum board size
int board[N_MAX][N_MAX]; // The chess board
int n; // Board size

// Check if it's safe to place a queen at position (x, y)
bool isSafe(int x, int y) {
    // Check if there's a queen in the same row
    for (int i = 0; i < n; i++) {
        if (board[x][i] == 1) {
            return false;
        }
    }
    // Check if there's a queen in the same column
    for (int i = 0; i < n; i++) {
        if (board[i][y] == 1) {
            return false;
        }
    }
    // Check if there's a queen in the same diagonal
    for (int i = x, j = y; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    for (int i = x, j = y; i < n && j < n; i++, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    for (int i = x, j = y; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    for (int i = x, j = y; i < n && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    // If no conflicts, it's safe to place the queen
    return true;
}

// Recursive function to solve the N Queen problem
bool solve(int col) {
    // Base case: all queens have been placed
    if (col >= n) {
        return true;
    }
    // Try placing a queen in each row of the current column
    for (int i = 0; i < n; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;
            if (solve(col+1)) { // Recursive call to place the next queen
                return true;
            }
            board[i][col] = 0; // Backtrack
        }
    }
    // If no solution found in this column, backtrack
    return false;
}

int main() {
    cout << "Enter board size (N): ";
    cin >> n;
    // Initialize the board
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }
    // Solve the N Queen problem
    if (solve(0)) {
        // Print the solution
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution found." << endl;
    }
    return 0;
}