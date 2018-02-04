class Solution {
public:
	/**
	 * @param num: Given the candidate numbers
	 * @param target: Given the target number
	 * @return: All the combinations that sum to target
	 */
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int>> res;
        if (num.empty()) return res;
        sort(num.begin(), num.end());
        vector<int> sol;
        DFS(res, sol, num, target, 0, 0);
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
            if (i > pos && candidates[i] == candidates[i-1]) continue;
            int val = candidates[i];
            sol.push_back(val);
            DFS(res, sol, candidates, target, sum + val, i + 1);
            sol.pop_back();
        }
    }
};
