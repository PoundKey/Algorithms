// Thoughts: We are greedy about the maxIndex that can be reached within
// the curIndex's range, set the next curIndex to the maxIndex within the range.
class Solution {
public:
    int jump(vector<int>& nums) {
        int currIndex = 0, nextIndex = 0, step = 0;
        int i = 0 , n = nums.size();
        while (i < n) {
            if (currIndex >= n-1) break;
            
            while (i <= currIndex) {
                nextIndex = max(nextIndex, i + nums[i]);
                i++;
            }
            
            step++;
            currIndex = nextIndex;
        }
        return step;
    }
};
