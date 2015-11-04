// Thoughts: currProfit = currPrice - minPrice
// We dynamically track the minPrice and maxProfit by storing them into two varibales.
// for each element i, update minPrice and maxProfit.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int minPrice = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            profit = max(profit, prices[i] - minPrice);
        }
        return profit;
    }
};

