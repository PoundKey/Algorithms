// 1. principle: buy at low price, and sell at high price
// 2. need two variables, minPrice to keep track of the lowest price in previous days, and maxProfit
// 2.1 if minPrice < A[i], do bother, let A[i] be the minPrice
// 2.2 else, calculate the maxProfit using A[i] - minPrice

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
     
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) return 0;
        int n = prices.size();
        int maxProfit = 0, minPrice = prices[0];
        for (int i = 1; i < n; i++) 
        {
            if (prices[i] < minPrice) 
            {
                minPrice = prices[i];
            }
            maxProfit = max(maxProfit, prices[i] - minPrice); 
        }
        return maxProfit;
    }
    
    int maxProfitBruteforce(vector<int> &prices) {
        if (prices.empty()) return 0;
        int n = prices.size();
        int maxProfit = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j <= n - 1; j++) {
                if (prices[j] > prices[i])
                    maxProfit = max(maxProfit, prices[j] - prices[i]);
            }
        }
        return maxProfit;
    }
};
