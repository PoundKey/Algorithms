// Thoughts: Two passes solution. Count each appearance of r,w,b and overrite the array accordingly.
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r = 0, w = 0, b = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) r++;
            else if (nums[i] == 1) w++;
            else b++;
            nums[i] = 0;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (r) {
                nums[i] = 0;
                r--;
            } else if (w) {
                nums[i] = 1;
                w--;
            } else if (b) {
                nums[i] = 2;
                b--;
            }
        }
    }
};

// Thoughts: One pass solution: two pointers, one ACK for red pointer from index 0;
// and the other ACL for blue pointer from index n - 1. 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int redPtr = 0, bluePtr = n - 1;
        int i = 0;
        while (i <= bluePtr) {
            if (nums[i] == 0) swap(nums[i++], nums[redPtr++]);
            else if (nums[i] == 2) swap(nums[i], nums[bluePtr--]);
            else i++;
        }
    }
    
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
};