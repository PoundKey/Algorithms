// Thoughts: There should be a general template for solving this type question.
// For now let's just derive the solution from 2sum and 3sum.
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 4) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int t1 = target - nums[i];
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                int t2 = t1 - nums[j];
                int start = j + 1, end = n - 1;
                while (start < end) {
                    int sum = nums[start] + nums[end];
                    if (t2 == sum) {
                        res.push_back(vector<int> {nums[i], nums[j], nums[start++], nums[end--]});
                        while (nums[start] == nums[start-1]) start++;
                        while (nums[end] == nums[end+1]) end--;
                    } else if (t2 > sum) {
                        start++;
                    } else {
                        end--;
                    }
                }
            }
        }
    }
};
