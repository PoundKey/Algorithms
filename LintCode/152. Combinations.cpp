class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> res;
        if (n == 0 || k == 0) return res;
        vector<int> sol;
        DFS(res, sol, 1, n, k);
        return res;
    }
    
    void DFS(vector<vector<int>>& res, vector<int>& sol, int pos, int n, int k) {
        if (sol.size() == k) {
            res.push_back(sol);
            return;
        }
        for (int i = pos; i <= n; i++) {
            sol.push_back(i);
            DFS(res, sol, i + 1, n, k);
            sol.pop_back();
        }
    }
};
