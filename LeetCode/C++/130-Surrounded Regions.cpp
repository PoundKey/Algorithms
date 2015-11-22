// Thoughts: 
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m-1 || j == 0 || j == n-1) {
                    DFS(board, i, j);
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = board[i][j] != '1' ? 'X' : 'O';
            }
        }
    }
    
    void DFS(vector<vector<char>>& board, int i, int j) {
        /*
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return;
        if (board[i][j] == 'O' ) {
            board[i][j] = '1';
            DFS(board, i - 1, j);
            DFS(board, i + 1, j);
            DFS(board, i, j - 1);
            DFS(board, i, j + 1);
        }
        */
        if (board[i][j] == 'O') {
            board[i][j] = '1';
            if (i > 0) DFS(board, i - 1, j);
            if (i < board.size() - 1) DFS(board, i + 1, j);
            if (j > 1) DFS(board, i, j - 1);
            if (j < board[0].size() - 1) DFS(board, i, j + 1);
        }
    }
};