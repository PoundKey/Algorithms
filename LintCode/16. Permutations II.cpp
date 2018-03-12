class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
    vector<vector<int> > permuteUnique(vector<int> &nums) {
       if (nums.empty()) return vector<vector<int>>{{}};
       vector<vector<int>> res;
       vector<int> sol;
       vector<bool> visited(nums.size(), false);
       sort(nums.begin(), nums.end());
       DFS(nums, res, sol, visited);
       return res;
    }
    
    void DFS(vector<int> &nums, vector<vector<int>>& res, vector<int>& sol, vector<bool>& visited) {
        if (sol.size() == nums.size()) 
        {
            res.push_back(sol);
            return;
        }
        for (int i = 0; i < nums.size(); i++) 
        {
            if (visited[i] || (i > 0 && nums[i] == nums[i-1] && !visited[i-1])) continue;
            sol.push_back(nums[i]);
            visited[i] = true;
            DFS(nums, res, sol, visited);
            visited[i] = false;
            sol.pop_back();
        }
    }
};
