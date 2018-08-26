class Solution{
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty() || wordDict.empty()) return false;
        unordered_set<string> wordSet(wordDict.begin(),wordDict.end());
        int len = s.size();
        vector<bool> dp(len+1,false);
        dp[0] = true;
        for(int i=0; i<=len; ++i){
            for(int j=0; j<i; ++j){
                if(dp[j] && wordSet.count(s.substr(j,i-j))){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[len];
    }

};
