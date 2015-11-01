// Thoughts: Backtracking problem, remove dulplicate by sliding through.

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if (candidates.size() == 0 || target <= 0) return res;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        DFS(res, candidates, curr, target, 0);
        return res;
    }
    
    void DFS(vector<vector<int>>&res, vector<int>& cand, vector<int>& curr, int target, int start) {
         if (target == 0) {
             res.push_back(curr);
             return;
         }
         if (target < 0) return;
         
         for (int i = start; i < cand.size(); i++) {
             if (i > start && cand[i] == cand[i-1]) continue;
             target -= cand[i];
             curr.push_back(cand[i]);
             DFS(res, cand, curr, target, i);
             curr.pop_back();
             target += cand[i];
         }
    }
};