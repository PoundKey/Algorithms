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

// Thoughts: Compute the different and accumulate to result.
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            result += i - nums[i];
        }
        return result + nums.size();
    }
};

// Thought: Bit manipulation: (a^b)^b = a
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = 0;
        for (int i=1; i < nums.size()+1; i++) {
            result ^= i;
        }
        for (int j=0; j < nums.size(); j++) {
            result ^= nums[j];
        }
        return result;
    }
};