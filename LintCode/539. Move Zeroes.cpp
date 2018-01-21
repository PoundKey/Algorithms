class Solution {
public:
    /**
     * @param nums an integer array
     * @return nothing, do this in-place
     */
    void moveZeroes(vector<int>& nums) {
        if (nums.empty()) return;
        int i = 0, n = nums.size(), j = i;
        while (j < n)
        {
            // [:i-1] != 0
            if (nums[j] != 0)
            {
                swap(nums[i++], nums[j]);
            }
            j++;
        }
     }
     
     void swap(int& a, int& b) {
         int temp = a;
         a = b;
         b = temp;
     }
};
