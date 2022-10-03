class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimum = prices[0];
        int len = prices.size();
        int profit = 0;
        for (int i = 1; i < len; i++) {
            profit = max(prices[i] - minimum, profit);
            minimum = min(minimum, prices[i]);
        }
        return profit;
    }
};