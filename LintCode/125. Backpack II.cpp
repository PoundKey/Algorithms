// 1. a world with me, there is a difference; I took one spot (i) and some space (A[i]), 
//    which means the rest, n-1 elements, could only take up to (m - A[i]) space
// 2. a world without me, there is NOT any difference; the rest n-1 elements, could use all m spaces
// 3. Try to make a difference to the world!

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        if (A.empty()) return 0;
        int n = A.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (A[i-1] > j)
                {
                    dp[i][j] = dp[i-1][j];
                }
                else
                {
                    dp[i][j] = max(V[i-1] + dp[i-1][j-A[i-1]], dp[i-1][j]);
                }
            }
        }
         return dp[n][m];
    }
    
    // space complexity O(m) solution, right to left overwrite
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        if (A.empty()) return 0;
        int n = A.size();
        vector<int> dp(m + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            for (int j = m; j >= 1; j--)
            {
                if (A[i-1] <= j)
                {
                    dp[j] = max(V[i-1] + dp[j-A[i-1]], dp[j]);
                }
            }
        }
        return dp[m];
    }    
};
