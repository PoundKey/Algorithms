// Thoughts: 
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for (auto elem : nums) {
            if (!set.count(elem)) {
                set.insert(elem);
            } else {
                return true;
            }
        }
        return false;
    }
};
