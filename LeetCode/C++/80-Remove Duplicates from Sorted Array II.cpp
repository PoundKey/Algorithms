// 每次定位 j，同时意味着定位 j 的值以及［0..j］的输出有效性。
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int j = 0, count = 0;
        for (int i=1; i < nums.size(); i++) {
            if (nums[i] == nums[j]) {
            		count++;
                if (count < 2) {
                    nums[++j] = nums[i];
                }
            } else {
                nums[++j] = nums[i];
                count = 0;
            }
        }
        return j + 1;
    }
};

