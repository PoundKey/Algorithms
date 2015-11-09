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

// Thoughts: Sort the array, remove dulplicates, and trace it. Runtime O(nlogn)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        removeDup(nums);
        int res = 1, count = 1;
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] + 1 == nums[i+1]) {
                count++;
                res = max(res, count);
            } else {
                count = 1;
            }
        }
        return res;
    }
    
    void removeDup(vector<int>& nums) {
        if (nums.size() <= 1) return;
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[i] == nums[j]) continue;
            nums[++i] = nums[j];
        }
        int n = nums.size() - i - 1;
        while (n) {
            nums.pop_back();
            n--;
        }
    }
};
