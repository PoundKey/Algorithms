// Thoughts: prices[0:n-1] => prices[0:i] + prices[i:n-1]
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        int profitPre[n] = {0};
        
        int maxProfit = 0, minPrice = prices[0];
        for (int i = 1; i < n; i++) {
            minPrice = min(minPrice, prices[i]);
            profitPre[i] = max(profitPre[i-1], prices[i] - minPrice);
        }
        
        int profitPost = 0, maxPrice = prices[n-1];
        for (int i = n - 2; i >= 0; i--) {
            maxPrice = max(maxPrice, prices[i]);
            profitPost = maxPrice - prices[i];
            maxProfit = max(maxProfit, profitPre[i] + profitPost);
        }
        return maxProfit;
    }

};
