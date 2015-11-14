//Thoughts:  STE: dp[i] = max(dp[i], dp[j] + 1), for 0 <= j < i, and nums[i] > nums[j]
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (!nums.size()) return 0;
        vector<int> dp(nums.size(), 1);
        int maxLen = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    maxLen = max(maxLen, dp[i]);
                }
            }
        }
        return maxLen;
    }
};

