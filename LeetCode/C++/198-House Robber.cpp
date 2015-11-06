// Thoughts: for last element, if it's included, d[i] = d[i-2] + A[i]
// else, d[i] = d[i-1].  STE: d[i] = max(d[i-2] + nums[i], d[i-1]) 
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp[n-1];
    }
};


// Thoughts: Recursive fasion. Initialize the list with value INT_MIN
class Solution {
public:
    int rob(vector<int>& nums) {
        int s = nums.size();
        if (!s) return 0;
        vector<int> dp(s, INT_MIN);
        return DP(nums, s-1, dp);
    }
    
    int DP(vector<int>& nums, int n, vector<int>& dp) {
        if (n == 0) return nums[0];
        if (n == 1) return max(nums[0], nums[1]);
        if (dp[n] != INT_MIN) return dp[n];
        dp[n] = max(DP(nums, n-1, dp), DP(nums, n-2, dp) + nums[n]);
        return dp[n];
    }
};