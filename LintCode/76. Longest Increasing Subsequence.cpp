// 1. DP[i] => The longest increasing subsequence, whereas A[i] is the last item in the LIS
// 2. to calculate DP[i], compare A[i] with A[j], j <- A[0, i - 1], if A[i] > A[j],
//    this means when could GET all a LIS of DP[j] + 1 , hence DP[i] = max(DP[i], DP[j] + 1)

class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> &nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<int> dp(n, 1);
        int res = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], 1 + dp[j]);
                    res = max(res, dp[i]);
                }
            }
        }
        
        return res;
    }
};
