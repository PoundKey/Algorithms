class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.empty()) return 0;
        int m = triangle.size();
        vector<int> dp(m, 0);
        
        for (int i = 0; i < m; i++) {
            dp[i] = triangle[m-1][i];
        }
        
        for (int i = m - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        }
        return dp[0];
        
    }
    
    int minimumTotal2D(vector<vector<int> > &triangle) {
        if (triangle.empty()) return 0;
        int m = triangle.size(), n = m;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for (int i = 0; i < n; i++) {
            dp[m-1][i] = triangle[m-1][i];
        }
        
        for (int i = m - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        return dp[0][0];
        
    }
};
