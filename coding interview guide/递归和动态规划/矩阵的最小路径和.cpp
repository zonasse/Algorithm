//
// Created by 钟奇龙 on 2019-05-04.
//
#include <vector>
#include <iostream>
using namespace std;

int minPathSum(vector<vector<int> > &m){
    if(m.size() == 0 || m[0].size() == 0) return 0;
    int row = m.size();
    int col = m[0].size();
    vector<vector<int> > dp(row,vector<int>(col,0));
    dp[0][0] = m[0][0];
    for(int i=1; i<row; ++i){
        dp[i][0] = dp[i-1][0] + m[i][0];
    }
    for(int j=1; j<col; ++j){
        dp[0][j] = dp[0][j-1] + m[0][j];
    }
    for(int i=1; i<row; ++i){
        for(int j=1; j<col; ++j){
            dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + m[i][j];
        }
    }
    return dp[row-1][col-1];
}

int minPathSum2(vector<vector<int> > &m){
    if(m.size() == 0 || m[0].size() == 0) return 0;
    int row = m.size();
    int col = m[0].size();
    int more = max(row,col);
    int less = min(row,col);
    bool isRowMore = more == row;
    vector<int> dp(less,0);
    dp[0] = m[0][0];
    for(int i=1; i<less; ++i){
        dp[i] = dp[i-1] + (isRowMore ? m[0][i]:m[i][0]);
    }
    for(int i=1; i<more; ++i){
        dp[0] = dp[0] + (isRowMore? m[i][0]:m[0][i]);
        for(int j=1; j<less; ++j){
            dp[j] = min(dp[j-1],dp[j]) + (isRowMore?m[i][j]:m[j][i]);
        }
    }
    return dp[less-1];
}
int main(){
    vector<vector<int> > matrix = {{1,3,5,9},{8,1,3,4},{5,0,6,1},{8,8,4,0}};
    cout<<minPathSum(matrix)<<endl;
    cout<<minPathSum2(matrix)<<endl;
    return 0;
}