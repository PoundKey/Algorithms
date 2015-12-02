// Thoughts: 
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.empty()) return;
        int i = 0, n = nums.size();
        for (int j = 0; j < n; j++) {
            if (nums[j] == 0) continue;
            swap(nums[i++], nums[j]);
        }
    }
    
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
};