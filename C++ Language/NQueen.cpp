//Implementing the NQueens problem with the Backtracking Technique
#include <iostream>
#include <vector>
using namespace std;
void printStep(const vector<vector<int> >& board, int N, int row, int col, string action) {
    cout << "\033[2J\033[1;1H";
    cout << "Action: " << action << " at Row " << row << ", Col " << col << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j]) cout << " Q ";
            else cout << " . ";
        }
        cout << endl;
    }
    cout << "-----------------------" << endl;
}

bool isSafe(const vector<vector<int> >& board, int row, int col, int N) {
    for (int i = 0; i < row; i++) if (board[i][col]) return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) if (board[i][j]) return false;
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) if (board[i][j]) return false;
    return true;
}

bool solveNQueens(vector<vector<int> >& board, int row, int N) {
    if (row >= N) return true;
    int a[N];
    for (int col = 0; col < N; col++) {
        printStep(board, N, row, col, "Checking");
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;
            a.add(row);
            printStep(board, N, row, col, "PLACED");
            if (solveNQueens(board, row + 1, N)) return true;
            board[row][col] = 0;
            printStep(board, N, row, col, "BACKTRACKING (Removing)");
        }
    }
    cout<<a;
    return false;
}

int main() {
    int N;
    cout << "Enter number of Queens: ";
    cin >> N;
    int a[N];

    vector<vector<int> > board(N, vector<int>(N, 0));

    if (solveNQueens(board, 0, N)) {
        cout << "Final Solution Found!" << endl;
    } else {
        cout << "No solution exists." << endl;
    }
    return 0;
}
