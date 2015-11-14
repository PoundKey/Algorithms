// Thoughts: Let's brute force first
class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            for (int j = s.size() - 1; j > i; j--) {
                int p = i, q = j;
                while (s[p] == s[q]) {
                    p++;
                    q--;
                    if (p >= q && (j-i > end-start)) {
                        start = i;
                        end = j;
                        break;
                    } 
                 }
                 if (p >= q) break;
            }
        }
        return s.substr(start, end - start + 1);
    }
};

// Dynamic Programming: time limit exceeded?
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, end = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, true));
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = s[i] == s[j] && dp[i+1][j-1];
                if (dp[i][j] && (j - i > end - start)) {
                    start = i;
                    end = j;
                }
            }
        }
        return s.substr(start, end - start + 1);
    }
};
