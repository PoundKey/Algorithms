// Similar to Q27, Key: if duplicate, j+1 < i

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int start = 0, end  = 1;
        while ( end < nums.size()) {
            if (nums[start] == nums[end]) {
                end++;
            } else {
                nums[++start] = nums[end++];
            }
        }
        return start + 1;
        
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

