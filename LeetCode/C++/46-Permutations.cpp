// Thoughts: use a vector<bool> vector to keep track of elements that
// have been visited in the previous level.
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() == 0) return res;
        vector<int> curr;
        vector<bool> visit(nums.size(), false);
        DFS(res, nums, curr, visit);
        return res;
    }
    
    void DFS(vector<vector<int>>& res, vector<int>& nums, vector<int>& curr, vector<bool>& visit) {
        if (curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (visit[i]) continue;
            curr.push_back(nums[i]);
            visit[i] = true;
            DFS(res, nums, curr, visit);
            visit[i] = false;
            curr.pop_back();
        }
    }
};
