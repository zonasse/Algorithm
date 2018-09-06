class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        vector<int> buy(prices.size(),0);
        vector<int> sell(prices.size(),0);
        buy[0] = -prices[0];
        buy[1] = prices[1]>prices[0]?-prices[0]:-prices[1];
        sell[0] = 0;
        sell[1] = prices[1]-prices[0];
        sell[1] = sell[1]>0?sell[1]:0;

        for(int i = 2; i < prices.size(); i++) {
            buy[i] = max(buy[i-1], sell[i-2]-prices[i]);
            sell[i] = max(buy[i-1]+prices[i], sell[i-1]);
        }
        return sell.back();

    }
};
