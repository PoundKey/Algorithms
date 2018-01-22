// 1. buy at lowest and sell at highest
// 2. record the lowest prices, highest means that A[i] > A[i-1]
class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) return 0;
        int maxProfit = 0, minPrice = prices[0], n = prices.size();
        for (int i = 0; i < n; i++) {
            if (i == n - 1) 
            {
                // one time profit if the stock prices go up all the time
                maxProfit += prices[i] - minPrice;
                continue;
            }            
            if (prices[i] >= prices[i + 1]) { // price not increasing
                maxProfit += prices[i] - minPrice; // profit get
                minPrice = prices[i + 1];
            }

        }
        return maxProfit;
    }
};
