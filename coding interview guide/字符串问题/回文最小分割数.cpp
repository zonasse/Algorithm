//
// Created by 钟奇龙 on 2019-05-11.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int minCut(string s){
    if(s.size() == 0) return 0;
    vector<vector<bool> > mark(s.size(),vector<bool> (s.size(),false));
    vector<int> dp(s.size()+1);
    dp[s.size()] = -1;
    for(int i=s.size()-1; i>=0; --i){
        dp[i] = INT_MAX;
        for(int j=i; j<s.size(); ++j){
            if(s[i] == s[j] && (j-i < 2 || mark[i+1][j-1])){
                mark[i][j] = true;
                dp[i] = min(dp[i],dp[j+1]+1);
            }
        }
    }
    return dp[0];
}

int main(){
    cout<<minCut("ACDCDCDAD")<<endl;

    return 0;
}