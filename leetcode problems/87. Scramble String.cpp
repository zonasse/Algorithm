int cnt[256];
class Solution1 {
public:
    bool isScramble(string s1, string s2) {
        return isScramble(s1,0,s1.size()-1,s2,0,s2.size()-1);
    }
    bool isScramble(string s1,int l1,int r1,string s2,int l2,int r2){
        if(l1 > r1 || l2 > r2) return false;
        if(r1-l1 != r2-l2) return false;
        if(l1 == r1) return s1[l1] == s2[l2];
        memset(cnt,0,sizeof(cnt));
        for(int i=l1; i<=r1; ++i){
            cnt[s1[i]]++;
        }
        for(int i=l2; i<=r2; ++i){
            cnt[s2[i]]--;
        }
        for(int i=0; i<256; ++i){
            if(cnt[i] != 0) return false;
        }
        for(int i=l1; i<r1; ++i){
            if(isScramble(s1,l1,i,s2,l2,l2+i-l1) && isScramble(s1,i+1,r1,s2,r2-(r1-(i+1)),r2)){
                return true;
            }
            if(isScramble(s1,l1,i,s2,r2-(i-l1),r2) && isScramble(s1,i+1,r1,s2,l2,l2+(r1-i-1))){
                return true;
            }
        }
        return false;
    }
};
class Solution2 {
public:
    bool isScramble(string s1, string s2) {
        if(s1.empty() && s2.empty()) return true;
        if(s1.size() != s2.size()) return false;
        //dp[i][j][k]表示s1从i开始、s2从j开始长度为k的子串是否scramble
        vector<vector<vector<int> > > dp(s1.size(),vector<vector<int> >(s2.size(),vector<int> (s1.size()+1,false)));
        for(int i=0; i<s1.size(); ++i){
            for(int j=0; j<s2.size(); ++j){
                dp[i][j][1] = s1[i] == s2[j];
            }
        }
        for(int len = 2; len <= s1.size(); ++len){
            for(int i=0; i<s1.size()-len+1; ++i){
                for(int j=0; j<s2.size()-len+1; ++j){
                    for(int k=1; k<len; ++k){
                        dp[i][j][len] = dp[i][j][len] || (dp[i][j][k] && dp[i+k][j+k][len-k]) || (dp[i][j+len-k][k] && dp[i+k][j][len-k]);
                    }
                }
            }
        }
        return dp[0][0][s1.size()];
    }
};
