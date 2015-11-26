// Thoughts: Initial Style
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.empty()) return res;
        int start = 0, end = 1, n = nums.size();
        while (end <= n) {
            if (nums[end] - 1 != nums[end-1] || end == n) {
                string s;
                if (start != end - 1) s = to_string(nums[start]) + "->" + to_string(nums[end-1]);
                else s = to_string(nums[start]);
                res.push_back(s);
                start = end;
            }
            end++;
        }
        return res;
    }
};

// Thoughts: Well, I can shrink it...
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int i= 0, n = nums.size();
        for (int j = 1; j <= n; j++) {
            if (nums[j] - 1 != nums[j-1] || j == n) {
                res.push_back(i == j - 1 ? to_string(nums[i]) : to_string(nums[i]) + "->" + to_string(nums[j-1]));
                i = j;
            }
        }
        return res;
    }
};

// Toughts: Alternative solution, play with indices. Found online.
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int i = 0, n = nums.size();
        while (i < n) {
            int j = 1;
            while (i + j < n && nums[i + j] - nums[i] == j) j++;
            res.push_back(j <= 1 ? to_string(nums[i]) : to_string(nums[i]) + "->" + to_string(nums[i + j - 1]));
            i += j;
        }
        return res;
    }
};



