class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if (board.size() != 9 || board[0].size() != 9) 
        {
            return;
        }
        backtrack(board, 0, 0);
    }
    
    bool backtrack(vector<vector<char>>& board, int row, int col) 
    {
        static const int SIZE = 9;
        if (SIZE == row)
        {
            return true;
        }
        
        if (SIZE == col)
        {
            return backtrack(board, row + 1, 0);
        }
        
        if (board[row][col] != '.')
        {
            return backtrack(board, row, col + 1);
        }
        
        for (int val = 1; val <= 9; val++)
        {
            board[row][col] = val + '0';
            if (isValid(board, row, col) && backtrack(board, row, col + 1))
            {
                return true;
            }
            board[row][col] = '.';
        }
        
        return false;
    }
    
    bool isValid(vector<vector<char>>& board, int i, int j) 
    {
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
