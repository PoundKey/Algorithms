// Thoughts: for each index i, we will need to check all indice j;
// that 0 < j < i, satisfying the condition A[j] < A[i] and dp[i] < dp[j] + 1
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (!nums.size()) return 0;
        vector<int> dp(nums.size(), 1);
        int maxLen = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && dp[i] < dp[j]+1) {
                    dp[i] = dp[j] + 1;
                    maxLen = max(maxLen, dp[i]);
                }
            }
        }
        return maxLen;
    }
};
