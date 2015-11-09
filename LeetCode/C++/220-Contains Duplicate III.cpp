// Thoughts: Brute force, Runtime: O(nk)
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        for (int i = 0; i < nums.size(); i++) {
            int range = (i + k >= nums.size()) ? nums.size() - 1 : i + k;
            for (int j = i + 1; j <= range; j++) {
                if (abs(nums[i] - nums[j]) <= t) return true;
            }
        }
        return false;
    }
};

