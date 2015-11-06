// Thoughts: dp[i][j] = min(dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]) + 1
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int row = matrix.size(), col = matrix[0].size();
        int memo[row][col] = {0}; // Initialize default value to 0
        int res = 0;
        
        for (int i = 0; i < col; i++) {
            memo[0][i] = matrix[0][i] - '0';
            res = max(res, memo[0][i]);
        }
        for (int i = 0; i < row; i++) {
            memo[i][0] = matrix[i][0] - '0';
            res = max(res, memo[i][0]);
        }
        
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[i][j] - '0') {
                    memo[i][j] = min(memo[i-1][j-1], min(memo[i][j-1], memo[i-1][j])) + 1;
                    res = max(res, memo[i][j]);
                }
            }
        }
        return res*res;
    }
};
