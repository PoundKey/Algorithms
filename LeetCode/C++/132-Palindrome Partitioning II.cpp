// Thoughts: State dp[i]: the minimal cut needed for string with length i, starting from index 0. (str[0, i-1])
// STE: dp[i] = min(dp[i], dp[j] + 1)  for 0 <= j < i
// for example, if i = 3, we wish to find out the minimal cut for str[0, 2],
// therefore, we check for:
// 1: isPal(str[2,2]), dp[3] = min(dp[3], dp[2] + 1)
// 2: isPal(str[1,2]), dp[3] = min(dp[3], dp[1] + 1)
// 3: isPal(str[0,2]), dp[3] = min(dp[3], dp[0] + 1)

class Solution {
public:
    int minCut(string s) {
        vector< vector<string> > res;
        int n = s.size();
        if (n == 0) return 0;
        vector< vector<bool> > isPal(n, vector<bool>(n, true));
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                isPal[i][j] = s[i] == s[j] && isPal[i+1][j-1];
            }
        }
        
        vector<int> dp(n + 1, n - 1);
        dp[0] = -1; 
        for (int i = 1; i <= n; i++) {
            for (int j = i-1; j >= 0; j--) {
                if (isPal[j][i-1]) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n];
    }
};

//Otherwise, we can brute force with backtracking, from Q131
class Solution {
public:
    int minCut(string s) {
        vector< vector<string> > res;
        int n = s.size();
        if (n == 0) return 0;
        vector< vector<bool> > dp(n, vector<bool>(n, true));
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = s[i] == s[j] && dp[i+1][j-1];
            }
        }
        
        int minCut = s.size() - 1;
        DFS(dp, s, minCut, 0, 0);
        return minCut;
    }
    
    void DFS(vector< vector<bool> >& dp, string& s, int& minCut, int cut, int start) {
        if (start == s.size()) {
            minCut = min(minCut, cut);
            return;
        }
        
        for (int i = start; i < s.size(); i++) {
            if (dp[start][i]) 
                DFS(dp, s, minCut, cut + 1, i + 1);
        }
    }
};