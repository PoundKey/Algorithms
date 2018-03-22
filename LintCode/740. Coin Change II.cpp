class Solution {
public:
    /**
     * @param amount: a total amount of money amount
     * @param coins: the denomination of each coin
     * @return: the number of combinations that make up the amount
     */
     
    int change(int amount, vector<int> &coins) {
        if (coins.size() == 0) return 0;
        int n = coins.size();
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (const auto& coin : coins)
        {
            for (int i = coin; i <= amount; i++)
            {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
    
    int changeO2(int amount, vector<int> &coins) {
        if (coins.size() == 0) return 0;
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = 1;
            for (int j = 1; j <= amount; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (coins[i - 1] <= j)
                {
                    dp[i][j] += dp[i][j - coins[i - 1]];
                }
            }
        }
        
        return dp[n][amount];
    }
};
