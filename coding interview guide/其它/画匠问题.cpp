//
// Created by 钟奇龙 on 2019-05-21.
//
#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> arr,int num){
    if(arr.size() == 0 || num < 1) return INT_MIN;
    vector<vector<int> > dp(num,vector<int>(arr.size()));
    dp[0][0] = arr[0];
    for(int j=1; j<arr.size(); ++j){
        dp[0][j] = dp[0][j-1] + arr[j];
    }
    for(int i=1; i<num; ++i){
        dp[i][0] = arr[0];
    }
    for(int i=1; i<num; ++i){
        for(int j=1; j<arr.size(); ++j){
            int minTime = INT_MAX;
            for (int k = 0; k < j; ++k) {
                minTime = min(minTime,max(dp[i-1][k],dp[0][j]-dp[0][k]));
            }
            dp[i][j] = minTime;
        }
    }
    return dp[num-1][arr.size()-1];
}

int main(){
        cout<<-3/2<<" "<<-3%2<<endl;
//    cout<<solution({3,1,4},2)<<endl;
//    cout<<solution({1,1,1,4,3},3)<<endl;

    return 0;
}