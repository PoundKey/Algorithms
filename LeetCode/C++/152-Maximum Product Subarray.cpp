// Thoughts: + * + = +, - * - = +, + * - = -
// when i = 0, maxProduct = A[i]
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        
        int maxPro = nums[0], maxVal = nums[0], minVal = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            int temp = maxVal;
            maxVal = max(max(maxVal * nums[i], nums[i]), minVal * nums[i]);
            minVal = min(min(minVal * nums[i], nums[i]), temp * nums[i]);
            maxPro = max(maxPro, maxVal);
        }
        
        return maxPro;
    }
};
