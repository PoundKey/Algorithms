// Thoughts: Without the further ado, typical backtracking
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() == 0) return res;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        DFS(res, nums, curr, 0);
        return res;
    }
    
    void DFS(vector<vector<int>>&res, vector<int>& nums, vector<int>& curr, int level) {
        if (curr.size() > nums.size()) return;
        res.push_back(curr);
        
        for (int i = level; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            DFS(res, nums, curr, i+1);
            curr.pop_back();
        }
    }
};