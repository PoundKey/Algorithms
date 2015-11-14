// Thoughts: Backtracking without dynamic programming, timeout.
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> res;
        if (s.empty()) return res;
        vector<string> sol;
        DFS(res, sol, wordDict, s, 0);
        return res;
    }
    
    void DFS(vector<string>& res, vector<string>& sol, unordered_set<string>& wordDict, string& s, int start) {
        if (start == s.size() && !sol.empty()) {
            string builder = sol[0];
            for (int i = 1; i < sol.size(); i++) {
                builder += " " + sol[i];
            }
            res.push_back(builder);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            string sub = s.substr(start, i - start + 1);
            if (wordDict.count(sub)) {
                sol.push_back(sub);
                DFS(res, sol, wordDict, s, i + 1);
                sol.pop_back();
            }
        }
        
    }
};