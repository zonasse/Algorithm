class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        vector<int> maxProfitBefore(prices.size(),0);
        vector<int> maxProfitAfter(prices.size(),0);
        /*
         * 计算第i天之前的最大收益
         */
        int minBuy = prices[0];
        int maxProfit = 0;
        for(int i=1; i<prices.size(); ++i){
            int curProfit = prices[i] - minBuy;
            if(curProfit < 0){
                minBuy = prices[i];
            }else if(curProfit > maxProfit){
                maxProfit = curProfit;
            }
            maxProfitBefore[i] = maxProfit;
        }
        /*
         * 计算第i天之后的最大收益
         */
        int maxSell = prices[prices.size()-1];
        maxProfit = 0;
        for(int i=prices.size()-2; i>=0; --i){
            int curProfit = maxSell - prices[i];
            if(curProfit < 0){
                maxSell = prices[i];
            }else if(curProfit > maxProfit){
                maxProfit = curProfit;
            }
            maxProfitAfter[i] = maxProfit;
        }
        /*
         * 计算两次买卖最大利润
         */
        maxProfit = 0;
        for(int i=0; i<prices.size(); ++i){
            maxProfit = max(maxProfit,maxProfitBefore[i] + maxProfitAfter[i]);
        }
        return maxProfit;
    }
};
