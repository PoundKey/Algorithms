class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        int totalMax = nums[0], n = nums.size();
        int prev = nums[0] < 0 ? 0 : nums[0];
        for (int i = 1; i < n; i++) {
            int curr = prev + nums[i];
            prev = curr < 0 ? 0 : curr;
            totalMax = max(curr, totalMax);
        }
        return totalMax;
    }

    int maxSubArrayAlt(vector<int> nums) {
        int totalMax = nums[0], n = nums.size();
        int prev = nums[0];
        for (int i = 1; i < n; i++) {
            int curr = prev <= 0 ? nums[i] : prev + nums[i];
            totalMax = max(curr, totalMax);
            prev = curr;
        }
        return totalMax;
    }

};
