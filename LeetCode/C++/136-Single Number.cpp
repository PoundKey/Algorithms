// Thoughts: Uset set or map. straight forward
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> s;
        set<int>::iterator it;
        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end()) {
                s.erase(nums[i]);
            } else {
                s.insert(nums[i]);
            }
        }
        return *s.begin();
    }
};

// Thoughts: Bit level manipulation: a^a = 0, a^0 = a, a^b^b = a
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = nums[0];
        for (int i = 1; i < nums.size(); i++)
            x ^= nums[i];
        return x;
    }
};