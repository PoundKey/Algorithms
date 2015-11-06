// Thoughts: There are two cases here: 
// (1) 1st element is included and last is not included 
// (2) 1st is not included and last is included. 
// Therefore, use DP to scan the array twice and get the larger value. 

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        if (n == 1) return nums[0];
        int optOne = DP(nums, 1, n-1);
        int optTwo = DP(nums, 0, n-2);
        return max(optOne, optTwo);
    }
    
    int DP(vector<int>& nums, int start, int end) {
        vector<int> memo(end + 1, 0);
        memo[start] = nums[start];
        memo[start + 1] = max(nums[start], nums[start+1]);
        for (int i = start + 2; i <= end; i++) {
            memo[i] = max(memo[i-2] + nums[i], memo[i-1]);
        }
        return memo[end];
    }
};