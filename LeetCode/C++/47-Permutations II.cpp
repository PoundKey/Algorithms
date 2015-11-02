// Thoughts: Same as Q46, whereas this time we sort and slide to skip dulplicates.
// look out to check nums[i] == nums[i-1] && !visit[i-1]
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() == 0) return res;
        vector<int> curr;
        vector<bool> visit(nums.size(), false);
        sort(nums.begin(), nums.end());
        DFS(res, nums, curr, visit);
        return res;
    }
    
    void DFS(vector<vector<int>>& res, vector<int>& nums, vector<int>& curr, vector<bool>& visit) {
        if (curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (visit[i] || (i > 0 && nums[i] == nums[i-1] && !visit[i-1])) continue;
            curr.push_back(nums[i]);
            visit[i] = true;
            DFS(res, nums, curr, visit);
            visit[i] = false;
            curr.pop_back();
        }
    }
};
