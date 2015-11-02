// Thoughts: 
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if (n <= 0 || k <= 0) return res;
        vector<int> curr;
        DFS(res, curr, n, k, 1);
        return res;
    }
    
    void DFS(vector<vector<int>>& res, vector<int>& curr, int n, int k, int start) {
        
        if (curr.size() == k) {
            res.push_back(curr);
            return;
        }
        
        for (int i = start; i <=n; i++) {
            curr.push_back(i);
            DFS(res, curr, n, k, i+1);
            curr.pop_back();
        }
    }
};