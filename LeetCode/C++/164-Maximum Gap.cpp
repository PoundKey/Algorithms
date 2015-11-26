// Thoughts: O(n) runtime
// TODO: Radix Sort/ Bucket Sort

// Thoughts: O(nlogn) runtime
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        sort(nums.begin(), nums.end());
        int maxDiff = 0;
        for (int i = 1; i < nums.size(); i++) {
            maxDiff = max(maxDiff, nums[i] - nums[i-1]);
        }
        return maxDiff;
    }
};
