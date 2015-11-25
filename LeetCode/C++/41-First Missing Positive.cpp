// Thoughts: O(n) time comlexity but with O(n) space comlexity
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.empty()) return 1;
        unordered_set<int> set;
        int n = nums.size(), maxVal = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                set.insert(nums[i]);
                maxVal = max(maxVal, nums[i]);
            }
        }
        for (int i = 1; i < maxVal; i++) {
            if (set.count(i) == 0) return i;
        }
        return maxVal + 1;
    }
};

// Thoughts: O(n) time comlexity, O(1) space comlexity
// Key: for 0 < nums[i] <= nums.size(), it should be placed at nums[nums[i]-1]
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.empty()) return 1;
        int i = 0, n = nums.size();
        while (i < n) {
            if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i]-1]);
            } else {
                i++;
            }
        }
        int res = 0;
        for (i = 0; i < n; i++) {
            if (nums[i] - 1 != res) return res + 1;
            res = nums[i];
        }
        return res + 1;
    }
    
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
};

// Thoughts: O(nlogn) method, sorting.
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.empty()) return 1;
        sort(nums.begin(), nums.end());
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                if (i > 0 && nums[i] == nums[i-1]) continue; // look out for dulplicate
                if (nums[i] - 1 != res) return res + 1;
                res = nums[i];
            }
        }
        return res + 1;
    }
};