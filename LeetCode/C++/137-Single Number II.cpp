// Thoughts: 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int count = 0;
            for (int j = 0; j < nums.size(); j++) {
                count += ((nums[j] >> i) & 1);
            }
            res |= (count % 3) << i;
        }
        return res;
    }
};

