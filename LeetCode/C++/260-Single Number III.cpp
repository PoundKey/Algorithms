// Thoughts: TODO/ Analysis
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for (int i = 0; i < nums.size(); i++) {
            x ^= nums[i];
        }
        int lowbit = x & -x;
        int a = 0, b = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & lowbit) {
                a ^= nums[i];
            } else {
                b ^= nums[i];
            }
        }
        return vector<int> { a, b };
    }
};
