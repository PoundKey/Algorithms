// Thoughts: O(logn) runtime. Binary Search (Recursion)
// 1. if A[mid] < A[end], A[mid:end+1] sorted, search for A[start:mid+1] (Including A[mid])
// 2. if A[mid] > A[end], A[start:mid+1] sorted, search for A[mid+1:end+1] (Excluding A[mid])
// 3. when (start == end), single val computed, return A[start]
class Solution {
public:
    int findMin(vector<int>& nums) {
        return findHelper(nums, 0, nums.size()-1);
    }
    
    int findHelper(vector<int>& nums, int start, int end) {
       if (start == end) return nums[start];
       int mid = start + (end-start)/2;
       if (nums[mid] < nums[end]) {
           findHelper(nums, start, mid);
       } else {
           findHelper(nums, mid+1, end);
       }
    }
};

// Thoughts: O(lgn) runtime. Binary Search (Iteration)
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

// Thoughts: O(n) runtime, loop through the vector and find the index with A[i] < A[i+1], return A[i+1]
class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = 0;
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] > nums[i+1]) {
                min = i+1;
                break;
            } 
        }
        return nums[min];
    }
};

