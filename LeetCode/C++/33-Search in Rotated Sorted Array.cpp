// Thoughts: runtime O(log(n)), let mid = (start + end) / 2, if target == A[mid] return mid.
// 1. if A[mid] < A[end], A[mid:end] is sorted, and if target < A[mid] || target > A[end],
//    we discard entire A[mid:end], and search for A[start:mid-1];
//    otherwise, target is in between, we search for A[mid+1:end] by letting start = mid + 1;
// 2. if A[mid] > A[end, A[start:mid] is sorted, and if target > A[mid] || target < A[start],
//    we discard entire A[start:mid], and search for A[mid+1:end];
//    otherwise, target is in between, we search for A[start:mid-1] by letting end = mid - 1;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (target == nums[mid]) return mid;
            if (nums[mid] < nums[end]) {
                if (target < nums[mid] || target > nums[end]) 
                    end = mid - 1;
                else 
                    start = mid + 1;
            } else {
                if (target > nums[mid] || target < nums[start]) 
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return -1;
    }
};