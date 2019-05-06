 //
// Created by 钟奇龙 on 2019-05-06.
//
#include <iostream>
#include <vector>
using namespace std;

int minHP(vector<vector<int> > arr){
    if(arr.size() == 0 || arr[0].size() == 0) return 1;
    int row = arr.size()-1;
    int col = arr[0].size()-1;
    vector<vector<int> > dp(row+1,vector<int> (col+1));
    dp[row][col] = arr[row][col] > 0 ? 1:(-arr[row][col] + 1);
    for(int i=row-1; i>=0; --i){
        dp[i][col] = max(1,dp[i+1][col]-arr[i][col]);
    }
    for(int j=col-1; j>=0; --j){
        dp[row][j] = max(1,dp[row][j+1]-arr[row][j]);
    }
    for(int i=row-1; i>=0; --i){
        for(int j=col-1; j>=0; --j){
            int right = max(1,dp[i][j+1]-arr[i][j]);
            int down = max(1,dp[i+1][j]-arr[i][j]);
            dp[i][j] = min(right,down);
        }
    }
    return dp[0][0];
}

int main(){
    vector<vector<int>> arr = {{-2,-3,3},{-5,-10,},{0,30,-5}};
    cout<<minHP(arr)<<endl;
    return 0;
}