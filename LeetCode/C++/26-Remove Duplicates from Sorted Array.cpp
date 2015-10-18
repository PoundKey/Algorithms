// Similar to Q27, Key: if duplicate, j+1 < i

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int j = 0;
        for (int i=1; i < nums.size(); i++) {
            if (nums[i] == nums[j]) {
                continue;
            }
            nums[++j] = nums[i];
        }
        return j + 1;
    }
};

// Just the other way around
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int j = 0;
        for (int i=1; i < nums.size(); i++) {
            if (nums[i] != nums[j]) {
                nums[++j] = nums[i];
            }
        }
        return j + 1;
    }
};

