// 1. for each A[i], record the minimum value of subarray [0, i-1]
// 2. if minValue of subarray [0, i-1] > 0, minValue of [0, i] = A[i]
// 3. else, minValue of [0, i] = minValue of [0, i-1] + A[i]

class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        if (nums.empty()) return 0;
        int prevMin = nums[0], minNumber = prevMin; 
        for (int i = 1; i < nums.size(); i++) {
            if (prevMin > 0) {
                prevMin = nums[i];
            } else {
                prevMin += nums[i];
            }
            minNumber = min(minNumber, prevMin);
        }
        return minNumber;
    }
    
    int minSubArrayOpt(vector<int> nums) {
        if (nums.empty()) return 0;
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int minNumber = nums[0]; 
        for (int i = 1; i < nums.size(); i++) {
            if (dp[i-1] > 0) {
                dp[i] = nums[i];
            } else {
                dp[i] = dp[i-1] + nums[i];
            }
            minNumber = min(minNumber, dp[i]);
        }
        return minNumber;
    }
};
