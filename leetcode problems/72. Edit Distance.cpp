class Solution {
public:
    int minDistance(string word1, string word2) {
        int dc = 1;//删除代价
        int rc = 1;//修改代价
        int ic = 1;//插入代价
        int m = word1.size();
        int n = word2.size();
        vector<vector<int> > dp(m+1,vector<int> (n+1,0));
        for(int i=1; i<=m; ++i){
            dp[i][0] = dc*i;
        }
        for(int j=1; j<=n; ++j){
            dp[0][j] = ic*j;
        }
        for(int i=1; i<=m; ++i){
            for(int j=1; j<=n; ++j){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = dp[i-1][j-1] + rc;
                }
                dp[i][j] = min(dp[i][j],dp[i-1][j] + dc);
                dp[i][j] = min(dp[i][j],dp[i][j-1] + ic);
            }
        }
        return dp[m][n];
    }
};
