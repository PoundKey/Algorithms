class Solution {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> A) {
        if (A.empty()) return 0;
        int n = A.size();
        if (n == 1) return A[0];
        if (n == 2) return max(A[0], A[1]);
        vector<long long> dp(n, 0);
        dp[0] = A[0];
        dp[1] = max(A[0], A[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + A[i]);
        }
        return dp[n-1];
    }
};
