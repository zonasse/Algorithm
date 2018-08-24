class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int sell = 0;
        int buy = INT_MAX;
        for(int i=0; i<prices.size(); ++i){
            buy = min(buy,prices[i]);
            sell = max(sell,prices[i]-buy);
        }
        return sell;
    }
};
