// Thoughts: construct the isPalindrome matrix from Q5
// backtracking, starting from s[0,0], s[0,1], s[0,2]...
// terminates when 'start' index is out of range (start == s.size());
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector< vector<string> > res;
        int n = s.size();
        if (n == 0) return res;
        vector< vector<bool> > dp(n, vector<bool>(n, true));
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = s[i] == s[j] && dp[i+1][j-1];
            }
        }
        
        vector<string> sol;
        DFS(res, sol, dp, s, 0);
        return res;
    }
    
    void DFS(vector< vector<string> >& res, vector<string>& sol, vector< vector<bool> >& dp, string& s, int start) {
        if (start == s.size()) {
            res.push_back(sol);
            return;
        }
        
        for (int i = start; i < s.size(); i++) {
            if (dp[start][i]) {
                sol.push_back(s.substr(start, i - start + 1));
                DFS(res, sol, dp, s, i + 1);
                sol.pop_back();
            }
        }
    }
};