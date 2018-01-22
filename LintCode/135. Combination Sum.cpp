class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        if (candidates.empty()) return res;
        sort(candidates.begin(), candidates.end());
        vector<int> sol;
        DFS(res, sol, candidates, target, 0, 0);
        return res;
    }
    
    void DFS(vector<vector<int>> &res, vector<int>& sol, vector<int>& candidates, int target, int sum, int pos) {
        // base case
        if (sum == target) {
            res.push_back(sol);
            return;
        }
        if (sum > target) return;
        // Each possible candidates always starts with [0, n-1)
        for (int i = pos; i < candidates.size(); i++) {
            // deal with duplicate
            if (i > 0 && candidates[i] == candidates[i-1]) continue;
            int val = candidates[i];
            sol.push_back(val);
            DFS(res, sol, candidates, target, sum + val, i);
            sol.pop_back();
        }
    }
};
