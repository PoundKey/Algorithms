class Solution {
public:    
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) return res;
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int target = -nums[i];
            int start = i + 1, end = n - 1;
            while (start < end) {
                int sum = nums[start] + nums[end];
                if (sum == target) {
                    res.push_back(vector<int>{nums[i], nums[start++], nums[end--]});
                    while (nums[start] == nums[start-1]) start++;
                    while (nums[end] == nums[end+1]) end--;
                } else if (sum > target) {
                    end--;
                } else {
                    start++;
                }
            }
        }
        return res;
    }
};
