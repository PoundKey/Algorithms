// Thoughts: Classic DFS and Backtracking, remember to return true if word is empty,
// put this statement on the top line of DFS.
// Total time complexity: O(mn * len(str))
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        bool res = false;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) DFS(board, word, visited, res, i, j);
        }
        return res;
    }
    
    void DFS(vector<vector<char>>& board, string word, vector<vector<bool>>& visited, bool& res, int row, int col) {
        if (word.empty()) {
            res = true;
            return;
        }        
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || visited[row][col] || res) return;
        if (board[row][col] == word[0]) {
            visited[row][col] = true;
            DFS(board, word.substr(1), visited, res, row + 1, col);
            DFS(board, word.substr(1), visited, res, row - 1, col);
            DFS(board, word.substr(1), visited, res, row, col + 1);
            DFS(board, word.substr(1), visited, res, row, col - 1);
            visited[row][col] = false;
        }
    }
};

// A bit optimazation to reduce the overhead of strings created by word.substr()
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        bool res = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) DFS(board, word, 0, visited, res, i, j);
        }
        return res;
    }
    
    void DFS(vector<vector<char>>& board, string& word, int index, vector<vector<bool>>& visited, bool& res, int row, int col) {
        if (index == word.size()) {
            res = true;
            return;
        }        
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || visited[row][col] || res) return;
        if (board[row][col] == word[index]) {
            visited[row][col] = true;
            DFS(board, word, index + 1, visited, res, row + 1, col);
            DFS(board, word, index + 1, visited, res, row - 1, col);
            DFS(board, word, index + 1, visited, res, row, col + 1);
            DFS(board, word, index + 1, visited, res, row, col - 1);
            visited[row][col] = false;
        }
    }
};