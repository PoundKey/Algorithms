class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        if (nums.empty()) return;
        int i = 0, j = i, n = nums.size();
        while (j < n) {
            if (nums[j] % 2 != 0) {
                swap(nums[i++], nums[j++]);
            } 
            else {
                j++;
            }
        }
    }
    
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
};
