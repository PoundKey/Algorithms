// Thoughts: Similar to previous Q153, the following situation can happen:
// 3 1 3 3 3 
// 3 3 3 1 3
// In which we won't be able to tell if should go left or right when nums[mid] == nums[end]
// Key: if nums[mid] == nums[end], disregard nums[end] and redo findMin on A[start:end]
// Thoughts: Therefore, dulpicates will affect the complexity if and only if there are way too many dulpicates
// such that the complexity turns from O(lgn) to O(n)
// Iterative fashion
class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < nums[end]) 
                end = mid;
            else if (nums[mid] == nums[end])
                end = end - 1;
            else
                start = mid + 1;
        }
        return nums[start];
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            if (start == end) return nums[start];
            int mid = start + (end - start) / 2;
            if (nums[mid] > nums[end]) 
                start = mid + 1;
            else if (nums[mid] < nums[end])
                end = mid;
            else
                end = end - 1;
        }
    }
};
