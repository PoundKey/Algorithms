// Thoughts: With obstacle meaning less path avaiable. dp[i][j] = 0 if obstacle[i][j] = 1
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int dp[m][n];
        
        dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
        if (dp[0][0] == 0) return 0;
        
        for (int i = 1; i < m; i++) {
            bool cond = obstacleGrid[i][0] == 0 && dp[i-1][0] == 1;
            dp[i][0] = cond ? 1 : 0;
        }
        
        for (int i = 1; i < n; i++) {
            bool cond = obstacleGrid[0][i] == 0 && dp[0][i-1] == 1;
            dp[0][i] = cond ? 1 : 0;
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};
