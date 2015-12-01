// Thoughts: O(logn) runtime
// 1. if A[mid] < A[end], A[mid:end+1] sorted, search for A[start:mid+1] (Including A[mid])
// 2. if A[mid] > A[end], A[start:mid+1] sorted, search for A[mid+1:end+1] (Excluding A[mid])
// 3. when (start == end), single val computed, return A[start]
class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < nums[end]) 
                end = mid;
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
            else
                end = mid;
        }
    }
};



