class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(coins.size() == 0 || amount < 0) return -1;
        int n = coins.size();
        vector<vector<int> > dp(n,vector<int> (amount+1,0));
        for(int j=1; j<=amount; ++j){
            dp[0][j] = INT_MAX;
            if(j - coins[0] >= 0 && dp[0][j-coins[0]] != INT_MAX){
                dp[0][j] = dp[0][j-coins[0]] + 1;
            }
        }
        for(int i=1; i<n; ++i){
            for(int j=1; j<=amount; ++j){
                int left = INT_MAX;
                if(j-coins[i] >= 0 && dp[i][j-coins[i]] != INT_MAX){
                    left = dp[i][j-coins[i]] + 1;
                }
                dp[i][j] = min(left,dp[i-1][j]);
            }
        }
        return dp[n-1][amount] == INT_MAX ? -1:dp[n-1][amount];
    }
};
