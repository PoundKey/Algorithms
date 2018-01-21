class Solution {
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) {
        if (nums.empty()) return 0;
        return findMinHelper(nums, 0, nums.size() - 1);
    }
    int findMinHelper(vector<int> &nums, int start, int end) {
        if (start == end) return nums[start];
        if (start + 1 == end) return min(nums[start], nums[end]);
        int mid = start + (end - start) / 2;
        if (nums[mid] < nums[start]) 
        {
            return findMinHelper(nums, start, mid);
        } 
        else if (nums[mid] > nums[end]) {
            return findMinHelper(nums, mid, end);
        } 
        else 
        {
            return nums[start]; // sorted, return the first item
        }
    }
};
