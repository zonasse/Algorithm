//
// Created by 钟奇龙 on 2019-05-10.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> getDP(string s){
    vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
    for(int j=1; j<s.size(); ++j){
        for(int i=0; i<j; ++i){
            if(i == j-1){
                if(s[i] == s[j]){
                    dp[i][j] = 0;
                }else{
                    dp[i][j] = 1;
                }
            }else{
                if(s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1];
                }else{
                    dp[i][j] = min(dp[i+1][j],dp[i][j-1]) + 1;
                }
            }
        }
    }
    return dp;
}

string getPalindrome(string s){
    if(s.size() == 0) return "";
    vector<vector<int> > dp = getDP(s);
    string res(s.size() + dp[0][s.size()-1],' ');
    int left = 0;
    int right = res.size() -1;
    int i = 0;
    int j = s.size()-1;
    while(i <= j){
        if(s[i] == s[j]){
            res[left++] = s[i++];
            res[right--] = s[j--];
        }else{
            if(dp[i+1][j] < dp[i][j-1]){
                res[left++] = s[i];
                res[right--] = s[i++];
            }else{
                res[left++] = s[j];
                res[right--] = s[j--];
            }
        }
    }
    return res;
}

int main(){
    cout<<getPalindrome("ab")<<endl;

    return 0;
}