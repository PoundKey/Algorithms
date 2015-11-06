// Thoughts: 
class Solution {
public:
    int numSquares(int n) {
        vector<int> memo(n + 1, INT_MAX);
        memo[0] = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 1; (i + j * j) <= n; j++) {
                memo[i + j * j] = min(memo[i + j * j], memo[i] + 1);
            }
        }
        return memo[n];
    }
};
