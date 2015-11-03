// Thoughts: fibonacci's sequence. f(n) = f(n-1) + f(n-2) tip to top approach
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 0) return 0;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }        
        return dp[n];
    }
};


// Thoguths: top to down approach
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 0) return 0;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 2;
        climb(n, dp);   
        return dp[n];
    }
    
    int climb(int n, vector<int>& dp) {
        if (dp[n]) return dp[n];
        dp[n] = climb(n-1, dp) + climb(n-2, dp);
        return dp[n];
    }
};