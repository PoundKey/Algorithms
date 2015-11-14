// Thoughts: Use a set to access i and i += 1, takes O(1) for each, O(n) in total.
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_set<int> set;
        for (int i = 0; i < nums.size(); i++) {
            set.insert(nums[i]);
        }
        int res = 1;
        while (!set.empty()) {
            int count = 0, val = *set.begin(), val2 = val - 1;
            while (set.count(val)) {
                set.erase(val);
                count++;
                val++;
            }
            
            while (set.count(val2)) {
                set.erase(val2);
                count++;
                val2--;
            }
            res = max(res, count);
        }
        return res;
    }
};

// Thoughts: Sort the array, slide through dulpicate Runtime O(nlogn)
// solves the [0, 1, 1, 2], situation
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        int res = 1;
        int count = 1;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] + 1 == nums[i+1]) {
                count++;
                res = max(res, count);
            } else if (nums[i] == nums[i+1]) {
                continue;
            } else {
                count = 1;
            }
        }
        return res;
    }
};