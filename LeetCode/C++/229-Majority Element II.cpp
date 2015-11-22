// Thoughts: O(n) space complexity
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> elem;
        for (int i = 0; i < nums.size(); i++) elem[nums[i]]++;
        vector<int> res;
        for (auto e : elem) {
            if (e.second > nums.size() / 3) res.push_back(e.first);
        }
        return res;
    }
};

// Boyer Moore Algorithm, Space O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1, cand2, count1 = 0, count2 = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == cand1) {
                count1++;
            } else if (nums[i] == cand2) {
                count2++;
            } else if (count1 == 0) {
                cand1 = nums[i];
                count1 = 1;
            } else if (count2 == 0) {
                cand2 = nums[i];
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        count1 = 0, count2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == cand1) count1++;
            else if (nums[i] == cand2) count2++;
        }
        vector<int> res;
        if (count1 > n/3) res.push_back(cand1);
        if (count2 > n/3) res.push_back(cand2);
        return res;
    }
};
