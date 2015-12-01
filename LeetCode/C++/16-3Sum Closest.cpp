// Thoughts: Sort the vector first, loop through i..size-2, for each i, compute sum = A[i] + A[start] + A[end]
// Having a minDiff value to keep tracking of sum - target. If diff = 0, return. else, if diff < 0, we try and see
// if we can make the diff a bit closer to 0 by increasing start. else if diff > 0, decrease end.
// Notice: Only convert to absolute value when comparing to preserve sign of minDiff, return sum = target + minDiff
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size(), minDiff = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            int start = i + 1, end = n - 1;
            while (start < end) {
                int sum = nums[i] + nums[start] + nums[end];
                int diff = sum - target;
                if (abs(diff) < abs(minDiff)) minDiff = diff;
                if (diff == 0) return target;
                else if (diff < 0) start++;
                else end--;
            }
        }
        return target + minDiff;
    }
};