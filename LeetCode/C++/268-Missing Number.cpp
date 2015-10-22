// Thoughts: Original length of the array: n = nums.size() + 1, sum = n*(n-1)/2
// Iterate through the nums, and sum = sum - nums[i]
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size() + 1;
        int diff = n*(n-1)/2;
        for (int i = 0; i < nums.size(); i++) {
            diff = diff - nums[i];
        }
        return diff;
    }
};

// Thoughts: Runtime O(1) Brute force solution
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size() + 1;
        int i = 0;
        while (i < n) {
            if (nums[i] != i) 
                return i;
            else
                i++;
        }
    }
};
