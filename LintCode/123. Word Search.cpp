// 1. classical DFS, key is to maintain a visited vector and check the 'accepted' condition in the beginning of the recursion.

class Solution {
public:
    /*
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool exist(vector<vector<char>> &board, string &word) {
        if (board.empty() || board[0].empty()) return false;
        if (word.empty()) return true;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (Search(board, visited, word, i, j, 0)) return true;
            }
        }
        return false;
    }
    bool Search(const vector<vector<char>>& board, vector<vector<bool>>& visited, const string& word, int row, int col, int pos)
    {
        if (pos == word.size()) return true;
        int m = board.size(), n = board[0].size();
        if (row < 0 || row >= m || col < 0 || col >= n || visited[row][col] || board[row][col] != word[pos]) return false;
        // search in all 4 directions
        visited[row][col] = true;
        bool res = 
            Search(board, visited, word, row + 1, col, pos + 1) ||
            Search(board, visited, word, row - 1, col, pos + 1) ||
            Search(board, visited, word, row, col + 1, pos + 1) ||
            Search(board, visited, word, row, col - 1, pos + 1);
        visited[row][col] = false;
        return res;
    }
};
