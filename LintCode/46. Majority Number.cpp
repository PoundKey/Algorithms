class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        int count = 0, n = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                n = nums[i];
                count++;
            }
            else if (n != nums[i]) count--;
            else count++;
        }
        return n;
    }
};
