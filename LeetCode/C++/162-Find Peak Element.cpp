// Thoughts: There exists a peak between [0, i-1] if A[i] < A[i-1], BST left
// Also, there exists a peak betwen [i+1, size()] if A[i] < A[i+1], BST right
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        int mid = 0;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if ((mid == 0 || nums[mid] > nums[mid-1]) &&
                (mid == nums.size()-1 || nums[mid] > nums[mid+1])) {
                return mid;
            } else if (mid > 0 && nums[mid] < nums[mid-1]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return mid;
    }
};
