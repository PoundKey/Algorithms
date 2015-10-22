// Thoughts: Runtime: O(logn) Binary Search on A to find the lowest index with A[low] = target
// and do a second time BST on A to find the highest index with A[high] = target
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> vec(2, -1);
        vec[0] = binarySearchLow(nums, target);
        vec[1] = binarySearchHigh(nums, target);
        return vec;
    }
    
    int binarySearchLow(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (nums[mid] >= target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        if (low < nums.size() && nums[low] == target) {
            return low; 
        } else {
            return -1;
        }
    }
    
    int binarySearchHigh(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if (high >= 0 && nums[high] == target) {
            return high;
        } else {
            return -1;
        }
    }
};

// Thoughts: Runtime O(n) solution, easy and simple
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> vec(2, -1);
        if (nums.size() == 0) return vec;
        int start = -1, end = -1;
        int i = 0;
        while (i < nums.size() && nums[i] <= target) {
            if (nums[i] == target) {
               if (start == -1) {
                  start = i; 
               } 
               end = i;
            }
            i++;
        }
        
        vec[0] = start;
        vec[1] = end;
        return vec;
    }
};

//