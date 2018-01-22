class Solution {
public:
    /**
      * @param board: the board
      * @return: wether the Sudoku is valid
      */
    bool isValidSudoku(const vector<vector<char>>& board) {
        if (board.size() != 9 || board[0].size() != 9) return false;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (!isdigit(board[i][j])) continue;
                if (!isValid(board, i, j)) return false;
            }
        }
        return true;
    }
    
    bool isValid(const vector<vector<char>>& board, int i, int j) {
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
