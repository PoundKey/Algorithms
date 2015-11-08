// Thoughts: Typical backtracking problem, we need to think a bit more about the constraint.
// 1. we are allowed to push back '(' as long as it's less than n
// 2. to be well-formed, we push ')' only if '(' is more than ')'
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n == 0) return res;
        string sol;
        DFS(res, sol, n, 0, 0);
        return res;
    }
    void DFS(vector<string>& res, string& sol, int n, int left, int right) {
        if (left == n && right == n) {
            res.push_back(sol);
            return;
        }
        
        if (left < n) {
            sol.push_back('(');
            DFS(res, sol, n, left + 1, right);
            sol.pop_back();
        }
        
        if (right < left) {
            sol.push_back(')');
            DFS(res, sol, n, left, right + 1);
            sol.pop_back();
        }
    }
};
