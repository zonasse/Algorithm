class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if(envelopes.size() == 0) return 0;
        sort(envelopes.begin(),envelopes.end());
        int n = envelopes.size();
        vector<int> dp(n,1);
        int res = 1;
        for(int i=1; i<n; ++i){
            for(int j=0; j<i; ++j){
                if(envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            res = max(res,dp[i]);
        }
        return res;
    }
};
