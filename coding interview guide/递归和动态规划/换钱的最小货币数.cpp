//
// Created by 钟奇龙 on 2019-05-04.
//
#include <iostream>
#include <vector>
using namespace std;

int minCoins1(vector<int> arr,int aim){
    if(arr.size() == 0 || aim < 0) return -1;
    int n = arr.size();
    vector<vector<int> > dp(n,vector<int>(aim+1));
    for (int i = 1; i <= aim; ++i) {
        dp[0][i] = INT_MAX;
        if(i-arr[0] >= 0 && dp[0][i-arr[0]] != INT_MAX){
            dp[0][i] = dp[0][i-arr[0]] + 1;
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= aim; ++j) {
            int left = INT_MAX;
            if(j-arr[i] >= 0 && dp[i][j-arr[i]] != INT_MAX){
                left = dp[i][j-arr[i]] + 1;
            }
            dp[i][j] = min(left,dp[i-1][j]);
        }
    }
    return dp[n-1][aim] != INT_MAX ? dp[n-1][aim]:-1;
}

int minCoins1_1(vector<int> arr,int aim){
    if(arr.size() == 0 || aim < 0) return -1;
    vector<int> dp(aim+1);
    for(int i=1; i<=aim; ++i){
        dp[i] = INT_MAX;
        if(i-arr[0] >= 0 && dp[i-arr[0]] != INT_MAX){
            dp[i] = dp[i-arr[0]] + 1;
        }
    }
    for(int i=0; i<arr.size(); ++i){
        for (int j = 1; j <= aim; ++j) {
            int left = INT_MAX;
            if(j-arr[i] >= 0 && dp[j-arr[i]] != INT_MAX){
                left = dp[j-arr[i]] + 1;
            }
            dp[j] = min(left,dp[j]);
        }
    }
    return dp[aim] != INT_MAX ? dp[aim]:-1;
}

int minCoins2(vector<int> arr,int aim){
    if(arr.size() == 0 || aim < 0) return -1;
    vector<vector<int> > dp(arr.size(),vector<int> (aim+1));
    for(int i=1; i<=aim; ++i){
        dp[0][i] = INT_MAX;
    }
    if(aim >= arr[0]){
        dp[0][arr[0]] = 1;
    }
    for(int i=1; i<arr.size(); ++i){
        for(int j=1; j<=aim; ++j){
            int left = INT_MAX;
            if(j >= arr[i] && dp[i-1][j-arr[i]] != INT_MAX){
                left = dp[i-1][j-arr[i]] + 1;
            }
            dp[i][j] = min(left,dp[i-1][j]);
        }
    }
    return dp[arr.size()-1][aim] != INT_MAX ? dp[arr.size()-1][aim]:-1;
}
int minCoins2_2(vector<int> arr,int aim){
    if(arr.size() == 0 || aim < 0) return -1;
    vector<int> dp(aim+1);
    for(int i=1; i<=aim; ++i){
        dp[i] = INT_MAX;
    }
    if(aim >= arr[0]){
        dp[arr[0]] = 1;
    }
    for (int i = 1; i < arr.size(); ++i) {
        for (int j = aim; j >= 1; --j) {
            int left = INT_MAX;
            if(j >= arr[i] && dp[j-arr[i]] != INT_MAX){
                left = dp[j-arr[i]] + 1;
            }
            dp[j] = min(left,dp[j]);
        }
    }
    return dp[aim] != INT_MAX ? dp[aim]:-1;
}
int main(){
    vector<int> arr = {5,2,3};
    cout<<minCoins1(arr,20)<<endl;
    cout<<minCoins1_1(arr,20)<<endl;
    cout<<minCoins2({5,2,5,3},15)<<endl;
    cout<<minCoins2_2({5,2,5,3},15)<<endl;

    return 0;
}