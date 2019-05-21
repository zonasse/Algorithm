//
// Created by 钟奇龙 on 2019-05-21.
//
#include <iostream>
#include <vector>
using namespace std;
/*
 * 暴力递归
 */
int helper(int nLevel,int kChess){
    if(nLevel == 0) return 0;
    if(kChess == 1) return nLevel;
    int minTimes = INT_MAX;
    for(int i=1; i<=nLevel; ++i){
        minTimes = min(minTimes,max(helper(i-1,kChess-1),helper(nLevel-i,kChess)));
    }
    return minTimes+1;
}
int solution(int nLevel,int kChess){
    if(nLevel < 1 || kChess < 1) return 0;
    return helper(nLevel,kChess);
}
/*
 * dp
 */
int solution2(int nLevel,int kChess){
    if(nLevel < 1 || kChess < 1) return 0;
    vector<vector<int> > dp(nLevel+1,vector<int>(kChess+1,0));
    //棋子数为1时
    for(int i=1; i<=nLevel; ++i){
        dp[i][1] = i;
    }
    for(int i=2; i<=nLevel; ++i){
        for(int j=2; j<=kChess; ++j){
            int minTimes = INT_MAX;
            for(int k=1; k<=i; ++k){
                minTimes = min(minTimes,max(dp[k-1][j-1],dp[i-k][j]));
            }
            dp[i][j] = minTimes+1;
        }
    }
    return dp[nLevel][kChess];
}
int main(){
//    cout<<solution(3,2)<<endl;
    cout<<solution2(105,2)<<endl;
    return 0;
}