// Thoughts: construct the isPalindrome matrix from Q5
// backtracking, starting from s[0,0], s[0,1], s[0,2]...
// terminates when 'start' index is out of range (start == s.size());

// 2015
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

// 2020
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if (s.empty())
        {
            return res;
        }
        vector<string> curr;
        partition(res, curr, s);
        return res;
    }
    
    void partition(vector<vector<string>>& res, vector<string>& curr, string s)
    {
        if (s.empty())
        {
            res.push_back(curr);
            return;
        }
        
        for (int i = 0; i < s.size(); i++)
        {
            string prefix = s.substr(0, i + 1);
            if (isPalindrome(prefix))
            {
                curr.push_back(prefix);
                partition(res, curr, s.substr(i + 1));
                curr.pop_back();
            }
        }
    }
    
    bool isPalindrome(const string& str)
    {
        if (str.size() <= 1)
        {
            return true;
        }
        
        int start = 0, end = str.size() - 1;
        while (start < end)
        {
            if (str[start] != str[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
