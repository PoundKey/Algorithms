// 1. Traverse the entire vector, if A[i] < A[i-1], then index i is the beginning of the rotated array
// 2. Use a temp vector to store the result, then transfer the result to the origional vector
// 3. Can we do better without the extra temp vector?

class Solution {
public:
    void recoverRotatedSortedArray(vector<int> &nums) {
        if (nums.empty()) return;
        int n = 0;
        vector<int> res;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] > nums[i]) {
                n = i;
                break;
            }
        }
        for (int i = n; i < nums.size(); i++) {
            res.push_back(nums[i]);
        }
        for (int i = 0; i < n; i++) {
            res.push_back(nums[i]);
        }
        nums = res;
    }
};
