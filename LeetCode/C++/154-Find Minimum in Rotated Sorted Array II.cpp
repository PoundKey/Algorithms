// Thoughts: Similar to previous Q153, the following situation can happen:
// 3 1 3 3 3 
// 3 3 3 1 3
// In which we won't be able to tell if should go left or right when nums[mid] == nums[end]
// Key: if nums[mid] == nums[end], disregard nums[end] and redo findMin on A[start:end]
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
       } else if (nums[mid] == nums[end]) {
           findHelper(nums, start, end-1);
        } else {
           findHelper(nums, mid+1, end);
       }
    }
};

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


// Again, Brute force O(n) works with and without dulpicate
class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = 0;
        for (int i=0; i < nums.size()-1; i++) {
            if (nums[i] > nums[i+1]) {
                min = i + 1;
                break;
            } 
        }
        return nums[min];
    }
};

