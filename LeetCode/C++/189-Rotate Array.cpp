// Thoughts: Space Complexity: O(n)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> vec = nums;
        int n = vec.size();
        for (int i = 0; i < n; i++) {
            int j = (i + k) % n;
            nums[j] = vec[i];
        }
    }
};

// Thoughts: Space Complexity: O(1)
// 1. Divide the array into two part: A[0, n-k), A[n-k, n)
// 2. Rotate the left part and the right part
// 3. Rotate the entire array
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int i = k % n;
        reverse(nums, 0, n-i-1);
        reverse(nums, n-i, n-1);
        reverse(nums, 0, n-1);
    }
    
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start++] = nums[end];
            nums[end--] = temp;
        }
    }
};