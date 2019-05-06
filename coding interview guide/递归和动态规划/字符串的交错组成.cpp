//
// Created by 钟奇龙 on 2019-05-06.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isCross(string s1,string s2,string aim){
    if(aim.size() != s1.size() + s2.size()) return false;
    vector<vector<bool>> dp(s1.size()+1,vector<bool> (s2.size()+1));
    dp[0][0] = true;
    for(int i=1; i<s1.size(); ++i){
        if(s1[i-1] != aim[i-1]){
            break;
        }
        dp[i][0] = true;
    }
    for(int j=1; j<s2.size(); ++j){
        if(s2[j-1] != aim[j-1]){
            break;
        }
        dp[0][j] = true;
    }
    for(int i=1; i<=s1.size(); ++i){
        for(int j=1; j<=s2.size(); ++j){
            if((dp[i-1][j] && s1[i-1] == aim[i+j-1]) || (dp[i][j-1] && s2[j-1] == aim[i+j-1])){
                dp[i][j] = true;
            }
        }
    }
    return dp[s1.size()][s2.size()];
}

int main(){
    string s1 = "AB";
    string s2 = "12";
    cout<<isCross(s1,s2,"1A2B")<<endl;

    return 0;
}