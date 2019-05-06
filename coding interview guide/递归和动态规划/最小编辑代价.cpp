//
// Created by 钟奇龙 on 2019-05-06.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int minEditCost(string s1,string s2,int insertCost,int deleteCost,int replaceCost){
    if(s1.size() == 0 || s2.size() == 0) return 0;
    vector<vector<int> > dp(s1.size()+1,vector<int> (s2.size()+1,0));
    for(int i=1; i<=s1.size(); ++i){
        dp[i][0] = deleteCost*i;
    }
    for(int j=1; j<=s2.size(); ++j){
        dp[0][j] = insertCost*j;
    }
    for(int i=1; i<=s1.size(); ++i){
        for (int j = 1; j <= s2.size(); ++j) {
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = dp[i-1][j-1] + replaceCost;
            }
            dp[i][j] = min(dp[i][j],dp[i-1][j] + deleteCost);
            dp[i][j] = min(dp[i][j],dp[i][j-1] + insertCost);
        }
    }
    return dp[s1.size()][s2.size()];
}

int main(){
    string s1 = "ab12cd3";
    string s2 = "abcdf";
    int insertCost = 5;
    int deleteCost = 3;
    int replaceCost = 2;
    cout<<minEditCost(s1,s2,insertCost,deleteCost,replaceCost)<<endl;

    return 0;
}