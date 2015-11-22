// Thoughts: Backtracking on a string. Divide a string into 4 valid parts.
// Checkout the string.cpp example under codebase folder.
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        DFS(s, res, "", 4);
        return res;
    }
    
    void DFS(string s, vector<string>& res, string sol, int part) {
        if (part == 0) {
            if (s.empty()) res.push_back(sol);
            return;
        }
        
        for (int i = 1; i <= 3; i++) {
            if (i <= s.size() && isValid(s.substr(0, i))) {
                string str = s.substr(0, i) + '.';
                if (part == 1) str.pop_back();
                DFS(s.substr(i), res, sol + str, part - 1);
            }
        }
    }
    
    bool isValid(string s) {
        if (s.empty() || s.size() > 3 || (s.size() > 1 && s[0] == '0')) return false;
        int val = stoi(s);
        return val >= 0 && val <= 255;
    }
};