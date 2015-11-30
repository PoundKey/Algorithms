// Thoughts: There exists a peak between [0, i-1] if A[i] < A[i-1], BST left
// Also, there exists a peak betwen [i+1, size()] if A[i] < A[i+1], BST right
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            if (start == end) return end;
            int mid = start + (end - start) / 2;
            if (nums[mid] > nums[mid + 1])
                end = mid;
            else
                start = mid + 1;
        }
    }
};

// Thoughts: Pure BST Sol, same idea with a bit deviation on the format
// start pointer -> the explorer, end pointer -> the protecter
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        if (nums.size() == 2) return nums[1] > nums[0] ? 1 : 0;
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] > nums[mid-1])
                start = mid + 1;
            else if (nums[mid] < nums[mid-1])
                end = mid - 1;
        }
        return end;
    }
};
