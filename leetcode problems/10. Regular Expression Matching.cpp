#include <bits/stdc++.h>
using namespace std;
class Solution1 {
public:
    bool isMatch(string s, string p) {

        return isValid(s,p) && process(s,p,0,0);
    }
    bool process(string &s,string &p,int si,int pi){
        if(pi == p.size()){
            return si == s.size();
        }
        if(pi + 1 == p.size() || p[pi+1] != '*'){
            return si != s.size() && (s[si] == p[pi] || p[pi] == '.') && process(s,p,si+1,pi+1);
        }
        while(si != s.size() && (s[si] == p[pi] || p[pi] == '.')){
            if(process(s,p,si,pi+2)){
                return true;
            }
            si++;
        }
        return process(s,p,si,pi+2);
    }

    bool isValid(string &s,string &p){
        for(int i=0; i<s.size(); ++i){
            if(s[i] == '.' || s[i] == '*'){
                return false;
            }
        }
        for(int i=0; i<p.size(); ++i){
            if(p[i] == '*' && (i == 0 || p[i+1] == '*')){
                return false;
            }
        }
        return true;
    }
};
class Solution2 {
public:
    bool isMatch(string s, string p) {
        if(!isValid(s,p)) return false;
        int sLen = s.size();
        int pLen = p.size();
        bool dp[sLen+1][pLen+1];
        //注意，不能用dp[][] = {false}初始化
        memset(dp,false,sizeof(dp));
        dp[sLen][pLen] = true;
        /*
         * 初始化dp数组
         */
        for(int pi=pLen-2; pi > -1; pi -= 2){
            //dp最后一行
            if(p[pi] != '*' && p[pi+1] == '*'){
                dp[sLen][pi] = true;
            }else{
                break;
            }
        }
        if(sLen > 0 && pLen > 0){
            if(s[sLen-1] == p[pLen-1] || p[pLen-1] == '.'){
                dp[sLen-1][pLen-1] = true;
            }
        }
        /*
         * 开始dp
         */
        for(int si = sLen-1; si > -1; --si){
            for(int pi = pLen-2; pi > -1; --pi){
                if(p[pi+1] != '*'){
                    dp[si][pi] = (s[si] == p[pi] || p[pi] == '.') && dp[si+1][pi+1];
                }else{
                    int sIndex = si;
                    while(sIndex != s.size() && (s[sIndex] == p[pi] || p[pi] == '.')){
                        if(dp[sIndex][pi+2]){
                            dp[si][pi] = true;
                            break;
                        }
                        sIndex++;
                    }
                    if(dp[si][pi] != true){
                        dp[si][pi] = dp[sIndex][pi+2];
                    }
                }
            }
        }
        for(int i=0; i<=sLen; ++i){
            for(int j=0; j<=pLen; ++j){
                printf("%d ",dp[i][j]);
            }
            printf("\n");
        }
        return dp[0][0];
    }
    bool isValid(string &s,string &p){
        for(int i=0; i<s.size(); ++i){
            if(s[i] == '.' || s[i] == '*'){
                return false;
            }
        }
        for(int i=0; i<p.size(); ++i){
            if(p[i] == '*' && (i==0 || p[i-1] == '*')){
                return false;
            }
        }
        return true;
    }
};
int main(){
    string s = "aaaaaaaaaaaaab";
    string p = "a*a*a*a*a*a*a*a*a*a*c";
    Solution2 handle;
    printf("\n%d\n",handle.isMatch(s,p));

}
