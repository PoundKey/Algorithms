class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 1));
        
        if (obstacleGrid[0][0]) return 0;
        
        for (int row = 1; row < m; row++) {
            if (obstacleGrid[row][0] == 1 || dp[row-1][0] == 0) {
                dp[row][0] = 0;
            } 
        }
        for (int col = 1; col < n; col++) {
            if (obstacleGrid[0][col] == 1 || dp[0][col-1] == 0) {
                dp[0][col] = 0;
            } 
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } 
                else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};
