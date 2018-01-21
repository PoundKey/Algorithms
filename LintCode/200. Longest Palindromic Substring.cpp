class Solution {
public:
    /**
     * @param s input string
     * @return the longest palindromic substring
     */
    string longestPalindrome(string& s) {
        if (s.empty()) return s;
        string res;
        int n = s.size(), maxLen = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= i; j--) {
                if (s[i] != s[j]) {
                    dp[i][j] = false; 
                } else if (j - i <= 1) {
                    dp[i][j] = true;
                } else {
                    dp[i][j] = dp[i+1][j-1];
                }
                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    res = s.substr(i, maxLen);
                }
            }
        }
        return res;
    }

    string longestPalindromeN2(string& s) {
        if (s.empty()) return s;
        string res;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int start = i, end = start;
            while (end < n - 1 && s[end] == s[end+1]) end++;
            while (start > 0 && end < n - 1) {
                if (s[start-1] != s[end+1]) {
                    break;
                } else {
                    start--;
                    end++;
                }
            }
            int len = end - start + 1;
            if (len > res.size()) res = s.substr(start, len);
        }
        return res;
    }
    
    string longestPalindromeN3(string& s) {
        if (s.empty()) return s;
        string res;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j) &&
                   (j - i + 1 > res.size())) 
                   {
                       res = s.substr(i, j - i + 1);
                   }
            }
        }
        return res;
    }
    bool isPalindrome(string& s, int start, int end) {
        if (start > end) return false;
        while (start <= end) {
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }
};
