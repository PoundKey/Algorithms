class Solution {
public:
    /**
     * @param s: A string
     * @return: An integer
     */
    int minCut(string &s) {
        if (s.size() <= 1) return 0;
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        IsPalindrome(isPal, s);
        
        vector<int> dp(n + 1, INT_MAX); // # of cut for s[0, i - 1]
        dp[0] = 0;
        
        for (int i = 1; i <= n; i++) // length
        {
            if (isPal[0][i - 1]) dp[i] = 0;
            
            for (int j = i - 1; j >= 0; j--) // index
            {
                if (isPal[j][i - 1])
                {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n];
    }
    
    
    // determine if substring: s[i][j] is a palindrome
    void IsPalindrome(vector<vector<bool>>& isPal, const string& s)
    {
        int n = s.size();
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (s[i] != s[j])
                {
                    isPal[i][j] = false;
                }
                else if (j - i <= 1)
                {
                    isPal[i][j] = true;
                }
                else
                {
                    isPal[i][j] = isPal[i + 1][j - 1];
                }
            }
        }        
    }
};
