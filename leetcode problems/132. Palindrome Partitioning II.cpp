class Solution {
public:
    int minCut(string s) {
        if(s.empty()) return 0;
        int len = s.size();
        vector<int> dp(len+1,0);
        dp[len] = -1;
        vector<vector<bool> > p(len+1,vector<bool> (len+1,false));
        for(int i=len-1; i>=0; --i){
            dp[i] = INT_MAX;
            for(int j=i; j<len; ++j){
                if(s[j] == s[i] && (j-i < 2 || p[i+1][j-1])){
                    p[i][j] = true;
                    dp[i] = min(dp[i],dp[j+1] + 1);
                }
            }
        }
        return dp[0];
    }
};
