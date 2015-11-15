// Thoughts: Accumuate the difference between A[i] and A[i-1], 
// given that A[i-1] > A[i], the greedy algorithm
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            int diff = prices[i] - prices[i-1];
            if (diff > 0) profit += diff; 
        }
        return profit;
    }
};

// Thoughts: More understable code, we're greedy about the profit gap between today and yesterday.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int profit = 0, total = 0;
        for (int i = 1; i < prices.size(); i++) {
            profit += prices[i] - prices[i-1];
            if (profit > 0) {
                total += profit;
            } 
             profit = 0;
        }
        return total;
    }
};

