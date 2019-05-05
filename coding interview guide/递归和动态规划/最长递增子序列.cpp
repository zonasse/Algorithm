//
// Created by 钟奇龙 on 2019-05-05.
//
#include <iostream>
#include <vector>
using namespace std;
vector<int> getDpArray(vector<int> arr){
    vector<int> dp(arr.size());
    for(int i=0; i<arr.size(); ++i){
        dp[i] = 1;
        for(int j=0; j<i; ++j){
            if(arr[j] < arr[i]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    return dp;
}
vector<int> getDpArray2(vector<int> arr){
    vector<int> dp(arr.size());
    vector<int> ends(arr.size());
    dp[0] = 1;
    ends[0] = arr[0];
    int right = 0;
    int l = 0;
    int r = 0;
    int m = 0;
    for(int i=1; i<arr.size(); ++i){
        int l = 0;
        int r = right;
        while(l <= r){
            m = (r-l)/2 + l;
            if(arr[i] > ends[m]){
                l = m+1;
            }else{
                r = m-1;
            }
        }
        right = max(l,r);
        dp[i] = l+1;
        ends[l] = arr[i];
    }
    return dp;
}
vector<int> generateLIS(vector<int> arr,vector<int> dp){
    int index = 0;
    int len = 0;
    for(int i=0; i<dp.size(); ++i){
        if(dp[i] > len){
            len = dp[i];
            index = i;
        }
    }
    vector<int> lis(len);
    lis[--len] = arr[index];
    for(int i=index-1; i>=0; --i){
        if(arr[i] < arr[index] && dp[i] == dp[index]-1){
            lis[--len] = arr[i];
            index = i;
        }
    }
    return lis;
}

int main(){
    vector<int> arr = {2,1,5,3,6,4,8,9,7};
    vector<int> lis = generateLIS(arr,getDpArray(arr));
    vector<int> lis2 = generateLIS(arr,getDpArray2(arr));

    return 0;
}
