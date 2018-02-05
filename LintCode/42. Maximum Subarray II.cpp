// 1. foreach index i, maxSum = leftMax(i) + rightMax(i + 1)
// 2. leftMax = max(globalLeftMax, localLeftMax), localLeftMax is consecutive
// 3. rightMax = max(globalRightMax, localRightMax), localRightMax is consecutive

class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> &nums) {
        if (nums.size() < 2) return 0;
        int n = nums.size();
        vector<int> localMax(n, 0);
        vector<int> leftMax(n, 0);
        localMax[0] = nums[0];
        leftMax[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            localMax[i] = localMax[i-1] <= 0 ? nums[i] : localMax[i-1] + nums[i];
            leftMax[i] = max(localMax[i], leftMax[i-1]);
        }
        
        localMax.clear();
        vector<int> rightMax(n, 0);
        localMax[n-1] = nums[n-1];
        rightMax[n-1] = nums[n-1];
        for (int i = n - 2; i >= 0; i--)
        {
            localMax[i] = localMax[i+1] <= 0 ? nums[i] : localMax[i+1] + nums[i];
            rightMax[i] = max(localMax[i], rightMax[i+1]);
        }
        int maxSum = nums[0] + rightMax[1];
        for (int i = 0; i < n - 1; i++)
        {
            maxSum = max(maxSum, leftMax[i] + rightMax[i+1]);
        }
        
        return maxSum;
    }
};
