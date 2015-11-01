// Thoughts: Backtracking
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if (k <= 0 || n <= 0) return res;
        vector<int> curr;
        DFS(res, curr, k, n, 1);
        return res;
    }
    
    void DFS(vector<vector<int>>& res, vector<int>& curr, int k, int n, int level) {
        if (curr.size() == k && n == 0) {
            res.push_back(curr);
            return;
        }
        
        if (curr.size() > k || n < 0) {
            return;
        }
        
        for (int i = level; i <= 9; i++) {
            curr.push_back(i);
            DFS(res, curr, k, n-i, i+1);
            curr.pop_back();
        }
    }
};