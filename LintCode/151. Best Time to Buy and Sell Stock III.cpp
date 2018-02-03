class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) return 0;
        int n = prices.size();
        vector<int> leftMaxProfit(n, 0);
        int minPrice = prices[0];
        for (int i = 1; i < n; i++) 
        {
            if (prices[i] < minPrice) 
            {
                minPrice = prices[i];
            }
            leftMaxProfit[i] = max(leftMaxProfit[i-1], prices[i] - minPrice);
        }
        
        vector<int> rightMaxProfit(n, 0);
        int maxPrice = prices[n-1];
        for (int i = n - 2; i >= 0; i--)
        {
            if (prices[i] > maxPrice)
            {
                maxPrice = prices[i];
            }
            rightMaxProfit[i] = max(rightMaxProfit[i+1], maxPrice - prices[i]);
        }
        
        int maxProfit = 0; 
        for (int i = 0; i < n; i++)
        {
            maxProfit = max(maxProfit, leftMaxProfit[i]);
            if (i < n - 1) // at most twice
            {
                maxProfit = max(maxProfit, leftMaxProfit[i] + rightMaxProfit[i+1]);
            }

        }
        return maxProfit;
    }
