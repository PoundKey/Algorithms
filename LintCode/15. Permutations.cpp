class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> nums) {
        vector<vector<int>> res;
        if (nums.empty()) return vector<vector<int>>{{}};
        vector<int> sol;
        vector<bool> visited(nums.size(), false);
        DFS(nums, res, sol, visited);
        return res;
    }
    
    void DFS(vector<int>& nums, vector<vector<int>>& res, vector<int>& sol, vector<bool>& visited) {
        if (sol.size() == nums.size()) {
            res.push_back(sol);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue;
            sol.push_back(nums[i]);
            visited[i] = true;
            DFS(nums, res, sol, visited);
            visited[i] = false;
            sol.pop_back();
        }
    }
};
