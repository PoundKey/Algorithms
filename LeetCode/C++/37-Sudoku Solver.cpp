// Thoughts: 
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if (board.size() != 9 || board[0].size() != 9) return;
        DFS(board, 0, 0);
    }
    
    bool DFS(vector<vector<char>>& board, int i, int j) {
        if (i == 9) return true;
        if (j == 9) return DFS(board, i + 1, 0);
        if (board[i][j] != '.') return DFS(board, i, j + 1);
        // up to this point, board[i][j] == '.', let's try all digits from 1-9
        for (int val = 1; val <= 9; val++) {
            board[i][j] = val + '0';
            if (isValid(board, i, j) && DFS(board, i, j + 1)) return true;
        }
        board[i][j] = '.';
        return false;
    }
    
    bool isValid(vector<vector<char>>& board, int i, int j) {
        char val = board[i][j];
        for (int col = 0; col < 9; col++) {
            if (col == j) continue;
            if (board[i][col] == val) return false;
        }
        for (int row = 0; row < 9; row++) {
            if (row == i) continue;
            if (board[row][j] == val) return false;
        }
        int row = 3 * (i / 3), col = 3 * (j / 3);
        for (int m = row; m < row + 3; m++) {
            for (int n = col; n < col + 3; n++) {
                if (m == i && n == j) continue;
                if (board[m][n] == val) return false;
             }
        }
        return true;
    }
};