// Thoughts: Sort the vector first O(nlogn), and reduce it to a 2sum problem
// Remove dulpicate: consider: [2, 2, 3, 4], target = 9. Here we have dulpicates.
// Key is to skip i if A[i-1] == A[i], same for return val from 2sum
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int target = 0 - nums[i];
            int start = i + 1, end = nums.size() - 1;
            while (start < end) {
                int sum = nums[start] + nums[end];
                if (target == sum) {
                    res.push_back(vector<int> {nums[i], nums[start++], nums[end--]});
                    while (nums[start] == nums[start-1]) start++;
                    while (nums[end] == nums[end+1]) end--;
                } else if (target > sum) {
                    start++;
                } else {
                    end--;
                }
            }
        }
    }
};