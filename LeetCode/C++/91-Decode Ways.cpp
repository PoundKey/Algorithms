// Thoughts: DP[i]: the total possible decode ways of s[0:i-1] with length i;
// STE: we will have to consider the siutation where '0' is presented.
// 1. if prev char != '0' 
//    i): curr char != '0' && (prev + curr)  <= 26     => DP[i] = DP[i-1] + DP[i-2];
//    ii): curr char != '0' && (prev + curr) > 26      => DP[i] = DP[i-1]
//    iii): curr char == '0' && (prev + curr) <= 26    => DP[i] = DP[i-2]
//    iv):  curr char == '0' && (prev + curr) > 26     => DP[i] = 0;
// 2. if prev char == '0'
//    i): if curr char != '0' => DP[i] = DP[i-1];
//    ii): if curr char = '0' => DP[i] = 0
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') return 0; 
        vector<int> dp(n + 1, 1);
        dp[1] = s[0] == '0' ? 0 : 1;
        
        for (int i = 2; i <= n; i++) {
            char prev = s[i-2], curr = s[i-1];
            int val = (prev - '0') * 10 + (curr - '0');
            if (val >= 10 && val <= 26) {
                dp[i] = (curr == '0') ? dp[i-2] : dp[i-1] + dp[i-2];
            } else {
                dp[i] = (curr == '0') ? 0 : dp[i-1];
            }
        }
        return dp[n];
    }
};
