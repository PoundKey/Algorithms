// Thoughts: Let's do the recursion way first
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if (s.empty()) return true;
        for (int i = 1; i <= s.size(); i++) {
            if (wordDict.count(s.substr(0, i)) &&
                wordBreak(s.substr(i, s.size() - i), wordDict)) {
                return true;
            }
        }
        return false;
    }
};

// Thoughts: Dynamic Programming
// dp[i] = true if str[0, i-1] is break-able.
// STE: dp[i] = any_of(dp[j] && wordDict.contains(j, i - j)) //another loop here
// for example: 'leetcode', when i = 4, check to see if 'leet' is break-able
// iterate pairs: (dp[3] = 'lee', 't'), (dp[2] = 'le', 'et'), (dp[1] = 'l', 'eet')
// and (dp[0] = true, 'leet')
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        if (n == 0) return true;
        vector<int> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] && wordDict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

