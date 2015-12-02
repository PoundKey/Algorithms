// Thoughts: dp[i] = combo(dp[node_left] + dp[node_right])
class Solution {
public:
    int numTrees(int n) {
        if (!n) return 0;
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i-j-1];
            }
        }
        return dp[n];
    }
};