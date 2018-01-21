class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        int n = nums.size();
        if (n <= 1) return n;
        int i = 0, j = 1;
        while (j < n) {
            if (nums[i] == nums[j]) {
                j++;
            } 
            else {
                nums[++i] = nums[j++];
            }
        }
        return i + 1;
    }
};
