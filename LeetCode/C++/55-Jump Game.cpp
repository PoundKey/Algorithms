// Thoughts: Typical Greedy Algorithm, we're greedy about the max length
// that can be reached from each element.
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int val = nums[0];
        
        for (int i=1; i < nums.size(); i++) {
            val -= 1;
            if (val < 0) return false;
            if (val < nums[i]) val = nums[i];
        }
        return true;
    }
};

// Thoughts: at index i, the maximum index that can be reached is i + A[i]
// exam if max index >= nums.size()-1
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int maxIndex = 0;
        for (int i=0; i < size; i++) {
            if (i > maxIndex || maxIndex >= size-1) break;
            maxIndex = max(maxIndex, i + nums[i]);
        }
        return (maxIndex >= size-1) ? true : false;
    }
};