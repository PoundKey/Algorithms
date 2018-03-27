class Solution {
public:
    bool wordBreak(string &s, unordered_set<string> &dict) {
        if (s.empty()) return true;
        if (dict.empty()) return false;
        int n = s.size();
        // dp[i] is true if s[0, i - 1] could be break
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        
        for (int i = 1; i <= n; i++)
        {
            if (dict.count(s.substr(0, i))) dp[i] = true;
            if (dp[i]) // dp[i] could be true due to prev calculation
            {
                for (int j = i + 1; j <= n; j++)
                {
                    string substr = s.substr(i, j - i);
                    if (dict.count(substr))
                    {
                        dp[j] = true;
                    }
                    if (j == n && dp[j]) return true;
                }
            }
        }
        return dp[n];
    }


     // Brute force way.
    /*
     * @param s: A string
     * @param dict: A dictionary of words dict
     * @return: A boolean
     */
    bool wordBreak(string &s, unordered_set<string> &dict) {
        if (s.empty()) return true;
        if (dict.empty()) return false;
        return WordBreak(s, dict, 0);
    }
    
    bool WordBreak(const string& s, const unordered_set<string>& dict, int start)
    {
        if (start >= s.size()) return true;
        for (int i = 1; i <= s.size() - start; i++)
        {
            if (dict.count(s.substr(start, i)) && WordBreak(s, dict, start + i))
            {
                return true;
            }
        }
        return false;
    }
};
