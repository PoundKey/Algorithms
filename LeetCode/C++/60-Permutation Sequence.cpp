// Thoughts: Normal DFS + Backtracking,  time limit exceeded.
class Solution {
public:
    string getPermutation(int n, int k) {
       string sol = "", res = "";
       if (n == 0 || k== 0) return sol;
       vector<bool> visited(n+1, false);
       DFS(res, sol, visited, n, k);
       return res;
    }
    
    void DFS(string& res, string& sol, vector<bool>& visited, int n, int& k) {
        if (sol.size() == n) {
            k--;
            res = sol;
            return;
        }
        
        if (k == 0) return;
        
        for (int i = 1; i <= n; i++) {
            if (visited[i]) continue;
            sol += to_string(i);
            visited[i] = true;
            DFS(res, sol, visited, n, k);
            visited[i] = false;
            sol.pop_back();
        }
    }
};

// Thoughts: Shall we do some math...?

