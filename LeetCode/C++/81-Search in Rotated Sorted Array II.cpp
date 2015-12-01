// Thoughts: Please refer to Q33. If there are way too many dulplicates, the runtime
// will depreciate to O(n), otherwise O(logn).
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (target == nums[mid]) return true;
            if (nums[mid] < nums[end]) {
                if (target < nums[mid] || target > nums[end]) 
                    end = mid - 1;
                else 
                    start = mid + 1;
            } else if (nums[mid] > nums[end]) {
                if (target > nums[mid] || target < nums[start]) 
                    start = mid + 1;
                else
                    end = mid - 1;
            } else {
                end = end - 1;
            }
        }
        return false;
    }
};