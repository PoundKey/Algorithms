class Solution {
public:    
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        sort(nums.begin(), nums.end());
        int res = INT_MAX, minVal = INT_MAX;
        for (int i = 0; i < nums.size() - 2; i++) {
            int start = i + 1, end = nums.size() - 1;
            while (start < end) {
                int sum = nums[i] + nums[start] + nums[end];
                if (sum > target) {
                    end--;
                } 
                else if (sum < target) {
                    start++;
                } 
                else {
                    return sum;
                }
                if (abs(sum - target) < minVal) {
                    minVal = abs(sum - target);
                    res = sum;
                }
            }
        }
        return res;
    }
};
