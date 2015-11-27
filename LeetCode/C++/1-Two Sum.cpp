// Thoughts: Key: use a hashmap to store {nums[index] : index} pair, takes O(1) to look up if diff exists or not.
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map; // Key: A[i] => Value: i
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (map.count(diff)) {
                return vector<int> { map[diff] + 1, i + 1 };
            } else {
                map[nums[i]] = i;
            }
        }
    }
};