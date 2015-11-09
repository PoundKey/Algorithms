// Thoughts: use a map to save each index for each A[i]
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (map.count(nums[i])) {
                int diff = i - map[nums[i]];
                if (diff <= k) return true;
            } 
            map[nums[i]] = i;
        }
        return false;
    }
};