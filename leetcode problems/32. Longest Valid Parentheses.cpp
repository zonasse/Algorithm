class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty()) return 0;
        vector<int> dp(s.size(),0);
        int maxLen = 0;
        for(int i=1; i<s.size(); ++i){
            if(s[i] == ')'){
                int pre = i-dp[i-1]-1;
                if(pre >= 0 && s[pre] == '('){
                    dp[i] = dp[i-1] + 2 + (pre > 0? dp[pre-1]:0);
                }

            }
            maxLen = max(maxLen,dp[i]);
        }
        return maxLen;
    }
};
