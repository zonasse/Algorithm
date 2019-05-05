//
// Created by 钟奇龙 on 2019-05-05.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> getDpArray(string s1,string s2){
    vector<vector<int> > dp(s1.size(),vector<int> (s2.size()));
    dp[0][0] = s1[0] == s2[0] ? 1:0;
    for(int i=1; i<s1.size(); ++i){
        dp[i][0] = max(dp[i-1][0],s1[i] == s2[0] ? 1:0);
    }
    for(int j=1; j<s2.size(); ++j){
        dp[0][j] = max(dp[0][j-1],s1[0] == s2[j] ? 1:0);
    }
    for(int i=1; i<s1.size(); ++i){
        for(int j=1; j<s2.size(); ++j){
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            if(s1[i] == s2[j]){
                dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
            }
        }
    }
    return dp;
}

string longestCommonSerial(string s1,string s2){
    if(s1.size() == 0 || s2.size() == 0) return "";
    vector<vector<int> > dp = getDpArray(s1,s2);
    int row = dp.size()-1;
    int col = dp[0].size()-1;
    int length = dp[row][col];
    string res = "";
    while(length >= 0){
        if(row > 0 && dp[row-1][col] == dp[row][col]){
            row--;
        }else if(col > 0 && dp[row][col-1] == dp[row][col]){
            col--;
        }else{
            res = s1[row] + res;
            row--;
            col--;
            length--;
        }
    }
    return res;
}

int main(){
    string s1 = "1A2C3D4B56";
    string s2 = "B1D23CA45B6A";
    cout<<longestCommonSerial(s1,s2)<<endl;

    return 0;
}