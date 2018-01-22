class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>& nums) {
        int maxVal = nums[0], prevMax = maxVal, prevMin = maxVal;
        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            if (num >= 0) {
                prevMax = max(num, num * prevMax);
                prevMin = min(num, num * prevMin);
            } else {
                int tempMax = prevMax;
                prevMax = max(num, num * prevMin);
                prevMin = min(num, num * tempMax);                
            }
            maxVal = max(maxVal, prevMax);
        }
        return maxVal;
    }
    
    int maxProductDP1(vector<int>& nums) {
        int n = nums.size();
        vector<int> curMax(n);
        vector<int> curMin(n);
        curMax[0] = nums[0];
        curMin[0] = nums[0];
        int maxVal = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                curMax[i] = max(nums[i], nums[i] * curMax[i-1]);
                curMin[i] = min(nums[i], nums[i] * curMin[i-1]);
            } else {
                curMax[i] = max(nums[i], nums[i] * curMin[i-1]);
                curMin[i] = min(nums[i], nums[i] * curMax[i-1]);                
            }
            maxVal = max(maxVal, curMax[i]);
        }
        return maxVal;
    }
    
    int maxProductN2(vector<int>& nums) {
        // method: bruteforce
        if (nums.empty()) return 0;
        int res = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            int maxVal = 1;
            for (int j = i; j < nums.size(); j++) {
                maxVal *= nums[j];
                res = max(maxVal, res);
            }
        }
        return res;
    }

};
